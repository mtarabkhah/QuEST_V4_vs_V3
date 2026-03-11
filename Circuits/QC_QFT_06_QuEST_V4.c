#include <stdio.h>
#include "quest.h"
#include "myFunctions.c"
#include <time.h>

int main (int narg, char *varg[]) {

	char timeFullPath[256], resultFullPath[256];
	const char *timePath;
	const char *resultPath;
	const char *numThreads;
	if (narg != 4) {
		timePath = "/home/meisam/Workspace/miniquest/LFQS/Results/csvFiles/";
		resultPath = "/home/meisam/Workspace/miniquest/LFQS/Results/CompareCSVFiles/csvFiles/";
		numThreads = "0";
	}
	else {
		timePath = varg[1];
		resultPath = varg[2];
		numThreads = varg[3];
	}

	struct timespec start, finish;
	qreal elapsed;

	// PREPARE QuEST environment
	initQuESTEnv();

	// PREPARE QUBIT SYSTEM
	int numQubits = 6;
	if (numQubits < 4)
		reportQuESTEnv();
	Qureg qubits = createQureg(numQubits);
	initZeroState(qubits);

	//APPLY CIRCUIT
	clock_gettime(CLOCK_MONOTONIC, &start);

	applyHadamard(qubits, 0);
	applyTwoQubitPhaseShift(qubits, 1, 0, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 2, 0, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 3, 0, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 4, 0, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 5, 0, 0.09817477042468103);
	applyHadamard(qubits, 1);
	applyTwoQubitPhaseShift(qubits, 2, 1, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 3, 1, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 4, 1, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 5, 1, 0.19634954084936207);
	applyHadamard(qubits, 2);
	applyTwoQubitPhaseShift(qubits, 3, 2, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 4, 2, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 5, 2, 0.39269908169872414);
	applyHadamard(qubits, 3);
	applyTwoQubitPhaseShift(qubits, 4, 3, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 5, 3, 0.7853981633974483);
	applyHadamard(qubits, 4);
	applyTwoQubitPhaseShift(qubits, 5, 4, 1.5707963267948966);
	applyHadamard(qubits, 5);


	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
	// STUDY QUANTUM STATE        
	// print_stateVec(qubits, "Circuit");

	char dynamicFileName[] = "_QC_QFT_06_QuEST_V4.csv";
	snprintf(timeFullPath, sizeof(timeFullPath), "%s%s%s%s", timePath, "RunTime_NumThreads_", numThreads, dynamicFileName);
	snprintf(resultFullPath, sizeof(resultFullPath), "%s%s%s", resultPath, "Results", dynamicFileName);
	
	writeDataToFile(elapsed, timeFullPath, "Simulation Time");
	if (numQubits < 16)
		print_stateVec_to_file(qubits, resultFullPath);


	// FREE MEMORY
	destroyQureg(qubits); 

	// CLOSE QUEST ENVIRONMET
	finalizeQuESTEnv();
	return 0;
}