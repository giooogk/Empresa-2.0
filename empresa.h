#ifndef empresa_H
#define empresa_H

#include <string>
#include <map>
#include "funcionario.h"

using namespace std;
/**
 * @brief classe de tipo empresa
 * 
 */
class Empresa{
    private:
        /**
         * @brief atributos/variáveis da minha classe empresa
         * 
         */
        string nome_empresa;
        int cnpj;
        map<int,Funcionario> fun;

    public:
        /**
         * @brief médotos de funcionalidades da empresa
         * 
         */
        int cadastrar_funcionario(Funcionario funcionario);
        int dar_aumento(float porcentagem);
        int quantidade_funcionarios();
        /**
         * @brief médotos para pegar e atribuir valores das variáveis
         * 
         */
        map<int,Funcionario> getFuncionarios_expreriencia();
        map<int,Funcionario> &getFuncionarios();
        void setNome(string nome_empresa);
        string getNome();
        void setCnpj(int cnpj);
        int getCnpj();
        /**
         * @brief Construct a new Empresa object
         * 
         */
        Empresa();
        /**
         * @brief Destroy the Empresa object
         * 
         */
        ~Empresa();
};

#endif