#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Palavra
{
    char str[30];
    int key;
    int rpt;
}palavra;

void insertionSort(palavra *vet, int tam)
{
    int i, j;
    palavra atual;

    for(i=1; i<tam; i++)
    {
        atual = vet[i];

        for(j=i-1; (j>=0) && strcmp(atual.str, vet[j].str) < 0; j--)
        {
            vet[j+1] = vet[j];
        }

        vet[j+1] = atual;
    }
}

void selectionSort(palavra *vet, int tam)
{ 
    int i, j, min;
    palavra aux;

    for(i=0; i<(tam-1); i++) 
    {
        min = i;

        for(j=(i+1); j<tam; j++)
        {
            if(strcmp(vet[j].str, vet[min].str) < 0) 
                min = j;
        }
        if(strcmp(vet[i].str, vet[min].str) != 0)
        {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

void shellSort(palavra *vet, int tam)
{
    int i , j;
    int gap = 1;
    palavra aux;

    while(gap < tam) 
    {
        gap = 3*gap+1;
    }

    while(gap > 1)
    {
        gap /= 3;

        for(i=gap; i<tam; i++)
        {
            aux = vet[i];
            j = i - gap;

            while(j >= 0 && strcmp(aux.str, vet[j].str) < 0)
            {
                vet[j+gap] = vet[j];
                j -= gap;
            }
            
            vet[j+gap] = aux;
        }
    }
}

void main()
{
    char str[30];
    int i, j, x, cont=0;

    palavra *vet;

    FILE *arq = fopen("primeira_entrada.txt", "r");

    x = fscanf(arq, "%s", str);
    while(x != EOF)
    {
        cont++;
        x = fscanf(arq, "%s", str);
    }

    vet = (palavra*)malloc(cont*sizeof(palavra));
    fseek(arq, 0, SEEK_SET);

    for(i=0; i<cont; i++)
    {
        fscanf(arq, "%s", str);
        strcpy(vet[i].str, str);
        vet[i].key = i;
        vet[i].rpt = 0;
    }

    /*

    for(i=0; i<cont; i++)
    {
        for(j=i; j<cont; j++)
        {
            if(strcmp(vet[i].str, vet[j].str) == 0)
            {
                vet[i].rpt++;
            }
        }
    }

    fclose(arq);
    insertionSort(vet, cont);
    //selectionSort(vet, cont);
    //shellSort(vet, cont);

    */

    for(i=0; i<cont; i++)
    {
        printf("%s \t %d \t %d \n", vet[i].str, vet[i].key, vet[i].rpt);
    }


}