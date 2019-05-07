#include <iostream>
#include <string>
#include <ctime>
#include <map>

#include "empresa.h"
#include "funcionario.h"

#include "gerenciador.h"

using namespace std;

/**
 * @brief Menu do programa empresa-funcionario
 * 
 */
void Gerenciador::gerencia()
{
    /**
     * @brief variáveis 
     * 
     */
    Empresa emp;
    Funcionario fun;

    map<int,Empresa> empresas;
    map<int,Empresa> :: iterator it_empresa;

    map<int,Funcionario> :: iterator it_func;
    
    map<int,Funcionario> func;
    func = emp.getFuncionarios();
    
    string aux = "";
    double aux2; 
    int iterator = 0;
    float aux3;

    time_t tempo;
    struct tm tmp = {0};
    int ano;
    tmp.tm_year = ano -1901;
    
    while (1)
    {
        int op = 0;
        cout << "1 - Criar empresa" << endl;
        cout << "2 - Criar funcionario" << endl;
        cout << "3 - Listar funcionarios em experiencia" << endl;
        cout << "4 - Dar aumento" << endl;
        cout << "5 - Listar funcionarios" << endl;
        
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Digite o nome da empresa: ";
            cin.ignore();
            getline(cin, aux);
            emp.setNome(aux);
            cout << "Digite o CNPJ da empresa: ";
            cin >> aux2;
            emp.setCnpj(aux2);

            empresas.insert(pair<int, Empresa>(emp.getCnpj(), emp));
            break;
        case 2:
            if (empresas.size() > 0)
            {
                cout << "Digite o CNPJ da empresa que deseja adicionar o funcionario: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if(it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    cout << "Nome do Funcionario:"<<endl;
                    cin.ignore();
                    getline(cin,aux);
                    fun.setNome(aux);
                    cout << "CPF do Funcionario:"<<endl;
                    cin >> aux2;
                    fun.setCpf(aux2);
                    cout << "Salario inicial do Funcionario:"<<endl;
                    cin >> aux3;
                    fun.setSalario(aux3);
                    fun.setData(time(0));
                    cout << "Digite a data de adimissao de acordo com o que se pede: "<< endl;
                    cout << "Dia: " << endl;
                    cin >> tmp.tm_mday;
                    cout << "Mes: " << endl;
                    cin >> tmp.tm_mon;
                    cout << "Ano: " << endl;
                    cin >> ano;
                    fun.setData(mktime(&tmp));
                    cout << fun.getData() << endl;
                    emp.cadastrar_funcionario(fun);
                }
            }
            else
            {
                cout << "Nao existem empresa cadastradas" << endl;
            }

            break;
        case 3:
           if (empresas.size() > 0)
           {
                cout << "Digite o CNPJ da empresa que deseja ver os funcionarios em experiencia: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if(it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    it_func = it_empresa->second.getFuncionarios_expreriencia().begin();
                    for(it_func; it_func != it_empresa->second.getFuncionarios_expreriencia().end(); it_func++)
                    {
                       cout << &it_func->second.getNome() << " - " << it_func->second.getCpf() << endl;
                    }
                }
            }
            else
            {
               cout << "Nao existe empresas o suficiente para essa operacao."<< endl;
            }
            break;
        case 4:
           if (empresas.size() > 0)
           {
                cout << "Digite o CNPJ da empresa que deseja dar aumento aos funcionarios: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if(it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    cout << "De quanto vai ser o aumento do funcionarios? " << endl;
                    cin >> aux3;
                    for(it_empresa = empresas.begin(); it_empresa != empresas.end(); it_empresa++){
                        it_empresa->second.dar_aumento(aux3);
                    }                    
                }
            }
            else
            {
                cout << "Nao existe empresas o suficiente para essa operacao."<< endl;
            }
            break;  
        case 5:
            
        default:
            cout << "operação invalida" << endl;
            break;
        }
    }
}

Gerenciador::Gerenciador()
{

}

Gerenciador::~Gerenciador()
{
    
}