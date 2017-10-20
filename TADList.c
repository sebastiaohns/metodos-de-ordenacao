#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "TADList.h"


list *criar()
{
    list *l;

    l = (list*)malloc(sizeof(list));

    if(l != NULL)
    {
        l->first = NULL;

        return l;
    }
    return NULL;
}

int inserir(list *l, char *str, int key)
{
    if(l != NULL)
    {
        word *n, *aux;

        n = (word*)malloc(sizeof(word));

        if(n != NULL)
        {
            if(l->first != NULL)
            {
                aux = l->first;
                while(aux->next != NULL)
                {
                    aux = aux->next;
                }
                strcpy(n->str, str);
                n->rpt = 0;
                n->key = key;
                n->next = NULL;
                aux->next = n;

                return 1;
            }
            else
            {
                strcpy(n->str, str);
                n->rpt = 0;
                n->key = key;
                n->next = NULL;
                l->first = n;

                return 1;
            }
        }
    }
    return 0;
}

int pesquisar(list *l)
{
    if(l != NULL)
    {
        char str[30];
        word *aux, *tmp;

        if(l->first != NULL)
        {
            aux = l->first;
            strcpy(str, aux->str);

            while(aux->next != NULL)
            {
                tmp = aux->next;

                while(tmp->next != NULL)
                {

                    if(strcmp(str, tmp->str) == 0)
                    {
                        aux->rpt++;
                    }
                    tmp = tmp->next;
                }
                aux = aux->next;
                strcpy(str, aux->str);
            }
            if(strcmp(str, tmp->str) == 0)
            {
                {
                    aux->rpt++;
                }
            }
        }
    }
}

int remover(list *l, int k)
{
    if(l != NULL && l->first != NULL)
    {
        int i=0;
        word *aux, *prev;

        aux = l->first;
        while(aux->next != NULL && i < k)
        {
            prev = aux;
            aux = aux->next;
            i++;
        }
        prev->next = aux->next;

        return 1;
    }
    return 0;
}

int apagar(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        l->first = NULL;
        return 1;
    }
    return 0;
}

int contador(list *l)
{
    int cont=1;
    word *aux;

    if(l != NULL && l->first != NULL)
    {
        aux = l->first;
        while(aux->next != NULL)
        {
            cont++;
            aux = aux->next;
        }
        return cont;
    }
    return 0;
}

int compara_listas(list *l1, list *l2)
{
    if(l1 != NULL || l2 != NULL)
    {
        int cont1=0, cont2=0;

        cont1 = contador(l1);
        cont2 = contador(l2);

        if(cont1 == cont2)
            return 0;

        if(cont1 > cont2)
            return 1;

        if(cont1 < cont2)
            return -1;

    }
    return 0;

}

int vazio(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        return 1;
    }
    return 0;
}

void mostrar(list *l)
{
    if(l != NULL && l->first != NULL)
    {
        char x[30];
        word *aux;
        aux = l->first;
        strcpy(x, aux->str);
        while(aux->next != NULL)
        {
            printf("%s\t%d\t%d\n", x, aux->key, aux->rpt);
            aux = aux->next;
            strcpy(x, aux->str);
        }
         printf("%s\t%d\t%d\n", x, aux->key, aux->rpt);
    }
}
