#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"


int main()
{
    Geom::Point A{0, 1, 2};
    Geom::Point B{-1, 2, 1};
    
    Geom::SwapPoints(A, B);
    if (A == Geom::Point{-1, 2, 1} && B == Geom::Point{0, 1, 2})
        std::cout << "Test 1:\t Passed" << std::endl;
    else
        std::cout << "Test 1:\t Failed" << std::endl;
    return 0;
}