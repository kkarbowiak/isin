/*
    Copyright 2018 Krzysztof Karbowiak
*/

#ifndef ISIN_H__DDK
#define ISIN_H__DDK

#include <initializer_list>


#define is_in(...) == isin_internal::is_in_get(__VA_ARGS__)
#define is_not_in(...) != isin_internal::is_in_get(__VA_ARGS__)

namespace isin_internal
{
    template<class C>
    class is_in_check
    {
        public:
            is_in_check(C const & args)
                : m_args(args)
            {
            }

            template<typename T>
            friend bool operator==(T const & lhs, is_in_check<C> const & rhs)
            {
                for (auto a : rhs.m_args)
                {
                    if (a == lhs)
                    {
                        return true;
                    }
                }

                return false;
            }

            template<typename T>
            friend bool operator!=(T const & lhs, is_in_check<C> const & rhs)
            {
                for (auto a : rhs.m_args)
                {
                    if (a == lhs)
                    {
                        return false;
                    }
                }

                return true;
            }

        private:
            C const & m_args;
    };

    template<class C>
    inline is_in_check<C> is_in_get(C const & args)
    {
        return is_in_check<C>(args);
    }

    template<typename T>
    inline is_in_check<std::initializer_list<T>> is_in_get(std::initializer_list<T> const & args)
    {
        return is_in_check<std::initializer_list<T>>(args);
    }
}

#endif /* ISIN_H__DDK */

