#include <iostream>
#include "include/matrix/matrix.hpp"

using namespace std;

int main(){
    int a_m = 2;
    int a_n = 3;
    int b_m = 3;
    int b_n = 4;

    Matrix<float> A = Matrix<float>(a_m,a_n);
    Matrix<float> B = Matrix<float>(b_m,b_n);

    unsigned i,j;
    for(i = 0; i < a_m; i++){
        for(j = 0; j < a_n; j++){
            A.set(i,j,i);
        } 
    }
    for(i = 0; i < b_m; i++){
        for(j = 0; j < b_n; j++){
            B.set(i,j,2);
        } 
    }

    A.print();
    B.print();
    Matrix<float>* C = A*B;
    C->print();

    std::cout<<std::endl;
    delete C;
}