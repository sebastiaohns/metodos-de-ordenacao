#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "TADList.c"

void selection_sort(list *l, int tam, int x, int y) {
    int i, j, min, aux;

    word *aux1, *aux2, *prev1, *prev2, *tmp1 =NULL, *tmp2= NULL;

    aux1 = l->first;
    aux2 = aux1->next;
    prev1 = NULL;
    prev2 = aux1;

    for(i=0; i<tam; i++)
    {
        if(i == x)
        {
            for(j=0; j<tam; j++)
            {
                if(j == y)
                {
                    printf("foi aqui\n");

                    tmp1 = aux1->next;
                    tmp2 = aux1;
                    aux1->next = aux2->next;
                    aux2->next = tmp1;
                    prev1->next = aux2;
                    prev2->next = tmp2;
                }
                prev2 = aux2;
                aux2 = aux2->next;
            }
        }
        prev1 = aux1;
        aux1 = aux1->next;
    }
}


void main()
{
    //função da biblioteca locale para exibir caracteres especiais da lingua portuguesa
    setlocale(LC_ALL, "Portuguese");

    int i, op, cont=0;
    char buff[30];

    list *l = criar();

    FILE *f = fopen("test.txt", "r");
    op = fscanf(f, "%s", buff);
    while(op != EOF)
    {
        inserir(l, buff, cont);
        op = fscanf(f, "%s", buff);
        cont++;
    }


    pesquisar(l);
    selection_sort(l, contador(l)-1, 0, 1);
    mostrar(l);

    for(i=cont; i>1; i--)
    {
        op = remover(l, i);
        if(op = 1)
        {
            printf(".");
        }
    }

    op = apagar(l);
    if(op = 1)
    {
        printf("fim");
    }
}

