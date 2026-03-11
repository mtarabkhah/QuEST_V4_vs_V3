# QuEST V4 vs V3
This repository contains a simple benchmark to compare the performance of the newer version of QuEST with the previous version.

## Running the benchmark
To run the benchmark, simply execute:

```./run.sh```

## Results
* Figures will be saved in `./Results/Figures`
* Raw simulation time data will be saved in `./Results/CSV_Files/Time`

## User inputs
Benchmark parameters can be modified inside `./run.sh`.

The current configuration:
* Runs the simulation on the CPU using **8 threads**
* Simulates two circuits: `QFT` and `QFT_H`
    * `QFT_H` is similar to `QFT` but adds Hadamard gates to all qubits at the start of the circuit
* Runs each circuit with different numbers of qubits (from **2 to 20**)
* Uses **5 warm-up iterations**, then **averages** the simulation time over the **next 5 iterations**