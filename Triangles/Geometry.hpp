namespace Geom {

    template <typename T>
    const T NaN = std::numeric_limits<T>::quiet_NaN();

    template <typename T>
    class Point
    {
    public:
        T x;
        T y;
        T z;

        void Read()
        {
            std::cin >> x >> y >> z;
        }

        Point(T px = NaN<T>,
              T py = NaN<T>,
              T pz = NaN<T>)
        {   
            x = px;
            y = py;
            z = pz;
        }
    };


    template <typename T>
    class Segment 
    {
    public:
        Point<T> m;
        Point<T> n;

        void Read()
        {
            m.Read();
            n.Read();
            return;
        }

        Segment(Point<T>& a, Point<T>& b) { m.x = a.x; m.y = a.y; m.z = a.z; 
                                      n.x = b.x; n.y = b.y; n.z = b.z;}

        Segment(T x1, T y1, T z1, T x2, T y2, T z2) 
        { m.x = x1; m.y = y1; m.z = z1; n.x = x2; n.y = y2; n.z = z2;}
    };


    template <typename T>
    class Vector
    {
    public:
        T x;
        T y;
        T z;

        Vector(T vx = NaN<T>, T vy = NaN<T>, T vz = NaN<T>)
        {
            x = vx;
            y = vy;
            z = vz;
        }

        double GetLenght()
        {
            return sqrt(x * x + y * y + z * z);
        }

    };


    //dot product
    template <typename T>
    T operator*(const Vector<T>& a, const Vector<T>& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }


    //cross product
    template <typename T>
    Vector<T> operator^(const Vector<T>& a, const Vector<T>& b)              
    {
        T x = a.y * b.z - b.y * a.z;
        T y = b.x * a.z - a.x * b.z;
        T z = a.x * b.y - b.x * a.y;
        return Vector<T>(x, y, z);
    }


    //multiplying by scalar
    template <typename T>
    Vector<T> operator*(T& k, const Vector<T>& a)
    {
        return Vector<T>(k * a.x, k * a.y, k * a.z);
    }


    //adding vectors
    template <typename T>
    Vector<T> operator+(const Vector<T>& a, const Vector<T>& b)
    {
        T x = a.x + b.x;
        T y = a.y + b.y;
        T z = a.z + b.z;
        return Vector<T>(x, y, z);
    }


    //subtracting vectors
    template <typename T>
    Vector<T> operator-(const Vector<T>& a, const Vector<T>& b)
    {
        T x = a.x - b.x;
        T y = a.y - b.y;
        T z = a.z - b.z;
        return Vector<T>(x, y, z);
    }


    //vector ba made of two points 
    template <typename T>
    Vector<T> operator-(const Point<T>& a, const Point<T>& b)
    {
        T x = a.x - b.x;
        T y = a.y - b.y;
        T z = a.z - b.z;
        return Vector<T>(x, y, z); 
    }


    template <typename T>
    bool operator==(const Point<T>& a, const Point<T>& b)
    {
        return (a.x == b.x && a.y == b.y && a.z == b.z);
    }


    template <typename T>
    class Triangle
    {
    public: 
        Point<T> p;
        Point<T> q;
        Point<T> r;
        
        Segment<T> pq = {p, q};
        Segment<T> qr = {q, r};
        Segment<T> rp = {r, p};

        bool IsValid()
        {
            if((q.y - p.y)*(r.z - q.z) - (r.y - q.y)*(q.z - p.z) == 0 &&               // cross product
               (q.x - p.x)*(r.z - q.z) - (r.x - q.x)*(q.z - p.z) == 0 &&
               (q.x - p.x)*(r.y - q.y) - (r.x - q.x)*(q.y - p.y) == 0)
                return false;

            return true;
        }

        void Read()
        {
            p.Read();
            q.Read();
            r.Read();

            pq = {p, q};
            qr = {q, r};
            rp = {r, p};

            return;
        }

        bool IntersectIndex = 0;


        double GetPerimeter()
        {
            return ((p - q).GetLenght() + (q-r).GetLenght() + (r - p).GetLenght());
        }

        Triangle(Point<T> A = {NaN<T>, NaN<T>, NaN<T>}, Point<T> B = {NaN<T>, NaN<T>, NaN<T>}, Point<T> C = {NaN<T>, NaN<T>, NaN<T>})
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

        }


    };


    template <typename T>
    void SwapPoints(Point<T>& a, Point<T>& b);

    template <typename T>
    bool Is2DIntersect(Triangle<T>& T1, Triangle<T>& T2);

    template <typename T>
    bool IsParallel(const Vector<T>& a, const Vector<T>& b);

    template <typename T>
    bool IsParallel(const Segment<T>& a, const Segment<T>& b);

    template <typename T>
    bool Is2DSegmIntersect(const Segment<T>& a, const Segment<T>& b);

    template <typename T>
    bool Is3DSegmIntersect(const Segment<T>& a, const Segment<T>& b);

    template <typename T>
    bool IsPointInTriangle(const Triangle<T>& Tr, const Point<T>& p);

    template <typename T>
    bool IsNotValidIntersect(Triangle<T>& T1, Triangle<T>& T2);
    
    template <typename T>
    T Determ(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d);


  
    //core function of whole program
    template <typename T>
    bool IsIntersect(Triangle<T>& T1, Triangle<T>& T2)
    {
        if(T1.IsValid() && T2.IsValid())
        {
            T   T1p2 = Determ<T>(T1.p, T1.q, T1.r, T2.p), 
                T1q2 = Determ<T>(T1.p, T1.q, T1.r, T2.q),
                T1r2 = Determ<T>(T1.p, T1.q, T1.r, T2.r); 
            
            //if all three points of T2 lie in the same open halfspace induced by T1
            if (T1p2 * T1q2 > 0 && T1p2 * T1r2 > 0 && T1q2 * T1r2 > 0)
                return false;


            T   T2p1 = Determ<T>(T2.p, T2.q, T2.r, T1.p),
                T2q1 = Determ<T>(T2.p, T2.q, T2.r, T1.q), 
                T2r1 = Determ<T>(T2.p, T2.q, T2.r, T1.r);

            //if all three points of T1 lie in the same open halfspace induced by T2
            if (T2p1 * T2q1 > 0 && T2p1 * T2r1 > 0 && T2q1 * T2r1 > 0)
                return false;

            //if both triangles lie in same plane
            if(T1p2 == 0 && T1q2 == 0 && T1r2 == 0)
                return Is2DIntersect<T>(T1, T2);

            // if 2 of vertices lie in other triangle's plane
            if(T1p2 == 0 && T1q2 == 0 && T1r2 != 0)
                return (Is2DSegmIntersect<T>(T2.pq, T1.pq) || Is2DSegmIntersect<T>(T2.pq, T1.qr) || Is2DSegmIntersect<T>(T2.pq, T1.rp));
            if(T1p2 == 0 && T1r2 == 0 && T1q2 != 0)
                return (Is2DSegmIntersect<T>(T2.rp, T1.pq) || Is2DSegmIntersect<T>(T2.rp, T1.qr) || Is2DSegmIntersect<T>(T2.rp, T1.rp));
            if(T1r2 == 0 && T1q2 == 0 && T1p2 != 0)
                return (Is2DSegmIntersect<T>(T2.qr, T1.pq) || Is2DSegmIntersect<T>(T2.qr, T1.qr) || Is2DSegmIntersect<T>(T2.qr, T1.rp));
            
            if(T2p1 == 0 && T2q1 == 0 && T2r1 != 0)
                return (Is2DSegmIntersect<T>(T1.pq, T2.pq) || Is2DSegmIntersect<T>(T1.pq, T2.qr) || Is2DSegmIntersect<T>(T1.pq, T2.rp));
            if(T2p1 == 0 && T2r1 == 0 && T2q1 != 0)
                return (Is2DSegmIntersect<T>(T1.rp, T2.pq) || Is2DSegmIntersect<T>(T1.rp, T2.qr) || Is2DSegmIntersect<T>(T1.rp, T2.rp));
            if(T2r1 == 0 && T2q1 == 0 && T2p1 != 0)
                return (Is2DSegmIntersect<T>(T1.qr, T2.pq) || Is2DSegmIntersect<T>(T1.qr, T2.qr) || Is2DSegmIntersect<T>(T1.qr, T2.rp));
            
            // if 1 or no vertex lie in other triangle's plane

            // making point p one with determinant sign (or zero) different from others
            while(Determ<T>(T2.p, T2.q, T2.r, T1.p) * Determ<T>(T2.p, T2.q, T2.r, T1.q) > 0 || 
                  Determ<T>(T2.p, T2.q, T2.r, T1.p) * Determ<T>(T2.p, T2.q, T2.r, T1.r) > 0)
            {
                SwapPoints<T>(T1.p, T1.q);                                                                 
                SwapPoints<T>(T1.q, T1.r);
            }

            // same
            while(Determ<T>(T1.p, T1.q, T1.r, T2.p) * Determ<T>(T1.p, T1.q, T1.r, T2.q) > 0 ||
                  Determ<T>(T1.p, T1.q, T1.r, T2.p) * Determ<T>(T1.p, T1.q, T1.r, T2.r) > 0)
            {
                SwapPoints<T>(T2.p, T2.q);
                SwapPoints<T>(T2.q, T2.r);
            }

            // swapping point q and r for triangles to be oriented counter-clockwise 
            if(Determ<T>(T2.p, T2.q, T2.r, T1.p) < 0)
                SwapPoints<T>(T2.q, T2.r);
            if(Determ<T>(T1.p, T1.q, T1.r, T2.p) < 0)
                SwapPoints<T>(T1.q, T1.r);


            if(Determ<T>(T1.p, T1.q, T2.p, T2.q) <= 0 && Determ<T>(T1.p, T1.r, T2.r, T2.p) <= 0) 
                return true;

            return false;
        }
        else
            return IsNotValidIntersect<T>(T1, T2);    // case when one or both triangles not valid
    }


    template <typename T>
    bool Is2DIntersect(Triangle<T>& T1, Triangle<T>& T2)
    {
        if(Is2DSegmIntersect<T>(T1.pq, T2.pq) || Is2DSegmIntersect<T>(T1.pq, T2.qr) || Is2DSegmIntersect<T>(T1.pq, T2.rp) ||   //checking if one of 
           Is2DSegmIntersect<T>(T1.qr, T2.pq) || Is2DSegmIntersect<T>(T1.qr, T2.qr) || Is2DSegmIntersect<T>(T1.qr, T2.rp) ||   //sides of triangle
           Is2DSegmIntersect<T>(T1.rp, T2.pq) || Is2DSegmIntersect<T>(T1.rp, T2.qr) || Is2DSegmIntersect<T>(T1.rp, T2.rp))     //crosses edge of another
        return true;

        return false;
    }


    template <typename T>
    T Determ(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d)
    {
        return  ((a.x - d.x)*((b.y - d.y)*(c.z - d.z) - (c.y - d.y)*(b.z - d.z))                //checking if the 4th point lies 
              -  (a.y - d.y)*((b.x - d.x)*(c.z - d.z) - (c.x - d.x)*(b.z - d.z))                //in the plane induced by other points
              +  (a.z - d.z)*((b.x - d.x)*(c.y - d.y) - (c.x - d.x)*(b.y - d.y))); 
    }


    template <typename T>
    void SwapPoints(Point<T>& a, Point<T>& b)                                                         //swapping two points
    {
        Point<T> tmp = {0, 0, 0};
        tmp.x = a.x;
        tmp.y = a.y;
        tmp.z = a.z;

        a.x = b.x;
        a.y = b.y;
        a.z = b.z;

        b.x = tmp.x;
        b.y = tmp.y;
        b.z = tmp.z;
    }


    template <typename T>
    bool Is2DSegmIntersect(const Segment<T>& a, const Segment<T>& b)
    {
        Vector<T> a1 = a.m - a.n;              //directing vectors
        Vector<T> a2 = b.m - b.n;

        //checking if a1 || a2
        if(IsParallel<T>(a1, a2))              //if a1 || a2
        {
            if(IsParallel<T>(a1, a.m - b.m))   //if lines induced by a and b coincide
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
    bool IsParallel(const Vector<T>& a, const Vector<T>& b)
    {   
        if ((a.y * b.z - b.y * a.z) == 0 && b.x * a.z - a.x * b.z == 0 && a.x * b.y - b.x * a.y == 0)    //is cross product zero
            return true;

        return false;
    }


    template <typename T>
    bool IsParallel(const Segment<T>& a, const Segment<T>& b)
    {   
        return IsParallel<T>(a.m - a.n, b.m - b.n);
    }


    template <typename T>
    bool IsPointInTriangle(const Triangle<T>& Tr, const Point<T>& O)
    {
        Vector<T> Op = Tr.p - O;
        Vector<T> Oq = Tr.q - O;
        Vector<T> Or = Tr.r - O;

        if( acos((Op * Oq)/(Op.GetLenght() * Oq.GetLenght())) + acos((Oq * Or)/(Oq.GetLenght() * Or.GetLenght())) + 
            acos((Or * Op)/(Or.GetLenght() * Op.GetLenght())) < 2.0 * M_PI)
            return false;

        return true;
    }


    template <typename T>
    bool IsNotValidIntersect(Triangle<T>& T1, Triangle<T>& T2)
    {
        // if T2 is not valid
        if(T1.IsValid() && !T2.IsValid())
        {

            T   T1p2 = Determ<T>(T1.p, T1.q, T1.r, T2.p), 
                T1q2 = Determ<T>(T1.p, T1.q, T1.r, T2.q),
                T1r2 = Determ<T>(T1.p, T1.q, T1.r, T2.r);

            if(T1p2 * T1q2 <= 0 || T1p2 * T1r2 <= 0 || T1q2 * T1r2 <= 0)
            {

                Vector<T> n = (T1.q - T1.p) ^ (T1.r - T1.q);
                double t = 0;

                if ((T1.p - T2.p) * n != 0)
                    t = ((T1.p - T2.p) * n)/((T2.p - T2.q) * n);

                // point of intersection of T1's plane and T2-line
                Point<T> O{T2.p.x - T1.p.x + t * (T2.p.x - T2.q.x), T2.p.y - T1.p.y + t * (T2.p.y - T2.q.y), T2.p.z - T1.p.z + t * (T2.p.z - T2.q.z)};

                return IsPointInTriangle<T>(T1, O);
            }

            return false;
        }

        // if T1 is not valid
        if(T2.IsValid() && !T1.IsValid())
        {

            T   T2p1 = Determ<T>(T2.p, T2.q, T2.r, T1.p),
                T2q1 = Determ<T>(T2.p, T2.q, T2.r, T1.q), 
                T2r1 = Determ<T>(T2.p, T2.q, T2.r, T1.r);

            if(T2p1 * T2q1 <= 0 || T2p1 * T2r1 <= 0 || T2q1 * T2r1 <= 0)
            {
                Vector<T> n = (T2.q - T2.p) ^ (T2.r - T2.q);
                double t = 0;

                if ((T2.p - T1.p) * n != 0)
                    t = ((T2.p - T1.p) * n)/((T1.p - T1.q) * n);

                // point of intersection of T2's plane and T1-line
                Point<T> O{T1.p.x - T2.p.x + t * (T1.p.x - T1.q.x), T1.p.y - T2.p.y + t * (T1.p.y - T1.q.y), T1.p.z - T2.p.z + t * (T1.p.z - T1.q.z)};

                return IsPointInTriangle<T>(T2, O);
            }

            return false;
        }

        // both invalid
        return (Is3DSegmIntersect<T>(T1.pq, T2.pq) || Is3DSegmIntersect<T>(T1.pq, T2.qr) || Is3DSegmIntersect<T>(T1.pq, T2.rp) || 
                Is3DSegmIntersect<T>(T1.qr, T2.pq) || Is3DSegmIntersect<T>(T1.qr, T2.qr) || Is3DSegmIntersect<T>(T1.qr, T2.rp) ||   
                Is3DSegmIntersect<T>(T1.rp, T2.pq) || Is3DSegmIntersect<T>(T1.rp, T2.qr) || Is3DSegmIntersect<T>(T1.rp, T2.rp));
    }


    template <typename T>
    bool Is3DSegmIntersect(const Segment<T>& a, const Segment<T>& b)
    {
        if((a.m - b.m) * ((a.m - a.n)^(b.m - b.n)) == 0)
            return Is2DSegmIntersect<T>(a, b);

        return false;
    }
}

