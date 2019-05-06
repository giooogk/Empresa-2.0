#ifndef empresa_H
#define empresa_H

#include <string>
#include <map>
#include "funcionario.h"

using namespace std;

class Empresa{
    private:
        string nome_empresa;
        int cnpj;
        map<int,Funcionario> fun;

    public:
        int cadastrar_funcionario(Funcionario funcionario);
        int dar_aumento(float porcentagem);
        int quantidade_funcionarios();
        
        map<int,Funcionario> getFuncionarios_expreriencia();
        map<int,Funcionario> &getFuncionarios();
        void setNome(string nome_empresa);
        string getNome();
        void setCnpj(int cnpj);
        int getCnpj();
        
        Empresa();
        ~Empresa();
};

#endif