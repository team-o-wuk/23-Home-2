#include <ostream>
#ifndef MATRIX_H
#define MATRIX_H
 

class Matrix
{
    int m;
    int n; 
    double  **data_arr;

    public:
        Matrix()
            : m(0), n(0), data_arr(nullptr) //конструктор
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
            data_arr = nullptr;
        }

        static Matrix zero(int lins, int tabs) // стат метод для нулевой матрицы
        {
        Matrix x(lins, tabs);
        for (int i = 0; i < lins; ++i)
        {
            for (int j = 0; j < tabs; ++j)
            {
                x.data_arr[i][j] = 0;
            }
        }
        return x;
        }

        static Matrix unit(int s) // стат метод для единичной матицы
        {
        Matrix x(s, s);
        for (int i = 0; i < s; ++i)
            {
                x.data_arr[i][i] = 1;
            }
        return x;
        }        

    void get_matrix();
    void print_matrix();

    friend std::ostream& operator<<(std::ostream&,const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);
    friend Matrix operator+(const Matrix a, const Matrix b);
    friend Matrix operator-(const Matrix a, const Matrix b);
    friend Matrix operator*(const Matrix a, const Matrix b);
    friend Matrix operator*(const Matrix a, double numb);
    friend bool operator==(const Matrix a, const Matrix b);
    friend bool operator==(const Matrix a,  int numb);
    friend bool operator!=(const Matrix a, const Matrix b);
    friend bool operator!=(const Matrix a, int numb);

    void change_ft(int str_1, int str_2);
    void change_st(int str_1, double  multiplier );
    void change_tt(int str_1, int str_2, double  multiplier);
    double  determinant();

    Matrix alg_compl();
    Matrix T();
    Matrix reversive();

};
#endif

 