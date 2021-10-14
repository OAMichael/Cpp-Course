#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"

int main()
{


    Geom::Segment<double> Array[20] = { {1, 1, 0, -1, -1, 0},  {-1, 1, 0, 1, -1, 0},           //1 - intersect
                                        {-1, -1, -1, 2, 2, 2}, {-1, 1, 0, 1, -1, 0},           //2 - intersect
                                        {1, 1, 1, -1, -1, -1}, {2, 2, 2, -2, -2, -2},          //3 - intersect
                                        {1, 1, 1, 2, 2, 2},    {-1, -1, -1, -2, -2, -2},       //4 - not intersect
                                        {0, 0, 0, 1, 0, 0},    {0, 0, 0, -1, 0, 0},            //5 - intersect
                                        {1, 1, 0, 1, 2, 0},    {1, -1, 0, 1, -2, 0},           //6 - not intersect
                                        {1, 1, 0, 1, -1, 0},   {1, 1, 0, 1, -1, 0},            //7 - intersect
                                        {1, 1, 0, 1, 4, 0},    {1, 2, -1, 1, 0, 4},            //8 - intersect
                                        {1, 1, 0, 1, 4, 0},    {1, 0, -1, 1, 0, 4},            //9 - not intersect
                                        {1, 1, 0, 1, 4, 0},    {1, 0, -1, 1, 0, -1} };         //10 - not intersect

    bool Test[10] = {1, 1, 1, 0, 1, 0, 1, 1, 0, 0};

    for(int i = 0; i < 10; i++)
        if(Geom::Is2DSegmIntersect<double>(Array[2 * i], Array[2 * i + 1]) == Test[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}