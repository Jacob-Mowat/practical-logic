//
//  main.cpp
//  practical-logic
//
//  Created by Jacob Mowat on 02/05/2016.
//
//

#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    
    int n = 0;
    std::string f = "";
    
    if (argc == 1)
    {
        std::cout << "Usage: ./logic -n <number_of_vars> -f <formula>" << std::endl;
    }
    else if (argv[2] != NULL & argv[4] != NULL)
    {
        n = std:: stoi(argv[2]);
        f = argv[4];
    }
    else
    {
        std::cout << "You must pass both a number of varibles and a formula like so; \n ./logic -n <number_of_vars> -f <formula>" << std::endl;
    }
    
    return 0;
}
