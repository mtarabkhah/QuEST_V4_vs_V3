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
	int numQubits = 2;
	Qureg qubits = createQureg(numQubits, env);
	initZeroState(qubits);

	//APPLY CIRCUIT
	clock_gettime(CLOCK_MONOTONIC, &start);

	hadamard(qubits, 0);
	controlledPhaseShift(qubits, 1, 0, 1.5707963267948966);
	hadamard(qubits, 1);


	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
	// STUDY QUANTUM STATE        
	// print_stateVec(qubits, "Circuit");

	char dynamicFileName[] = "_QC_QFT_02_QuEST.csv";
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