import sys, os, csv

if __name__ == "__main__":
    print("Merging results...")
    # "$resultsDir" "$namePattern" "${#QSchoice[@]}" "${QSchoice[@]}" "${#Circchoice[@]}" "${Circchoice[@]}" "${#nQ[@]}" "${nQ[@]}" "${#nL[@]}" "${nL[@]}" "${#numThreads[@]}" "${numThreads[@]}"
    resultDir = sys.argv[1]
    namePattern = sys.argv[2]
    QSchoiceLength = int(sys.argv[3])
    QSchoiceList = sys.argv[4:4+QSchoiceLength]
    CircuitsLength = int(sys.argv[4+QSchoiceLength])
    CircuitList = sys.argv[5+QSchoiceLength:5+QSchoiceLength+CircuitsLength]
    nQLength = int(sys.argv[5+QSchoiceLength+CircuitsLength])
    nQList = [int(x) for x in sys.argv[6+QSchoiceLength+CircuitsLength:6+QSchoiceLength+CircuitsLength+nQLength]]
    numThreads = int(sys.argv[6+QSchoiceLength+CircuitsLength+nQLength])
    
    # print(f"resultDir: {resultDir}")
    # print(f"namePattern: {namePattern}")
    # print(f"QSchoice: {QSchoiceList}")
    # print(f"CicuitsLength: {CircuitsLength}")
    # print(f"Circuits: {CircuitList}")
    # print(f"nQLength: {nQLength}")
    # print(f"nQ: {nQList}")
    # print(f"numThreads: {numThreads}")

    for Circchoice in CircuitList:
        mergedName = f"Merged_{namePattern}_{Circchoice}.csv"
        filePath = f"{resultDir}{mergedName}"
        data = [["name"],["Threads"]]
        for QSchoice in QSchoiceList:
            data[0].append(QSchoice)
            data[1].append(numThreads)
            rows = 1
            name = f"{namePattern}_NumThreads_{numThreads}_{Circchoice}_{QSchoice}.csv"
            path = f"{resultDir}{name}"
            # print(f"Reading {name}")
            if os.path.exists(path):
                # Open and read the CSV file
                # print(f"Reading {path}")
                with open(path, mode='r') as file:
                    csv_reader = csv.reader(file)
                    for nQ in nQList:
                        circ = f"{Circchoice}_{nQ:02d}"
                        # data = circ
                        # print(f"Reading {circ}")
                        rows += 1
                        if len(data) < rows+1:
                            data.append([circ])
                        # data[rows] = [circ]
                        for row in csv_reader:
                            # print(row)
                            if row[0] == circ:
                                iter = row[2]  # Get the value in the third column
                                break
                        # else:
                        #     # print("No match found.")
                        #     iter = ""
                        data[rows].append(iter)
                        # print(data[rows])
            else:
                print(f"File '{name}' does not exist.")
                # Create an empty csv_reader
                # csv_reader = iter([])  # Empty iterator
                for nQ in nQList:
                    circ = f"{Circchoice}_{nQ:02d}"
                    rows += 1
                    if len(data) < rows+1:
                        data.append([circ])
                    data[rows].append("")
                    # print(data[rows])
        with open(filePath, 'w') as output:
            writer = csv.writer(output)
            writer.writerows(data)
            # print(data)
            print(f"Created file {mergedName}")
