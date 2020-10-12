#include "liblasshard.h"

void gera(void)
{
    int numerosAlea[MAX], i, j, parada, aux;

    srand(time(NULL));

    for(i=0; i<MAX; i++)
    {
        numerosAlea[i] = i+1;
    }
    printf("\n quer sortear um numero entre %d (0|1) ? \n", MAX);
    scanf("%d", &parada);
    printf("\n");

    if(parada==0)
        return; 
    for(i=0; i<MAX; i++)
    {
        j = MAX - (rand() % (MAX - i)) -1;
        aux = numerosAlea[j];
        numerosAlea[j] = numerosAlea[i];
        numerosAlea[i] = aux;
        printf("Numero aleatorio: %d\n\n", numerosAlea[i]);
        printf("Quer  sortear outro numero (0|1)?\n");
        scanf("%d", &parada);
        printf("\n");

        if(parada==0)
            return;
    }
}
void reverse(const char * const sPtr)
{
    if('\0' == sPtr[0])
        return;
    else
    {
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}
void funcao(void)
{
     int Nminmax_1, Nminmax_2, x, resposta;


    printf("Entre com o valor min max da escala 1:\n");
    scanf("%d", &Nminmax_1);

    printf("Entre com o X da escala 1:\n");
    scanf("%d", &x);

    printf("Entre com o valor min max da escala 2:\n");
    scanf("%d", &Nminmax_2);


    resposta = (Nminmax_1*Nminmax_2)/x;

    printf("O valor na escala 2 eh: %d\n", resposta);

    return;
}
