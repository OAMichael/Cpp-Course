#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../Headers/Geometry.hpp"


int main(int argc, char* argv[])
{   
    int N = 0;
    std::cin >> N;
    assert(std::cin.good());
    
    // Maximum possible coordinate for our space
    double Max = 0.0;

    Geom::Octants::Octant<double> Space{ {-Max, -Max, -Max}, {Max, Max, Max} };
    Space.OctantTriangles.resize(N);

    std::vector<Geom::Triangle<double>>::iterator TrIt = Space.OctantTriangles.begin();

    int i = 0;
    while(i < N)
    {

        Geom::ReadTriangle(*TrIt);

        if(TrIt->MaxCoordinate > Max)
        {
            Max = TrIt->MaxCoordinate;
        }

        TrIt->TriangleNumber = i;

        ++TrIt;
        ++i;
    }

            Space.Min.x = -Max;
            Space.Min.y = -Max;
            Space.Min.z = -Max;
            Space.Max.x = Max;
            Space.Max.y = Max;
            Space.Max.z = Max;


    Geom::Octants::OctantDivide(&Space);

    bool IntersectionArray[N]{};

    Geom::TriangleIntersect(&Space, IntersectionArray);

    for(i = 0; i < N; ++i)
        if(IntersectionArray[i] == 1)
            std::cout << i << std::endl;

    return 0;
}


