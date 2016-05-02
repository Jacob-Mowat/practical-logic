//
//  main.cpp
//  practical-logic
//
//  Created by Jacob Mowat on 02/05/2016.
//
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

// alternation of 'n'

// 2^i  2^i  2^i  2^i
// 2^3  2^2  2^1  2^0
// 8    4    2    1
// A,   B,   C,   D
// 0    0    0    1
// 0    0    0    0
// 0    0    1    1
// 0    0    1    0
// 0    1    0    1
// 0    1    0    0


std::vector<std::vector<int> > generateInputs(unsigned int n)
{
    std::vector<std::vector<int> > cout(n, std::vector<int>(1 << n));
    
    unsigned nf = 1U << (n - 1); // current out.n
    for (unsigned y = 0; y < n; ++y, nf >>= 1U) // y - column
    {
        for (unsigned x = nf; x < (1U << n); x += (nf * 2))
        {
            std::fill_n(&cout[y][x], nf, 1); // refference the cout of (x, y)
        }
    }
    
    for(unsigned i = 0; i < (1 << n); ++i)
    {
        for(unsigned j =0; j < n; ++j)
        {
            std::cout << cout[j][i] << "";
        }
        std::cout << std::endl;
    }
    
    return cout;
}


int main(int argc, const char * argv[])
{
    
    unsigned int n = 0;
    std::string f = "";
    
    if (argc == 1)
    {
        std::cout << "Usage: ./logic -n <number_of_vars> -f <formula>" << std::endl;
    }
    else if (argv[2] != NULL & argv[4] != NULL)
    {
        // set the parameters into there local variables
        n = std::stoi(argv[2]);
        f = argv[4];
        
        generateInputs(n); // generate all possible inputs for the thruth table of numvars 'n'
        
    }
    else
    {
        std::cout << "You must pass the number of varibles and the formula in the following format\n Usage: ./logic -n <number_of_vars> -f <formula>" << std::endl;
    }
    
    return 0;
}
