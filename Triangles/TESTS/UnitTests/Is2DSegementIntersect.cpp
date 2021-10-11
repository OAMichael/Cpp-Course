#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"

int main()
{
    //1 - intersect
    Geom::Segment A{1, 1, 0, -1, -1, 0};
    Geom::Segment B{-1, 1, 0, 1, -1, 0};

    if(Geom::Is2DSegmIntersect(A, B))
        std::cout << "Test 1:\t Passed" << std::endl;
    else
        std::cout << "Test 1:\t Failed" << std::endl;
    
    //2 - intersect
    Geom::Segment C{-1, -1, -1, 2, 2, 2};
    Geom::Segment D{-1, 1, 0, 1, -1, 0};

    if(Geom::Is2DSegmIntersect(C, D))
        std::cout << "Test 2:\t Passed" << std::endl;
    else
        std::cout << "Test 2:\t Failed" << std::endl;
    
    //3 - intersect
    Geom::Segment E{1, 1, 1, -1, -1, -1};
    Geom::Segment F{2, 2, 2, -2, -2, -2};

    if(Geom::Is2DSegmIntersect(E, F))
        std::cout << "Test 3:\t Passed" << std::endl;
    else
        std::cout << "Test 3:\t Failed" << std::endl;
    
    //4 - not intersect
    Geom::Segment G{1, 1, 1, 2, 2, 2};
    Geom::Segment H{-1, -1, -1, -2, -2, -2};

    if(!Geom::Is2DSegmIntersect(G, H))
        std::cout << "Test 4:\t Passed" << std::endl;
    else
        std::cout << "Test 4:\t Failed" << std::endl;
    
    //5 - intersect
    Geom::Segment I{0, 0, 0, 1, 0, 0};
    Geom::Segment J{0, 0, 0, -1, 0, 0};

    if(Geom::Is2DSegmIntersect(I, J))
        std::cout << "Test 5:\t Passed" << std::endl;
    else
        std::cout << "Test 5:\t Failed" << std::endl;
    
    //6 - not intersect
    Geom::Segment K{1, 1, 0, 1, 2, 0};
    Geom::Segment L{1, -1, 0, 1, -2, 0};

    if(!Geom::Is2DSegmIntersect(K, L))
        std::cout << "Test 6:\t Passed" << std::endl;
    else
        std::cout << "Test 6:\t Failed" << std::endl;
    
    //7 - intersect
    Geom::Segment M{1, 1, 0, 1, -1, 0};
    Geom::Segment N{1, 1, 0, 1, -1, 0};

    if(Geom::Is2DSegmIntersect(M, N))
        std::cout << "Test 7:\t Passed" << std::endl;
    else
        std::cout << "Test 7:\t Failed" << std::endl;
    
    //8 - intersect
    Geom::Segment P{1, 1, 0, 1, 4, 0};
    Geom::Segment Q{1, 2, -1, 1, 0, 4};

    if(Geom::Is2DSegmIntersect(P, Q))
        std::cout << "Test 8:\t Passed" << std::endl;
    else
        std::cout << "Test 8:\t Failed" << std::endl;
    
    //9 - not intersect
    Geom::Segment R{1, 1, 0, 1, 4, 0};
    Geom::Segment S{1, 0, -1, 1, 0, 4};

    if(!Geom::Is2DSegmIntersect(R, S))
        std::cout << "Test 9:\t Passed" << std::endl;
    else
        std::cout << "Test 9:\t Failed" << std::endl;
    
    //10 - not intersect
    Geom::Segment T{1, 1, 0, 1, 4, 0};
    Geom::Segment U{1, 0, -1, 1, 0, -1};

    if(!Geom::Is2DSegmIntersect(T, U))
        std::cout << "Test 10: Passed" << std::endl;
    else
        std::cout << "Test 10: Failed" << std::endl;


    return 0;
}