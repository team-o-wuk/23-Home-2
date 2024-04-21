#include <iostream>
#include <fstream>
#include <ostream>
#include "matrix.h"

 

int main()
{
     

    Matrix m(3,3);
  

    std::ifstream in("in.txt");
    if (in.is_open())
    {
        in >> m;
        in.close();
    }

    
    Matrix r = !m;

    std::cout << m;
    std::cout << r;

    Matrix s = m+r;
    std::cout << s;

    std::ofstream out("out.txt");
    out << s;
    out.close();

    Matrix z = Matrix::zero(1, 5);
    std::cout << z;

    Matrix u = Matrix::unit(4);
    std::cout << u;

 
    

    return 0;
}