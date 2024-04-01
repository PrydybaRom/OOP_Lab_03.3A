#include "VectorN.h"
#include <iostream>
#include <string>
#include <sstream>

// Конструктори
VectorN::VectorN() : N(0), a(nullptr) {}
VectorN::VectorN(int size, double* values) : N(size), a(new double[size]) {
    for (int i = 0; i < N; ++i) {
        a[i] = values[i];
    }
}
VectorN::VectorN(const VectorN& other) : N(other.N), a(new double[other.N]) {
    for (int i = 0; i < N; ++i) {
        a[i] = other.a[i];
    }
}
VectorN::~VectorN() {
    delete[] a;
}



// SET GET
void VectorN::SetA(double* values) {
    delete[] a;
    a = new double[N];
    for (int i = 0; i < N; ++i) {
        a[i] = values[i];
    }
}
void VectorN::SetN(int value) {
    N = value;
}

int VectorN::GetN() const { return N; }
double* VectorN::GetA() const { return a; }



// OPEARTOR << >>
std::ostream& operator<<(std::ostream& out, const VectorN& vector) {
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
std::istream& operator>>(std::istream& in, VectorN& vector) {
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

VectorN::operator string() const {
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
