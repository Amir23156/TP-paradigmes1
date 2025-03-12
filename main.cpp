//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia obj1("Photo1", "Telecom_Paris_main_court.jpg");
    obj1.afficher(std::cout);
    std::cout << "Hello brave new world" << std::endl;
    return 0;
}
