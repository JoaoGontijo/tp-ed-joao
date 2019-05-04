#ifndef ALUNO_H
#define ALUNO_H
#include <iostream>
#include <string>

using namespace std;


struct Aluno{

    int id;
    string nomeAluno;
    double notaAluno;  
    int escolha1;
    int escolha2;
    int escolhido;
    int espera;  

};

void ordenarAlunos(Aluno *vetor_alunos, int numeroDeAlunos);
void imprimrAlunos(Aluno *vetor_alunos, int numeroDeAlunos);
Aluno criarAluno (string nomeAluno, int id, float valoresAluno, int opcao1, int opcao2);

#endif