#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"


/* See here https://github.com/onqtam/doctest/blob/master/doc/markdown/main.md for more options */
int main(int argc, char** argv) {
    doctest::Context context;
    context.addFilter("reporters", "console");   // options: "console", "xml", "empty", "grader"
    context.run();  // alternative: return context.run()
}
