#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"


int main()
{
    Geom::Point<double> A{0.0, 1.0, 2.0};
    Geom::Point<double> B{-1.0, 2.0, 1.0};
    
    Geom::SwapPoints<double>(A, B);
    if (A == Geom::Point<double>{-1, 2, 1} && B == Geom::Point<double>{0, 1, 2})
        std::cout << "Test 1:\t Passed" << std::endl;
    else
        std::cout << "Test 1:\t Failed" << std::endl;
    return 0;
}