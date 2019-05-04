#include "curso.hpp"

void alocarAlunos_Cursos(Curso *vetor_cursos, Aluno *vetor_alunos, int numeroDeCursos, int numeroDeAlunos){

    

    for(int i = 0 ; i < numeroDeCursos ; i++){
       
       for(int j = 0; j < numeroDeAlunos ; j++){
            
            int opcao_aluno1 = vetor_alunos[j].escolha1;
            int opcao_aluno2 = vetor_alunos[j].escolha2;
            
            if((vetor_alunos[j].escolha1 == i) && (vetor_alunos[j].escolhido == -1) && (vetor_cursos[i].vagas > 0)){
                
                
                insere_item(vetor_cursos[i].aprovados, j);
                
                vetor_cursos[i].notaDeCorte = vetor_alunos[j].notaAluno;
                vetor_cursos[i].vagas -= 1;
                vetor_alunos[j].escolhido = 1;
                
            }else if((vetor_alunos[j].escolha2 == i) && (vetor_cursos[i].vagas > 0) && (vetor_alunos[j].escolhido == -1) ){
                
                
                if(vetor_cursos[opcao_aluno1].vagas > 0){
                    
                    
                    insere_item(vetor_cursos[opcao_aluno1].aprovados, j);
                    vetor_cursos[opcao_aluno1].vagas -= 1;  
                    vetor_alunos[j].escolhido = 1;
                    vetor_cursos[opcao_aluno1].notaDeCorte = vetor_alunos[j].notaAluno;
                    
                }else{

                    
                    insere_item(vetor_cursos[i].aprovados, j);
                    vetor_cursos[i].vagas -= 1;  
                    insere_item(vetor_cursos[opcao_aluno1].espera, j);
                    vetor_alunos[j].escolhido = 1;
                    vetor_cursos[opcao_aluno2].notaDeCorte = vetor_alunos[j].notaAluno;
                }

            }else if((vetor_alunos[j].escolha1 == i) && (vetor_alunos[j].escolhido == -1) && (vetor_alunos[j].espera == 0)){
               
                insere_item(vetor_cursos[opcao_aluno1].espera, j);
                insere_item(vetor_cursos[opcao_aluno2].espera, j);
                vetor_alunos[j].espera = 1;
            }
            
        
            
        }
        
    }
    
}

Curso criar_curso(string nomeCurso, int idCurso, int numeroDeVagas){

    Curso auxiliar;

    auxiliar.id = idCurso;
    auxiliar.vagas = numeroDeVagas;
    auxiliar.nome = nomeCurso;
    auxiliar.aprovados = criarLista();
    auxiliar.espera = criarLista();
    auxiliar.notaDeCorte = 0;

    return auxiliar;

}