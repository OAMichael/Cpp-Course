#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "Geometry.hpp"


int main()
{	
	int N = 0;
	std::cin >> N;

	Geom::Triangle* TrSet = new Geom::Triangle[N]{};

	int i = 0, j = 0;

	for(i = 0; i < N; i++)
	{

		TrSet[i].Read();
	}


	for (i = 0; i < N - 1; i++)
	{	
		if(TrSet[i].IntersectIndex == 0)
		for(j = i + 1; j < N; j++)
			if(IsIntersect(TrSet[i], TrSet[j]))
				{
					TrSet[i].IntersectIndex = 1;
					TrSet[j].IntersectIndex = 1;
				}
	}  

//	delete[] TrSet;

//	std::cout << "Those triangles have intersections with others:" << std::endl;
	for (i = 0; i < N; i++){
//		std::cout << i + 1 << ") ";
		if(TrSet[i].IntersectIndex != 0)
			std::cout << i << "\t" << TrSet[i].IsValid() << TrSet[i].IntersectIndex <<   std::endl;
		else std::cout << "\t" << TrSet[i].IsValid() << TrSet[i].IntersectIndex <<  std::endl;
	}

	return 0;
}


