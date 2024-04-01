#pragma once
#include <iostream>
using namespace std;

class VectorN {
protected:
    int N;
    double* a;
public:
    // ŒÕ—“–” “Œ–»
    VectorN();
    VectorN(int size, double* values);
    VectorN(const VectorN& other);
    ~VectorN();

    // SET GET
    void SetN(int value);
    void SetA(double* value);
    int GetN() const;
    double* GetA() const;

    

    //OPERATOR << >> string
    friend ostream& operator<<(ostream& out, const VectorN& vector);
    friend istream& operator>>(istream& in, VectorN& vector);

    operator string() const;

};


