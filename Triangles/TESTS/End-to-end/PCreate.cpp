#include <iostream>
#include <cstdlib>
//#include <ctime>

int main()
{
    long long N = 0;
    std::cin >> N;

    int edge = 1000;

    std::cout << N << std::endl;

    //time_t t = time(NULL);

    //srand(t);

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