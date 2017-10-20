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
int inserir(list*, char*, int);
int remover(list*, int);
int apagar(list*);
int contador(list*);
int compara_listas(list*, list*);
int pesquisar(list*);
int vazio(list*);
void mostrar(list*);
