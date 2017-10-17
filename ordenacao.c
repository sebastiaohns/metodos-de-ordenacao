#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Word
{
    char str[30];
    int rpt;
    int key;
    struct Word *next;
}word;

typedef struct List
{
    word *first;
}list;

list *criar();
int inserir(list*, char*);
int remover(list*, int);
int apagar(list*);
int contador(list*);
int compara_listas(list*, list*);
int pesquisar(list*, char*);
int vazio(list*);
void mostrar(list*);

void main()
{
    //função da biblioteca locale para exibir caracteres especiais da lingua portuguesa
    setlocale(LC_ALL, "Portuguese");

    int op;
    char buff[30];

    list *l = criar();

    FILE *f = fopen("test.txt", "r");
    op = fscanf(f, "%s", buff);
    while(op != EOF)
    {
        inserir(l, buff);
        op = fscanf(f, "%s", buff);
    }

    mostrar(l);
}

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

int inserir(list *l, char* str)
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
                n->next = NULL;
                aux->next = n;

                return 1;
            }
            else
            {
                strcpy(n->str, str);
                n->rpt = 0;
                n->next = NULL;
                l->first = n;

                return 1;
            }
        }
    }
    return 0;
}

/*
int pesquisar(list *l, char* data)
{
    if(l != NULL)
    {
        int list_data, dado;
        word* aux;

        if(l->first != NULL)
        {
            aux = l->first;
            dado = (int)data;
            while(aux->next != NULL)
            {
                list_data = (int)aux->str;
                if(list_data == dado)
                {
                    return 1;
                }
                aux = aux->next;
            }
            list_data = (int)aux->data;
            if(list_data == dado)
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }


    }
    return 0;
}

*/

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
            printf("%s ", x);
            aux = aux->next;
            strcpy(x, aux->str);
        }
        printf("%s\n", x);
    }
}
