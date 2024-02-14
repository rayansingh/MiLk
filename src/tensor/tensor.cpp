#include "../../include/tensor/tensor.hpp"
#include <iostream>

using namespace std;

Tensor::Tensor(int dim, int* dims): dim(dim) {
    size = 1;
    this->dims = new int[dim];
    unsigned i;
    for(i = 0; i < dim; i++){
        size *= dims[i];
        this->dims[i] = dims[i];
    }
    this->data = new float[size];

    for(i = 0; i < size; i++){
        this->data[i] = 0.0;
    }
}

Tensor::Tensor(float* data, int dim, int* dims){
    size = 1;
    unsigned i;
    for(i = 0; i < dim; i++){
        size *= dims[i];
        this->dims[i] = dims[i];
    }
    this->data = new float[size];

    for(i = 0; i < size; i++){
        this->data[i] = data[i];
    }
}

Tensor::Tensor(Tensor& t){
    if(data != (float*)NULL){
        delete data;
    }
    unsigned i;
    size = 1;

    this->dim = t.dim;
    this->size = t.size;

    for(i = 0; i < dim; i++){
        this->dims[i] = t.dims[i];
    }

    this->data = new float[size];

    for(i = 0; i < size; i++){
        this->data[i] = t.data[i];
    }
}

Tensor::~Tensor(){
    delete dims;
    delete data;
}

Tensor* Tensor::operator+(Tensor& other){
    if(dim != other.dim){
        return NULL;
    }

    unsigned i;
    for(i = 0; i < dim; i++){
        if(dims[i] != other.dims[i]){
            return NULL;
        }
    }

    Tensor* sum = new Tensor(dim,dims);

    for(i = 0; i < size; i++){
        sum->data[i] = this->data[i] + other.data[i];
    }

    return sum;
}

Tensor* Tensor::operator-(Tensor& other){
    if(dim != other.dim){
        return NULL;
    }

    unsigned i;
    for(i = 0; i < dim; i++){
        if(dims[i] != other.dims[i]){
            return NULL;
        }
    }

    Tensor* sum = new Tensor(dim,dims);

    for(i = 0; i < size; i++){
        sum->data[i] = this->data[i] - other.data[i];
    }

    return sum;
}

Tensor* Tensor::operator*(Tensor& other){
    if(dim != other.dim || dim != 2){
        return NULL;
    }

    // Check that dimensions are valid
    if(dims[1] != other.dims[0]){
        std::cout<<"Invalid Dimensions for Matrix Multiplication"<<std::endl;
        return nullptr;
    }

    int set_dims[2] = {dims[0],other.dims[1]};
    Tensor* product = new Tensor(2,set_dims);

    unsigned a_row,a_col,b_col;
    float sum;

    for(a_row = 0; a_row < dims[0]; a_row++){
        for(b_col = 0; b_col < other.dims[1]; b_col++){
            sum = 0.0;
            for(a_col = 0; a_col < dims[1]; a_col++){
                sum += data[a_row*dims[1] + a_col]*other.data[a_col*other.dims[1] + b_col];
            }
            product->set(sum,a_row*other.dims[1] + b_col);
        }
    }

    return product;
}

float Tensor::get(int coords){
    return data[coords];
}

float Tensor::get(int* coords, int num_coords){
    int pos = 0;
    unsigned i;
    for(i = 0; i < num_coords; i++){
        pos += dims[dim - i - 1]*coords[i];
    }
    return data[pos];
}

void Tensor::set(float value, int coords){
    data[coords] = value;
}

void Tensor::set(float value, int* coords, int num_coords){
    int pos = 0;
    unsigned i;
    for(i = 0; i < num_coords; i++){
        pos += dims[dim - i - 1]*coords[i];
    }
    data[pos] = value;
}

void Tensor::print(){
    // figure this out for > 2 dimensions
    std::cout<<std::endl;
    unsigned i,j;

    if(dim == 1){
        std::cout<<"[";
        for(i = 0; i < size; i++){
            std::cout<<data[i];
            if(i < size-1){
                std::cout<<",";
            }
        }
        std::cout<<"]";
    } else {
        std::cout<<"[";
        for(i = 0; i < dims[0]; i++){
            if(i > 0){
                std::cout<<" ";
            }
            std::cout<<"[";
            for(j = 0; j < dims[1]; j++){
                std::cout<<data[i * dims[1] + j];
                if(j < dims[1]-1){
                    std::cout<<",";
                }
            }
            std::cout<<"]";
            if(i < dims[0]-1){
                std::cout<<","<<std::endl;;
            }
        }
        std::cout<<"]";
    }
    
    std::cout<<std::endl;
}