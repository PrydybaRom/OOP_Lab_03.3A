#include "VectorN_Close.h"
#include <iostream>
#include <sstream>

// operator =
VectorN_Close& VectorN_Close::operator=(const VectorN_Close& other) {
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
VectorN_Close VectorN_Close::operator+(const VectorN_Close& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for addition");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] + other.a[i];
    VectorN_Close result(N, resultValues);
    delete[] resultValues;
    return result;
}

// operator -
VectorN_Close VectorN_Close::operator-(const VectorN_Close& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for subtraction");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] - other.a[i];
    VectorN_Close result(N, resultValues);
    delete[] resultValues;
    return result;
}

// operator *
VectorN_Close VectorN_Close::operator*(const VectorN_Close& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for dot product");

    double result = 0;
    for (int i = 0; i < N; ++i)
        result += a[i] * other.a[i];

    double* resultValues = new double[1];
    resultValues[0] = result;
    VectorN_Close resultVector(1, resultValues);
    delete[] resultValues;

    return resultVector;
}

// operator ++
VectorN_Close& VectorN_Close::operator++() {
    for (int i = 0; i < N; ++i)
        ++a[i];
    return *this;
}

// operator ++int
VectorN_Close VectorN_Close::operator++(int) {
    VectorN_Close temp(*this);
    operator++();
    return temp;
}

// operator --
VectorN_Close& VectorN_Close::operator--() {
    for (int i = 0; i < N; ++i)
        --a[i];
    return *this;
}

// operator --int
VectorN_Close VectorN_Close::operator--(int) {
    VectorN_Close temp(*this);
    operator--();
    return temp;
}

// operator << >>
std::ostream& operator<<(std::ostream& out, const VectorN_Close& vector) {
    out << " N = " << vector.N << std::endl;
    out << " a = ";
    for (int i = 0; i < vector.N; ++i) {
        out << vector.a[i];
        if (i != vector.N - 1)
            out << ", ";
    }
    out << std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, VectorN_Close& vector) {
    int size;
    in >> size;
    double* values = new double[size];
    for (int i = 0; i < size; ++i) {
        in >> values[i];
    }
    vector.SetN(size);
    vector.SetA(values);
    delete[] values;
    return in;
}

// String
VectorN_Close::operator string() const {
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
