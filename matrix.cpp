#include "matrix.h"
#include <iostream>
#include <fstream>
#include <ostream>

template <typename T>
void Matrix<T> :: get_matrix() //считать
{   
    if (m==0 && n ==0){
        std::cin >> m;
        std::cin >> n;
    }
    for (int i = 0; i < m; ++ i)
    {
        for (int j = 0; j < n; ++ j)
        {
            std::cin >> data_arr[i][j];
        }
    }
}

template <typename T>
void Matrix<T> :: print_matrix() // вывести
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) std::cout << data_arr[i][j] << " ";
        std::cout << std::endl;
    } 
    std::cout << std::endl;
}  

// операторы ------------------------------------------------------------------

template <typename T>
std::istream& operator>>(std::istream& in, const
Matrix<T>& matrix) //считать !!! для матрицы с заданным размером !!!
{   
    for (int i = 0; i < matrix.m; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            in >> matrix.data_arr[i][j];
        }
    }
    return in;
}

// std::ifstream& operator>>(std::ifstream& in, Matrix& matrix) //считать 
// {   
//     if (matrix.m == 0 && matrix.n == 0){
//         in >> matrix.m;
//         in >> matrix.n;
//     }
//     for (int i = 0; i < matrix.m; ++i)
//     {
//         for (int j = 0; j < matrix.n; ++j)
//         {
//             in >> matrix.data_arr[i][j];
//         }
//     }
//     return in;
// }

template <typename T>
std::ostream& operator<< (std::ostream& out, const Matrix<T>& matrix) //вывести
{   
    for (int i = 0; i < matrix.m; ++i)
    {
        for (int j = 0; j < matrix.n; ++j)
        {
            out << matrix.data_arr[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
Matrix<T> operator+(const Matrix<T> a, const Matrix<T> b) //сложение
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
        return Matrix(T(0),T(0));
    }
};

template <typename T>
Matrix<T> operator-(const Matrix<T> a, const Matrix<T> b) // вычитание
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
        return Matrix(T(0),T(0));
    }
};

template <typename T>
Matrix<T> operator*(const Matrix<T> a, const Matrix<T> b) // умножение
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

template <typename T>
Matrix<T> operator*(const Matrix<T> a, T numb) // умножение на число
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

template <typename T>
bool operator==(const Matrix<T> a, const Matrix<T> b) // равенство
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

template <typename T>
bool operator==(const Matrix<T> a, T numb) // равенство со скаляром
{
    for (int i = 0; i < a.m; ++ i)
    {
        for (int j = 0; j < a.n; ++ j) 
        {   
            if (i == j)
            {
                if (a.data_arr[i][j] ==  numb) continue;
                else return false;
            }
            else
            {
                if (a.data_arr[i][j] ==  0) continue;
                else return false;
            }
        }
    }
    return true;
}

template <typename T>
bool operator!=(const Matrix<T> a, const Matrix<T> b) // неравенство
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

template <typename T>
bool operator!=(const Matrix<T> a, T numb) // неравенство со скаляром
{
    if (a == numb) return false;
    else return true;
}

// элементаные преобразования --------------------------------------------------
template <typename T>
void Matrix<T> :: change_ft(int str_1, int str_2) // первый тип
{   
    double  temp[n] = {0};
    for (int i = 0; i < n; ++i) temp[i] = data_arr[str_1-1][i];
    for (int i = 0; i < n; ++i) data_arr[str_1 - 1][i] = data_arr[str_2 - 1][i];
    for (int i = 0; i < n; ++i) data_arr[str_2 - 1] [i] = temp[i];
    
}

template <typename T>
void Matrix<T> :: change_st(int str_1, T  multiplier ) // второй тип
{
    for (int i = 0; i < n; ++i) data_arr[str_1-1][i] = data_arr[str_1-1][i] * multiplier ;
}

template <typename T>
void Matrix<T> :: change_tt(int str_1, int str_2, T  multiplier) // третий тип
{
    for (int i = 0; i < n; ++i) data_arr[str_1-1][i] = data_arr[str_1-1][i] + data_arr[str_2-1][i] * multiplier;
}

// нахождение определителя -----------------------------------------------------
template <typename T>
T  Matrix<T> :: determinant()
{   
    T  det = 0;
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
template <typename T>
Matrix<T> Matrix<T> :: alg_compl() // матрица алгебраических дополнений
{   
    Matrix ansver(m, n);
    if (m == n)
    {
        for (int mat_i = 0; mat_i < m; ++mat_i)
        {
            for (int mat_j = 0; mat_j < n; ++mat_j)
            {   
                T  one;
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

template <typename T>
Matrix<T> Matrix<T> :: transposed() // транспонирование
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

template <typename T>
Matrix<T> Matrix<T>::reversed()
{
    Matrix x(m, n);
    try
    {
        if (determinant() == 0)
        {
            throw std::runtime_error("sorry, it has no reversive one");
        }
        x = ((alg_compl()).T())*(double(1)/determinant());
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        x = Matrix(0, 0);
    }
    return x;
}

template <typename T>
Matrix<T> operator!(Matrix<T> a)
{
    Matrix x(a.m, a.n);
    try
    {
         
        if (a.determinant() == 0)
        {
            throw std::runtime_error("sorry, it has no reversive one");
        }
        x = ((a.alg_compl()).T())*(double(1)/a.determinant());
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        x = Matrix(0, 0);
    }
    return x;
}
 