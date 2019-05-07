/**
 * @file funcionario.cpp
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
 * @brief atribuir data de admissão do funcionario
 * 
 * @param data_de_admissao 
 */
void Funcionario::setData(time_t data_de_admissao)
{
    this->data_de_admissao = data_de_admissao;
}
/**
 * @brief pegar data de admissão do funcionario
 * 
 * @return time_t 
 */
time_t Funcionario::getData()
{
    return this->data_de_admissao;
}
/**
 * @brief atribuir salário do funcionario
 * 
 * @param salario 
 */
void Funcionario::setSalario(float salario)
{
    this->salario = salario;
}
/**
 * @brief pegar o valor do salário do funcionario
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