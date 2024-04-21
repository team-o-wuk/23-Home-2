#include <iostream>
#include <fstream>
#include <ostream>
#include "matrix.h"

 

int main()
{
     

    Matrix<double> m(3,3);
  

    std::ifstream in("in.txt");
    if (in.is_open())
    {
        in >> m;
        in.close();
    }

    
    Matrix<double> r = !m;

    std::cout << m;
    std::cout << r;

    Matrix<double> s = m+r;
    std::cout << s;

    std::ofstream out("out.txt");
    out << s;
    out.close();

    Matrix<int> z = Matrix<int>::zero(1, 5);
    std::cout << z;

    Matrix<int> u = Matrix<int>::unit(4);
    std::cout << u;

    return 0;
}