/* Passos do Metodo dos Minimos Quadrados

1) Recebimento dos dados da tabela

2) Implementacao do Metodo dos Minimos Quadrados, com opcao de reta ou parabola
  2.1) Calcular vetores e exibi-los (y, u0, u1...)
  2.2) Calcular e exibir o sistema escalar resultante
  2.3) Calcular e exibir o sistema resultante da Eliminacao de Gauss

3) Exibir o polinomio p(x) obtido atraves do sistema equivalente (Eliminacao de Gauss)

*/


/*
- Vai ter só reta ou parabola
- Retas são matrizes 2x2
- Parabolas são Matrizes 3x3 

- O vetor u0 é tudo 1 
*/

#include<stdio.h>
#include<stdlib.h>

void alocaInt(int **p, int tam);
void alocaFloat(float **p, int tam);
void qtdNumerosTabela(int *num);
void receberTermos(int *num, float *x, float *y);

int main() {
  float *matriz=NULL, *x = NULL, *y = NULL;
  int *quantidadeTermos = NULL, opc;

  alocaInt(&quantidadeTermos, 1);
  recebeQtdNumerosTabela(quantidadeTermos);

  alocaFloat(&x,*quantidadeTermos);
  alocaFloat(&y,*quantidadeTermos);

  receberTermos(quantidadeTermos, x, y);

  do{
    printf("\nEscolha: [1] Reta\t[2] Parabola\n");
    scanf("%i", &opc);

    switch(opc){
      case 1: 
        //fazer MMQ de reta
        break;
      case 2:
        //fazer MMQ de parabola
        break;
      default:
        printf("\nPor favor, tente novamente...\n");
    }

  }while(opc != 1 && opc != 2);

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