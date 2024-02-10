#ifndef matrix_hpp
#define matrix_hpp

#include <stdlib.h>
#include <iostream>

template <typename T>
class Matrix{
    uint32_t m;
    uint32_t n;
    T** values;

    private:

    void allocate_values(){
        values = new T*[m];
        for(unsigned i = 0; i < m; i++){
            values[i] = new T[n];
        }
    }

    void deallocate_values(){
        for(unsigned i = 0; i < m; i++){
            delete values[i];
        }
        delete values;
    }

    public:

    void zero(){
        unsigned i,j;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                values[i][j] = 0;
            }
        }
    }

    T get(int i, int j){
        return values[i][j];
    }

    void set(int i, int j, T to_set){
        values[i][j] = to_set;
    }

    void print(){
        unsigned i,j;

        std::cout<<std::endl<<"[";
        for(i = 0; i < m; i++){
            if(i > 0){
                std::cout<<" ";
            }
            std::cout<<"[";
            for(j = 0; j < n; j++){
                std::cout<<values[i][j];
                if(j < n-1){
                    std::cout<<",";
                }
            }
            std::cout<<"]";
            if(i < m-1){
                std::cout<<std::endl;
            }
        }
        std::cout<<"]"<<std::endl;
    }

    public:

    Matrix(int m, int n) : m(m), n(n){
        allocate_values();
        zero();
    }

    Matrix(int m, int n, T** values): m(m), n(n){
        allocate_values();

        unsigned i,j;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                this->values[i][j] = values[i][j];
            }
        }
    }

    ~Matrix(){
        deallocate_values();
    }

    Matrix<T>* operator*(const Matrix<T>& other) const{
        // Check that dimensions are valid
        if(n != other.m){
            std::cout<<"Invalid Dimensions"<<std::endl;
            return nullptr;
        }

        Matrix<T>* C = new Matrix<T>(m,other.n);

        unsigned a_row,a_col,b_col;
        T sum;

        for(a_row = 0; a_row < m; a_row++){
            for(b_col = 0; b_col < other.n; b_col++){
                sum = 0;
                for(a_col = 0; a_col < n; a_col++){
                    sum += values[a_row][a_col]*other.values[a_col][b_col];
                }
                C->set(a_row,b_col,sum);
            }
        }

        return C;
    }
};

#endif
