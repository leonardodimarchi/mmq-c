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

int main() {
  float *matriz=NULL, *x = NULL, *y = NULL;
  int *quantidadeTermos = NULL;

  alocaInt(&quantidadeTermos, 1);
  recebeQtdNumerosTabela(quantidadeTermos);

  alocaFloat(&x,*quantidadeTermos);
  alocaFloat(&y,*quantidadeTermos);

  receberTermos(quantidadeTermos, x, y);

  system("PAUSE");
  return 0;
}

void receberTermos(int *num, float *x, float *y){
	int contador;

	printf("\n--- Digite os valores ---\n");

	for(contador=0; contador<(*num); contador++){
		printf("x[%d] = ",contador);
		scanf("%f",x+contador);
	}

  for(contador=0; contador<(*num); contador++){
    printf("y[%d] = ",contador);
		scanf("%f",y+contador);
	}

}

void recebeQtdNumerosTabela(int *num){
	printf("\nQuantidade de termos da tabela: ");
	scanf("%d",num);
}

void alocaFloat(float **p, int tam){
  if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL){
    printf("\nFalha na alocacao dinamica !(float)\n");
    exit(1);
  }
}

void alocaInt(int **p, int tam){
  if((*p=(int*)realloc(*p,tam*sizeof(int)))==NULL){
    printf("\nFalha na alocacao dinamica ! (int)\n");
    exit(1);
  }
}