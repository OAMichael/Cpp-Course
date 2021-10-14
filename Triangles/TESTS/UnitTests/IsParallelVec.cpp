#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"


int main()
{
    Geom::Vector<double> Array[20] = { {1, 2, 3},             {-1, -2, -3},          //1 - parallel
                                       {1, 1, 1},             {2, 2, 2},             //2 - parallel
                                       {0, 0, 0},             {6, 6, 6},             //3 - parallel
                                       {2, 4, 5},             {1, 4, -3},            //4 - not parallel
                                       {-2, 3, 5},            {2, -4, 5},            //5 - not parallel
                                       {-4, 5, 6},            {1, 9, 500},           //6 - not parallel
                                       {2, 2, 2.00000000001}, {1, 1, 1},             //7 - not parallel
                                       {50, 1, 2},            {0.5, 0.01, 0.02},     //8 - parallel
                                       {0, 0, 0.00000000001}, {0, 0, 0.000000001},   //9 - parallel
                                       {1, 1, 4},             {2, 1, 4} };           //10 - not parallel

    bool Test[10] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 0};

    for(int i = 0; i < 10; i++)
        if(Geom::IsParallel(Array[2 * i], Array[2 * i + 1]) == Test[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);
    
    return 0;
}