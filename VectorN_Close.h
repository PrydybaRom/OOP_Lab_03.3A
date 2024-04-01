#pragma once
#include "VectorN.h"
using namespace std;

class VectorN_Close : private VectorN {
public:
    using VectorN::VectorN;

    VectorN_Close& operator=(const VectorN_Close& other);
    VectorN_Close operator+(const VectorN_Close& other) const;
    VectorN_Close operator-(const VectorN_Close& other) const;
    VectorN_Close operator*(const VectorN_Close& other) const;

    VectorN_Close& operator++();
    VectorN_Close operator++(int);
    VectorN_Close& operator--();
    VectorN_Close operator--(int);

    friend ostream& operator<<(ostream& out, const VectorN_Close& vector);
    friend istream& operator>>(istream& in, VectorN_Close& vector);

    operator string() const;

};


