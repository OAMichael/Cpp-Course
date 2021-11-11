#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../../Headers/Geometry.hpp"


int main()
{
    int Intresect = 0;
    int edge = 32000;
    int edge_red = edge / 32;   // Reduced value of edge

    std::cin >> Intresect;

    std::cout << 2 << std::endl;

    Geom::Point<int> T1p, T1q, T1r, T2p, T2q, T2r;

    if(Intresect)
    {
        /* Generate cases when triangles intersect */

        Geom::Point<int> M = { -edge + rand() % (2 * edge), 
                               -edge + rand() % (2 * edge),
                               -edge + rand() % (2 * edge) };

        Geom::Point<int> N = { -edge + rand() % (2 * edge), 
                               -edge + rand() % (2 * edge), 
                               -edge + rand() % (2 * edge) };

        Geom::Vector<int> DirectVec = M - N;


        Geom::Vector<int> Vec1 = { -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red) };


        Geom::Vector<int> Vec2 = { -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red) };



        Geom::Vector<int> Vec3 = { -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red) };


        Geom::Vector<int> Vec4 = { -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red),
                                   -edge_red + rand() % (2 * edge_red) };


        T1p = { N.x + Vec1.x,
                N.y + Vec1.y,
                N.z + Vec1.z };

        T1q = { M.x + Vec2.x,
                M.y + Vec2.y,
                M.z + Vec2.z };

        T1r = { N.x - Vec1.x,
                N.y - Vec1.y,
                N.z - Vec1.z };

        double t1 = (rand() % edge) / (static_cast<double>(edge));
        double t2 = (rand() % edge) / (static_cast<double>(edge));

        N.x += t1 * DirectVec.x;
        N.y += t1 * DirectVec.y;
        N.z += t1 * DirectVec.z;

        M.x -= t2 * DirectVec.x;
        M.y -= t2 * DirectVec.y;
        M.z -= t2 * DirectVec.z;



        T2p = { N.x + Vec3.x,
                N.y + Vec3.y,
                N.z + Vec3.z };

        T2q = { M.x + Vec4.x,
                M.y + Vec4.y,
                M.z + Vec4.z };

        T2r = { N.x - Vec3.x,
                N.y - Vec3.y,
                N.z - Vec3.z };

    }
    else
    {
        /* Generate cases when triangles do not intersect */
        Geom::Point<int> A = { -edge + rand() % (2 * edge), 
                               -edge + rand() % (2 * edge),
                               -edge + rand() % (2 * edge) };    

        Geom::Point<int> B = { -edge + rand() % (2 * edge), 
                               -edge + rand() % (2 * edge),
                               -edge + rand() % (2 * edge) };

        Geom::Point<int> C = { -edge + rand() % (2 * edge), 
                               -edge + rand() % (2 * edge),
                               -edge + rand() % (2 * edge) };
    

        Geom::Vector<int> n = (A - B)^(B - C);



        Geom::Vector<int> nVec1 = { -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red) };
        if(nVec1 * n < 0)
            nVec1 = -1 * nVec1;


        Geom::Vector<int> nVec2 = { -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red) };
        if(nVec2 * n < 0)
            nVec2 = -1 * nVec2;


        Geom::Vector<int> nVec3 = { -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red) };
        if(nVec3 * n < 0)
            nVec3 = -1 * nVec3;


        T1p = {A.x + nVec1.x, A.y + nVec1.y, A.z + nVec1.z};
        T1q = {B.x + nVec2.x, B.y + nVec2.y, B.z + nVec2.z};
        T1r = {C.x + nVec3.x, C.y + nVec3.y, C.z + nVec3.z};


        Geom::Vector<int> nVec4 = { -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red) };
        if(nVec4 * n > 0)
            nVec4 = -1 * nVec4;


        Geom::Vector<int> nVec5 = { -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red) };
        if(nVec5 * n > 0)
            nVec5 = -1 * nVec5;


        Geom::Vector<int> nVec6 = { -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red),
                                    -edge_red + rand() % (2 * edge_red) };
        if(nVec6 * n > 0)
            nVec6 = -1 * nVec6;


        T2p = {A.x + nVec4.x, A.y + nVec4.y, A.z + nVec4.z};
        T2q = {B.x + nVec5.x, B.y + nVec5.y, B.z + nVec5.z};
        T2r = {C.x + nVec6.x, C.y + nVec6.y, C.z + nVec6.z};

    }


    std::cout << T1p.x << "\t" << T1p.y << "\t" << T1p.z << "\t"
              << T1q.x << "\t" << T1q.y << "\t" << T1q.z << "\t"
              << T1r.x << "\t" << T1r.y << "\t" << T1r.z << "\t" << std::endl;



    std::cout << T2p.x << "\t" << T2p.y << "\t" << T2p.z << "\t"
              << T2q.x << "\t" << T2q.y << "\t" << T2q.z << "\t"
              << T2r.x << "\t" << T2r.y << "\t" << T2r.z << std::endl;

    return 0; 
}
