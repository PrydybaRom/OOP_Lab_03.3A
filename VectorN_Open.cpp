#include "VectorN_Open.h"
#include <iostream>
#include <sstream>

// operator =
VectorN_Open& VectorN_Open::operator=(const VectorN_Open& other) {
    if (this == &other)
        return *this;

    int N = other.N;
    double* otherA = other.a;
    double* newA = new double[N];

    for (int i = 0; i < N; ++i) {
        newA[i] = otherA[i];
    }
    delete[] a;
    a = newA;
    N = other.N;

    return *this;
}

// operator +
VectorN_Open VectorN_Open::operator+(const VectorN_Open& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for addition");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] + other.a[i];
    VectorN_Open result(N, resultValues);
    delete[] resultValues;
    return result;
}

// operator -
VectorN_Open VectorN_Open::operator-(const VectorN_Open& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for subtraction");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] - other.a[i];
    VectorN_Open result(N, resultValues);
    delete[] resultValues;
    return result;
}

// operator *
VectorN_Open VectorN_Open::operator*(const VectorN_Open& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for dot product");

    double result = 0;
    for (int i = 0; i < N; ++i)
        result += a[i] * other.a[i];

    double* resultValues = new double[1];
    resultValues[0] = result;
    VectorN_Open resultVector(1, resultValues);
    delete[] resultValues;

    return resultVector;
}

// ++
VectorN_Open& VectorN_Open::operator++() {
    for (int i = 0; i < N; ++i)
        ++a[i];
    return *this;
}

// ++int
VectorN_Open VectorN_Open::operator++(int) {
    VectorN_Open temp(*this);
    operator++();
    return temp;
}

// --
VectorN_Open& VectorN_Open::operator--() {
    for (int i = 0; i < N; ++i)
        --a[i];
    return *this;
}

// --int
VectorN_Open VectorN_Open::operator--(int) {
    VectorN_Open temp(*this);
    operator--();
    return temp;
}

// STRING
VectorN_Open::operator string() const {
    stringstream oss;
    oss << " N = " << N << endl;
    oss << " a = ";
    for (int i = 0; i < N; ++i) {
        oss << a[i];
        if (i != N - 1)
            oss << ", ";
    }
    oss << endl;
    return oss.str();
}
