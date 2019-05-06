#ifndef funcionario_H
#define funcionario_H

#include <string>
#include <ctime>

using namespace std;

class Funcionario{
    private:
        string nome;
        time_t data_de_admissao;
        float salario;
        int cpf;
    
    public:
        void setNome(string nome);
        void setData(time_t data_de_admissao);
        void setSalario(float salario);
        void setCpf(int cpf);

        string getNome();
        time_t getData();
        float getSalario();
        int getCpf();
        Funcionario();
        ~Funcionario();
};

#endif