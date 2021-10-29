#ifndef GEOMETRY_H
#define GEOMETRY_H


namespace Geom {

    template <typename T>
    const T NaN = std::numeric_limits<T>::quiet_NaN();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                            GEOMETRIC STRUCTURES                                                //

    template <typename T>
    struct Point
    {
        T x = NaN<T>;
        T y = NaN<T>;
        T z = NaN<T>;

        Point()
        {}

        Point(T px, T py, T pz)
        {   
            x = px;
            y = py;
            z = pz;
        }
    };


    template <typename T>
    struct Segment 
    {
        Point<T> m;
        Point<T> n;

        Segment()
        {}

        Segment(Point<T>& a, Point<T>& b) { m.x = a.x; m.y = a.y; m.z = a.z; 
                                            n.x = b.x; n.y = b.y; n.z = b.z;}

        Segment(T x1, T y1, T z1, T x2, T y2, T z2) 
        { m.x = x1; m.y = y1; m.z = z1; n.x = x2; n.y = y2; n.z = z2;}
    };


    template <typename T>
    struct Vector
    {
        T x = NaN<T>;
        T y = NaN<T>;
        T z = NaN<T>;

        Vector(T vx, T vy, T vz)
        {
            x = vx;
            y = vy;
            z = vz;
        }

        Vector()
        {}

        const double GetLenght()
        {
            return sqrt(x * x + y * y + z * z);
        }

        // assigning operator
        Vector<T>& operator=(const Vector<T>& a)
        {
            x = a.x;
            y = a.y;
            z = a.z;
            return *this;
        }

    };


    //dot product
    template <typename T>
    const T operator*(const Vector<T>& a, const Vector<T>& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }


    //cross product
    template <typename T>
    const Vector<T> operator^(const Vector<T>& a, const Vector<T>& b)              
    {
        T x = a.y * b.z - b.y * a.z;
        T y = b.x * a.z - a.x * b.z;
        T z = a.x * b.y - b.x * a.y;
        return Vector<T>(x, y, z);
    }


    //multiplying by scalar
    template <typename T>
    const Vector<T> operator*(const T& k, const Vector<T>& a)
    {
        return Vector<T>(k * a.x, k * a.y, k * a.z);
    }


    //adding vectors
    template <typename T>
    const Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
    {
        T x = a.x + b.x;
        T y = a.y + b.y;
        T z = a.z + b.z;
        return Vector<T>(x, y, z);
    }


    //subtracting vectors
    template <typename T>
    const Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
    {
        T x = a.x - b.x;
        T y = a.y - b.y;
        T z = a.z - b.z;
        return Vector<T>(x, y, z);
    }


    //vector ba made of two points 
    template <typename T>
    const Vector<T> operator-(const Point<T>& a, const Point<T>& b)
    {
        T x = a.x - b.x;
        T y = a.y - b.y;
        T z = a.z - b.z;
        return Vector<T>(x, y, z); 
    }


    //points comparing operator
    template <typename T>
    const bool operator==(const Point<T>& a, const Point<T>& b)
    {
        return (a.x == b.x && a.y == b.y && a.z == b.z);
    }



    template <typename T>
    struct Triangle
    { 
        Point<T> p{NaN<T>, NaN<T>, NaN<T>};
        Point<T> q{NaN<T>, NaN<T>, NaN<T>};
        Point<T> r{NaN<T>, NaN<T>, NaN<T>};
        
        Segment<T> pq = {p, q};
        Segment<T> qr = {q, r};
        Segment<T> rp = {r, p};

        bool IsValid()
        {
            // if cross product is zero then the triangle is invalid
            Vector<T> Vec = (q - p)^(r - q);
            if(Vec.x == 0 && Vec.y == 0 && Vec.z == 0)
                return false;

            return true;
        }

        bool Validation = false;

        T MaxCoordinate = NaN<T>;

        int TriangleNumber = -1;
        

        const double GetPerimeter()
        {
            return ((p - q).GetLenght() + (q - r).GetLenght() + (r - p).GetLenght());
        }

        Triangle()
        {}

        Triangle(Point<T> A, Point<T> B, Point<T> C)
        {
            p.x = A.x;
            p.y = A.y;
            p.z = A.z;
            q.x = B.x;
            q.y = B.y;
            q.z = B.z;
            r.x = C.x;
            r.y = C.y;
            r.z = C.z;

            pq = {p, q};
            qr = {q, r};
            rp = {r, p};

        }

        Triangle(T Ax, T Ay, T Az, T Bx, T By, T Bz, T Cx, T Cy, T Cz)
        {
            p.x = Ax;
            p.y = Ay;
            p.z = Az;
            q.x = Bx;
            q.y = By;
            q.z = Bz;
            r.x = Cx;
            r.y = Cy;
            r.z = Cz;

            pq = {p, q};
            qr = {q, r};
            rp = {r, p};

            MaxCoordinate = std::max( {std::abs(Ax), std::abs(Ay), std::abs(Az),
                                       std::abs(Bx), std::abs(By), std::abs(Bz),
                                       std::abs(Cx), std::abs(Cy), std::abs(Cz)});

        }


    };


    template <typename T>
    void ReadTriangle(Triangle<T>& Tr)
    {
        std::cin >> Tr.p.x >> Tr.p.y >> Tr.p.z
                 >> Tr.q.x >> Tr.q.y >> Tr.q.z
                 >> Tr.r.x >> Tr.r.y >> Tr.r.z;

        assert(std::cin.good());

        Tr.MaxCoordinate = std::max( {std::abs(Tr.p.x), std::abs(Tr.p.y), std::abs(Tr.p.z),
                                      std::abs(Tr.q.x), std::abs(Tr.q.y), std::abs(Tr.q.z),
                                      std::abs(Tr.r.x), std::abs(Tr.r.y), std::abs(Tr.r.z)});
        Tr.Validation = Tr.IsValid();
    }


    template <typename T>
    void SwapPoints(Point<T>& a, Point<T>& b);

    template <typename T>
    bool Is2DIntersect(const Triangle<T>& T1, const Triangle<T>& T2);

    template <typename T>
    const bool IsParallel(const Vector<T>& a, const Vector<T>& b);

    template <typename T>
    const bool IsParallel(const Segment<T>& a, const Segment<T>& b);

    template <typename T>
    bool Is2DSegmIntersect(const Segment<T>& a, const Segment<T>& b);

    template <typename T>
    bool Is3DSegmIntersect(const Segment<T>& a, const Segment<T>& b);

    template <typename T>
    bool IsPointInTriangle(const Triangle<T>& Tr, const Point<T>& p);

    template <typename T>
    bool IsNotValidIntersect(const Triangle<T>& T1, const Triangle<T>& T2);

    template <typename T>
    const T Determ(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                    ALGORITHM OF TWO TRIANGLES INTERSECTION                                     //


    //core function of whole program
    template <typename T>
    bool IsIntersect(Triangle<T>& T1, Triangle<T>& T2)
    {

        if(T1.Validation && T2.Validation)
        {
            T   T1p2 = Determ(T1.p, T1.q, T1.r, T2.p), 
                T1q2 = Determ(T1.p, T1.q, T1.r, T2.q),
                T1r2 = Determ(T1.p, T1.q, T1.r, T2.r); 

            
            // if all three points of T2 lie in the same open halfspace induced by T1
            if (T1p2 * T1q2 > 0 && T1p2 * T1r2 > 0 && T1q2 * T1r2 > 0)
                return false;


            T   T2p1 = Determ(T2.p, T2.q, T2.r, T1.p),
                T2q1 = Determ(T2.p, T2.q, T2.r, T1.q), 
                T2r1 = Determ(T2.p, T2.q, T2.r, T1.r);

            
            // if all three points of T1 lie in the same open halfspace induced by T2
            if (T2p1 * T2q1 > 0 && T2p1 * T2r1 > 0 && T2q1 * T2r1 > 0)
                return false;


            // if both triangles lie in same plane
            if(T1p2 == 0 && T1q2 == 0 && T1r2 == 0)
                return Is2DIntersect(T1, T2);


            // if 2 of vertices lie in other triangle's plane
            if(T1p2 == 0 && T1q2 == 0)
                return (Is2DSegmIntersect(T2.pq, T1.pq) || Is2DSegmIntersect(T2.pq, T1.qr) || Is2DSegmIntersect(T2.pq, T1.rp));
            if(T1p2 == 0 && T1r2 == 0)
                return (Is2DSegmIntersect(T2.rp, T1.pq) || Is2DSegmIntersect(T2.rp, T1.qr) || Is2DSegmIntersect(T2.rp, T1.rp));
            if(T1r2 == 0 && T1q2 == 0)
                return (Is2DSegmIntersect(T2.qr, T1.pq) || Is2DSegmIntersect(T2.qr, T1.qr) || Is2DSegmIntersect(T2.qr, T1.rp));
            
            if(T2p1 == 0 && T2q1 == 0)
                return (Is2DSegmIntersect(T1.pq, T2.pq) || Is2DSegmIntersect(T1.pq, T2.qr) || Is2DSegmIntersect(T1.pq, T2.rp));
            if(T2p1 == 0 && T2r1 == 0)
                return (Is2DSegmIntersect(T1.rp, T2.pq) || Is2DSegmIntersect(T1.rp, T2.qr) || Is2DSegmIntersect(T1.rp, T2.rp));
            if(T2r1 == 0 && T2q1 == 0)
                return (Is2DSegmIntersect(T1.qr, T2.pq) || Is2DSegmIntersect(T1.qr, T2.qr) || Is2DSegmIntersect(T1.qr, T2.rp));
            

            // if one of the points of T2 lies in T1's plane
            if(T1p2 == 0)
                return IsPointInTriangle(T1, T2.p);

            if(T1q2 == 0)
                return IsPointInTriangle(T1, T2.q);

            if(T1r2 == 0)
                return IsPointInTriangle(T1, T2.r);


            // if one of the points of T1 lies in T2's plane
            if(T2p1 == 0)
                return IsPointInTriangle(T2, T1.p);

            if(T2q1 == 0)
                return IsPointInTriangle(T2, T1.q);

            if(T2r1 == 0)
                return IsPointInTriangle(T2, T1.r);


            // if no vertex lie in other triangle's plane


            // making point p one with determinant sign different from others
            while(T2r1 * T2q1 < 0)
            {
                SwapPoints(T1.p, T1.q);                                                                 
                SwapPoints(T1.q, T1.r);

                T2q1 = Determ(T2.p, T2.q, T2.r, T1.q);
                T2r1 = Determ(T2.p, T2.q, T2.r, T1.r);
            }

            // same
            while(T1r2 * T1q2 < 0)
            {
                SwapPoints(T2.p, T2.q);
                SwapPoints(T2.q, T2.r);

                T1q2 = Determ(T1.p, T1.q, T1.r, T2.q);
                T1r2 = Determ(T1.p, T1.q, T1.r, T2.r);
            }


            // swapping point q and r for triangles to be oriented counter-clockwise 
            if(Determ(T2.p, T2.q, T2.r, T1.p) < 0)
                SwapPoints(T2.q, T2.r);
            if(Determ(T1.p, T1.q, T1.r, T2.p) < 0)
                SwapPoints(T1.q, T1.r);


            if(Determ(T1.p, T1.q, T2.p, T2.q) > 0) 
                return false;

            if(Determ(T1.p, T1.r, T2.r, T2.p) > 0)
                return false;

            return true;
        }
        else
            return IsNotValidIntersect(T1, T2);    // case when one or both triangles happened to be not valid
    }


    template <typename T>
    bool Is2DIntersect(Triangle<T>& T1, Triangle<T>& T2)
    {
        if(IsPointInTriangle(T1, T2.p) || IsPointInTriangle(T1, T2.q) || IsPointInTriangle(T1, T2.r) ||                 //checking if point of
           IsPointInTriangle(T2, T1.p) || IsPointInTriangle(T2, T1.q) || IsPointInTriangle(T2, T1.r) ||                 //one triangle lies in 
                                                                                                                        //other

           Is2DSegmIntersect(T1.pq, T2.pq) || Is2DSegmIntersect(T1.pq, T2.qr) || Is2DSegmIntersect(T1.pq, T2.rp) ||     //checking if one of 
           Is2DSegmIntersect(T1.qr, T2.pq) || Is2DSegmIntersect(T1.qr, T2.qr) || Is2DSegmIntersect(T1.qr, T2.rp) ||     //sides of triangle
           Is2DSegmIntersect(T1.rp, T2.pq) || Is2DSegmIntersect(T1.rp, T2.qr) || Is2DSegmIntersect(T1.rp, T2.rp))       //crosses edge of another
        return true;

        return false;
    }


    template <typename T>
    const T Determ(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d)
    {
        return  ((a.x - d.x)*((b.y - d.y)*(c.z - d.z) - (c.y - d.y)*(b.z - d.z))                        //checking if the 4th point lies 
              -  (a.y - d.y)*((b.x - d.x)*(c.z - d.z) - (c.x - d.x)*(b.z - d.z))                        //in the plane induced by other points
              +  (a.z - d.z)*((b.x - d.x)*(c.y - d.y) - (c.x - d.x)*(b.y - d.y))); 
    }


    template <typename T>
    void SwapPoints(Point<T>& a, Point<T>& b)                                                           //swapping two points
    {
        Point<T> tmp = a;
        a = b;
        b = tmp;
    }


    template <typename T>
    bool Is2DSegmIntersect(const Segment<T>& a, const Segment<T>& b)
    {
        Vector<T> a1 = a.m - a.n;               //directing vectors
        Vector<T> a2 = b.m - b.n;

        //checking if a1 || a2
        if(IsParallel(a1, a2))                  //if a1 || a2
        {
            if(IsParallel(a1, a.m - b.m))       //if lines induced by a and b coincide
            {
                if((a.m.x != a.n.x && fmin(a.m.x, a.n.x) <= fmax(b.m.x, b.n.x) && fmin(b.m.x, b.n.x) <= fmax(a.m.x, a.n.x)) ||    //segments on line induced
                   (a.m.y != a.n.y && fmin(a.m.y, a.n.y) <= fmax(b.m.y, b.n.y) && fmin(b.m.y, b.n.y) <= fmax(a.m.y, a.n.y)) ||
                   (a.m.z != a.n.z && fmin(a.m.z, a.n.z) <= fmax(b.m.z, b.n.z) && fmin(b.m.z, b.n.z) <= fmax(a.m.z, a.n.z)))      //by a and b intersect
                    return true;
            }
            return false;
        }


        // a1 !(||) a2
        // t-parameter of line r = r0 + at
        double t = 0;
        if(a1.x * a2.y - a1.y * a2.x != 0)
            t = (a2.y * (b.m.x - a.m.x) + a2.x * (a.m.y - b.m.y)) / (a1.x * a2.y - a1.y * a2.x);
        else if(a1.x * a2.z - a1.z * a2.x != 0)
            t = (a2.z * (b.m.x - a.m.x) + a2.x * (a.m.z - b.m.z)) / (a1.x * a2.z - a1.z * a2.x);
        else
            t = (a2.z * (b.m.y - a.m.y) + a2.y * (a.m.z - b.m.z)) / (a1.y * a2.z - a1.z * a2.y);

        Point<T> OInt = {a.m.x + t * a1.x, a.m.y + t * a1.y, a.m.z + t * a1.z};

        if((a.m - OInt) * (a.n - OInt) <= 0 && (b.m - OInt) * (b.n - OInt) <= 0)                        
            return true;

        return false;
    }


    template <typename T>
    const bool IsParallel(const Vector<T>& a, const Vector<T>& b)
    {   
        Vector<T> tmp = a^b;
        if ( tmp.x == 0 && tmp.y == 0 && tmp.z == 0 )    //is cross product zero
            return true;

        return false;
    }


    template <typename T>
    const bool IsParallel(const Segment<T>& a, const Segment<T>& b)
    {   
        return IsParallel(a.m - a.n, b.m - b.n);
    }


    template <typename T>
    bool IsPointInTriangle(const Triangle<T>& Tr, const Point<T>& O)
    {
        Vector<T> Op = Tr.p - O;
        Vector<T> Oq = Tr.q - O;
        Vector<T> Or = Tr.r - O;

        double OpLenght = Op.GetLenght();
        double OqLenght = Oq.GetLenght();
        double OrLenght = Or.GetLenght();

        // if angles between Op and Oq, Oq and Or, Or and Op add up to 360 degrees 
        // then point lies inside triangle (including edges and vertices)
        if(OpLenght != 0 && OqLenght != 0 && OqLenght != 0 && (acos((Op * Oq)/(OpLenght * OqLenght)) + acos((Oq * Or)/(OqLenght * OrLenght)) + 
            acos((Or * Op)/(OrLenght * OpLenght)) < 2.0 * M_PI))
            return false;

        return true;
    }


    template <typename T>
    bool IsNotValidIntersect(Triangle<T>& T1, Triangle<T>& T2)
    {
        // if T2 is not valid
        if(T1.Validation && !T2.Validation)
        {

            T   T1p2 = Determ(T1.p, T1.q, T1.r, T2.p), 
                T1q2 = Determ(T1.p, T1.q, T1.r, T2.q),
                T1r2 = Determ(T1.p, T1.q, T1.r, T2.r);

            if(T1p2 * T1q2 <= 0 || T1p2 * T1r2 <= 0 || T1q2 * T1r2 <= 0)
            {
                if(T1p2 == 0 || T1q2 == 0 || T1r2 == 0)
                    return (IsPointInTriangle(T1, T2.p) || IsPointInTriangle(T1, T2.q) || IsPointInTriangle(T1, T2.r));

                Vector<T> n = (T1.q - T1.p) ^ (T1.r - T1.q);
                double t = 0;

                if ((T2.p - T2.q) * n != 0)
                    t = ((T1.p - T2.p) * n)/((T2.p - T2.q) * n);

                // point of intersection of T1's plane and T2-line
                Point<T> O{T2.p.x + t * (T2.p.x - T2.q.x), T2.p.y + t * (T2.p.y - T2.q.y), T2.p.z + t * (T2.p.z - T2.q.z)};

                return IsPointInTriangle(T1, O);
            }

            return false;
        }

        // if T1 is not valid
        if(T2.Validation && !T1.Validation)
        {

            T   T2p1 = Determ(T2.p, T2.q, T2.r, T1.p),
                T2q1 = Determ(T2.p, T2.q, T2.r, T1.q), 
                T2r1 = Determ(T2.p, T2.q, T2.r, T1.r);

            if(T2p1 * T2q1 <= 0 || T2p1 * T2r1 <= 0 || T2q1 * T2r1 <= 0)
            {
                if(T2p1 == 0 || T2q1 == 0 || T2r1 == 0)
                    return (IsPointInTriangle(T2, T1.p) || IsPointInTriangle(T2, T1.q) || IsPointInTriangle(T2, T1.r));

                Vector<T> n = (T2.q - T2.p) ^ (T2.r - T2.q);
                double t = 0;

                if ((T1.p - T1.q) * n != 0)
                    t = ((T2.p - T1.p) * n)/((T1.p - T1.q) * n);

                // point of intersection of T2's plane and T1-line
                Point<T> O{T1.p.x + t * (T1.p.x - T1.q.x), T1.p.y + t * (T1.p.y - T1.q.y), T1.p.z + t * (T1.p.z - T1.q.z)};

                return IsPointInTriangle(T2, O);
            }

            return false;
        }

        // both invalid
        if((T1.p == T1.q) && (T1.p == T1.r) && (T2.p == T2.q) && (T2.p == T2.r))
            return (T1.p == T2.p);

        return (Is3DSegmIntersect(T1.pq, T2.pq) || Is3DSegmIntersect(T1.pq, T2.qr) || Is3DSegmIntersect(T1.pq, T2.rp) || 
                Is3DSegmIntersect(T1.qr, T2.pq) || Is3DSegmIntersect(T1.qr, T2.qr) || Is3DSegmIntersect(T1.qr, T2.rp) ||   
                Is3DSegmIntersect(T1.rp, T2.pq) || Is3DSegmIntersect(T1.rp, T2.qr) || Is3DSegmIntersect(T1.rp, T2.rp));
    }


    // Segments which are not complanar can not intersect
    template <typename T>
    bool Is3DSegmIntersect(const Segment<T>& a, const Segment<T>& b)
    {
        if((a.m - b.m) * ((a.m - a.n)^(b.m - b.n)) == 0)
            return Is2DSegmIntersect(a, b);

        return false;
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Recursively dividing space into octants                                       //


    // Dividing whole space into octants which divided into smaller octants 
    // which divided into even smaller octants and so on
    namespace Octants
    {
        template <typename T>
        struct Octant 
        {
            Vector<T> Min{}, Max{};
            Octant<T>* SubOctants[8]{};


            std::vector<Triangle<T>> OctantTriangles{};

            Octant(Vector<T> MinVec, Vector<T> MaxVec)
            {
                Min = MinVec;
                Max = MaxVec;
            }

            Octant()
            {}
        };


        // 1) x >= 0, y >= 0, z >= 0
        // 2) x > 0, y < 0, z >= 0
        // 3) x < 0, y > 0, z >= 0
        // 4) x < 0, y < 0, z >= 0
        // 5) x > 0, y > 0, z < 0
        // 6) x > 0, y < 0, z < 0
        // 7) x < 0, y > 0, z < 0
        // 8) x < 0, y < 0, z < 0
        // In which corner of the octant the triangle lies
        // Returns 0 if triangle does not fit in one of corners
        template <typename T>
        int InWhichCorner(const Triangle<T>& Tr, const Octant<T>& Oct)
        {
            Vector<T> MidPoint = 0.5*(Oct.Max + Oct.Min);

            if (Tr.p.x >= MidPoint.x && Tr.p.y >= MidPoint.y && Tr.p.z >= MidPoint.z &&
                Tr.q.x >= MidPoint.x && Tr.q.y >= MidPoint.y && Tr.q.z >= MidPoint.z &&
                Tr.r.x >= MidPoint.x && Tr.r.y >= MidPoint.y && Tr.r.z >= MidPoint.z)
                return 0;

            if (Tr.p.x > MidPoint.x && Tr.p.y < MidPoint.y && Tr.p.z >= MidPoint.z &&
                Tr.q.x > MidPoint.x && Tr.q.y < MidPoint.y && Tr.q.z >= MidPoint.z &&
                Tr.r.x > MidPoint.x && Tr.r.y < MidPoint.y && Tr.r.z >= MidPoint.z)
                return 1;

            if (Tr.p.x < MidPoint.x && Tr.p.y > MidPoint.y && Tr.p.z >= MidPoint.z &&
                Tr.q.x < MidPoint.x && Tr.q.y > MidPoint.y && Tr.q.z >= MidPoint.z &&
                Tr.r.x < MidPoint.x && Tr.r.y > MidPoint.y && Tr.r.z >= MidPoint.z)
                return 2;

            if (Tr.p.x < MidPoint.x && Tr.p.y < MidPoint.y && Tr.p.z >= MidPoint.z &&
                Tr.q.x < MidPoint.x && Tr.q.y < MidPoint.y && Tr.q.z >= MidPoint.z &&
                Tr.r.x < MidPoint.x && Tr.r.y < MidPoint.y && Tr.r.z >= MidPoint.z)
                return 3;

            if (Tr.p.x >= MidPoint.x && Tr.p.y >= MidPoint.y && Tr.p.z < MidPoint.z &&
                Tr.q.x >= MidPoint.x && Tr.q.y >= MidPoint.y && Tr.q.z < MidPoint.z &&
                Tr.r.x >= MidPoint.x && Tr.r.y >= MidPoint.y && Tr.r.z < MidPoint.z)
                return 4;

            if (Tr.p.x > MidPoint.x && Tr.p.y < MidPoint.y && Tr.p.z < MidPoint.z &&
                Tr.q.x > MidPoint.x && Tr.q.y < MidPoint.y && Tr.q.z < MidPoint.z &&
                Tr.r.x > MidPoint.x && Tr.r.y < MidPoint.y && Tr.r.z < MidPoint.z)
                return 5;

            if (Tr.p.x < MidPoint.x && Tr.p.y > MidPoint.y && Tr.p.z < MidPoint.z &&
                Tr.q.x < MidPoint.x && Tr.q.y > MidPoint.y && Tr.q.z < MidPoint.z &&
                Tr.r.x < MidPoint.x && Tr.r.y > MidPoint.y && Tr.r.z < MidPoint.z)
                return 6;

            if (Tr.p.x < MidPoint.x && Tr.p.y < MidPoint.y && Tr.p.z < MidPoint.z &&
                Tr.q.x < MidPoint.x && Tr.q.y < MidPoint.y && Tr.q.z < MidPoint.z &&
                Tr.r.x < MidPoint.x && Tr.r.y < MidPoint.y && Tr.r.z < MidPoint.z)
                return 7;

            return -1;
        }


        template <typename T>
        ssize_t InsertTriangle(Octant<T>& Oct, const Triangle<T>& Tr)
        {
            int Corner = InWhichCorner(Tr, Oct);
            
            if(Corner && Oct.OctantTriangles.size() > 2)
            {

                if(Oct.SubOctants[Corner] == nullptr)
                {   
                    Vector<T> Min = Oct.Min;
                    Vector<T> Max = Oct.Max;
                    
                    if(Corner == 1)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = 0.5*(Min + Max);
                        Oct.SubOctants[Corner]->Max = Max;

                    }
                    
                    if(Corner == 2)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = {0.5*(Min.x + Max.x),        Min.y,        0.5*(Min.z + Max.z)};
                        Oct.SubOctants[Corner]->Max = {       Max.x,        0.5*(Min.y + Max.y),         Max.z};     
                    }
                    
                    if(Corner == 3)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = {       Min.x,        0.5*(Min.y + Max.y), 0.5*(Min.z + Max.z)}; 
                        Oct.SubOctants[Corner]->Max = {0.5*(Min.x + Max.x),        Max.y,                 Max.z};    
                    }


                    if(Corner == 4)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = {       Min.x,               Min.y,        0.5*(Min.z + Max.z)};
                        Oct.SubOctants[Corner]->Max = {0.5*(Min.x + Max.x), 0.5*(Min.y + Max.y),          Max.z};    
                    }

                    if(Corner == 5)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = {0.5*(Min.x + Max.x), 0.5*(Min.y + Max.y),          Min.z     };
                        Oct.SubOctants[Corner]->Max = {       Max.x,               Max.y,        0.5*(Min.z + Max.z)};
                    }

                    if(Corner == 6)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = {0.5*(Min.x + Max.x),        Min.y,                 Min.z     };
                        Oct.SubOctants[Corner]->Max = {       Max.x,        0.5*(Min.y + Max.y), 0.5*(Min.z + Max.z)};
                    }

                    if(Corner == 7)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = {       Min.x,        0.5*(Min.y + Max.y),          Min.z     };
                        Oct.SubOctants[Corner]->Max = {0.5*(Min.x + Max.x),        Max.y,        0.5*(Min.z + Max.z)};
                    }

                    if(Corner == 8)
                    {
                        Oct.SubOctants[Corner] = new Octant<T>;
                        Oct.SubOctants[Corner]->Min = Min;
                        Oct.SubOctants[Corner]->Max = 0.5*(Min + Max);
                    }
                }

                InsertTriangle(*Oct.SubOctants[Corner], Tr);

                return 0;
            }
            
            Oct.OctantTriangles.push_back(Tr);

            return 0;
        }

    }


        template <typename T>
        void TriangleIntersect(Octants::Octant<T>* OcTree, bool* IntArr)
        {
            int i = 0;
    
            typename std::vector<Triangle<T>>::iterator Iter1;
            typename std::vector<Triangle<T>>::iterator Iter2;
            
            for(Iter1 = OcTree->OctantTriangles.begin(); Iter1 != --(OcTree->OctantTriangles.end()); ++Iter1)
            {
                for(Iter2 = Iter1 + 1; Iter2 != OcTree->OctantTriangles.end(); ++Iter2)
                    if((IntArr[Iter1->TriangleNumber] != 1 || IntArr[Iter2->TriangleNumber] != 1) && IsIntersect(*Iter1, *Iter2))
                    {   
                        IntArr[Iter1->TriangleNumber] = 1;
                        IntArr[Iter2->TriangleNumber] = 1;
                    }   
            }


            // specially made to take into account cases when Tr does not fit
            // in the next octant but it has no intersections with triangles
            // in its own octant and has intersections with triangles in
            // lower nested octants. So Tr is being pushed into all suboctants
            // and then this function being called for each suboctant recursively
            for(Iter1 = OcTree->OctantTriangles.begin(); Iter1 != OcTree->OctantTriangles.end(); ++Iter1)
            {
                if(IntArr[Iter1->TriangleNumber] == 0)
                    for(i = 0; i < 8; ++i)
                        if (OcTree->SubOctants[i] != nullptr)
                        {
                            OcTree->SubOctants[i]->OctantTriangles.push_back(*Iter1);
                        }
            }

            for(i = 0; i < 8; ++i)
            {
                if(OcTree->SubOctants[i] != nullptr)
                    TriangleIntersect(OcTree->SubOctants[i], IntArr);
            } 

            return;
        }

}


#endif