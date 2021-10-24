#include <iostream>
#include <cstdlib>
#include <limits>
#include <cassert>
#include <vector>
#include <cmath>
#include "../../Headers/Geometry.hpp"


int main()
{
    Geom::Triangle<double> Array[20] = { { {0, 0, 0},  {4, 0, 0},  {0, 0, 4}  },  { {4, 0, 0},   {4, 0, 4},           {0, 0, 4}   },   //1 - intersect
                                         { {0, 2, 0},  {0, 0, 4},  {2, 0, 0}  },  { {0, 0, 4},   {3.75, -3.58, 3.66}, {2, 0, 0}   },   //2 - intersect           
                                         { {-2, 0, 0}, {3, 0, 0},  {3, 3, 0}  },  { {-2, 0, 0},  {3, 0, 0},           {3, 3, 0}   },   //3 - intersect
                                         { {-2, 0, 0}, {3, 0, 0},  {3, 3, 0}  },  { {-2, 1, 0},  {2, 3, 0},           {0, 4, 0}   },   //4 - not intersect          
                                         { {-2, 0, 0}, {3, 0, 0},  {3, 3, 0}  },  { {-3, -2, 0}, {-3, 0, 0},          {0, 5, 0}   },   //5 - not intersect
                                         { {0, 0, 0},  {0, 0, 1},  {0, 5, 1}  },  { {0, 1, 0},   {0, 6, 1},           {0, -8, -2} },   //6 - not intersect
                                         { {0, 0, 0},  {0, 0, 1},  {0, 5, 1}  },  { {0, -5, 0},  {0, 6, 1},           {0, -8, -2} },   //7 - intersect
                                         { {0, 0, 1},  {0, 0, 2},  {0, 2, -1} },  { {0, -5, 0},  {0, 6, 1},           {0, -8, -2} },   //8 - intersect
                                         { {1, 0, 0},  {2, 0, 0},  {-1, 2, 0} },  { {4, 0, 0},   {0, 2, 0},           {1, 6, 0}   },   //9 - not intersect
                                         { {0, 0, 0},  {-2, 0, 0}, {-1, -3, 0}},  { {0, -7, 0},  {1, 6, 0},           {-3, 2, 0}  } }; //10 -intersect

    bool Test[10] = {1, 1, 1, 0, 0, 0, 1, 1, 0, 1};

    for(int i = 0; i < 10; i++)
        if (Geom::Is2DIntersect(Array[2 * i], Array[2 * i + 1]) == Test[i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}
