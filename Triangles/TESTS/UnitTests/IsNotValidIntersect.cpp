#include <iostream>
#include <cstdlib>
#include <limits>
#include <cassert>
#include <vector>
#include <cmath>
#include "../../Headers/Geometry.hpp"


int main()
{
    Geom::Triangle<double> Triangles[20] = { { {4, 0, 0}, {0, -4, 0}, {-4, 2, 0} },     //1 - intersect
                                             { {0, 0, -4}, {0, 0, 4}, {0, 0, 8}  },

                                             { {4, 0, 0}, {0, -4, 0}, {4, 0, 0}  },     //2 - intersect
                                             { {4, 0, 0}, {0, -4, 0}, {-4, 2, 0} },     
                                             
                                             { {4, 0, 0}, {0, -4, 0}, {-4, 2, 0} },     //3 - intersect
                                             { {0, 0, 0}, {0, 0, 0},  {0, 0, 0}  }, 

                                             { {1, 1, 1}, {1, 1, 1},  {1, 1, 1}  },     //4 - intersect
                                             { {1, 1, 1}, {1, 1, 1},  {1, 1, 1}  },

                                             { {4, 0, 0}, {0, -4, 0}, {-4, 2, 0} },     //5 - not intersect
                                             { {0, 6, 0}, {0, 0, 4},  {0, 6, 0}  },

                                             { {4, 0, 0}, {0, -4, 0}, {-4, 2, 0} },     //6 - intersect
                                             { {0, 6, 0}, {0, 0, 0},  {0, 6, 0}  },

                                             { {0, 6, 0}, {0, 0, 4},  {0, 6, 0}  },     //7 - not intersect
                                             { {4, 0, 0}, {-4, 2, 0}, {-4, 2, 0} },

                                             { {0, 6, 0}, {0, 0, 0},  {0, 6, 0}  },     //8 - intersect
                                             { {4, 0, 0}, {-4, 2, 0}, {-4, 2, 0} },

                                             { {0, -6, 0}, {0, 0, 0}, {0, 0, 0}  },     //9 - intersect
                                             { {0, 6, 0},  {0, 0, 0}, {0, 0, 0}  }, 

                                             { {2, 2, 2},  {2, 2, 2}, {2, 2, 2}  },     //10 - not intersect 
                                             { {0, 0, 0},  {0, 0, 0}, {0, 0, 0}  } };


    bool Test[10] = {1, 1, 1, 1, 0, 1, 0, 1, 1, 0};

    for(int i = 0; i < 10; i++)
        if(Geom::IsNotValidIntersect<double>(Triangles[2 * i], Triangles[2 * i + 1]) == Test [i])
            printf("Test %d: Passed\n", i);
        else
            printf("Test %d: Failed\n", i);

    return 0;
}
