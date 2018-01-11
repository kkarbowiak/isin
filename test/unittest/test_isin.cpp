#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "isin.h"

#include <string>
#include <vector>


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

TEST_CASE("test is_in with std::string and braced-list")
{
    std::string v = "bar";

    CHECK(v is_in({"bar"}));
    CHECK(v is_in({"foo", "bar"}));
    CHECK(v is_in({"foo", "bar", "baz"}));
    CHECK_FALSE(v is_in({"foo"}));
    CHECK_FALSE(v is_in({"foo", "baz"}));
}

TEST_CASE("test is_in with int and std::vector")
{
    int v = 2;
    std::vector<int> vec1 = {2};
    std::vector<int> vec2 = {1, 2};
    std::vector<int> vec3 = {1, 2, 3};
    std::vector<int> vec4 = {1};
    std::vector<int> vec5 = {1, 3};

    CHECK(v is_in(vec1));
    CHECK(v is_in(vec2));
    CHECK(v is_in(vec3));
    CHECK_FALSE(v is_in(vec4));
    CHECK_FALSE(v is_in(vec5));
}
