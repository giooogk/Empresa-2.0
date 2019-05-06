#include <string>
#include <map>

#include "empresa.h"
#include "funcionario.h"

using namespace std;

int Empresa::cadastrar_funcionario(Funcionario funcionario)
{
    map <int,Funcionario> :: iterator it;
    it = fun.find(funcionario.getCpf());
    if(it == fun.end())
    {
        return 404;
    }
    else
    {
        fun.insert(pair<int, Funcionario>(funcionario.getCpf(),funcionario));
    }
    return 1;
}

int Empresa::dar_aumento(float porcentagem)
{
    map <int,Funcionario> :: iterator it;
    for(it = fun.begin(); it != fun.end(); it++)
    {
        it->second.setSalario(it->second.getSalario() + ((it->second.getSalario()*porcentagem) / 100));
    }

    return 1;
}

int Empresa::quantidade_funcionarios()
{
    return fun.size();
}

void Empresa::setNome(std::string nome_empresa)
{
    this->nome_empresa = nome_empresa;
}

string Empresa::getNome()
{
    return this->nome_empresa;
}

void Empresa::setCnpj(int cnpj)
{
    this->cnpj = cnpj;
}

int Empresa::getCnpj()
{
    return this->cnpj;
}


map<int,Funcionario> &Empresa::getFuncionarios()
{
    return fun;
}

map<int,Funcionario> Empresa::getFuncionarios_expreriencia()
{
    time_t hoje = time(0);
    map<int,Funcionario> fun_expreriencia;
    map <int,Funcionario> :: iterator it;
    it = fun.begin();

    for(it; it != fun.end(); it++)
    {
        if((hoje - it->second.getData()) / 86400 <= 90 )
        {
            fun_expreriencia.insert(pair<int, Funcionario>(it->second.getCpf(), it->second));
        }
    }
    return fun_expreriencia;
}

Empresa::Empresa()
{
    
}

Empresa::~Empresa()
{

}