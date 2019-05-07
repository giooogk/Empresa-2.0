/**
 * @file main.cpp
 * @author Frankleiton Levy (frankleiton@gmail.com) e Giovanna Karla (macedo1999.gk@gmail.com)
 *
 * @brief Sistema Empresa-Funcionario 
 * @version 2.0
 *
 * since 23-04-2019
 * @date 06-05-2019
 *
 * @sa Materiais disponiveis no SIGAA da materia de LP-I
 * 
 */

#include <iostream>
#include "gerenciador.h"

int main(int argc, char const *argv[])
{
    
    Gerenciador * a = new Gerenciador();
    a->gerencia();
    
    return 0;
}

