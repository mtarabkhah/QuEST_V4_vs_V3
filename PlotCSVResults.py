import sys, os, csv
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.gridspec import GridSpec

legendDict = {"QuEST_V3"   : ["QuEST_V3", "QuEST_V3"],
              "QuEST_V4"   : ["QuEST_V4", "QuEST_V4"],
              "QuEST_V4_func"   : ["QuEST_V4_func", "QuEST_V4_func"],
             }

def plotResults1(fSize, xVals, xTicks, data, legends, colors, linestylesList, markersList, lw, xLabel, yLabel, title, figPath, figName, legloc, bbox=None):
    with open(figPath.replace(".png", ".txt"), "w") as f:
        for i in range(len(data)-1):
            ratios = []
            for j in range(len(data[i])):
                if data[i][j] is not None and data[i][j] != 0 and data[-1][j] is not None:
                    ratios.append(data[-1][j]/data[i][j])
            if len(ratios) > 0:
                ave = sum(ratios)/len(ratios)
                f.write(f"Average speed-up of {legends[-1]} vs {legends[i]}: {ave}\n")
    plt.figure(figsize=fSize)
    plt.rcParams.update({'font.size': 12})
    for i, legend in enumerate(legends):
        plt.plot(xVals, data[i], color=colors[i], linestyle=linestylesList[i], marker=markersList[i], linewidth=lw, label=legend)
    plt.xlabel(xLabel)
    # plt.xticks(xVals)
    plt.xticks(xVals, xTicks)
    plt.ylabel(yLabel)
    plt.yscale("log")
    plt.title(title)
    plt.grid(axis='y', linestyle='--', linewidth=0.5)
    plt.tight_layout()
    plt.legend(loc=legloc, fancybox=True, shadow=False, labels=legends, fontsize='large')
    
    plt.savefig(figPath, dpi=300)
    plt.close()
    print(f"Created plot: {figName}")


    
if __name__ == "__main__":
    print("Plotting results...")
    timeDir = sys.argv[1]
    namePattern = sys.argv[2]
    numThreads = int(sys.argv[3])
    QSchoiceLength = int(sys.argv[4])
    QSchoiceList = sys.argv[5:5+QSchoiceLength]
    CircuitsLength = int(sys.argv[5+QSchoiceLength])
    CircuitList = sys.argv[6+QSchoiceLength:6+QSchoiceLength+CircuitsLength]
    figDir = sys.argv[6+QSchoiceLength+CircuitsLength]
    xValsLength = int(sys.argv[7+QSchoiceLength+CircuitsLength])
    xVals = [int(x) for x in sys.argv[8+QSchoiceLength+CircuitsLength:8+QSchoiceLength+CircuitsLength+xValsLength]]
    xTicks = xVals
    xLabel = "Number of Qubits"
    yLabel = "Iterations per second"
    # title = ""
    colors = ["r", "b"]
    linestylesList = ["-", ":"]
    markersList = ["+", "o"]
    lw = 2
    
    
    # print(f"timeDir: {timeDir}")
    # print(f"namePattern: {namePattern}")
    # print(f"QSchoice: {QSchoiceList}")
    # print(f"Circuits: {CircuitList}")
    # print(f"numThreads: {numThreads}")
    # print(f"figPath: {figDir}")
    # print(f"xLabel: {xLabel}")
    # print(f"yLabel: {yLabel}")
    # print(f"title: {title}")
    # print(f"xVals: {xVals}")
    # print(f"colors: {colors}")
    # print(f"linestylesList: {linestylesList}")
    # print(f"markersList: {markersList}")
    # print(f"lw: {lw}")

    for Circchoice in CircuitList:
        mergedName = f"Merged_{namePattern}_{Circchoice}.csv"
        filePath = f"{timeDir}{mergedName}"
        data = []
        legend = []
        if os.path.exists(filePath):
            # Open and read the CSV file
            with open(filePath, mode='r') as file:
                csv_reader = csv.reader(file)
                # for row in csv_reader:
                
                for row in csv_reader:
                    if row[0] == "name":
                        legends = [legendDict[x][1] for x in row[1:]]
                        data = [[] for _ in range(len(legends))]
                    elif row[0] != "Threads":
                        for i in range(len(legends)):
                            if row[i+1] == "":
                                data[i].append(None)
                            else:
                                data[i].append(float(row[i+1]))
                
                fSize = (8, 3.5)
                figtitle = f"{Circchoice}"
                figPath = f"{figDir}{namePattern}_{Circchoice}.png"
                figName = f"{namePattern}_{Circchoice}.png"
                legloc = 'best'
                plotResults1(fSize, xVals, xTicks, data, legends, colors, linestylesList, markersList, lw, xLabel, yLabel, figtitle, figPath, figName, legloc)
                    