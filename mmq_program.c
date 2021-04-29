// #region Passos do Metodo dos Minimos Quadrados
/*

- Vai ter só reta ou parabola
- Retas são matrizes 2x2
- Parabolas são Matrizes 3x3 

1)

*/
// #endregion

#include <stdlib.h>
#include <stdio.h>

void main (){
    float matriz[3][3];
    int linha, coluna;

    for(linha=0; linha < 3; linha++){
        for(coluna=0; coluna < 3; coluna++){
            printf("Digite o valor para a linha %i e coluna %i: ",linha, coluna);
            scanf("%f", &matriz[linha][coluna]);
        }
    }

    for(linha=0; linha < 3; linha++){
        for(coluna=0; coluna < 3; coluna++){
            printf("%.1f\t", matriz[linha][coluna]);
        }
        printf("\n");
    }
}