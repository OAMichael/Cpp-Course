#include <iostream>
#include <cstdlib>

int main()
{
	long long N = 0;
	std::cin >> N;

	std::cout << N << std::endl;
	for(long long i = 0; i < N; i++)
	{
		std::cout << -1000 + rand() % 2000 << " " << -1000 + rand() % 2000 << " " << -1000 + rand() % 2000 << " " 
				  << -1000 + rand() % 2000 << " " << -1000 + rand() % 2000 << " " << -1000 + rand() % 2000 << " " 
				  << -1000 + rand() % 2000 << " " << -1000 + rand() % 2000 << " " << -1000 + rand() % 2000 << " " << std::endl;
	}

	return 0; 
}