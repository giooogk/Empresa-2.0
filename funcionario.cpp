#include "funcionario.h"

using namespace std;
/**
 * @brief atribuir nome do funcionario
 * 
 * @param nome 
 */
void Funcionario::setNome(string nome)
{
    this->nome = nome;
}
/**
 * @brief pegar o nome do funcionario
 * 
 * @return string 
 */
string Funcionario::getNome()
{
    return this->nome;
}
/**
 * @brief atribuir data de admissao do funcionario
 * 
 * @param data_de_admissao 
 */
void Funcionario::setData(time_t data_de_admissao)
{
    this->data_de_admissao = data_de_admissao;
}
/**
 * @brief pegar data de admissao do funcionario
 * 
 * @return time_t 
 */
time_t Funcionario::getData()
{
    return this->data_de_admissao;
}
/**
 * @brief atribuir salario do funcionario
 * 
 * @param salario 
 */
void Funcionario::setSalario(float salario)
{
    this->salario = salario;
}
/**
 * @brief pegar o valor do salario do funcionario
 * 
 * @return float 
 */
float Funcionario::getSalario()
{
    return this->salario;
}
/**
 * @brief inserir o CPF do funcionario
 * 
 * @param cpf 
 */
void Funcionario::setCpf(double cpf)
{
    this->cpf = cpf;
}
/**
 * @brief pegar o CPF do funcionario
 * 
 * @return int 
 */
int Funcionario::getCpf()
{
    return this->cpf;
}
/**
 * @brief Construct a new Funcionario:: Funcionario object
 * 
 */
Funcionario::Funcionario()
{

}
/**
 * @brief Destroy the Funcionario:: Funcionario object
 * 
 */
Funcionario::~Funcionario()
{
    
}