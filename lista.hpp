#ifndef LISTA_H
#define LISTA_H
#include "aluno.hpp"    
#include <iostream>
#include <string>
using namespace std;


struct no{
    int id;
    struct no *anterior; 
    struct no *proximo;
}; 

struct lista{
    
    int numeroDeItens; 
    no *inicio;
    no *fim;
};

lista *criarLista();  
void insere_item(lista *l, int id); 
void removerNo(lista *l); 
void destruirLista(lista *l); 
void imprime_lista(lista *l, Aluno *vetor_alunos); 

#endif