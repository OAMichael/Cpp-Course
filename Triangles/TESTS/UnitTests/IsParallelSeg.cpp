#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"


int main()
{
    Geom::Segment<double> Array[20] = { {0, -2, 0, 2, 3, 0}, {0, 0, 0, 2, 5, 0},                   //1 - parallel
                                        {0, -2, 0, 2, 0, 0}, {0, 0, 0, 2, 5, 0},                   //2 - not parallel
                                        {1, 3, 4, 6, 4, 3},  {1, 3, 4, 6, 4, 3},                   //3 - parallel
                                        {1, 3, 4, 6, 4, 3},  {0, 2, 3, 7, 5, 4},                   //4 - not parallel
                                        {2, 2, 2, 3, 3, 3},  {2, -2, 2, 3, -3, 3},                 //5 - not parallel
                                        {1, 1, 1, 1, 2, 3},  {1, 1, 1, 1, 2, 3.000000000000001},   //6 - not parallel
                                        {3, 3, 3, 3, 3, 3},  {2, 4, 5, 6, 7, 3},                   //7 - parallel
                                        {0, 0, 0, 1, -3, 6}, {0, 0, 0, 3, 1, 1},                   //8 - not parallel
                                        {2, 4, 6, 3, 4, 5},  {2, 4, 5, 3, 4, 4},                   //9 - parallel
                                        {3, 4, 5, 6, 7, 8},  {4, 4, 5, 6, 7, 8} };                 //10 - not parallel

    bool Test[10] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 0};

    for (int i = 0; i < 10; i++)
        if(Geom::IsParallel<double>(Array[2 * i], Array[2 * i + 1]) == Test[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}