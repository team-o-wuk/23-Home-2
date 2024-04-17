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

    void get_matrix();
    void print_matrix();
    friend Matrix operator+(const Matrix a, const Matrix b);
    friend Matrix operator-(const Matrix a, const Matrix b);
    friend Matrix operator*(const Matrix a, const Matrix b);
    friend Matrix operator*(const Matrix a, double numb);
    friend bool operator==(const Matrix a, const Matrix b);
    friend bool operator!=(const Matrix a, const Matrix b);
    void change_ft(int str_1, int str_2);
    void change_st(int str_1, double  multiplier );
    void change_tt(int str_1, int str_2, double  multiplier);
    double  determinant();
    Matrix alg_compl();
    Matrix T();
    Matrix reversive();



};
#endif

 