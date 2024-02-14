#include <iostream>
#include "include/matrix/matrix.hpp"
#include "include/tensor/tensor.hpp"

using namespace std;

int main(){
    int dims[2] = {5,3};

    Tensor* t1 = new Tensor(2,dims);
    Tensor* t2 = new Tensor(2,dims);

    t1->set(0.212,4);
    t1->print();

    t2->set(0.1122, 4);
    t2->print();

    Tensor* t3 = *t1-*t2;
    t3->print();

    delete t1;
    delete t2;
    delete t3;
}