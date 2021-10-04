#define NaN std::numeric_limits<double>::quiet_NaN()


namespace Geom {

	class Point
	{
	public:
		double x;
		double y;
		double z;

		void Read()
		{
			std::cin >> x >> y >> z;
		}

		Point(double px = NaN,
			  double py = NaN,
			  double pz = NaN)
		{	
			x = px;
			y = py;
			z = pz;
		}
	};


	class Segment 
	{
	public:
		Point m;
		Point n;

		Segment(Point& a, Point& b) { m.x = a.x; m.y = a.y; m.z = a.z; 
									  n.x = b.x; n.y = b.y; n.z = b.z;}
	};


	class Vector
	{
	public:
		double x;
		double y;
		double z;

		Vector(double vx = NaN, double vy = NaN, double vz = NaN)
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
	double operator*(const Vector& a, const Vector& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}


	//cross product
	Vector operator^(const Vector& a, const Vector& b)				
	{
		double x = a.y * b.z - b.y * a.z;
		double y = b.x * a.z - a.x * b.z;
		double z = a.x * b.y - b.x * a.y;
		return Vector(x, y, z);
	}


	//multiplying by scalar
	Vector operator*(double& k, const Vector& a)
	{
		return Vector(k * a.x, k * a.y, k * a.z);
	}


	//adding vectors
	Vector operator+(const Vector& a, const Vector& b)
	{
		double x = a.x + b.x;
		double y = a.y + b.y;
		double z = a.z + b.z;
		return Vector(x, y, z);
	}


	//subtracting vectors
	Vector operator-(const Vector& a, const Vector& b)
	{
		double x = a.x - b.x;
		double y = a.y - b.y;
		double z = a.z - b.z;
		return Vector(x, y, z);
	}


	//vector ba made of two points 
	Vector operator-(const Point& a, const Point& b)
	{
		double x = a.x - b.x;
		double y = a.y - b.y;
		double z = a.z - b.z;
		return Vector(x, y, z);	
	}


	class Triangle
	{
	public:	
		Point p;
		Point q;
		Point r;

		Segment pq = {p, q};
		Segment qr = {q, r};
		Segment rp = {r, p};
		
		bool IsValid()
		{
			if((q.y - p.y)*(r.z - q.z) - (r.y - q.y)*(q.z - p.z) == 0 &&               // vector product
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
			return;
		}

		Triangle(Point A = {NaN, NaN, NaN}, Point B = {NaN, NaN, NaN}, Point C = {NaN, NaN, NaN})
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

		}
	};


	void SwapPoints(Point& a, Point& b);
	bool Is2DIntersect(Triangle& T1, Triangle& T2);
	bool IsParallel(const Vector& a, const Vector& b);
	bool IsParallel(const Segment& a, const Segment& b);
	bool IsSegmIntersect(const Segment& a, const Segment& b);
	double Determ(const Point& a, const Point& b, const Point& c, const Point& d);


	//core function of whole program
	bool IsIntersect(Triangle& T1, Triangle& T2)
	{
		double T1p2 = Determ(T1.p, T1.q, T1.r, T2.p), 
			   T1q2 = Determ(T1.p, T1.q, T1.r, T2.q),
			   T1r2 = Determ(T1.p, T1.q, T1.r, T2.r); 
		
		//if all three points of T2 lie in the same open halfspace induced by T1
		if (T1p2 * T1q2 > 0 && T1p2 * T1r2 > 0 && T1q2 * T1r2 > 0)
			return false;


		double T2p1 = Determ(T2.p, T2.q, T2.r, T1.p),
			   T2q1 = Determ(T2.p, T2.q, T2.r, T1.q), 
			   T2r1 = Determ(T2.p, T2.q, T2.r, T1.r);

		//if all three points of T1 lie in the same open halfspace induced by T2
		if (T2p1 * T2q1 > 0 && T2p1 * T2r1 > 0 && T2q1 * T2r1 > 0)
			return false;

		//if both triangles lie in same plane
		if(T1p2 == 0 && T1q2 == 0 && T1r2 == 0)
			return Is2DIntersect(T1, T2);

		// if 2 of vertices lie in other triangle's plane
		if(T1p2 == 0 && T1q2 == 0 && T1r2 != 0)
			return (IsSegmIntersect(T2.pq, T1.pq) || IsSegmIntersect(T2.pq, T1.qr) || IsSegmIntersect(T2.pq, T1.rp));
		if(T1p2 == 0 && T1r2 == 0 && T1q2 != 0)
			return (IsSegmIntersect(T2.rp, T1.pq) || IsSegmIntersect(T2.rp, T1.qr) || IsSegmIntersect(T2.rp, T1.rp));
		if(T1r2 == 0 && T1q2 == 0 && T1p2 != 0)
			return (IsSegmIntersect(T2.qr, T1.pq) || IsSegmIntersect(T2.qr, T1.qr) || IsSegmIntersect(T2.qr, T1.rp));
		
		if(T2p1 == 0 && T2q1 == 0 && T2r1 != 0)
			return (IsSegmIntersect(T1.pq, T2.pq) || IsSegmIntersect(T1.pq, T2.qr) || IsSegmIntersect(T1.pq, T2.rp));
		if(T2p1 == 0 && T2r1 == 0 && T2q1 != 0)
			return (IsSegmIntersect(T1.rp, T2.pq) || IsSegmIntersect(T1.rp, T2.qr) || IsSegmIntersect(T1.rp, T2.rp));
		if(T2r1 == 0 && T2q1 == 0 && T2p1 != 0)
			return (IsSegmIntersect(T1.qr, T2.pq) || IsSegmIntersect(T1.qr, T2.qr) || IsSegmIntersect(T1.qr, T2.rp));
		
		// if 1 or no vertex lie in other triangle's plane

		// making point p one with determinant sign (or zero) different from others
		while(Determ(T2.p, T2.q, T2.r, T1.p) * Determ(T2.p, T2.q, T2.r, T1.q) > 0 || 
			  Determ(T2.p, T2.q, T2.r, T1.p) * Determ(T2.p, T2.q, T2.r, T1.r) > 0)
		{
			SwapPoints(T1.p, T1.q);																	
			SwapPoints(T1.q, T1.r);
		}

		// same
		while(Determ(T1.p, T1.q, T1.r, T2.p) * Determ(T1.p, T1.q, T1.r, T2.q) > 0 ||
			  Determ(T1.p, T1.q, T1.r, T2.p) * Determ(T1.p, T1.q, T1.r, T2.r) > 0)
		{
			SwapPoints(T2.p, T2.q);
			SwapPoints(T2.q, T2.r);
		}

		// swapping point q and r for triangles to be oriented counter-clockwise 
		if(Determ(T2.p, T2.q, T2.r, T1.p) < 0)
			SwapPoints(T2.q, T2.r);
		if(Determ(T1.p, T1.q, T1.r, T2.p) < 0)
			SwapPoints(T1.q, T1.r);


		if(Determ(T1.p, T1.q, T2.p, T2.q) <= 0 && Determ(T1.p, T1.r, T2.r, T2.p) <= 0) 
			return true;

		return false;
	}


	bool Is2DIntersect(Triangle& T1, Triangle& T2)
	{
		if(IsSegmIntersect(T1.pq, T2.pq) || IsSegmIntersect(T1.pq, T2.qr) || IsSegmIntersect(T1.pq, T2.rp) || 	//checking if one of 
		   IsSegmIntersect(T1.qr, T2.pq) || IsSegmIntersect(T1.qr, T2.qr) || IsSegmIntersect(T1.qr, T2.rp) ||	//sides of triangle
		   IsSegmIntersect(T1.rp, T2.pq) || IsSegmIntersect(T1.rp, T2.qr) || IsSegmIntersect(T1.rp, T2.rp))		//crosses edge of another
		return true;

		return false;
	}


	double Determ(const Point& a, const Point& b, const Point& c, const Point& d)
	{
		return  ((a.x - d.x)*((b.y - d.y)*(c.z - d.z) - (c.y - d.y)*(b.z - d.z)) 				//checking if the 4th point lies 
			  -  (a.y - d.y)*((b.x - d.x)*(c.z - d.z) - (c.x - d.x)*(b.z - d.z))				//in the plane induced by other points
			  +  (a.z - d.z)*((b.x - d.x)*(c.y - d.y) - (c.x - d.x)*(b.y - d.y))); 
	}


	void SwapPoints(Point& a, Point& b)															//swapping two points
	{
		Point tmp = {0, 0, 0};
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


	bool IsSegmIntersect(const Segment& a, const Segment& b)
	{
		Vector a1 = a.m - a.n;				//directing vectors
		Vector a2 = b.m - b.n;

		//checking if a1 || a2
		if(IsParallel(a1, a2))				//if a1 || a2
		{
			if(IsParallel(a1, a.m - b.m))   //if lines induced by a and b coincide
			{
				if((fmin(a.m.x, a.n.x) <= fmax(b.m.x, b.n.x) && fmin(b.m.x, b.n.x) <= fmax(a.m.x, a.n.x)) || 	//segments on line induced
				   (fmin(a.m.y, a.n.y) <= fmax(b.m.y, b.n.y) && fmin(b.m.y, b.n.y) <= fmax(a.m.y, a.n.y)))		//by a and b intersect
					return true;
			}
			return false;
		}


		// a1 !(||) a2
		// t-parameter of line r = r0 + at
		double t = 0;
		if(a2.x - a1.x != 0)
			t = (a.m.x - b.m.x) / (a2.x - a1.x);
		else if(a2.y - a1.y != 0)
			t = (a.m.y - b.m.y) / (a2.y - a1.y);
		else 
			t = (a.m.z - b.m.z) / (a2.z - a1.z); 

		Point OInt = {a.m.x + t * a1.x, a.m.y + t * a1.y, a.m.z + t * a1.z};

		if((a.m - OInt) * (a.n - OInt) <= 0 && (b.m - OInt) * (b.n - OInt) <= 0)						
			return true;

		return false;
	}


	bool IsParallel(const Vector& a, const Vector& b)
	{	
		if ((a.y * b.z - b.y * a.z) == 0 && b.x * a.z - a.x * b.z == 0 && a.x * b.y - b.x * a.y == 0)    //is vector product zero
			return true;

		return false;
	}


	bool IsParallel(const Segment& a, const Segment& b)
	{	
		return IsParallel(a.m - a.n, b.m - b.n);
	}

}