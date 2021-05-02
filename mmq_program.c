/* 
Passos do Metodo dos Minimos Quadrados

1) Recebimento dos dados da tabela

2) Implementacao do Metodo dos Minimos Quadrados, com opcao de reta ou parabola
  2.1) Calcular vetores e exibi-los (y, u0, u1...)
  2.2) Calcular e exibir o sistema escalar resultante
  2.3) Calcular e exibir o sistema resultante da Eliminacao de Gauss

3) Exibir o polinomio p(x) obtido atraves do sistema equivalente (Eliminacao de Gauss)
*/


/* 
- Vai ter só reta ou parabola
- Retas são matrizes 2x3 (linha e coluna)
- Parabolas são Matrizes 3x4 (linha e coluna)

- O vetor u0 é tudo 1 
- O vetor u1 é o proprio X
*/

#include<stdio.h>
#include<stdlib.h>

//Prototipos de funcoes gerais
void alocaInt(int **p, int tam);
void alocaFloat(float **p, int tam);
void recebeQtdNumerosTabela(int *num);
void receberTermos(int *num, float *x, float *y);
void mostrarMatriz(float *matriz, int quantidadeDeLinhas, int quantidadeDeColunas);

//Prototipos de funcoes para ajustes de reta
void aplicarMetodoReta(int *quantidadeTermos, float *y, float *x);
void calculaMostraVetoresReta(int *quantidadeTermos, float *y, float *x, float *u0, float *u1);
void calculaMostraSistemaEscalarReta(int *quantidadeTermos, float *y, float *u0, float *u1, float *sistemaMatriz);

//Prototipos de funcoes para ajuste de parabola
void calculaMostraVetoresParabola(int *quantidadeTermos, float *y, float *x, float *u0, float *u1, float *u2);

int main() {
  float *x = NULL, *y = NULL;
  int *quantidadeTermos = NULL, opc;

  alocaInt(&quantidadeTermos, 1);
  recebeQtdNumerosTabela(quantidadeTermos);

  alocaFloat(&x,*quantidadeTermos);
  alocaFloat(&y,*quantidadeTermos);

  receberTermos(quantidadeTermos, x, y);

  do{
    printf("\nEscolha: [1] Reta\t[2] Parabola: ");
    scanf("%i", &opc);

    switch(opc){
      case 1: 
        aplicarMetodoReta(quantidadeTermos, y, x);
        break;

      case 2:
        //aplicarMetodoParabola();
        break;

      default:
        printf("\nPor favor, tente novamente...\n");
    }

  }while(opc != 1 && opc != 2);

  system("PAUSE");
  return 0;
}

void aplicarMetodoReta(int *quantidadeTermos, float *y, float *x){
  float *sistemaMatriz=NULL,*u0=NULL, *u1=NULL;
  float *coeficienteA0 = NULL, *coeficienteA1 = NULL;

  alocaFloat(&sistemaMatriz,6);
  alocaFloat(&u0, *quantidadeTermos);
  alocaFloat(&u1, *quantidadeTermos);
  alocaFloat(&coeficienteA0, 1);
  alocaFloat(&coeficienteA1, 1);

  calculaMostraVetoresReta(quantidadeTermos, y, x, u0, u1);
  calculaMostraSistemaEscalarReta(quantidadeTermos, y, u0, u1, sistemaMatriz);
  calculaMostraSistemaGauss(sistemaMatriz, coeficienteA0, coeficienteA1);

  if(*coeficienteA1 > 0){
    printf("\nA reta que possui o melhor ajuste da funcao tabelada: p(x) = %.3f + %.3fx\n", *coeficienteA0, *coeficienteA1);
  }else if(*coeficienteA1 < 0){
    printf("\nA reta que possui o melhor ajuste da funcao tabelada: p(x) = %.3f - %.3fx\n", *coeficienteA0, *coeficienteA1);
  }else{
    printf("\nA reta que possui o melhor ajuste da funcao tabelada: p(x) = %.3f\n", *coeficienteA0);
  }
  
}

void calculaMostraSistemaGauss(float *sistemaMatriz, float *coeficienteA0, float *coeficienteA1){
  int contador;
  float auxiliar;
  float multiplicador = *(sistemaMatriz+(1*3+0)) / *(sistemaMatriz+(0*3+0));

  //Linha2 = Linha2 - Linha1 * multiplicador
  for(contador=0; contador < 3; contador++){
    auxiliar = *(sistemaMatriz+(0*3+contador)) * multiplicador;
    *(sistemaMatriz+(1*3+contador)) -= auxiliar;
  }

  *coeficienteA1 = *(sistemaMatriz+(1*3+2)) / *(sistemaMatriz+(1*3+1));

  auxiliar = *(sistemaMatriz+(0*3+1)) * *coeficienteA1;

  if(auxiliar > 0){
    auxiliar = *(sistemaMatriz+(0*3+2)) - auxiliar;
  }else{
    auxiliar = *(sistemaMatriz+(0*3+2)) + auxiliar;
  }

  *coeficienteA0 = auxiliar / *(sistemaMatriz+(0*3+0));
}

void calculaMostraSistemaEscalarReta(int *quantidadeTermos, float *y, float *u0, float *u1, float *sistemaMatriz){
  int linha, coluna, contador;
  float resultado=0;

  //Realiza os calculos do sistema escalar
  for(linha=0; linha < 2; linha++){

    for(coluna=0; coluna < 3; coluna++){

      *(sistemaMatriz+(linha*3+coluna)) = 0;

      for(contador=0; contador < *quantidadeTermos; contador++){

        //Seleciona o vetor, de acordo com a coluna
        if(coluna == 0){
          resultado =  *(u0+contador);
        }else if(coluna == 1){
          resultado =  *(u1+contador);
        }else{
          resultado =  *(y+contador);
        }

        //Seleciona o outro vetor de acordo com a linha
        if(linha == 0){
          resultado *= *(u0+contador);
        }else{
          resultado *= *(u1+contador);
        }

        //A posicao ira receber o resultado
        *(sistemaMatriz+(linha*3+coluna)) += resultado;  
      }

    }
  }

  printf("\n--- Sistema Escalar ---\n");
  mostrarMatriz(sistemaMatriz, 2, 3);
}

void mostrarMatriz(float *matriz, int quantidadeDeLinhas, int quantidadeDeColunas){
  int linha, coluna;

  for(linha=0; linha < quantidadeDeLinhas; linha++){  

    for(coluna=0; coluna < quantidadeDeColunas; coluna++){    
      printf("%.2f \t", *(matriz+linha*quantidadeDeColunas+coluna));  
    }   

    printf("\n");
  }
}

void calculaMostraVetoresReta(int *quantidadeTermos, float *y, float *x, float *u0, float *u1){
  int contador;

  //Construindo o vetor u0
  for(contador=0; contador < *quantidadeTermos; contador++){
    *(u0+contador) = 1;
  }

  //Construindo o vetor u1
  for(contador=0; contador < *quantidadeTermos; contador++){
    *(u1+contador) = *(x+contador);
  }

  printf("\n--- Vetores ---\n");
  printf("y\tu0\tu1\n");
  for(contador=0; contador < *quantidadeTermos; contador++){
    printf("%.2f\t%.2f\t%.2f\n", *(y+contador), *(u0+contador), *(u1+contador));
  }
}

void calculaMostraVetoresParabola(int *quantidadeTermos, float *y, float *x, float *u0, float *u1, float *u2){
  int contador;

  for(contador=0; contador < *quantidadeTermos; contador++){
    *(u0+contador) = 1;
  }

  for(contador=0; contador < *quantidadeTermos; contador++){
    *(u1+contador) = *(x+contador);
  }
  
  for(contador=0; contador < *quantidadeTermos; contador++){
    *(u2+contador) = *(x+contador) * *(x+contador);
  }

  printf("\n--- Vetores ---\n");
  printf("y\tu0\tu1\tu2\n");
  for(contador=0; contador < *quantidadeTermos; contador++){
    printf("%.2f\t%.2f\t%.2f\t%.2f\n", *(y+contador), *(u0+contador), *(u1+contador), *(u2+contador));
  }
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