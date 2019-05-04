#include <iostream>
#include <string>
#include <fstream>

#include "aluno.hpp"
#include "curso.hpp"
#include "lista.hpp"



using namespace std;

int main(){
    
    int numeroDeCursos, numeroDeAlunos, numeroDeVagas, opcao1, opcao2;
    double valoresAluno;
    string nomeCurso, nomeAluno;
    

    //cout << "Digite o numero de cursos e numero de alunos:";
    cin >> numeroDeCursos >> numeroDeAlunos;

    Curso vetor_cursos[numeroDeCursos];
    Aluno vetor_alunos[numeroDeAlunos];
    

    for(int i = 0 ; i < numeroDeCursos; i++){
        
        //cout << "Digite o nome do curso:";
        cin.ignore();
        getline(cin, nomeCurso);

        //cout << "Digite o numero de vagas do curso:";
        //fflush(stdin);
        cin >> numeroDeVagas;
        
        vetor_cursos[i] = criar_curso(nomeCurso, i, numeroDeVagas);
    }
    
    //Imprimir Cursos
    /*/for(int i = 0 ; i < numeroDeCursos; i++){
        cout << "\nNome do curso:";
        cout << vetor_cursos[i].nome;
        cout << "\nID do curso:";
        cout << vetor_cursos[i].id;
        cout << "\nVagas do curso:";
        cout << vetor_cursos[i].vagas;

    }/*/
    
    //LEITURA ALUNO

    for(int i = 0 ; i < numeroDeAlunos; i++){
        
        //cout << "Digite o nome do Aluno:";
        cin.ignore();
        getline(cin, nomeAluno);
        
        //cout << "Digite a nota do Aluno:";
        cin >> valoresAluno >> opcao1 >> opcao2;
        

        vetor_alunos[i] = criarAluno(nomeAluno, i, valoresAluno, opcao1, opcao2);

    }
    
    ordenarAlunos(vetor_alunos, numeroDeAlunos);

    alocarAlunos_Cursos(vetor_cursos, vetor_alunos, numeroDeCursos, numeroDeAlunos);
    
    for(int i = 0 ; i < numeroDeCursos; i++){
    
    cout << vetor_cursos[i].nome << " " << vetor_cursos[i].notaDeCorte << endl;
    cout << "Classificados" << endl;
    imprime_lista(vetor_cursos[i].aprovados, vetor_alunos);
    cout << "Lista de espera" << endl;
    imprime_lista(vetor_cursos[i].espera, vetor_alunos);
    cout << "\n";
    }
   

    return 0;
}