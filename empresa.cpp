#include <string>
#include <map>

#include "empresa.h"
#include "funcionario.h"

using namespace std;
/**
 * @brief médoto para cadastrar funcionario
 * 
 * @param funcionario
 * @return int
 */
int Empresa::cadastrar_funcionario(Funcionario funcionario)
{
    map <int,Funcionario> :: iterator it;
    it = fun.find(funcionario.getCpf());
    /**
     * @brief verificação de existência do funcionario se já existir retorna a um erro, caso contrario cria
     * 
     */
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
/**
 * @brief médoto dá aumento aos funcionarios de uma determinada empresa
 * 
 * @param porcentagem 
 * @return int 
 */
int Empresa::dar_aumento(float porcentagem)
{
    map <int,Funcionario> :: iterator it;
    for(it = fun.begin(); it != fun.end(); it++)
    {
        it->second.setSalario(it->second.getSalario() + ((it->second.getSalario()*porcentagem) / 100));
    }

    return 1;
}
/**
 * @brief saber a quantidade de funcionario de uma empresa
 * 
 * @return int
 */
int Empresa::quantidade_funcionarios()
{
    return fun.size();
}
/**
 * @brief inserir nome da empresa
 * 
 * @param nome_empresa 
 */
void Empresa::setNome(std::string nome_empresa)
{
    this->nome_empresa = nome_empresa;
}
/**
 * @brief pegar nome da empresa
 * 
 * @return string 
 */
string Empresa::getNome()
{
    return this->nome_empresa;
}
/**
 * @brief inserir CNPJ da empresa
 * 
 * @param cnpj 
 */
void Empresa::setCnpj(int cnpj)
{
    this->cnpj = cnpj;
}
/**
 * @brief pegar CPNJ da empresa
 * 
 * @return int 
 */
int Empresa::getCnpj()
{
    return this->cnpj;
}
/**
 * @brief pegar os funcionarios 
 * 
 * @return map<int,Funcionario>& 
 */
map<int,Funcionario> &Empresa::getFuncionarios()
{
    return fun;
}
/**
 * @brief pegar os funcionarios em experiência
 * 
 * @return map<int,Funcionario> 
 */
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
/**
 * @brief Construct a new Empresa:: Empresa object
 * 
 */
Empresa::Empresa()
{
    
}
/**
 * @brief Destroy the Empresa:: Empresa object
 * 
 */
Empresa::~Empresa()
{

}