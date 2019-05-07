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