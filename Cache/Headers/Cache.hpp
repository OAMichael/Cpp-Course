#ifndef CACHE_H
#define CACHE_H


namespace Caches
{
    // Division of size between the lists
    const double InSizeFrac = 0.25;
    const double OutSizeFrac = 0.5;

    // Types of lists
    enum ListType
    {
        IN,
        OUT,
        HOT
    };


    // Single node of our list
    // Contains information about <data> and type of its list
    template <typename T> 
    struct Node
    {
        ListType Type;
        T data;
    };


    // Description of one of the lists
    template <typename T>
    class DataList 
    {   

    private:

        size_t ListSize;

    public:

        std::list<Node<T>> List;

        bool IsFull() const
        {
            return (ListSize <= List.size());
        }

        void set_size(size_t NewSize)
        {
            ListSize = NewSize;
            return;
        }

        size_t size() const 
        {
            return ListSize;
        }

    DataList() {}
    DataList(const size_t NewSize) : ListSize{NewSize} {} 

    };


    // Main class of whole program
    template <typename T, typename Key>
    class Cache2Q 
    {

    private:

        const size_t CacheSize;
        size_t HitsNumber = 0;

    public:

        // Declaration of cache lists
        DataList<T> In{ (static_cast<size_t>(CacheSize * InSizeFrac)  > 0) ? static_cast<size_t>(CacheSize * InSizeFrac)  : 1};

        DataList<T> Out{(static_cast<size_t>(CacheSize * OutSizeFrac) > 0) ? static_cast<size_t>(CacheSize * OutSizeFrac) : 1};

        DataList<T> Hot{(CacheSize > In.size() + Out.size()) ? CacheSize - In.size() - Out.size() : 1};  

        using ListIter = typename std::list<Node<T>>::iterator;
        using MapIter  = typename std::unordered_map<Key, ListIter>::iterator;

        std::unordered_map<Key, ListIter> Map; 


        size_t hits() const 
        {
            return HitsNumber;
        }


        void NewPageInsert(const Node<T>& NewPage)
        {
            ListIter InsertedPage;

            // If list <In> is not full, just inserting new page
            // Otherwise, popping out last element of <Out>, 
            // moving last element of <In> to begining of <Out>
            // and finally insert new page into <In> list
            if(In.IsFull())
            {
                MapIter LastNodeIN = Map.find(In.List.back().data);
                
                if(Out.IsFull())
                {
                    Map.erase(Map.find(Out.List.back().data));
                    Out.List.pop_back();
                }

                LastNodeIN->second->Type = OUT;
                Out.List.splice(Out.List.begin(), In.List, LastNodeIN->second);
            }

            InsertedPage = In.List.insert(In.List.begin(), NewPage);
            Map.insert({NewPage.data, InsertedPage});
            
            return;
        }


        void PageGet(const Node<T>& Page)
        {
            MapIter CurPage = Map.find(Page.data);

            // If there is no needed page in cache, insert it
            if(CurPage == Map.end())
            {
                NewPageInsert(Page);
                return;
            }
            else
            {
                ++HitsNumber;

                // But if cache has needed page, do what 2QCache assumes
                // depending on what list type where hit was
                switch(CurPage->second->Type)
                {
                    case IN:    return;

                    case OUT:
                    {
                        if(Hot.IsFull())
                        {
                            Map.erase(Map.find(Hot.List.back().data));
                            Hot.List.pop_back();
                        }

                        Hot.List.splice(Hot.List.begin(), Out.List, CurPage->second);

                        CurPage->second = Hot.List.begin();
                        CurPage->second->Type = HOT;

                        return;
                    }

                    case HOT:
                    {
                        Hot.List.splice(Hot.List.begin(), Hot.List, CurPage->second);
                        return;
                    }
                }
            }
        }


        Cache2Q() {}
        Cache2Q(const size_t NewSize) : CacheSize{NewSize} {}

    };
}


#endif   // CACHE_H