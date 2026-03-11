#include <stdio.h>
#include "quest.h"
#include <stdlib.h>
#include <math.h>

void print_stateVec_to_file(Qureg qubits, char *output_file) {

    // // Copy data from GPU to CPU
    // copyStateFromGPU(qubits);
    // should use an array called Amps and set it to gpuApms or cpuAmps based on the backend
    
    // Open the CSV file for writing.
    FILE *csvFile = fopen(output_file, "w");

    if (!csvFile) {
        fprintf(stderr, "Failed to open CSV file for writing\n");
        return;
    }

    // Define the header names.
    const char *headers[] = {"State", "Real", "Imag"};

    // Write the headers to the CSV file.
    for (int col = 0; col < 3; col++) {
        fprintf(csvFile, "%s", headers[col]);
        if (col < 2) {
            fprintf(csvFile, ",");
        }
    }
    fprintf(csvFile, "\n");

    // Write the data to the CSV file.
    // for (int i=0;i<(int) pow(2,qubits.numQubits); i++)
    for (int i=0;i<(int) qubits.numAmps; i++)
        // fprintf(csvFile, "%d,%f,%f\n",i, *(qubits.cpuAmps.real+i), *(qubits.cpuAmps.imag+i));
        fprintf(csvFile, "%d,%f,%f\n",i, creal(*(qubits.cpuAmps+i)), cimag(*(qubits.cpuAmps+i)));

    // Close the CSV file.
    fclose(csvFile);
    printf("Results saved to %s\n",output_file);
}

void print_stateVec(Qureg qubits, char txt[]){
    printf("stateVec after %s:\n",txt);
    // for (int i=0;i<(int) pow(2,qubits.numQubits); i++)
    for (int i=0;i<(int) qubits.numAmps; i++)
        // printf("stateVec %d : real = %6.3f, imag = %6.3f\n", i, *(qubits.cpuAmps.real+i), *(qubits.cpuAmps.imag+i));
        printf("stateVec %d : real = %6.3f, imag = %6.3f\n", i, creal(*(qubits.cpuAmps+i)), cimag(*(qubits.cpuAmps+i)));
}

void writeDataToFile(qreal data, const char *file_path, const char *header) {
    FILE *csv_file;

    // Check if the file already exists
    int file_exists = 0;
    if ((csv_file = fopen(file_path, "r")) != NULL) {
        file_exists = 1;
        fclose(csv_file);
    }

    // Open the CSV file in append mode if it exists, otherwise create a new file
    if ((csv_file = fopen(file_path, file_exists ? "a" : "w")) == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // If the file is newly created, write the header
    if (!file_exists) {
        fprintf(csv_file, "%s\n", header);  // header
    }

    // Write the data
    fprintf(csv_file, "%.9f\n", data);  // Replace %f with the actual data format

    // Close the file
    fclose(csv_file);
}

CompMatr1 uSW(){
    return getInlineCompMatr1({{.707107,-.5-0.5i},{.5-0.5i,.707107}});
}

// CompMatr1 uX = {
//     .real={{0,1},{1,0}},
//     .imag={{0,0},{0,0}}};

// CompMatr1 uH = {
//     .real={{1,1},{1,-1}},
//     .imag={{0,0},{0,0}}};

// CompMatr1 uT = {
//     .real={{1,0},{0,.707107}},
//     .imag={{0,0},{0,.707107}}};

CompMatr1 uSY() {
    return getInlineCompMatr1({{.5+0.5i,-.5-0.5i},{.5+0.5i,.5+0.5i}});
}

CompMatr1 uSX() {
    return getInlineCompMatr1({{.5+0.5i,.5-0.5i},{.5-0.5i,.5+0.5i}});
}

CompMatr2 uFSim(qreal theta, qreal phi) {
    qreal a,b, cr, ci;
    a = cos(theta);
	b = -sin(theta);
	cr = cos(phi);
	ci = -sin(phi);
	return getInlineCompMatr2({{1,0,0,0},{0,a,b*1i,0},{0,b*1i,a,0},{0,0,0,cr+ci*1i}});
}

// CompMatr2 uU1(qreal theta, qreal phi) {
//     qreal a,b, c, d;
//     CompMatr2 u;
//     a = cos(theta);
// 	b = sin(theta);
// 	c = cos(phi);
// 	d = sin(phi);
// 	u = (CompMatr2){
// 		.real={{1,0,0,0},{0,a,c*b,0},{0,c*b,-a,0},{0,0,0,1}},
// 		.imag={{0,0,0,0},{0,0,d*b,0},{0,-d*b,0,0},{0,0,0,0}}};
//     return u;
// }