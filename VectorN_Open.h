#pragma once
#include "VectorN.h"
using namespace std;

class VectorN_Open : public VectorN {
public:
    using VectorN::VectorN;

    VectorN_Open& operator=(const VectorN_Open& other);
    VectorN_Open operator+(const VectorN_Open& other) const;
    VectorN_Open operator-(const VectorN_Open& other) const;
    VectorN_Open operator*(const VectorN_Open& other) const;

    VectorN_Open& operator++();
    VectorN_Open operator++(int);
    VectorN_Open& operator--();
    VectorN_Open operator--(int);

    operator string() const;
    
};

