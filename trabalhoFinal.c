#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define m 13

typedef struct caractere
{
    char c[m]; 
} hash;

// Calcula a função de espalhamento
int funcao(char insere)
{
    int b = ((int)insere) %m;
    return b;
}

void inicial_vetor(hash *vet)
{
    int i;

    for (i = 0; i < m; ++i)
    {
       vet->c[i]='*';
    }
}

// Insere um elemento k na tabela T de tamanho m
void Insere_Hash(hash *T, char insere)
{
    int indice;
    indice = funcao(insere);
    int posicao;
    _Bool cheia = false;

    (indice==0)?(posicao = 12) : (posicao = indice-1);

    while(T->c[indice] != '*'){
        indice++;
        if (indice == m)
        {
            indice = 0;
        }
        if (indice == posicao&&T->c[posicao]!='*')
        {
            cheia = true;
            break;
        }
    }
    if (cheia == true){
        printf("A tabela está cheia");
    }
    else
        T->c[indice]=insere;
}

void printar_hash(hash *p)
{
    int i;

    for (i = 0; i < m; i++)
    {
        if (p->c[i] == '*')
        {
            printf("\n<vazio>\n");
        }
        else 
            printf("%c\n", p->c[i]);
    }
}

void main(int argc, char*argv[])
{
    hash hash_;
    char k;
    char resp;
    inicial_vetor(&hash_);

    while(1){
        printf("\nInserir (i) printar (p) Sair (s)\n");
        scanf(" %c",&resp);
        
        switch(resp)
        {
            case 'i':
                printf("\nEntre com o caractere a ser inserido na tabela: ");
                scanf(" %c", &k);
                Insere_Hash(&hash_, k);
                break;
            case 'p':
                printar_hash(&hash_);
                break;
            case 's':
                exit(0);
                break;
      }
   }
}
