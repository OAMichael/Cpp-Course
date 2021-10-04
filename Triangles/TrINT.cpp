
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

	int TrNum[N] = {0};
	int i = 0, j = 0;

	for(i = 0; i < N; i++)
	{

		TrSet[i].Read();
	}

	for (i = 0; i < N - 1; i++)
	{	
		if((TrNum[i] == 0) && TrSet[i].IsValid())
		for(j = i + 1; j < N; j++)
			if(TrSet[j].IsValid() && IsIntersect(TrSet[i], TrSet[j]))
				{
					TrNum[i] = 1;
					TrNum[j] = 1;
				}
	}  

	delete[] TrSet;

//	std::cout << "Those triangles have intersections with others:" << std::endl;
	for (i = 0; i < N; i++){
//		std::cout << i + 1 << ") ";
		if(TrNum[i] != 0)
			std::cout << i << std::endl;
		else std::cout << std::endl;
	}
	return 0;
}


