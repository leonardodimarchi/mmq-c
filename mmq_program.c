/* 
  Passos do Metodo dos Minimos Quadrados

  1) Recebimento dos dados da tabela

  2) Implementacao do Metodo dos Minimos Quadrados, com escolhaRetaParabolaao de reta ou parabola
    2.1) Calcular vetores e exibi-los (y, u0, u1...)
    2.2) Calcular e exibir o sistema escalar resultante
    2.3) Calcular e exibir o sistema resultante da Eliminacao de Gauss

  3) Exibir o polinomio p(x) obtido atraves do sistema equivalente (Eliminacao de Gauss)
*/

//Bibliotecas
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
void calculaMostraSistemaGaussReta(float *sistemaMatriz, float *coeficienteA0, float *coeficienteA1);

//Prototipos de funcoes para ajuste de parabola
void aplicarMetodoParabola(int *quantidadeTermos, float *y, float *x);
void calculaMostraVetoresParabola(int *quantidadeTermos, float *y, float *x, float *u0, float *u1, float *u2);
void calculaMostraSistemaEscalarParabola(int *quantidadeTermos, float *y, float *u0, float *u1, float *u2, float *sistemaMatriz);
void calculaMostraSistemaGaussParabola(float *sistemaMatriz, float *coeficienteA0, float *coeficienteA1, float *coeficienteA2);

//Main
int main() {

  //Variaveis
  float *x = NULL, *y = NULL;
  int *quantidadeTermos = NULL, escolhaRetaParabola;
  char escolhaContinuacao;

  alocaInt(&quantidadeTermos, 1);
  
  //Repetição geral para a escolha de inserir uma nova tabela
  do{

    system("cls");

    printf("\n------ Metodo dos Minimos Quadrados ------\n");

    recebeQtdNumerosTabela(quantidadeTermos);
    alocaFloat(&x,*quantidadeTermos);
    alocaFloat(&y,*quantidadeTermos);

    receberTermos(quantidadeTermos, x, y);

    //Escolha de continuacao a partir da mesma tabela
    do{

      //Escolha do tipo de ajuste (reta ou parabola)
      do{

        printf("\nEscolha: [1] Reta\t[2] Parabola: ");
        fflush(stdin);
        scanf("%i", &escolhaRetaParabola);

        switch(escolhaRetaParabola){
          case 1: 
            aplicarMetodoReta(quantidadeTermos, y, x);
            break;

          case 2:
            aplicarMetodoParabola(quantidadeTermos, y, x);
            break;

          default:
            printf("\nPor favor, tente novamente...\n");
        }
      }while(escolhaRetaParabola != 1 && escolhaRetaParabola != 2);

      printf("\nDeseja realizar outro ajuste com a mesma tabela ? [S/n]: ");
      fflush(stdin);
      scanf("%c", &escolhaContinuacao);

    }while(escolhaContinuacao != 'n' && escolhaContinuacao != 'N');
  
    
    printf("\nDeseja inserir outra tabela ? [S/n]: ");
    fflush(stdin);
    scanf("%c", &escolhaContinuacao);

  }while(escolhaContinuacao != 'n' && escolhaContinuacao != 'N');
  
  printf("\n\n------\n\nFeito por:\n\t-> Luiz\n\t-> Leonardo\n\n");

  system("PAUSE");
  return 0;
}

//Funcoes para ajuste de parabola
void aplicarMetodoParabola(int *quantidadeTermos, float *y, float *x){
  float *sistemaMatriz=NULL,*u0=NULL, *u1=NULL, *u2 = NULL;
  float *coeficienteA0 = NULL, *coeficienteA1 = NULL, *coeficienteA2 = NULL;

  alocaFloat(&sistemaMatriz,12);
  alocaFloat(&u0, *quantidadeTermos);
  alocaFloat(&u1, *quantidadeTermos);
  alocaFloat(&u2, *quantidadeTermos);
  alocaFloat(&coeficienteA0, 1);
  alocaFloat(&coeficienteA1, 1);
  alocaFloat(&coeficienteA2, 1);

  calculaMostraVetoresParabola(quantidadeTermos, y, x, u0, u1, u2);
  calculaMostraSistemaEscalarParabola(quantidadeTermos, y, u0, u1, u2, sistemaMatriz);
  calculaMostraSistemaGaussParabola(sistemaMatriz, coeficienteA0, coeficienteA1, coeficienteA2);

  //Resultados
  printf("\nValor de a0: %.3f", *coeficienteA0);
  printf("\nValor de a1: %.3f", *coeficienteA1);
  printf("\nValor de a2: %.3f", *coeficienteA2);

  if(*coeficienteA1 > 0){
    if(*coeficienteA2 > 0){
      printf("\n\nA parabola que possui o melhor ajuste da funcao tabelada: p(x) = %.3f + %.3fx + %.3fx^2\n", *coeficienteA0, *coeficienteA1, *coeficienteA2);
    }else{
      printf("\n\nA parabola que possui o melhor ajuste da funcao tabelada: p(x) = %.3f + %.3fx %.3fx^2\n", *coeficienteA0, *coeficienteA1, *coeficienteA2);
    }
  }else if(*coeficienteA1 < 0){
    if(*coeficienteA2 > 0){
      printf("\n\nA parabola que possui o melhor ajuste da funcao tabelada: p(x) = %.3f %.3fx + %.3fx^2\n", *coeficienteA0, *coeficienteA1, *coeficienteA2);  
    }else{
      printf("\n\nA parabola que possui o melhor ajuste da funcao tabelada: p(x) = %.3f %.3fx %.3fx^2\n", *coeficienteA0, *coeficienteA1, *coeficienteA2);
    }
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

void calculaMostraSistemaEscalarParabola(int *quantidadeTermos, float *y, float *u0, float *u1, float *u2, float *sistemaMatriz){
  int linha, coluna, contador;
  float resultado=0;

  //Realiza os calculos do sistema escalar
  for(linha=0; linha < 3; linha++){

    for(coluna=0; coluna < 4; coluna++){

      *(sistemaMatriz+(linha*4+coluna)) = 0;

      for(contador=0; contador < *quantidadeTermos; contador++){

        //Seleciona o vetor, de acordo com a coluna
        if(coluna == 0){
          resultado =  *(u0+contador);
        }else if(coluna == 1){
          resultado =  *(u1+contador);
        }else if(coluna == 2){
          resultado =  *(u2+contador);
        }else{
          resultado =  *(y+contador);
        }

        //Seleciona o outro vetor de acordo com a linha
        if(linha == 0){
          resultado *= *(u0+contador);
        }else if(linha == 1){
          resultado *= *(u1+contador);
        }else{
          resultado *= *(u2+contador);
        }

        //A posicao ira receber o resultado
        *(sistemaMatriz+(linha*4+coluna)) += resultado;  
      }

    }
  }

  printf("\n--- Sistema Escalar ---\n");
  mostrarMatriz(sistemaMatriz, 3, 4);
}

void calculaMostraSistemaGaussParabola(float *sistemaMatriz, float *coeficienteA0, float *coeficienteA1, float *coeficienteA2){
  int linha, coluna;
  float auxiliar, multiplicador;

  //Passo k=1
  //L2 = L2 - L1 * M21
  //L3 = L3 - L1 * M31
  for(linha=1; linha < 3; linha++){

    multiplicador = *(sistemaMatriz+(linha*4+0)) / *sistemaMatriz;

    for(coluna=0; coluna < 4; coluna++){
      auxiliar = *(sistemaMatriz+(0*4+coluna)) * multiplicador;
      *(sistemaMatriz+(linha*4+coluna)) -= auxiliar;
    }

  }

  //Passo k=2
  multiplicador = *(sistemaMatriz+(2*4+1)) / *(sistemaMatriz+(1*4+1));

  //L3 = L3 - L2 * M32
  for(coluna=1; coluna < 4; coluna++){
    auxiliar = *(sistemaMatriz+(1*4+coluna)) * multiplicador;
    *(sistemaMatriz+(2*4+coluna)) -= auxiliar;
  }

  //Calculo do a2
  *coeficienteA2 = *(sistemaMatriz+(2*4+3)) / *(sistemaMatriz+(2*4+2));

  //Calculo do a1
  auxiliar = *(sistemaMatriz+(1*4+2)) * *coeficienteA2;
  auxiliar = *(sistemaMatriz+(1*4+3)) + -auxiliar;

  *coeficienteA1 = auxiliar / *(sistemaMatriz+(1*4+1));

  //Calculo do a0
  auxiliar = *(sistemaMatriz+(0*4+1)) * *coeficienteA1;
  auxiliar += *(sistemaMatriz+(0*4+2)) * *coeficienteA2;
  auxiliar = *(sistemaMatriz+(0*4+3)) + -auxiliar;

  *coeficienteA0 = auxiliar / *(sistemaMatriz+(0*4+0));

  printf("\n--- Eliminacao de Gauss - Sistema equivalente ---\n");
  mostrarMatriz(sistemaMatriz, 3, 4);
}

//Funcoes para ajuste de reta

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
  calculaMostraSistemaGaussReta(sistemaMatriz, coeficienteA0, coeficienteA1);

  //Resultados
  printf("\nValor de a0: %.3f", *coeficienteA0);
  printf("\nValor de a1: %.3f", *coeficienteA1);

  if(*coeficienteA1 > 0){
    printf("\n\nA reta que possui o melhor ajuste da funcao tabelada: p(x) = %.3f + %.3fx\n", *coeficienteA0, *coeficienteA1);
  }else if(*coeficienteA1 < 0){
    printf("\n\nA reta que possui o melhor ajuste da funcao tabelada: p(x) = %.3f %.3fx\n", *coeficienteA0, *coeficienteA1);
  }else{
    printf("\n\nA reta que possui o melhor ajuste da funcao tabelada: p(x) = %.3f\n", *coeficienteA0);
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

void calculaMostraSistemaGaussReta(float *sistemaMatriz, float *coeficienteA0, float *coeficienteA1){
  int contador;
  float auxiliar;
  float multiplicador = *(sistemaMatriz+(1*3+0)) / *(sistemaMatriz+(0*3+0));

  //Linha2 = Linha2 - Linha1 * multiplicador
  for(contador=0; contador < 3; contador++){
    auxiliar = *(sistemaMatriz+(0*3+contador)) * multiplicador;
    *(sistemaMatriz+(1*3+contador)) -= auxiliar;
  }

  //Calculo do a1
  *coeficienteA1 = *(sistemaMatriz+(1*3+2)) / *(sistemaMatriz+(1*3+1));

  //Calculo do a0
  auxiliar = *(sistemaMatriz+(0*3+1)) * *coeficienteA1;
  auxiliar = *(sistemaMatriz+(0*3+2)) + -auxiliar;

  *coeficienteA0 = auxiliar / *(sistemaMatriz+(0*3+0));

  printf("\n--- Eliminacao de Gauss - Sistema linear equivalente ---\n");
  mostrarMatriz(sistemaMatriz, 2, 3);
}

//Funcoes gerais

void mostrarMatriz(float *matriz, int quantidadeDeLinhas, int quantidadeDeColunas){
  int linha, coluna;

  for(linha=0; linha < quantidadeDeLinhas; linha++){  

    for(coluna=0; coluna < quantidadeDeColunas; coluna++){    
      printf("%.2f \t", *(matriz+linha*quantidadeDeColunas+coluna));  
    }   

    printf("\n");
  }
}

void receberTermos(int *num, float *x, float *y){
	int contador;

	printf("\n--- Digite os valores para X ---\n");

	for(contador=0; contador<(*num); contador++){
		printf("x[%d] = ",contador);
		scanf("%f",x+contador);
	}

  printf("\n--- Digite os valores para Y ---\n");

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