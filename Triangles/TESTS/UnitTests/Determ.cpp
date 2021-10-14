#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "../../Geometry.hpp"


int main()
{
    Geom::Point<double> Points[40] = { {1, 2, 3},  {3, 4, 3}, {4, 5, 6}, {1, 4, -5}, {-5, 6, -6}, {1, 0, 0}, {-3, 4, 5},          {0, 2, 9},
                                       {3, -2, 4}, {4, 9, 9}, {3, 3, 7}, {2, 2, 8},  {4, 2, 0},   {6, 6, 6}, {9, 9, 9},           {4, 8, 8},
                                       {5, 5, 5},  {5, 5 ,5}, {5, 5, 5}, {5, 5, 5},  {1, 2, 3},   {4, 5, 6}, {7, 8, 9},           {0, -1, -2},
                                       {3, -4, 5}, {1, 0, 0}, {0, 0, 0}, {2, 2, 2},  {8, 8, 8},   {8, 8, 8}, {9, 0.001, 0.00001}, {0.0000001, 0.1, 1},
                                       {0.000001, 0, 0}, {3, 3, 7}, {2, 2, 7}, {7, 7, 7}, {0, 0.1, 0.1}, {1, 11, 111}, {-2, 4, -8}, {27, 9, 3} };

    double TestArray[10] = {12, 54, 0, -24, 0, 0, -18, 0, 0, 15889};

    for(int i = 0; i < 10; i++)
        if(Geom::Determ<double>(Points[4 * i], Points[4 * i + 1], Points[4 * i + 2], Points[4 * i + 3]) == TestArray[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}


