#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <math.h>

double Q = 0.000001;
double R = 0.01;
double P = 1, X = 0, K;
int result;

void measurementUpdate(){
	
 	K = (P + Q) / (P + Q + R);
 	P = R * (P + Q) / (R + P + Q);
}


double update(double measurement){
	
	 measurementUpdate();
 	double result = X + (measurement - X) * K;
 	X = result;
 	return result;
}

int main(int argc, char *argv[]) {

char filename[30],file_out[30];
   if (argc != 3)
   { 
      printf("Comando inválido\n");
      return 1;   
   }
    strcpy(filename, argv[1]);
    strcat (filename, ".txt");

    FILE *myFile;
    myFile = fopen(filename, "r");

    strcpy(file_out, argv[2]);
    strcat (file_out, ".txt");

    FILE *myFileOut;
    myFileOut = fopen(file_out, "w");

    float data[800];
    int i;

    if (myFile == NULL)
    {
        printf("error\n");
        exit(0);
    }

    for (i = 0; i < 800; i++)
    {
        fscanf(myFile, "%f,", &data[i] );

    }

    fclose(myFile);

    for (i = 0; i < 800; i++){
	result = rint(update(data[i]));
	fprintf(myFileOut, "%d\n", result); //result 
    }
//	fclose(file_out);
	return 0;
}
