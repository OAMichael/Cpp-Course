#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "Geometry.hpp"


int main()
{	
	int N = 0;
	std::cin >> N;

	Geom::Triangle<double>* TrSet = new Geom::Triangle<double>[N]{};

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

	std::cout << "#Tr Valid/Intsct" << std::endl;
	for (i = 0; i < N; i++){

		if(TrSet[i].IntersectIndex != 0)
			std::cout << i << "\t" << TrSet[i].IsValid() << "/" << TrSet[i].IntersectIndex << std::endl;
		else std::cout << "\t" << TrSet[i].IsValid() << "/" << TrSet[i].IntersectIndex << std::endl;
	}
	delete[] TrSet;

	return 0;
}


