#include <iostream>
#include <cstdlib>
#include <limits>
#include <cassert>
#include <vector>
#include <cmath>
#include "../../Headers/Geometry.hpp"


int main()
{
    Geom::Triangle<double> Triangles[10] = { { {2, -3, 0}, {3, 4, 0},   {-2, 0, 0} },
                                             { {2, -3, 0}, {3, 4, 0},   {-2, 0, 0} },
                                             { {2, -3, 0}, {3, 4, 0},   {-2, 0, 0} },
                                             { {2, -3, 0}, {3, 4, 0},   {-2, 0, 0} }, 
                                             { {0, 0, 0},  {0, 4, 0},   {-3, 8, 0} },
                                             { {0, 0, 0},  {0, 4, 0},   {-3, 8, 0} },
                                             { {0, 0, 0},  {0, 4, 0},   {-3, 8, 0} }, 
                                             { {-4, 0, 0}, {-1, -1, 0}, {-3, -7, 0}},
                                             { {-4, 0, 0}, {-1, -1, 0}, {-3, -7, 0}},
                                             { {-4, 0, 0}, {-1, -1, 0}, {-3, -7, 0}}, };


//                                        yes          yes           no            yes                 no
    Geom::Point<double> Points[10] = { {0, 0, 0},  {2, -3, 0}, {3, 3.999, 0}, {0, -1.5, 0},        {0, 5, 0},
                                       {-2, 3, 0}, {-3, 8, 0}, {0, 5, 0},     {-3, -7.0000001, 0}, {-2, -2, 0} };
//                                        no           yes           no            no                  yes

    bool Test[10] = {1, 1, 0, 1, 0, 0, 1, 0, 0, 1};

    for(int i = 0; i < 10; i++)
        if(Geom::IsPointInTriangle<double>(Triangles[i], Points[i]) == Test[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}
