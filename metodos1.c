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

void merge(palavra *vet, int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0;
    palavra vetAux[fim-comeco+1];
    
    while(com1<=meio && com2<=fim)
    {
        if(strcmp(vetor[com1].str, vetor[com2].str) <= 0){
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1<=meio)
    {  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;com1++;
    }

    while(com2<=fim)
    {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;com2++;
    }

    for(comAux=comeco;comAux<=fim;comAux++)
    {    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
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