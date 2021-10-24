#include <iostream>
#include <cstdlib>
#include <limits>
#include <cassert>
#include <vector>
#include <cmath>
#include "../../Headers/Geometry.hpp"

int main()
{


    Geom::Segment<double> Array[20] = { {1, 3, 4, 6, 4, 3},   {0, 2, 3, 7, 5, 4},       //1 - intersect
                                        {1, 3, 4, 6, 4, 3},   {0, 0, 0, 7, 5, 4},       //2 - intersect
                                        {1, 3, 4, 6, 4, 3},   {0, 0, 0, 0, 4, 4},       //3 - not intersect
                                        {0, 4, 4, 0, 6, 3},   {0, 0, 0, 0, 4, 4},       //4 - intersect       
                                        {0, 4, 4, 0, 0, 0},   {0, 0, 0, 0, 8, 8},       //5 - intersect      
                                        {0, 4, 4, 0, 0, 0},   {0, 0, 0, 0, 0, 0},       //6 - intersect         
                                        {0, 6, 6, 0, 8, 8},   {0, 4, 4, 0, 0, 0},       //7 - not intersect  
                                        {-2, 0, -6, 2, 0, 6}, {0, 4, 4, 0, -2, -2},     //8 - intersect       
                                        {0, 4, 4, 0, -2, -2}, {2, 0, -6, -2, 0, -6},    //9 - not intersect       
                                        {0, 0, 0, 2, 0, -6},  {0, 4, 4, 0, -2, -2} };   //10 - intersect
 
    bool Test[10] = {1, 1, 0, 1, 1, 1, 0, 1, 0, 1};

    for(int i = 0; i < 10; i++)
        if(Geom::Is2DSegmIntersect<double>(Array[2 * i], Array[2 * i + 1]) == Test[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}
