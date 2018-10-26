#pragma once

namespace DEV
{
    template< class T >
    class List
    {
    public:
        void Add( const T& Target )
        {
            this->PrivateList.push_back(Target);
        }

        std::list<T>& Get() { return PrivateList; }

    private:
        std::list<T> PrivateList;
    };
};
