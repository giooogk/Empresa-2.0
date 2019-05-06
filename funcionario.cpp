#include "funcionario.h"

using namespace std;

void Funcionario::setNome(string nome)
{
    this->nome = nome;
}

string Funcionario::getNome()
{
    return this->nome;
}

void Funcionario::setData(time_t data_de_admissao)
{
    this->data_de_admissao = data_de_admissao;
}

time_t Funcionario::getData()
{
    return this->data_de_admissao;
}

void Funcionario::setSalario(float salario)
{
    this->salario = salario;
}
float Funcionario::getSalario()
{
    return this->salario;
}

void Funcionario::setCpf(double cpf)
{
    this->cpf = cpf;
}

int Funcionario::getCpf()
{
    return this->cpf;
}

Funcionario::Funcionario()
{

}

Funcionario::~Funcionario()
{
    
}