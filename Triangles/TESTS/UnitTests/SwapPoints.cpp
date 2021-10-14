#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"


int main()
{
    Geom::Point<double> Array[20]   =   { {0, 1, 2},   {1, 2, 3},    {-1, 0, 0},   {2, -5, 3},
                                          {1, 3, 4},   {-4, 5, 6},   {-2, 3, 4},   {2, -4 ,6},
                                          {92, 4, -5}, {2, 45, -3},  {-2, 4, 6},   {0, 5, -3},
                                          {39, 5, 6},  {4, -2, -1},  {0, 0, 0},    {0, -2, -2},
                                          {-2, 9, 8},  {6, 6, 6},    {2, 2, 8},    {3, 3, 7} };

    Geom::Point<double> TestArray[20] = { {0, 1, 2},   {1, 2, 3},    {-1, 0, 0},   {2, -5, 3},
                                          {1, 3, 4},   {-4, 5, 6},   {-2, 3, 4},   {2, -4 ,6},
                                          {92, 4, -5}, {2, 45, -3},  {-2, 4, 6},   {0, 5, -3},
                                          {39, 5, 6},  {4, -2, -1},  {0, 0, 0},    {0, -2, -2},
                                          {-2, 9, 8},  {6, 6, 6},    {2, 2, 8},    {3, 3, 7} };

    int i = 0;
    for (i = 0; i < 10; i++)
        Geom::SwapPoints<double>(Array[2 * i], Array[2 * i + 1]);
    for(i = 0; i < 10; i++)
        if (Array[2 * i] == TestArray[2 * i + 1] && Array[2 * i + 1] == TestArray[2 * i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);
    return 0;
}