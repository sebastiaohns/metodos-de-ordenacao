#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADList.c"

void selection_sort(list *l, int tam) {
    int i, j, min, aux;

    word *aux1, *aux2, *prev1, *prev2, *tmp1, *tmp2;

    aux1 = l->first;
    aux2 = aux1->next;

    for(i=0; i<tam-1; i++)
    {
        min = aux1->key;
        for(j =i+1; j<tam; j++) {
            if(aux2->rpt < aux1->rpt)
            {
                min = aux2->key;
            }
            prev2 = aux2;
            aux2 = aux2->next;
        }

        if(aux1->key != aux2->key) {

            tmp1 = aux1->next;
            aux1->next = aux2->next;
            aux2->next = tmp1;

            tmp2 = prev1->next;
            prev1->next = aux2;
            prev2->next = tmp2;

        }
        prev1 = aux1;
        aux1 = aux1->next;
    }
}
