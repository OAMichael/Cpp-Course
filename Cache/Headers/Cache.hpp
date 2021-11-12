#ifndef CACHE_H
#define CACHE_H


namespace Caches
{
    const double InSizeFrac = 0.25;
    const double OutSizeFrac = 0.5;

    enum ListType
    {
        IN,
        OUT,
        HOT
    };


    template <typename T> 
    struct Node
    {
        ListType Type;
        T data;
    };


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


    template <typename T, typename Key>
    class Cache2Q 
    {

    private:

        const size_t CacheSize;
        size_t HitsNumber = 0;

    public:

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

            if(CurPage == Map.end())
            {
                NewPageInsert(Page);
                return;
            }
            else
            {
                ++HitsNumber;

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