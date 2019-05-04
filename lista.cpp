#include <stdio.h>
#include <stdlib.h>
#include "lista.hpp"


lista *criarLista(){
    lista *l = (lista *) malloc(sizeof(lista));

    l->inicio = NULL;
    l->fim = NULL;
    l->numeroDeItens = 0;

    return l;
}


void insere_item(lista *l, int id){
    
    no *i = (no *) malloc(sizeof(no));
    i->id = id;
    i->proximo = NULL;

    
    if(l->numeroDeItens == 0){
        i->anterior = NULL;
        l->inicio = i;
    } else{
        no *aux = l->fim;
        i->anterior = aux;
        aux->proximo = i;
    }
    l->fim = i;
    l->numeroDeItens++;
}


void remove_item(lista *l){
    no *primeiro = l->inicio;

    if(l->numeroDeItens == 1){
        l->inicio = NULL;
        l->fim = NULL;
        l->numeroDeItens = 0;
        delete(primeiro);
        
    } else{
        no *primeiro = l->inicio;
        no *segundo = primeiro->proximo;
        segundo->anterior = NULL;
        free(primeiro);
        l->inicio = segundo;

        l->numeroDeItens--;
    }
}

void imprime_lista(lista *l, Aluno *vetor_alunos){
    if(l->numeroDeItens == 0){
        
    }
    else{
        no *aux = l->inicio;
        while(aux != NULL){
            int id = aux->id;
            cout << vetor_alunos[id].nomeAluno << " " << vetor_alunos[id].notaAluno << endl;
            aux = aux->proximo;
            remove_item(l);
        }
        
    }
}

void apaga_lista(lista *l){
    no *aux = l->inicio;
    no *toFree;
    while(aux != NULL){
        toFree = aux;
        aux = toFree->proximo;
        free(toFree);
    }
    free(l);
}