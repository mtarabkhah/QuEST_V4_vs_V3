import csv
import math
import os
import sys
import re

def compare_csv_files(file1, file2, tolerance=1e-6):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        reader1 = csv.reader(f1)
        reader2 = csv.reader(f2)

        # Assuming the first row contains headers, read and compare them.
        headers1 = next(reader1)
        headers2 = next(reader2)

        if headers1 != headers2:
            print("Headers are different. Files are not comparable.")
            return

        # Compare data line by line.
        flag = True
        line_number = 1
        for row1, row2 in zip(reader1, reader2):
            differences = [abs(float(x) - float(y)) > tolerance for x, y in zip(row1, row2)]

            if any(differences):
                # print(f"Difference in state {line_number}:\nFile 1: {row1}\nFile 2: {row2}")
                flag = False

            line_number += 1
    # if flag:
    #     print("Results are the same")
    return flag


if __name__ == "__main__":
    print("Comparing Final StateVectors...")
    # "$resultsDir" "$tolerance" ${#QSchoice[@]} "${QSchoice[@]}" "${#Circchoice[@]}" "${Circchoice[@]}" "${#nQ[@]}" "${nQ[@]}" "${#nL[@]}" "${nL[@]}"
    resultDir = sys.argv[1]
    tolerance = float(sys.argv[2])
    QSchoiceLength = int(sys.argv[3])
    QSchoiceList = sys.argv[4:4+QSchoiceLength]
    CircuitsLength = int(sys.argv[4+QSchoiceLength])
    CircuitList = sys.argv[5+QSchoiceLength:5+QSchoiceLength+CircuitsLength]
    nQLength = int(sys.argv[5+QSchoiceLength+CircuitsLength])
    nQList = [int(x) for x in sys.argv[6+QSchoiceLength+CircuitsLength:6+QSchoiceLength+CircuitsLength+nQLength]]
    namePattern = sys.argv[6+QSchoiceLength+CircuitsLength+nQLength]
    
    # print(f"resultDir: {resultDir}")
    # print(f"tolerance: {tolerance}")
    # print(f"Circuits: {CircuitList}")
    # print(f"nQLength: {nQLength}")
    # print(f"nQ: {nQList}")
    # print(f"nL: {nLList}")
    
    flag = True
    
    # Print the list of result names
    with open("./Results/CompareStateVecs.txt", 'a') as output:
        for nQ in nQList:
            for Circchoice in CircuitList:
                firstname = ""
                firstPath = ""
                for QSchoice in QSchoiceList:
                    name = f"Results_QC_{Circchoice}_{nQ:02d}_{QSchoice}.csv"
                    filePath = f"{resultDir}{name}"
                    if os.path.isfile(filePath):
                        if firstname == "":
                            firstname = name
                            firstPath = filePath
                        else:
                            output.write(f"comparing files {firstname} and {name}\n")
                            if not compare_csv_files(firstPath,filePath,tolerance):
                                output.write(f"Different results in files {firstname} and {name}\n")
                                flag = False
                            else:
                                output.write("Results are the same\n")
                            output.write("=====\n")
                            
        if flag:
            print("Results are the same")
            output.write("\n===== All results are the same =====\n\n")
        else:
            print("Different results in some files")
            output.write("\n===== Different results in some files =====\n\n")