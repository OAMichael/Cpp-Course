#include <iostream>
#include <cstdlib>

int main()
{
    long long N = 0;
    std::cin >> N;

    int edge = 32000;

    std::cout << N << std::endl;

    for(long long i = 0; i < N; i++)
    {
        std::cout << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t" << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t" 
                  << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t" << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t"
                  << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t" << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t"
                  << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t" << -edge + rand() % (2 * edge) << "." << rand() % 100 << "\t\t"
                  << -edge + rand() % (2 * edge) << "." << rand() % 100 << std::endl;
    }

    return 0; 
}
