/*
    Copyright 2018 Krzysztof Karbowiak
*/

#ifndef ISIN_H__DDK
#define ISIN_H__DDK

#include <initializer_list>


#define is_in(...) == isin_internal::is_in_get({__VA_ARGS__})
#define is_not_in(...) != isin_internal::is_in_get({__VA_ARGS__})

namespace isin_internal
{
    template<typename T>
    class is_in_check
    {
        public:
            is_in_check(std::initializer_list<T> const & args)
                : m_args(args)
            {
            }

            friend bool operator==(T const & lhs, is_in_check<T> const & rhs)
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

            friend bool operator!=(T const & lhs, is_in_check<T> const & rhs)
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
            std::initializer_list<T> const & m_args;
    };

    template<typename T>
    inline is_in_check<T> is_in_get(std::initializer_list<T> const & args)
    {
        return is_in_check<T>(args);
    }
}

#endif /* ISIN_H__DDK */

