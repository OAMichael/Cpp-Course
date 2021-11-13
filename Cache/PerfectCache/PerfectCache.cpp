#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <iterator>
#include <unordered_map>


// Function prototypes because the last one is too messy
void PrintCache(std::list<int>& Cache);
size_t FindFutureNumber(const std::vector<int>& Pages, const std::vector<int>::iterator& Start, const int& Page);
size_t PerfectCache(const size_t CacheSize, const size_t NumberOfPages);



int main()
{
    size_t Hits = 0,
           NumberOfPages = 0;
    
    size_t CacheSize = 0;

    std::cin >> CacheSize;
    assert(std::cin.good());

    std::cin >> NumberOfPages;
    assert(std::cin.good());


    std::cout << PerfectCache(CacheSize, NumberOfPages) << std::endl;

    return 0;
}


// Function which finds how many other pages before one with same value
size_t FindFutureNumber(const std::vector<int>& Pages, const std::vector<int>::iterator& Start, const int& Page)
{
    size_t Counter = 0;

    std::vector<int>::iterator Iter = Start;
    std::vector<int>::const_iterator End = Pages.end();

    for(Iter; Iter != End; ++Iter)
    {
        if(*Iter == Page)
            return Counter;
        else
            ++Counter;
    }

    return Counter;
}


// Just printing all elements of cache at present moment
void PrintCache(std::list<int>& Cache)
{
    for(std::list<int>::iterator It = Cache.begin(); It != Cache.end(); ++It)
        std::cout << " " << *It;
    return;
}


size_t PerfectCache(const size_t CacheSize, const size_t NumberOfPages)
{
    size_t Hits = 0;
    std::vector<int> Pages;
    std::list<int> Cache;

    using VecIter  = typename std::vector<int>::iterator;
    using ListIter = typename std::list<int>::iterator;
    using MapIter  = typename std::unordered_map<int, ListIter>::iterator;

    std::unordered_map<int, ListIter> Map;

    int i = 0;
    int NewPage = 0;
    for(i = 0; i < NumberOfPages; ++i)
    {
        std::cin >> NewPage;
        assert(std::cin.good());
        Pages.push_back(NewPage);
    }

    VecIter PagesIter = Pages.begin();
    VecIter PagesEnd  = Pages.end();

    MapIter FoundPage;

    // Going through whole array again to fill in the cache
    for(PagesIter; PagesIter != PagesEnd; ++PagesIter)
    {
        FoundPage = Map.find(*PagesIter);

        // If needed page is found, then increase hit counter 
        // and replace it on the top within the cache.
        
        // If it is not, remove particular page and insert new one
        if(FoundPage == Map.end())
        {
            if(Cache.size() >= CacheSize)
            {
                int MaxFutureNumber = 0;
                int WhatPage = -1;

                ListIter CacheIter = Cache.begin();
                ListIter CacheEnd  = Cache.end();

                // Finding page in the cache which will appear at the most distance 
                for(CacheIter; CacheIter != CacheEnd; ++CacheIter)
                {
                    if(FindFutureNumber(Pages, PagesIter, *CacheIter) > MaxFutureNumber)
                    {
                        MaxFutureNumber = FindFutureNumber(Pages, PagesIter, *CacheIter);
                        WhatPage = *CacheIter;
                    }
                }

                // And removing it
                for(CacheIter = Cache.begin(); CacheIter != CacheEnd; ++CacheIter)
                {
                    if(*CacheIter == WhatPage)
                    {
                        Map.erase(Map.find(WhatPage));
                        Cache.erase(CacheIter);
                        break;
                    }

                }

            }

            Map.insert({*PagesIter, Cache.insert(Cache.begin(), *PagesIter)});
            
        }
        else
        {
            ++Hits;
            Cache.splice(Cache.begin(), Cache, FoundPage->second);
        }
    }
    return Hits;
}