#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, char** argv) {
    doctest::Context context;
    //context.addFilter("reporters", "console");
    context.addFilter("reporters", "counter");
    context.run();  // returns 0 on success and 1 on failure
}
