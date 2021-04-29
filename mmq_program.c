// #region Passos do Metodo dos Minimos Quadrados
/*

- Vai ter só reta ou parabola
- Retas são matrizes 2x2
- Parabolas são Matrizes 3x3 

1)

*/
// #endregion

// #include <stdlib.h>
// #include <stdio.h>

// void main (){
//     float matriz[3][3];
//     int linha, coluna;

//     for(linha=0; linha < 3; linha++){
//         for(coluna=0; coluna < 3; coluna++){
//             printf("Digite o valor para a linha %i e coluna %i: ",linha, coluna);
//             scanf("%f", &matriz[linha][coluna]);
//         }
//     }

//     for(linha=0; linha < 3; linha++){
//         for(coluna=0; coluna < 3; coluna++){
//             printf("%.1f\t", matriz[linha][coluna]);
//         }
//         printf("\n");
//     }
// }

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void alocaFloat(float **p, int tam);
void qtdNumerosTabela(int *num);
void receberTermos(int *num, float *x, float *y);

void main (  ) {
  float *matriz=NULL;
  int *linha=NULL, *coluna=NULL;
  system("pause");
}

void receberTermos(int *num, float *x, float *y){
	int f;
	printf("\nEnter data:\n");
	for(f=0; f<(*num); f++){
		printf("x[%d] = ",f);
		scanf("%f",x+f);

		printf("y[%d] = ",f);
		scanf("%f",y+f);
	}
}

void qtdNumerosTabela(int *num){
	printf("\nEnter number of data: ");
	scanf("%d",num);
}

void alocaFloat(float **p, int tam){
  if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL){
    printf("\nDynamic Allocation Error! (float)\n");
    exit(1);
  }
}

void alocaInt(int **p, int tam){
  if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL){
    printf("\nDynamic Allocation Error! (int)\n");
    exit(1);
  }
}