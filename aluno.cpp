#include "aluno.hpp"

void ordenarAlunos(Aluno *vetor_alunos, int numeroDeAlunos){

    Aluno auxiliar;
        
    for(int i = 0 ; i < numeroDeAlunos ; i++) {
        for(int j = i+1 ; j < numeroDeAlunos ; j++) {
            if(vetor_alunos[i].notaAluno < vetor_alunos[j].notaAluno){
                
                auxiliar = vetor_alunos[i];
                vetor_alunos[i] = vetor_alunos[j];
                vetor_alunos[j] = auxiliar;
                
                
            }else if(vetor_alunos[i].notaAluno == vetor_alunos[j].notaAluno){
                if(vetor_alunos[i].escolha1 > vetor_alunos[j].escolha1){
                    auxiliar = vetor_alunos[i];
                    vetor_alunos[i] = vetor_alunos[j];
                    vetor_alunos[j] = auxiliar;
                }
                
                
            }

        }
   
    }


}

void imprimrAlunos(Aluno *vetor_alunos, int numeroDeAlunos){
    for(int i = 0 ; i < numeroDeAlunos; i++){
        
        
        cout << "\nNome do aluno:";
        cout << vetor_alunos[i].nomeAluno;
        cout << "\nNota Aluno:";
        cout << vetor_alunos[i].notaAluno;
        cout << "\n ID aluno:";
        cout << vetor_alunos[i].id;
    }

}

Aluno criarAluno (string nomeAluno, int id, float valoresAluno, int opcao1, int opcao2){


    Aluno auxiliar;
    auxiliar.nomeAluno = nomeAluno;
    auxiliar.id = id;
    auxiliar.notaAluno = valoresAluno;
    auxiliar.escolha1 = opcao1;
    auxiliar.escolha2 = opcao2;
    auxiliar.escolhido = -1;
    auxiliar.espera = 0;

    return auxiliar;


}