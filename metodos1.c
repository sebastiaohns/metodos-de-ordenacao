#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavra
{
    char str[30];
    int key;
    int rpt;
}palavra;


void insertionSort(palavra *vet, int tam)
{
    int i, j;
    palavra aux;

    for(i=1; i<tam; i++)
    {
        aux = vet[i];

        for(j=i-1; (j>=0) && strcmp(aux.str, vet[j].str) < 0; j--)
        {
            vet[j+1] = vet[j];
        }

        vet[j+1] = aux;
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
    int i, j, gap = 1;
    palavra aux;

    while(gap < tam)
    {
        gap = 3*gap+1;
    }

    while(gap > 1)
    {
        gap = gap/3;

        for(i=gap; i<tam; i++)
        {
            aux = vet[i];
            j = i - gap;

            while(j >= 0 && strcmp(aux.str, vet[j].str) < 0)
            {
                vet[j+gap] = vet[j];
                j = j - gap;
            }

            vet[j+gap] = aux;
        }
    }
}

void quickSort(palavra *vet, int esq, int dir) {
    int i, j;
    palavra aux, tmp;

    i = esq;
    j = dir;
    aux = vet[(esq + dir)/2];

    while(i <= j)
    {
        while((strcmp(vet[i].str, aux.str) < 0) && i < dir)
        {
            i++;
        }
        while((strcmp(vet[j].str, aux.str) > 0) && j > esq)
        {
            j--;
        }
        if(i <= j)
        {
            tmp = vet[i];
            vet[i] = vet[j];
            vet[j] = tmp;
            i++;
            j--;
        }
    }

    if(j > esq)
    {
        quickSort(vet, esq, j);
    }
    if(i < dir)
    {
        quickSort(vet, i, dir);
    }
}

void heapSort(palavra *vet, int tam)
{
    int i = tam/2, pai, filho;
    palavra aux;

    while(1)
    {
        if(i > 0)
        {
            i--;
            aux = vet[i];
        }
        else
        {
            tam--;
            if (tam == 0) return;
            aux = vet[tam];
            vet[tam] = vet[0];
        }

        pai = i;
        filho = i * 2 + 1;

        while(filho < tam)
        {
            if((filho + 1 < tam)  &&  strcmp(vet[filho + 1].str, vet[filho].str) > 0)
                filho++;
            if(strcmp(vet[filho].str, aux.str) > 0)
            {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai * 2 + 1;
            }
            else
            {
                break;
            }
        }

        vet[pai] = aux;
    }
}

void merge(palavra *vet, int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0;
    palavra vetAux[fim-comeco+1];

    while(com1<=meio && com2<=fim)
    {
        if(strcmp(vet[com1].str, vet[com2].str) <= 0){
            vetAux[comAux] = vet[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vet[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio)
    {  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vet[com1];
        comAux++;com1++;
    }

    while(com2<=fim)
    {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vet[com2];
        comAux++;com2++;
    }

    for(comAux=comeco;comAux<=fim;comAux++)
    {    //Move os elementos de volta para o vetor original
        vet[comAux] = vetAux[comAux-comeco];
    }
}


void mergeSort(palavra *vet, int comeco, int fim)
{
    int meio;
    if(comeco < fim)
    {
        meio = (fim+comeco)/2;

        mergeSort(vet, comeco, meio);
        mergeSort(vet, meio+1, fim);
        merge(vet, comeco, meio, fim);
    }
}
