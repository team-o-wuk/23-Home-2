#include <iostream>
// using namespace std; 
 

class Matrix
{
    int m;
    int n; 
    double  **data_arr;

    public:
        Matrix()
            : m(0), n(0), data_arr(NULL) //конструктор
        {
        }

        Matrix(int lins, int tabs) //корструктор с параметрами
            :m(lins), n(tabs), data_arr(new double  *[m])
        {
            for (int i = 0; i < m; ++ i)
            {
                data_arr[i] = new double [n];
                for (int j = 0; j < n; ++ j) data_arr[i][j] = 0;
            }
        }
 
        Matrix(const Matrix &other) //конструктор копирования
            : m(other.m), n(other.n), data_arr(new double  *[m])
        {
            for (int i = 0; i < m; ++ i)
            {
                data_arr[i] = new double [n];
                for (int j = 0; j < n; ++ j) data_arr[i][j] = other.data_arr[i][j];
            }
            
        }

        ~Matrix() //деструктор
       {
            if (n) for (int i = 0; i < m; i++) delete[] data_arr[i];
            if (m) delete[] data_arr;

            m = n = 0;
            data_arr = NULL;
        }

        void get_matrix() //считать
        {
            double  element;
            for (int i = 0; i < m; ++ i)
            {
                for (int j = 0; j < n; ++ j)
                {
                    std::cin >> element;
                    data_arr[i][j] = element;
                }
            }
        }

        void print_matrix() // вывести
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++) std::cout << data_arr[i][j] << " ";
                std::cout << std::endl;
            } 
            std::cout << std::endl;
        }  
        
        // операторы ------------------------------------------------------------------
        friend Matrix operator+(const Matrix a, const Matrix b) //сложение
        {
            if (a.m == b.m && a.n == b.n)
            {   
                Matrix c(a.m, a.n);
                for (int i = 0; i < b.m; ++ i)
                {
                    for (int j = 0; j < a.n; ++ j) c.data_arr[i][j] = a.data_arr[i][j] + b.data_arr[i][j];
                }
                return c;
            }
            else 
            {
                std::cerr << "sorry, I can't add them up" << std::endl;
                return Matrix(0,0);
            }
        };

        friend Matrix operator-(const Matrix a, const Matrix b) // вычитание
        {
            if (a.m == b.m && a.n == b.n)
            {   Matrix c(a.m, a.n);
                for (int i = 0; i < b.m; ++ i)
                {
                    for (int j = 0; j < a.n; ++ j) c.data_arr[i][j] = a.data_arr[i][j] - b.data_arr[i][j];
                }
                return c;
            }
            else 
            {   
                std::cerr << "sorry, I can't substract them" << std::endl;
                return Matrix(0,0);
            }
        };
        
        friend Matrix operator*(const Matrix a, const Matrix b) // умножение
        {
            if (a.n == b.m)
            {    
                Matrix c(a.m, b.n);
                for (int i = 0; i < a.m; ++ i)
                {
                    for (int j = 0; j < b.n; ++ j) 
                    {
                        for (int k = 0; k < a.n; ++ k)
                        {
                            c.data_arr[i][j] = c.data_arr[i][j] + a.data_arr[i][k] * b.data_arr[k][j];
                        }
                    }
                }
                return c;
            }  
            else 
            {   
                std::cerr << "sorry, I can't multiply them" << std::endl;
                return Matrix(0,0);
            }    
        }

        friend Matrix operator*(const Matrix a, double numb) // умножение на число
        {
            Matrix c(a.m, a.n);         
            for (int i = 0; i < a.m; ++ i)
            {
                for (int j = 0; j < a.n; ++ j) 
                {
                    c.data_arr[i][j] = a.data_arr[i][j] * numb;
                }
            }
            return c;
        }

        friend bool operator==(const Matrix a, const Matrix b) // равенство
        {
            if (a.m == b.m && a.n == b.n)
            {    
                for (int i = 0; i < a.m; ++ i)
                {
                    for (int j = 0; j < b.n; ++ j) 
                    {
                        if (a.data_arr[i][j] == b.data_arr[i][j]) continue;
                        else return false;
                    }
                }
                return true;
            }
            else return false;
        }

        friend bool operator!=(const Matrix a, const Matrix b) // неравенство
    {
        if (a.m == b.m && a.n == b.n)
        {    
            for (int i = 0; i < a.m; ++ i)
            {
                for (int j = 0; j < b.n; ++ j) 
                {
                    if (a.data_arr[i][j] == b.data_arr[i][j]) continue;
                    else return true;
                }
            }
            return false;
        }
        else return true;
    }

        // элементаные преобразования --------------------------------------------------
        void change_ft(int str_1, int str_2) // первый тип
        {   
            double  temp[n] = {0};
            for (int i = 0; i < n; ++i) temp[i] = data_arr[str_1-1][i];
            for (int i = 0; i < n; ++i) data_arr[str_1 - 1][i] = data_arr[str_2 - 1][i];
            for (int i = 0; i < n; ++i) data_arr[str_2 - 1] [i] = temp[i];
            
        }

        void change_st(int str_1, double  multiplier ) // второй тип
        {
            for (int i = 0; i < n; ++i) data_arr[str_1-1][i] = data_arr[str_1-1][i] * multiplier ;
        }

        void change_tt(int str_1, int str_2, double  multiplier) // третий тип
        {
            for (int i = 0; i < n; ++i) data_arr[str_1-1][i] = data_arr[str_1-1][i] + data_arr[str_2-1][i] * multiplier;
        }
        
        // нахождение определителя -----------------------------------------------------
        double  determinant()
        {   
            double  det = 0;
            if (m == n)
            {
                if (m == 1) det = data_arr[0][0];
                else
                {
                    for (int element = 0; element < n; ++element)
                    {
                        Matrix x(m-1, n-1);
                        for(int i = 0; i<x.m; ++i)
                        {
                            for(int j = 0; j<x.m; ++j)
                            {
                                if (j < element)
                                {
                                    x.data_arr[i][j] = data_arr[i+1][j];
                                }
                                else if (j >= element)
                                {
                                    x.data_arr[i][j] = data_arr[i+1][j+1];
                                }
                            }
                        }
                        if (element % 2 == 0) det += data_arr[0][element] * x.determinant();
                        else det -= data_arr[0][element] * x.determinant();
                    }
                }
            }
            else
            {
                std::cerr << "sorry, it has no determinant" << std::endl;
            }
            return det;
        }

        // нахождение обратной матрицы -------------------------------------------------
        Matrix alg_compl() // матрица алгебраических дополнений
        {   
            Matrix ansver(m, n);
            if (m == n)
            {
                for (int mat_i = 0; mat_i < m; ++mat_i)
                {
                    for (int mat_j = 0; mat_j < n; ++mat_j)
                    {   
                        double  one;
                        if ((mat_i + mat_j)%2 == 0) one = 1;
                        else one = -1;
                            
                        Matrix x(m-1, n-1);
                        for(int i = 0; i < x.m; ++i)
                        {
                            for(int j = 0; j < x.n; ++j)
                            {
                                if (i < mat_i && j < mat_j)   x.data_arr[i][j] = data_arr[i][j];
                                if (i < mat_i && j >= mat_j)  x.data_arr[i][j] = data_arr[i][j+1];
                                if (i >= mat_i && j < mat_j)  x.data_arr[i][j] = data_arr[i+1][j];
                                if (i >= mat_i && j >= mat_j) x.data_arr[i][j] = data_arr[i+1][j+1];
                            }   
                        }
                        ansver.data_arr[mat_i][mat_j] = x.determinant() * one;
                    }           
                }

            }
            else
            {
                std::cerr << "sorry, it does not exist" << std::endl;
            }
            return ansver;
        }   
               
        Matrix T() // транспонирование
        {
            Matrix x(n, m);
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    x.data_arr[i][j] = data_arr[j][i];
                }
            } 
            return x;
        }

        Matrix reversive()
        {
            Matrix x(m, n);
            if (determinant() != 0 && determinant() !=100001)
            {
                x = ((alg_compl()).T())*(double(1)/determinant());
            }
            else
            {
                std::cerr << "sorry, it has no reversive one";
                x = Matrix(0, 0);
            }
            return x;
        }     
};


int main()
{
    /*
    Matrix a(4, 4);
    a.get_matrix();

    Matrix b(4, 4);
    b.get_matrix();

    Matrix c(2, 3);
    c.get_matrix();

    (a+b).print_matrix();
    (a+c).print_matrix();

    (a-b).print_matrix();
    (a-c).print_matrix();

    (a*b).print_matrix();
    (a*c).print_matrix();    
    (a*2).print_matrix();
    (c*0.5).print_matrix();

    std::cout << (a==b) << std::endl;
    std::cout << (a!=c) << std::endl;
  
    a.change_st(2, 3);
    a.change_ft(1, 2);
    a.change_tt(3, 2, 2);
    a.print_matrix();
   
    Matrix A(3, 3);
    A.get_matrix();
 
    std::cout << A.determinant() << std::endl;
    (A*2).print_matrix();
    A.reversive().print_matrix();
    */

    return 0;
}