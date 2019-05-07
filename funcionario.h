/**
 * @file funcionario.h
 * @author Frankleiton Levy (frankleiton@gmail.com) e Giovanna Karla (macedo1999.gk@gmail.com)
 *
 * @brief Sistema Empresa-Funcionario 
 * @version 1.0
 *
 * since 23-04-2019
 * @date 06-05-2019
 *
 * @sa Materiais disponiveis no SIGAA da materia de LP-I 2019.1
 * 
 */

#ifndef funcionario_H
#define funcionario_H

#include <string>
#include <ctime>

using namespace std;
/**
 * @brief classe do tipo fincionario
 * 
 */
class Funcionario{
        /**
         * @brief atributos/variaveis da minha classe funcionario
         * 
         */
    private:
        string nome;
        time_t data_de_admissao;
        float salario;
        double cpf;
    
    public:
        /**
         * @brief medotos utilizados para atribuir valores aos atributos
         * 
         */
        void setNome(string nome);
        void setData(time_t data_de_admissao);
        void setSalario(float salario);
        void setCpf(double cpf);
        /**
         * @brief medotos utilizados para pegar os valores aos atributos
         * 
         *  
         */
        string getNome();
        time_t getData();
        float getSalario();
        int getCpf();
        /**
         * @brief Construct a new Funcionario object
         * 
         */
        Funcionario();
        /**
         * @brief Destroy the Funcionario object
         * 
         */
        ~Funcionario();
};

#endif