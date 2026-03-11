#include <stdio.h>
#include "quest.h"
#include "myFunctions.c"
#include <time.h>

int main (int narg, char *varg[]) {

	char timeFullPath[256], resultFullPath[256];
	const char *timePath;
	const char *resultPath;
	const char *numThreads;
	
	timePath = varg[1];
	resultPath = varg[2];
	numThreads = varg[3];

	struct timespec start, finish;
	qreal elapsed;

	// PREPARE QuEST environment
	initQuESTEnv();

	// PREPARE QUBIT SYSTEM
	int numQubits = 18;
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
	applyTwoQubitPhaseShift(qubits, 6, 0, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 7, 0, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 8, 0, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 9, 0, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 10, 0, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 11, 0, 0.0015339807878856412);
	applyTwoQubitPhaseShift(qubits, 12, 0, 0.0007669903939428206);
	applyTwoQubitPhaseShift(qubits, 13, 0, 0.0003834951969714103);
	applyTwoQubitPhaseShift(qubits, 14, 0, 0.00019174759848570515);
	applyTwoQubitPhaseShift(qubits, 15, 0, 9.587379924285257e-05);
	applyTwoQubitPhaseShift(qubits, 16, 0, 4.7936899621426287e-05);
	applyTwoQubitPhaseShift(qubits, 17, 0, 2.3968449810713143e-05);
	applyHadamard(qubits, 1);
	applyTwoQubitPhaseShift(qubits, 2, 1, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 3, 1, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 4, 1, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 5, 1, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 6, 1, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 7, 1, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 8, 1, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 9, 1, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 10, 1, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 11, 1, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 12, 1, 0.0015339807878856412);
	applyTwoQubitPhaseShift(qubits, 13, 1, 0.0007669903939428206);
	applyTwoQubitPhaseShift(qubits, 14, 1, 0.0003834951969714103);
	applyTwoQubitPhaseShift(qubits, 15, 1, 0.00019174759848570515);
	applyTwoQubitPhaseShift(qubits, 16, 1, 9.587379924285257e-05);
	applyTwoQubitPhaseShift(qubits, 17, 1, 4.7936899621426287e-05);
	applyHadamard(qubits, 2);
	applyTwoQubitPhaseShift(qubits, 3, 2, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 4, 2, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 5, 2, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 6, 2, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 7, 2, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 8, 2, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 9, 2, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 10, 2, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 11, 2, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 12, 2, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 13, 2, 0.0015339807878856412);
	applyTwoQubitPhaseShift(qubits, 14, 2, 0.0007669903939428206);
	applyTwoQubitPhaseShift(qubits, 15, 2, 0.0003834951969714103);
	applyTwoQubitPhaseShift(qubits, 16, 2, 0.00019174759848570515);
	applyTwoQubitPhaseShift(qubits, 17, 2, 9.587379924285257e-05);
	applyHadamard(qubits, 3);
	applyTwoQubitPhaseShift(qubits, 4, 3, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 5, 3, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 6, 3, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 7, 3, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 8, 3, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 9, 3, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 10, 3, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 11, 3, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 12, 3, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 13, 3, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 14, 3, 0.0015339807878856412);
	applyTwoQubitPhaseShift(qubits, 15, 3, 0.0007669903939428206);
	applyTwoQubitPhaseShift(qubits, 16, 3, 0.0003834951969714103);
	applyTwoQubitPhaseShift(qubits, 17, 3, 0.00019174759848570515);
	applyHadamard(qubits, 4);
	applyTwoQubitPhaseShift(qubits, 5, 4, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 6, 4, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 7, 4, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 8, 4, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 9, 4, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 10, 4, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 11, 4, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 12, 4, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 13, 4, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 14, 4, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 15, 4, 0.0015339807878856412);
	applyTwoQubitPhaseShift(qubits, 16, 4, 0.0007669903939428206);
	applyTwoQubitPhaseShift(qubits, 17, 4, 0.0003834951969714103);
	applyHadamard(qubits, 5);
	applyTwoQubitPhaseShift(qubits, 6, 5, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 7, 5, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 8, 5, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 9, 5, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 10, 5, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 11, 5, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 12, 5, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 13, 5, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 14, 5, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 15, 5, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 16, 5, 0.0015339807878856412);
	applyTwoQubitPhaseShift(qubits, 17, 5, 0.0007669903939428206);
	applyHadamard(qubits, 6);
	applyTwoQubitPhaseShift(qubits, 7, 6, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 8, 6, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 9, 6, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 10, 6, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 11, 6, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 12, 6, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 13, 6, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 14, 6, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 15, 6, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 16, 6, 0.0030679615757712823);
	applyTwoQubitPhaseShift(qubits, 17, 6, 0.0015339807878856412);
	applyHadamard(qubits, 7);
	applyTwoQubitPhaseShift(qubits, 8, 7, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 9, 7, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 10, 7, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 11, 7, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 12, 7, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 13, 7, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 14, 7, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 15, 7, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 16, 7, 0.006135923151542565);
	applyTwoQubitPhaseShift(qubits, 17, 7, 0.0030679615757712823);
	applyHadamard(qubits, 8);
	applyTwoQubitPhaseShift(qubits, 9, 8, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 10, 8, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 11, 8, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 12, 8, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 13, 8, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 14, 8, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 15, 8, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 16, 8, 0.01227184630308513);
	applyTwoQubitPhaseShift(qubits, 17, 8, 0.006135923151542565);
	applyHadamard(qubits, 9);
	applyTwoQubitPhaseShift(qubits, 10, 9, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 11, 9, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 12, 9, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 13, 9, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 14, 9, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 15, 9, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 16, 9, 0.02454369260617026);
	applyTwoQubitPhaseShift(qubits, 17, 9, 0.01227184630308513);
	applyHadamard(qubits, 10);
	applyTwoQubitPhaseShift(qubits, 11, 10, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 12, 10, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 13, 10, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 14, 10, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 15, 10, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 16, 10, 0.04908738521234052);
	applyTwoQubitPhaseShift(qubits, 17, 10, 0.02454369260617026);
	applyHadamard(qubits, 11);
	applyTwoQubitPhaseShift(qubits, 12, 11, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 13, 11, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 14, 11, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 15, 11, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 16, 11, 0.09817477042468103);
	applyTwoQubitPhaseShift(qubits, 17, 11, 0.04908738521234052);
	applyHadamard(qubits, 12);
	applyTwoQubitPhaseShift(qubits, 13, 12, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 14, 12, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 15, 12, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 16, 12, 0.19634954084936207);
	applyTwoQubitPhaseShift(qubits, 17, 12, 0.09817477042468103);
	applyHadamard(qubits, 13);
	applyTwoQubitPhaseShift(qubits, 14, 13, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 15, 13, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 16, 13, 0.39269908169872414);
	applyTwoQubitPhaseShift(qubits, 17, 13, 0.19634954084936207);
	applyHadamard(qubits, 14);
	applyTwoQubitPhaseShift(qubits, 15, 14, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 16, 14, 0.7853981633974483);
	applyTwoQubitPhaseShift(qubits, 17, 14, 0.39269908169872414);
	applyHadamard(qubits, 15);
	applyTwoQubitPhaseShift(qubits, 16, 15, 1.5707963267948966);
	applyTwoQubitPhaseShift(qubits, 17, 15, 0.7853981633974483);
	applyHadamard(qubits, 16);
	applyTwoQubitPhaseShift(qubits, 17, 16, 1.5707963267948966);
	applyHadamard(qubits, 17);


	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
	// STUDY QUANTUM STATE        
	// print_stateVec(qubits, "Circuit");

	char dynamicFileName[] = "_QC_QFT_18_QuEST_V4.csv";
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