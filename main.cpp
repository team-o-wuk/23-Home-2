#include <iostream>
#include <fstream>
#include <ostream>
#include "matrix.h"

 

int main()
{
    // Matrix n;
    // std::cin >> n;
    // n.print_matrix();

    // Matrix m(3,3);
    // Matrix m;

    // std::ifstream in("in.txt");
    // if (in.is_open())
    // {
    //     in >> m;
    //     in.close();
    // }

    
    // m.print_matrix();
    // std::cout << m;

    // if (m == 3) std::cout << "lol yes";
    // else std::cout << "noooo";
    // std::cout << (m == 3);
    // std::ofstream f("out.txt");
    // if (f.is_open())
    // {
    //     f << m;
    //     f.close();
    // }

    Matrix z = Matrix::zero(1, 5);
    std::cout << z;

    Matrix u = Matrix::unit(4);
    std::cout << u;

    // Matrix a(2, 2);
    // a.get_matrix();

    // Matrix b(2, 2);
    // b.get_matrix();

    // Matrix c(2, 3);
    // c.get_matrix();

    // (a+b).print_matrix();
    // (a+c).print_matrix();

    // (a-b).print_matrix();
    // (a-c).print_matrix();

    // (a*b).print_matrix();
    // (a*c).print_matrix();    
    // (a*2).print_matrix();
    // (c*0.5).print_matrix();

    // std::cout << (a==b) << std::endl;
    // std::cout << (a!=c) << std::endl;
  
    // a.change_st(2, 3);
    // a.change_ft(1, 2);
    // a.change_tt(3, 2, 2);
    // a.print_matrix();
   
    // Matrix A(3, 3);
    // A.get_matrix();
 
    // std::cout << A.determinant() << std::endl;
    // (A*2).print_matrix();
    // A.reversive().print_matrix();
    

    return 0;
}