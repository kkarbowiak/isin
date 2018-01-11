#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "isin.h"


enum Values
{
    EVALUE_1,
    EVALUE_2,
    EVALUE_3,
    EVALUE_4,
    EVALUE_5
};

TEST_CASE("test is_in with int and braced-list")
{
    int v = 2;

    CHECK(v is_in({2}));
    CHECK(v is_in({1, 2}));
    CHECK(v is_in({1, 2, 3}));
    CHECK_FALSE(v is_in({1}));
    CHECK_FALSE(v is_in({1, 3}));
}

TEST_CASE("test is_in with enum and braced-list")
{
    Values v = EVALUE_2;

    CHECK(v is_in({EVALUE_2}));
    CHECK(v is_in({EVALUE_1, EVALUE_2}));
    CHECK(v is_in({EVALUE_1, EVALUE_2, EVALUE_3}));
    CHECK_FALSE(v is_in({EVALUE_1}));
    CHECK_FALSE(v is_in({EVALUE_1, EVALUE_3}));
}

TEST_CASE("test is_in with char and braced-list")
{
    char v = 'b';

    CHECK(v is_in({'b'}));
    CHECK(v is_in({'a', 'b'}));
    CHECK(v is_in({'a', 'b', 'c'}));
    CHECK_FALSE(v is_in({'a'}));
    CHECK_FALSE(v is_in({'a', 'c'}));
}
