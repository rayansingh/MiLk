#ifndef tensor_hpp
#define tensor_hpp

class Tensor {
    public:
    float* data;
    int dim;
    int* dims;
    int size;


    Tensor(int dim, int* dims);
    Tensor(float* data, int dim, int* dims);
    Tensor(Tensor& t);

    ~Tensor();

    Tensor* operator+(Tensor& other);
    Tensor* operator-(Tensor& other);
    Tensor* operator*(Tensor& other);

    float get(int coords);
    float get(int* coords, int num_coords);

    void set(float value, int coords);
    void set(float value, int* coords, int num_coords);

    void print();
};

#endif
