/**
 * @file gerenciador.cpp
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

#include <iostream>
#include <string>
#include <ctime>
#include <map>

#include "empresa.h"
#include "funcionario.h"

#include "gerenciador.h"

using namespace std;

void clearScreen()
{
    if (system("clear") != 0)
    {
        system("CLS");
    }
}

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

    map<int, Empresa> empresas;

    map<int, Empresa>::iterator it_empresa;

    map<int, Funcionario>::iterator it_func;

    string aux = "";
    double aux2;
    int iterator = 0;

    int count_media = 0;
    int media = 0;

    float aux3;

    time_t tempo;
    struct tm tmp = {0};
    int ano;
    int mes;

    /**
     * @brief While para loop infinito do menu
     * 
     */
    while (1)
    {
        int op = 0;
        cout << "-----------------------------------------------------------" << endl;
        cout << "----------------Gerenciador de empresas 0.9----------------" << endl;
        cout << "1 - Criar empresa" << endl;
        cout << "2 - Criar funcionario" << endl;
        cout << "3 - Listar funcionarios de uma empresa" << endl;
        cout << "4 - Listar funcionarios em experiencia de uma empresa" << endl;
        cout << "5 - Dar aumento aos funcionarios de uma empresa" << endl;
        cout << "6 - Media de funcionarios por empresa" << endl;
        cout << "7 - Sair" << endl;
        cout << "-----------------------------------------------------------" << endl;

        cin >> op;

        switch (op)
        {
        case 1:
            clearScreen();
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
            clearScreen();
            if (empresas.size() > 0)
            {
                cout << "Digite o CNPJ da empresa que deseja adicionar o funcionario: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if (it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    cout << "Nome do Funcionario:" << endl;
                    cin.ignore();
                    getline(cin, aux);
                    fun.setNome(aux);
                    cout << "CPF do Funcionario:" << endl;
                    cin >> aux2;
                    fun.setCpf(aux2);
                    cout << "Salario inicial do Funcionario:" << endl;
                    cin >> aux3;
                    fun.setSalario(aux3);
                    fun.setData(time(0));
                    cout << "Digite a data de adimissao de acordo com o que se pede: " << endl;
                    cout << "Dia: " << endl;
                    cin >> tmp.tm_mday;
                    cout << "Mes: " << endl;
                    cin >> mes;
                    tmp.tm_mon = mes - 1;
                    cout << "Ano: " << endl;
                    cin >> ano;
                    tmp.tm_year = ano - 1900;
                    fun.setData(mktime(&tmp));
                    clearScreen();
                    if (it_empresa->second.cadastrar_funcionario(fun) == 404)
                    {
                        cout << "<<<<ERRO>>> Funcionario ja existe ! <<<<ERRO>>>" << endl;
                    }
                     
                }
            }
            else
            {
                cout << "Nao existem empresa cadastradas" << endl;
            }

            break;
        case 3:
            clearScreen();
            if (empresas.size() > 0)
            {
                cout << "Digite o CNPJ da empresa que deseja ver os funcionarios: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if (it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    for (auto it = it_empresa->second.getFuncionarios().begin(); it != it_empresa->second.getFuncionarios().end(); it++)
                    {
                        cout << "Nome: " << it->second.getNome() << endl;
                        cout << "Salario: " << it->second.getSalario() << endl;
                        cout << "CPF: " << it->second.getCpf() << endl;
                    }
                }
            }
            else
            {
                cout << "Nao existe empresas o suficiente para essa operacao." << endl;
            }
            break;

        case 4:
            clearScreen();
            if (empresas.size() > 0)
            {
                cout << "Digite o CNPJ da empresa que deseja ver os funcionarios em experiencia: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if (it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    cout << "EMPRESA: " << it_empresa->second.getCnpj() << endl;
                    cout << "FUNS: " << it_empresa->second.getFuncionarios().size() << endl;

                    it_empresa->second.getFuncionarios_expreriencia();
                }
            }
            else
            {
                cout << "Nao existe empresas o suficiente para essa operacao." << endl;
            }
            break;
        case 5:
            clearScreen();
            if (empresas.size() > 0)
            {
                cout << "Digite o CNPJ da empresa que deseja dar aumento aos funcionarios: " << endl;
                cin >> aux2;
                it_empresa = empresas.find(aux2);
                if (it_empresa == empresas.end())
                {
                    cout << "Empresa nao encontrada" << endl;
                }
                else
                {
                    cout << "De quanto vai ser o aumento dos funcionarios em % ? " << endl;
                    cin >> aux3;
                    for (it_empresa = empresas.begin(); it_empresa != empresas.end(); it_empresa++)
                    {
                        it_empresa->second.dar_aumento(aux3);
                    }
                }
            }
            else
            {
                cout << "Nao existe empresas o suficiente para essa operacao." << endl;
            }
            break;
        case 6:
            clearScreen();
            for (auto it = empresas.begin(); it != empresas.end(); it++)
            {
                cout << "Empresa: " << it->second.getNome() << " Possui " << it->second.getFuncionarios().size() << " Funcionarios" << endl;
                media += it->second.getFuncionarios().size();
                count_media++;
            }

            cout << "A media de funcionarios por empresa eh de " << media / count_media << endl;

            break;

        case 7: 
            
            exit(0);
            break;

        default:
            cout << "operação invalida" << endl;
            break;
        }
    }
}
/**
 * @brief Construct a new Gerenciador:: Gerenciador object
 * 
 */
Gerenciador::Gerenciador()
{
}
/**
 * @brief Destroy the Gerenciador:: Gerenciador object
 * 
 */
Gerenciador::~Gerenciador()
{
}