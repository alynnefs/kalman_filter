#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <math.h>


double Q = 0.0;
double R = 0.2;
double P = 1.0, X = 0.0, K;

//double Q = 0.00001;
//double R = 0.1;
//double P = 1.0, X = 3.0, K;
double result;

void measurementUpdate(){
	
 	K = (P + Q) / (P + Q + R);
 	P = R * (P + Q) / (R + P + Q);
}


double update(double measurement){
	
 	double result = X + (measurement - X) * K;
	measurementUpdate();
 	X = result;
 	return result;
}

int main(int argc, char *argv[]) {

char filename[30];
   if (argc != 3)
   { 
      printf("error\n");
      return 1;   
   }
    strcpy(filename, argv[1]);
    strcat (filename, ".txt");

    FILE *myFile;
    myFile = fopen(filename, "r");

    strcpy(filename, argv[2]);
    strcat (filename, ".txt");

    FILE *out;
    out = fopen(filename, "w");


    float data[800];
    int i;

    if (myFile == NULL)
    {
        printf("error\n");
        exit(0);
    }

    for (i = 0; i < 800; i++)
    {
        fscanf(myFile, "\n %f", &data[i] );

    }

    fclose(myFile);


    for (i = 0; i < 800; i++){
	result = update(data[i]);
	fprintf(out, "%.2f \n", result);
    }

   
  return 0;
}
