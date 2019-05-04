#ifndef CURSO_H
#define CURSO_H
#include "aluno.hpp"
#include "lista.hpp"

#include <string>

using namespace std;


struct Curso{
    
    
    int id;
    string nome;
    int vagas;
    float notaDeCorte;
    
    lista *aprovados;
    lista *espera;

};

void alocarAlunos_Cursos(Curso *vetor_cursos, Aluno *vetor_alunos, int numeroDeCursos, int numeroDeAlunos);
Curso criar_curso(string nomeCurso, int idCurso, int numeroDeVagas);


#endif