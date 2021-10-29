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
    
    std::vector<Geom::Triangle<double>> TrSet(N);
    std::vector<Geom::Triangle<double>>::iterator TrIt = TrSet.begin();

    // Maximum possible coordinate for our space
    double Max = 0.0;
    
    int i = 0;
    while(i < N)
    {

        Geom::ReadTriangle(*TrIt);

        if(TrIt->MaxCoordinate > Max)
            Max = TrIt->MaxCoordinate;

        TrIt->TriangleNumber = i;

        ++TrIt;
        ++i;
    }

    Geom::Octants::Octant<double> Space{ {-Max, -Max, -Max}, {Max, Max, Max} };
    TrIt = TrSet.begin();

    while(TrIt != TrSet.end())
    {

        Geom::Octants::InsertTriangle<double>(Space, *TrIt);
    
        ++TrIt;
    }

    bool IntersectionArray[N]{};

    Geom::TriangleIntersect<double>(&Space, IntersectionArray);

    for(i = 0; i < N; ++i)
        if(IntersectionArray[i] == 1)
            std::cout << i << std::endl;
        
    return 0;
}


