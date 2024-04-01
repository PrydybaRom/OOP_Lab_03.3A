#include "VectorN.h"
#include <iostream>
#include "VectorN_Close.h"
#include "VectorN_Open.h"

int main()
{
    double values1[] = { 1.0, 2.0, 3.0 };
    double values2[] = { 4.0, 5.0, 6.0 };

    // VectorN_Close demonstration
    VectorN_Close vec_close1(3, values1);
    VectorN_Close vec_close2(3, values2);

    std::cout << "VectorN_Close demonstration:" << std::endl;
    std::cout << "Vector 1: " << vec_close1 << std::endl;
    std::cout << "Vector 2: " << vec_close2 << std::endl;

    // Addition
    VectorN_Close sum_close = vec_close1 + vec_close2;
    std::cout << "Sum: " << sum_close << std::endl;

    // Subtraction
    VectorN_Close diff_close = vec_close1 - vec_close2;
    std::cout << "Difference: " << diff_close << std::endl;

    // Multiplication
    VectorN_Close mul_close = vec_close1 * vec_close2;
    std::cout << "Dot product: " << mul_close << std::endl;

    // Input
    std::cout << "Enter size of vector and its elements: ";
    std::cin >> vec_close1;
    std::cout << "New vector: " << vec_close1 << std::endl;


    double values3[] = { 10.0, 20.0, 30.0 };
    double values4[] = { 14.0, 35.0, 25.0 };

    // VectorN_Open demonstration
    VectorN_Open vec_open1(3, values3);
    VectorN_Open vec_open2(3, values4);

    std::cout << "VectorN_Open demonstration:" << std::endl;
    std::cout << "Vector 1: " << vec_open1 << std::endl;
    std::cout << "Vector 2: " << vec_open2 << std::endl;

    // Addition
    VectorN_Open sum_open = vec_open1 + vec_open2;
    std::cout << "Sum: " << sum_open << std::endl;

    // Subtraction
    VectorN_Open diff_open = vec_open1 - vec_open2;
    std::cout << "Difference: " << diff_open << std::endl;

    // Multiplication
    VectorN_Open mul_open = vec_open1 * vec_open2;
    std::cout << "Dot product: " << mul_open << std::endl;

    return 0;

    
}

