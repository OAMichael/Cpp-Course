#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include "Geometry.hpp"


int main(int argc, char* argv[])
{	
	int N = 0;
	std::cin >> N;
	
/*	while(!std::cin.good())
	{
		std::cout << "Incorrect input.\nPlease enter value correctly:" << std::endl;
		std::cin.clear();
		std::cin.ignore('\n');
		std::cin >> N;
	}	*/

	Geom::Triangle<double>* TrSet = new Geom::Triangle<double>[N]{};

	int i = 0, j = 0;

	for(i = 0; i < N; i++)
	{

		std::cin >> TrSet[i].p.x >> TrSet[i].p.y >> TrSet[i].p.z
				 >> TrSet[i].q.x >> TrSet[i].q.y >> TrSet[i].q.z
				 >> TrSet[i].r.x >> TrSet[i].r.y >> TrSet[i].r.z;

		TrSet[i].pq = {TrSet[i].p, TrSet[i].q};
		TrSet[i].qr = {TrSet[i].q, TrSet[i].r};
		TrSet[i].rp = {TrSet[i].r, TrSet[i].p};
	}


	std::cout << "Read" << std::endl;
	return 0;

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

	i = 0;
	while(TrSet[N-1].IntersectIndex == 0)
	{
			if(IsIntersect(TrSet[N-1], TrSet[i]))
			{	
				TrSet[i].IntersectIndex = 1;
				TrSet[N-1].IntersectIndex = 1;
			}
			i++;
	}

//	std::cout << "#Tr Valid/Intsct" << std::endl;
	for (i = 0; i < N; i++){

		if(TrSet[i].IntersectIndex != 0)
		{
			std::cout << i;
//			std::cout << "\t" << TrSet[i].IsValid() << "/" << TrSet[i].IntersectIndex;
			std::cout << std::endl;
		}
//		else std::cout << "\t" << TrSet[i].IsValid() << "/" << TrSet[i].IntersectIndex << std::endl;
	}
	delete[] TrSet;

	return 0;
}


