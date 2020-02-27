/**
 * Test program for Gimatriya calculation.
 * 
 * Date: 2020-02
 * 
 * IMPORTANT: THE TESTS BELOW ARE ONLY A SMALL EXAMPLE.
 *            PLEASE ADD MORE TESTS.
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

