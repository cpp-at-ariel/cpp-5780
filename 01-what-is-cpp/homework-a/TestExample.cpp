/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "Gimatriya.hpp"
using namespace ariel;

TEST_CASE("Test gimatriya without punctuation") {
    CHECK(gimatriya("א") == 1);
    CHECK(gimatriya("תשפ") == 780);
}


TEST_CASE("Test gimatriya with punctuation") {
    CHECK(gimatriya("'א") == 1);
    CHECK(gimatriya("תש\"פ") == 780);
}

