#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxCaracteres 100

void escolha(int entrada, char *frase);
int pergunta();
void subFrase(char *frase);
void subLetra(char *frase);

void escolha(int entrada, char *frase)
{
    switch(entrada)
    {
        case 1:
            subFrase(frase);
            printf("Frase atualizada: %s\n", frase);
        break;

        case 2:
            subLetra(frase);
            printf("Frase atualizada: %s\n", frase);
        break;

        case 3:
            break;
    }
}
int pergunta()
{
    int entrada;
    do
    {
        printf("\n1 - Substituir frase inteira.\n2 - Substituir alguma letra da frase.\n3 - Encerrar Programa\n\n");
        scanf("%d", &entrada);
    }while(entrada != 1 && entrada != 2 && entrada != 3);
    return entrada;
}
void subFrase(char *frase)
{
    char novaFrase[MaxCaracteres];
    getchar();
    printf("\nDigite a nova frase: ");
    fgets(novaFrase, MaxCaracteres, stdin);
    novaFrase[strcspn(novaFrase, "\n")] = '\0';
    strcpy(frase, novaFrase);
    printf("\n");
    system("cls||clear");
}
 void subLetra(char *frase)
 {
    char  alvo, alternativo, substituto;
    printf("\nQual letra deseja substituir: ");
    scanf(" %c", &alvo);
    printf("Qual letra deseja colocar no local: ");
    scanf(" %c", &substituto);
    printf("\n");
    if(alvo <= 'Z' && alvo >= 'A')
    {
        alternativo = alvo + 32;
    }
    else if(alvo <= 'z' && alvo >= 'a')
    {
        alternativo = alvo - 32;
    }
    for(int i = 0; i < MaxCaracteres; i++)
    {
        if(frase[i] == alvo || frase[i] == alternativo)
        {
            frase[i] = substituto;
        }
    }
    system("cls||clear");
 }

int main()
{
int entrada;
char frase[MaxCaracteres];

printf("Digite uma frase: ");
fgets(frase, MaxCaracteres, stdin);
frase[strcspn(frase, "\n")] = '\0';
do
{
entrada = pergunta();
escolha(entrada, frase);
}while(entrada != 3);
}
