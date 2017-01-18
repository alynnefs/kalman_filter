#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <math.h>


double Q = 0.0; // erro estimado no processo
double R = 0.2; // erro estimado nas medidas
double P = 1.0, X = 0.0, K;
// P: estimativa de covariância inicial, X: estimativa inicial do estado, K: variavel auxiliar
double result;

// atualizacao de medidas com base no filtro de kalman
void measurementUpdate(){
 	K = (P + Q) / (P + Q + R);
 	P = R * (P + Q) / (R + P + Q);
}

// soma com k anterior
double update(double measurement){
	
 	double result = X + (measurement - X) * K;
	measurementUpdate(); //atualizacao de medidas
 	X = result;
 	return result;
}

int main(int argc, char *argv[]) {

    // abrindo arquivos
    char filename[30];
    if (argc != 3)
    { 
        printf("error\n");
        return 1;   
    }
    //arquivo de entrada de dados para calculo
    strcpy(filename, argv[1]);
    strcat (filename, ".txt");

    FILE *myFile;
    myFile = fopen(filename, "r");

    // arquivo para armazenar a saida dos dados
    strcpy(filename, argv[2]);
    strcat (filename, ".txt");

    FILE *out;
    out = fopen(filename, "w");

    // se o arquivo de entrada estiver vazio, apresenta mensagem de erro
    if (myFile == NULL)
    {
        printf("error\n");
        exit(0);
    }

    // declaracao de variaveis
    float data[800];
    int i;


    // lendo valores do arquivo de entrada e armazenando no float data
    for (i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        fscanf(myFile, "\n %f", &data[i]);

    }

    fclose(myFile);


    // gravando valores de saida em um arquivo
    for (i = 0; i < sizeof(data)/sizeof(data[0]); i++){
	result = update(data[i]); // atualizando valores do float data
	fprintf(out, "%.2f \n", result); // armazenando resultados em arquivo com 2 casas decimais
    }

   
  return 0;
}
