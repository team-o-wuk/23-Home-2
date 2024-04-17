#include <iostream>
#include "matrix.h"

int main()
{
    
    Matrix a(2, 2);
    a.get_matrix();

    Matrix b(2, 2);
    b.get_matrix();

    // Matrix c(2, 3);
    // c.get_matrix();

    (a+b).print_matrix();
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