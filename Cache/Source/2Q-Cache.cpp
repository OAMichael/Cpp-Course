#include <iostream>
#include <cassert>
#include <list>
#include <iterator>
#include <unordered_map>
#include "../Headers/Cache.hpp"

int main()
{
    size_t CacheSize = 0;
    size_t PageNum = 0;

    std::cin >> CacheSize;
    assert(std::cin.good());

    std::cin >> PageNum;
    assert(std::cin.good());
    
    int Page = 0;
    Caches::Cache2Q<int, int> MyCache{CacheSize};

    for(int i = 0; i < PageNum; ++i)
    {
        std::cin >> Page;
        Caches::Node<int> NewPage = {Caches::IN, Page};
        MyCache.PageGet(NewPage);
    }


    //std::cout << MyCache.In.size() << " " << MyCache.Out.size() << " " << MyCache.Hot.size() << std::endl;
    std::cout << "Hits: " << MyCache.hits() << std::endl;

    return 0;
}