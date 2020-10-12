#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    
    printf("\n///ola seja bem vindo a um projeto de calculadora polonesa///\n");
    printf("\n///acho que voce ja deve saber usar mas contando que nao saiba///\n");
    printf("\n///vou da um exemplo de como ultilizala usualmente calculamos///\n");
    printf("\n///adicao assim 10 + 10 mas na calculadora polonesa em um pouco///\n");
    printf("\n///diferente seria ultilizada assim 10 10 + os sinais ficam///\n");
    printf("\n///atras e nao no meio espero que tenha entendido///\n\n\n");
    printf("######################\n");
    printf("#CALCULADORA POLONESA# \n");
    printf("######################\n\n");

    while((type = getop(s)) !=EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2=pop();
                push(pop() - op2);
                break;
            case '/':
                op2=pop();
                if(op2!=0.0)
                    push(pop() / op2);
                else
                    printf("erro: divisor zero, recomece o programa!\n");
                break;
            case '\n':
                printf("Resultado: %.8g\n\n", pop());
                printf("Digite a proxima conta! \n");
                break;
            default:
                printf("erro: comando desconhecido, por favor tente de novo %s\n", s);
                printf("\nrecomece o programa novamente!\n");
                return 0;
        }
    }
    return 0;
}


int sp=0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("erro: pilha está cheia impossivel continuar %g\n", f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("erro: pilha vazia, recomece o programa!\n");
        return 0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;
    
    
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1]='\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c =='.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i]='\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: muitos caracteres \n");
    else
        buf[bufp++]=c;
}
