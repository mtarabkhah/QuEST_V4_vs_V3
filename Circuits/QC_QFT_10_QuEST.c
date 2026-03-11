#include <stdio.h>
#include "QuEST.h"
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
	QuESTEnv env = createQuESTEnv();

	// PREPARE QUBIT SYSTEM
	int numQubits = 10;
	Qureg qubits = createQureg(numQubits, env);
	initZeroState(qubits);

	//APPLY CIRCUIT
	clock_gettime(CLOCK_MONOTONIC, &start);

	hadamard(qubits, 0);
	controlledPhaseShift(qubits, 1, 0, 1.5707963267948966);
	controlledPhaseShift(qubits, 2, 0, 0.7853981633974483);
	controlledPhaseShift(qubits, 3, 0, 0.39269908169872414);
	controlledPhaseShift(qubits, 4, 0, 0.19634954084936207);
	controlledPhaseShift(qubits, 5, 0, 0.09817477042468103);
	controlledPhaseShift(qubits, 6, 0, 0.04908738521234052);
	controlledPhaseShift(qubits, 7, 0, 0.02454369260617026);
	controlledPhaseShift(qubits, 8, 0, 0.01227184630308513);
	controlledPhaseShift(qubits, 9, 0, 0.006135923151542565);
	hadamard(qubits, 1);
	controlledPhaseShift(qubits, 2, 1, 1.5707963267948966);
	controlledPhaseShift(qubits, 3, 1, 0.7853981633974483);
	controlledPhaseShift(qubits, 4, 1, 0.39269908169872414);
	controlledPhaseShift(qubits, 5, 1, 0.19634954084936207);
	controlledPhaseShift(qubits, 6, 1, 0.09817477042468103);
	controlledPhaseShift(qubits, 7, 1, 0.04908738521234052);
	controlledPhaseShift(qubits, 8, 1, 0.02454369260617026);
	controlledPhaseShift(qubits, 9, 1, 0.01227184630308513);
	hadamard(qubits, 2);
	controlledPhaseShift(qubits, 3, 2, 1.5707963267948966);
	controlledPhaseShift(qubits, 4, 2, 0.7853981633974483);
	controlledPhaseShift(qubits, 5, 2, 0.39269908169872414);
	controlledPhaseShift(qubits, 6, 2, 0.19634954084936207);
	controlledPhaseShift(qubits, 7, 2, 0.09817477042468103);
	controlledPhaseShift(qubits, 8, 2, 0.04908738521234052);
	controlledPhaseShift(qubits, 9, 2, 0.02454369260617026);
	hadamard(qubits, 3);
	controlledPhaseShift(qubits, 4, 3, 1.5707963267948966);
	controlledPhaseShift(qubits, 5, 3, 0.7853981633974483);
	controlledPhaseShift(qubits, 6, 3, 0.39269908169872414);
	controlledPhaseShift(qubits, 7, 3, 0.19634954084936207);
	controlledPhaseShift(qubits, 8, 3, 0.09817477042468103);
	controlledPhaseShift(qubits, 9, 3, 0.04908738521234052);
	hadamard(qubits, 4);
	controlledPhaseShift(qubits, 5, 4, 1.5707963267948966);
	controlledPhaseShift(qubits, 6, 4, 0.7853981633974483);
	controlledPhaseShift(qubits, 7, 4, 0.39269908169872414);
	controlledPhaseShift(qubits, 8, 4, 0.19634954084936207);
	controlledPhaseShift(qubits, 9, 4, 0.09817477042468103);
	hadamard(qubits, 5);
	controlledPhaseShift(qubits, 6, 5, 1.5707963267948966);
	controlledPhaseShift(qubits, 7, 5, 0.7853981633974483);
	controlledPhaseShift(qubits, 8, 5, 0.39269908169872414);
	controlledPhaseShift(qubits, 9, 5, 0.19634954084936207);
	hadamard(qubits, 6);
	controlledPhaseShift(qubits, 7, 6, 1.5707963267948966);
	controlledPhaseShift(qubits, 8, 6, 0.7853981633974483);
	controlledPhaseShift(qubits, 9, 6, 0.39269908169872414);
	hadamard(qubits, 7);
	controlledPhaseShift(qubits, 8, 7, 1.5707963267948966);
	controlledPhaseShift(qubits, 9, 7, 0.7853981633974483);
	hadamard(qubits, 8);
	controlledPhaseShift(qubits, 9, 8, 1.5707963267948966);
	hadamard(qubits, 9);


	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
	// STUDY QUANTUM STATE        
	// print_stateVec(qubits, "Circuit");

	char dynamicFileName[] = "_QC_QFT_10_QuEST.csv";
	snprintf(timeFullPath, sizeof(timeFullPath), "%s%s%s%s", timePath, "RunTime_NumThreads_", numThreads, dynamicFileName);
	snprintf(resultFullPath, sizeof(resultFullPath), "%s%s%s", resultPath, "Results", dynamicFileName);
	
	writeDataToFile(elapsed, timeFullPath, "Simulation Time");
	if (numQubits < 16)
		print_stateVec_to_file(qubits, resultFullPath);


	// FREE MEMORY
	destroyQureg(qubits, env); 

	// CLOSE QUEST ENVIRONMET
	destroyQuESTEnv(env);
	return 0;
}