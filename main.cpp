#include <iostream>
#include "include/matrix/matrix.hpp"
#include "include/tensor/tensor.hpp"

using namespace std;

int main(){
    int dims_t1[2] = {5,3};
    int dims_t2[2] = {3,2};

    Tensor* t1 = new Tensor(2,dims_t1);
    Tensor* t2 = new Tensor(2,dims_t2);

    t1->set(1,2);
    t1->print();

    t2->set(1, 4);
    t2->print();

    Tensor* t3 = (*t1)*(*t2);
    t3->print();

    delete t1;
    delete t2;
    delete t3;
}