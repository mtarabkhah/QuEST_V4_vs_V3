#include <stdio.h>
#include "QuEST.h"
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
	QuESTEnv env = createQuESTEnv();

	// PREPARE QUBIT SYSTEM
	int numQubits = 20;
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
	controlledPhaseShift(qubits, 10, 0, 0.0030679615757712823);
	controlledPhaseShift(qubits, 11, 0, 0.0015339807878856412);
	controlledPhaseShift(qubits, 12, 0, 0.0007669903939428206);
	controlledPhaseShift(qubits, 13, 0, 0.0003834951969714103);
	controlledPhaseShift(qubits, 14, 0, 0.00019174759848570515);
	controlledPhaseShift(qubits, 15, 0, 9.587379924285257e-05);
	controlledPhaseShift(qubits, 16, 0, 4.7936899621426287e-05);
	controlledPhaseShift(qubits, 17, 0, 2.3968449810713143e-05);
	controlledPhaseShift(qubits, 18, 0, 1.1984224905356572e-05);
	controlledPhaseShift(qubits, 19, 0, 5.992112452678286e-06);
	hadamard(qubits, 1);
	controlledPhaseShift(qubits, 2, 1, 1.5707963267948966);
	controlledPhaseShift(qubits, 3, 1, 0.7853981633974483);
	controlledPhaseShift(qubits, 4, 1, 0.39269908169872414);
	controlledPhaseShift(qubits, 5, 1, 0.19634954084936207);
	controlledPhaseShift(qubits, 6, 1, 0.09817477042468103);
	controlledPhaseShift(qubits, 7, 1, 0.04908738521234052);
	controlledPhaseShift(qubits, 8, 1, 0.02454369260617026);
	controlledPhaseShift(qubits, 9, 1, 0.01227184630308513);
	controlledPhaseShift(qubits, 10, 1, 0.006135923151542565);
	controlledPhaseShift(qubits, 11, 1, 0.0030679615757712823);
	controlledPhaseShift(qubits, 12, 1, 0.0015339807878856412);
	controlledPhaseShift(qubits, 13, 1, 0.0007669903939428206);
	controlledPhaseShift(qubits, 14, 1, 0.0003834951969714103);
	controlledPhaseShift(qubits, 15, 1, 0.00019174759848570515);
	controlledPhaseShift(qubits, 16, 1, 9.587379924285257e-05);
	controlledPhaseShift(qubits, 17, 1, 4.7936899621426287e-05);
	controlledPhaseShift(qubits, 18, 1, 2.3968449810713143e-05);
	controlledPhaseShift(qubits, 19, 1, 1.1984224905356572e-05);
	hadamard(qubits, 2);
	controlledPhaseShift(qubits, 3, 2, 1.5707963267948966);
	controlledPhaseShift(qubits, 4, 2, 0.7853981633974483);
	controlledPhaseShift(qubits, 5, 2, 0.39269908169872414);
	controlledPhaseShift(qubits, 6, 2, 0.19634954084936207);
	controlledPhaseShift(qubits, 7, 2, 0.09817477042468103);
	controlledPhaseShift(qubits, 8, 2, 0.04908738521234052);
	controlledPhaseShift(qubits, 9, 2, 0.02454369260617026);
	controlledPhaseShift(qubits, 10, 2, 0.01227184630308513);
	controlledPhaseShift(qubits, 11, 2, 0.006135923151542565);
	controlledPhaseShift(qubits, 12, 2, 0.0030679615757712823);
	controlledPhaseShift(qubits, 13, 2, 0.0015339807878856412);
	controlledPhaseShift(qubits, 14, 2, 0.0007669903939428206);
	controlledPhaseShift(qubits, 15, 2, 0.0003834951969714103);
	controlledPhaseShift(qubits, 16, 2, 0.00019174759848570515);
	controlledPhaseShift(qubits, 17, 2, 9.587379924285257e-05);
	controlledPhaseShift(qubits, 18, 2, 4.7936899621426287e-05);
	controlledPhaseShift(qubits, 19, 2, 2.3968449810713143e-05);
	hadamard(qubits, 3);
	controlledPhaseShift(qubits, 4, 3, 1.5707963267948966);
	controlledPhaseShift(qubits, 5, 3, 0.7853981633974483);
	controlledPhaseShift(qubits, 6, 3, 0.39269908169872414);
	controlledPhaseShift(qubits, 7, 3, 0.19634954084936207);
	controlledPhaseShift(qubits, 8, 3, 0.09817477042468103);
	controlledPhaseShift(qubits, 9, 3, 0.04908738521234052);
	controlledPhaseShift(qubits, 10, 3, 0.02454369260617026);
	controlledPhaseShift(qubits, 11, 3, 0.01227184630308513);
	controlledPhaseShift(qubits, 12, 3, 0.006135923151542565);
	controlledPhaseShift(qubits, 13, 3, 0.0030679615757712823);
	controlledPhaseShift(qubits, 14, 3, 0.0015339807878856412);
	controlledPhaseShift(qubits, 15, 3, 0.0007669903939428206);
	controlledPhaseShift(qubits, 16, 3, 0.0003834951969714103);
	controlledPhaseShift(qubits, 17, 3, 0.00019174759848570515);
	controlledPhaseShift(qubits, 18, 3, 9.587379924285257e-05);
	controlledPhaseShift(qubits, 19, 3, 4.7936899621426287e-05);
	hadamard(qubits, 4);
	controlledPhaseShift(qubits, 5, 4, 1.5707963267948966);
	controlledPhaseShift(qubits, 6, 4, 0.7853981633974483);
	controlledPhaseShift(qubits, 7, 4, 0.39269908169872414);
	controlledPhaseShift(qubits, 8, 4, 0.19634954084936207);
	controlledPhaseShift(qubits, 9, 4, 0.09817477042468103);
	controlledPhaseShift(qubits, 10, 4, 0.04908738521234052);
	controlledPhaseShift(qubits, 11, 4, 0.02454369260617026);
	controlledPhaseShift(qubits, 12, 4, 0.01227184630308513);
	controlledPhaseShift(qubits, 13, 4, 0.006135923151542565);
	controlledPhaseShift(qubits, 14, 4, 0.0030679615757712823);
	controlledPhaseShift(qubits, 15, 4, 0.0015339807878856412);
	controlledPhaseShift(qubits, 16, 4, 0.0007669903939428206);
	controlledPhaseShift(qubits, 17, 4, 0.0003834951969714103);
	controlledPhaseShift(qubits, 18, 4, 0.00019174759848570515);
	controlledPhaseShift(qubits, 19, 4, 9.587379924285257e-05);
	hadamard(qubits, 5);
	controlledPhaseShift(qubits, 6, 5, 1.5707963267948966);
	controlledPhaseShift(qubits, 7, 5, 0.7853981633974483);
	controlledPhaseShift(qubits, 8, 5, 0.39269908169872414);
	controlledPhaseShift(qubits, 9, 5, 0.19634954084936207);
	controlledPhaseShift(qubits, 10, 5, 0.09817477042468103);
	controlledPhaseShift(qubits, 11, 5, 0.04908738521234052);
	controlledPhaseShift(qubits, 12, 5, 0.02454369260617026);
	controlledPhaseShift(qubits, 13, 5, 0.01227184630308513);
	controlledPhaseShift(qubits, 14, 5, 0.006135923151542565);
	controlledPhaseShift(qubits, 15, 5, 0.0030679615757712823);
	controlledPhaseShift(qubits, 16, 5, 0.0015339807878856412);
	controlledPhaseShift(qubits, 17, 5, 0.0007669903939428206);
	controlledPhaseShift(qubits, 18, 5, 0.0003834951969714103);
	controlledPhaseShift(qubits, 19, 5, 0.00019174759848570515);
	hadamard(qubits, 6);
	controlledPhaseShift(qubits, 7, 6, 1.5707963267948966);
	controlledPhaseShift(qubits, 8, 6, 0.7853981633974483);
	controlledPhaseShift(qubits, 9, 6, 0.39269908169872414);
	controlledPhaseShift(qubits, 10, 6, 0.19634954084936207);
	controlledPhaseShift(qubits, 11, 6, 0.09817477042468103);
	controlledPhaseShift(qubits, 12, 6, 0.04908738521234052);
	controlledPhaseShift(qubits, 13, 6, 0.02454369260617026);
	controlledPhaseShift(qubits, 14, 6, 0.01227184630308513);
	controlledPhaseShift(qubits, 15, 6, 0.006135923151542565);
	controlledPhaseShift(qubits, 16, 6, 0.0030679615757712823);
	controlledPhaseShift(qubits, 17, 6, 0.0015339807878856412);
	controlledPhaseShift(qubits, 18, 6, 0.0007669903939428206);
	controlledPhaseShift(qubits, 19, 6, 0.0003834951969714103);
	hadamard(qubits, 7);
	controlledPhaseShift(qubits, 8, 7, 1.5707963267948966);
	controlledPhaseShift(qubits, 9, 7, 0.7853981633974483);
	controlledPhaseShift(qubits, 10, 7, 0.39269908169872414);
	controlledPhaseShift(qubits, 11, 7, 0.19634954084936207);
	controlledPhaseShift(qubits, 12, 7, 0.09817477042468103);
	controlledPhaseShift(qubits, 13, 7, 0.04908738521234052);
	controlledPhaseShift(qubits, 14, 7, 0.02454369260617026);
	controlledPhaseShift(qubits, 15, 7, 0.01227184630308513);
	controlledPhaseShift(qubits, 16, 7, 0.006135923151542565);
	controlledPhaseShift(qubits, 17, 7, 0.0030679615757712823);
	controlledPhaseShift(qubits, 18, 7, 0.0015339807878856412);
	controlledPhaseShift(qubits, 19, 7, 0.0007669903939428206);
	hadamard(qubits, 8);
	controlledPhaseShift(qubits, 9, 8, 1.5707963267948966);
	controlledPhaseShift(qubits, 10, 8, 0.7853981633974483);
	controlledPhaseShift(qubits, 11, 8, 0.39269908169872414);
	controlledPhaseShift(qubits, 12, 8, 0.19634954084936207);
	controlledPhaseShift(qubits, 13, 8, 0.09817477042468103);
	controlledPhaseShift(qubits, 14, 8, 0.04908738521234052);
	controlledPhaseShift(qubits, 15, 8, 0.02454369260617026);
	controlledPhaseShift(qubits, 16, 8, 0.01227184630308513);
	controlledPhaseShift(qubits, 17, 8, 0.006135923151542565);
	controlledPhaseShift(qubits, 18, 8, 0.0030679615757712823);
	controlledPhaseShift(qubits, 19, 8, 0.0015339807878856412);
	hadamard(qubits, 9);
	controlledPhaseShift(qubits, 10, 9, 1.5707963267948966);
	controlledPhaseShift(qubits, 11, 9, 0.7853981633974483);
	controlledPhaseShift(qubits, 12, 9, 0.39269908169872414);
	controlledPhaseShift(qubits, 13, 9, 0.19634954084936207);
	controlledPhaseShift(qubits, 14, 9, 0.09817477042468103);
	controlledPhaseShift(qubits, 15, 9, 0.04908738521234052);
	controlledPhaseShift(qubits, 16, 9, 0.02454369260617026);
	controlledPhaseShift(qubits, 17, 9, 0.01227184630308513);
	controlledPhaseShift(qubits, 18, 9, 0.006135923151542565);
	controlledPhaseShift(qubits, 19, 9, 0.0030679615757712823);
	hadamard(qubits, 10);
	controlledPhaseShift(qubits, 11, 10, 1.5707963267948966);
	controlledPhaseShift(qubits, 12, 10, 0.7853981633974483);
	controlledPhaseShift(qubits, 13, 10, 0.39269908169872414);
	controlledPhaseShift(qubits, 14, 10, 0.19634954084936207);
	controlledPhaseShift(qubits, 15, 10, 0.09817477042468103);
	controlledPhaseShift(qubits, 16, 10, 0.04908738521234052);
	controlledPhaseShift(qubits, 17, 10, 0.02454369260617026);
	controlledPhaseShift(qubits, 18, 10, 0.01227184630308513);
	controlledPhaseShift(qubits, 19, 10, 0.006135923151542565);
	hadamard(qubits, 11);
	controlledPhaseShift(qubits, 12, 11, 1.5707963267948966);
	controlledPhaseShift(qubits, 13, 11, 0.7853981633974483);
	controlledPhaseShift(qubits, 14, 11, 0.39269908169872414);
	controlledPhaseShift(qubits, 15, 11, 0.19634954084936207);
	controlledPhaseShift(qubits, 16, 11, 0.09817477042468103);
	controlledPhaseShift(qubits, 17, 11, 0.04908738521234052);
	controlledPhaseShift(qubits, 18, 11, 0.02454369260617026);
	controlledPhaseShift(qubits, 19, 11, 0.01227184630308513);
	hadamard(qubits, 12);
	controlledPhaseShift(qubits, 13, 12, 1.5707963267948966);
	controlledPhaseShift(qubits, 14, 12, 0.7853981633974483);
	controlledPhaseShift(qubits, 15, 12, 0.39269908169872414);
	controlledPhaseShift(qubits, 16, 12, 0.19634954084936207);
	controlledPhaseShift(qubits, 17, 12, 0.09817477042468103);
	controlledPhaseShift(qubits, 18, 12, 0.04908738521234052);
	controlledPhaseShift(qubits, 19, 12, 0.02454369260617026);
	hadamard(qubits, 13);
	controlledPhaseShift(qubits, 14, 13, 1.5707963267948966);
	controlledPhaseShift(qubits, 15, 13, 0.7853981633974483);
	controlledPhaseShift(qubits, 16, 13, 0.39269908169872414);
	controlledPhaseShift(qubits, 17, 13, 0.19634954084936207);
	controlledPhaseShift(qubits, 18, 13, 0.09817477042468103);
	controlledPhaseShift(qubits, 19, 13, 0.04908738521234052);
	hadamard(qubits, 14);
	controlledPhaseShift(qubits, 15, 14, 1.5707963267948966);
	controlledPhaseShift(qubits, 16, 14, 0.7853981633974483);
	controlledPhaseShift(qubits, 17, 14, 0.39269908169872414);
	controlledPhaseShift(qubits, 18, 14, 0.19634954084936207);
	controlledPhaseShift(qubits, 19, 14, 0.09817477042468103);
	hadamard(qubits, 15);
	controlledPhaseShift(qubits, 16, 15, 1.5707963267948966);
	controlledPhaseShift(qubits, 17, 15, 0.7853981633974483);
	controlledPhaseShift(qubits, 18, 15, 0.39269908169872414);
	controlledPhaseShift(qubits, 19, 15, 0.19634954084936207);
	hadamard(qubits, 16);
	controlledPhaseShift(qubits, 17, 16, 1.5707963267948966);
	controlledPhaseShift(qubits, 18, 16, 0.7853981633974483);
	controlledPhaseShift(qubits, 19, 16, 0.39269908169872414);
	hadamard(qubits, 17);
	controlledPhaseShift(qubits, 18, 17, 1.5707963267948966);
	controlledPhaseShift(qubits, 19, 17, 0.7853981633974483);
	hadamard(qubits, 18);
	controlledPhaseShift(qubits, 19, 18, 1.5707963267948966);
	hadamard(qubits, 19);


	clock_gettime(CLOCK_MONOTONIC, &finish);

	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
	// STUDY QUANTUM STATE        
	// print_stateVec(qubits, "Circuit");

	char dynamicFileName[] = "_QC_QFT_20_QuEST_V3.csv";
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