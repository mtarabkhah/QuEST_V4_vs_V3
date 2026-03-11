#!/bin/bash

# Function to write results to CSV file
write_to_csv() {
    local output_file="$1"
    echo "file_name,average_time (s),iterations per second" > "$output_file"
    for i in "${!file_names[@]}"; do
        echo "${file_names[i]},${average_times[i]},${iter_per_secs[i]}" >> "$output_file"
    done
}

create_clear_csv() {
    local file_path="$1"
    local header="$2"

    # Create the file if it doesn't exist
    touch "$file_path"

    # Clear the file
    > "$file_path"

    # Write the header to the file
    echo "$header" > "$file_path"
}

calc_average_time() {
    # This Bash script version uses awk to skip the header line and the specified number of warm-up lines 
    # and then calculates the average of the remaining values in the first column.
    # In Bash, the special variables $1, $2, $3, etc., represent the positional parameters passed to a script or function. 
    local file_path="$1"
    local warmup_iterations="$2"

    if [ ! -f "$file_path" ]; then
        echo "Error!"
        echo "$file_path does not exist"
        return 0
    fi

    # awk -v warmup_iterations="$warmup_iterations" 'NR > warmup_iterations + 1 { sum += $1; count++ } END { print sum / count }' "$file_path"
    # awk -v warmup_iterations="$warmup_iterations" 'NR > warmup_iterations + 1 { sum += $1 + 0; count++ } END { if(count>0) print sum / count; else print 0 }' "$file_path"
    awk -v warmup_iterations="$warmup_iterations" 'NR > warmup_iterations + 1 { sum += $1 + 0; count++ } END { if(count>0) printf "%.10f\n", sum / count; else print 0 }' "$file_path"

}

report_results() {
    local file_path="$1"
    local fun="$2"
    local ave="$3"
    local iter_per_sec="$4"

    # Check if the file already exists
    if [ ! -f "$file_path" ]; then
        touch "$file_path"  # Create the file if it doesn't exist
        echo "name,average time,iter per sec" > "$file_path"  # Write the header
    fi

    # Write the data in append mode
    echo "$fun,$ave,$iter_per_sec" >> "$file_path"
}

# Run the benchmark
clear
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
warmupIterations=5
benchmarkingIterations=5
timeDir="$script_dir/Results/CSV_Files/Time/"
resultDir="$script_dir/Results/CSV_Files/StateVector/"
figDir="$script_dir/Results/Figures/"
CircuitList=("QFT" "QFT_H")
QSchoice=("QuEST_V3" "QuEST_V4")
numThreads="8"
nQList=({2..20..2})
namePattern="BenchTime"
lineWidth=2
tolerance=0.0001

echo "warmupIterations: $warmupIterations"
echo "benchmarkingIterations: $benchmarkingIterations"
echo "timeDir: $timeDir"
echo "resultDir: $resultDir"
echo "Circuits: ${CircuitList[@]}"
echo "Number of threads: ${numThreads}"
echo "nQ: ${nQList[@]}"

# fileList=()
for circuit in ${CircuitList[@]}; do
    echo "========="
    echo "Circuit: $circuit"
    for ver in 3 4
    do
        sourceDir="$script_dir/QuEST_V${ver}/QuEST/Benchmarking"
        benchmark_output_file="${timeDir}${namePattern}_NumThreads_${numThreads}_${circuit}_QuEST_V${ver}.csv"
        
        # echo "$benchmark_output_file"
        create_clear_csv "$benchmark_output_file" "name,average time,iter per sec" # clear the previous results if any
        for nQ in ${nQList[@]}; do
            echo "---------"
            echo "Number of qubits: $nQ"
            nQ2D=$(printf "%02d" "$nQ")
            
            filename="QC_${circuit}_${nQ2D}_QuEST_V${ver}.c"
            filepath="${sourceDir}/${filename}"
            if [[ -f "$filepath" ]]; then
                # fileList+=("$filepath")
                echo "Compiling $filename"
                output_file="${timeDir}RunTime_NumThreads_${numThreads}_QC_${circuit}_${nQ2D}_QuEST_V${ver}.csv"
                create_clear_csv "$output_file" "Simulation Time" # clear the previous results if any

                # Change directory to the source directory
                cd "$sourceDir"
                
                echo "numThreads = $numThreads"
                if [ $ver -eq 3 ]; then
                    cmake .. -DUSER_SOURCE="$filename" -DMULTITHREADED=ON -DGPUACCELERATED=OFF
                else
                    cmake .. -DUSER_SOURCE="$filename" -DENABLE_MULTITHREADING=ON -DENABLE_CUDA=OFF -DOUTPUT_EXE="demo"
                fi
                make
                export OMP_NUM_THREADS=$numThreads
                
                # Warm-up
                for i in $(seq 1 $warmupIterations); do
                    ./demo "$timeDir" "$resultDir" "$numThreads" > /dev/null 
                done

                # Actual benchmarking
                for i in $(seq 1 $benchmarkingIterations); do
                    ./demo "$timeDir" "$resultDir" "$numThreads" > /dev/null
                done

                # Calculate average time
                average=$(calc_average_time "$output_file" "$benchmarkingIterations")
                echo "average = ${average}"
                iter_per_sec=$(echo "scale=10; 1/$average" | bc -l)

                benchmark_output_file="${timeDir}${namePattern}_NumThreads_${numThreads}_${circuit}_QuEST_V${ver}.csv"
                # echo "$benchmark_output_file"
                report_results "$benchmark_output_file" "${circuit}_${nQ2D}" "$average" "$iter_per_sec"

                # Clean up (if needed)
                make clean
            else
                echo "File not found: $filepath"
            fi
        done
    done
done

cd "$script_dir"

python3 CompareCSVResults.py "$resultsDir" "$tolerance" ${#QSchoice[@]} "${QSchoice[@]}" "${#CircuitList[@]}" "${CircuitList[@]}" "${#nQList[@]}" "${nQList[@]}" "$namePattern"

python3 MergeCSVResults.py "$timeDir" "$namePattern" "${#QSchoice[@]}" "${QSchoice[@]}" "${#CircuitList[@]}" "${CircuitList[@]}" "${#nQList[@]}" "${nQList[@]}" "${numThreads}"

python3 PlotCSVResults.py "$timeDir" "$namePattern" "${#numThreads}" ${#QSchoice[@]} "${QSchoice[@]}" "${#CircuitList[@]}" "${CircuitList[@]}" "${figDir}" "${#nQList[@]}" "${nQList[@]}"