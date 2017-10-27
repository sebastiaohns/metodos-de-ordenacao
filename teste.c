#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "metodos1.c"

void main()
{

    setlocale(LC_ALL, "Portuguese");

    char str[30];
    int i, j, x, cont=0;

    palavra *vet;

    FILE *arq = fopen("segunda-entrada.txt", "r");

    x = fscanf(arq, "%s", str);
    while(x != EOF)
    {
        cont++;
        x = fscanf(arq, "%s", str);
    }
    printf("foi");

    vet = (palavra*)malloc(cont*sizeof(palavra));
    fseek(arq, 0, SEEK_SET);

    for(i=0; i<cont; i++)
    {
        fscanf(arq, "%s", str);
        if(strstr(str, ",") != NULL || strstr(str, ".") != NULL)
        {
            strtok(str, ",");
            strtok(str, ".");
        }
        strcpy(vet[i].str, str);
        vet[i].key = i;
        vet[i].rpt = 0;

        //for(j=i; j>=0; j--)
        //{
        //    if(strcmp(vet[i].str, vet[j].str) == 0)
        //    {
        //        vet[i].rpt++;
        //    }
        //}

    }
    printf("foi");

    fclose(arq);
    //insertionSort(vet, cont);
    //selectionSort(vet, cont);
    shellSort(vet, cont);
    //quickSort(vet, 0, cont-1);
    //heapSort(vet, cont);
    //mergeSort(vet, 0, cont-1);
    //countingSort(vet, cont);
    printf("foi");

    /*
    for(i=0; i<cont; i++)
    {
        if(strlen(vet[i].str) > 4)
        {
            printf("%s\t\t%d\t\t%d\n", vet[i].str, vet[i].key, vet[i].rpt);
        }
    }
    */

}
