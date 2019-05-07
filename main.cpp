/**
 * @file main.cpp
 * @author Frankleiton Levy (frankleiton@gmail.com) e Giovanna Karla (macedo1999.gk@gmail.com)
 * @brief 
 * @version 2.0
 * @date 2019-05-06
 * 
 * @copyright Copyright (c) 2019
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

