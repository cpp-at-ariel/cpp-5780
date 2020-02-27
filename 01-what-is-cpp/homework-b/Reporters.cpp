/*
   Based on example from here:
   https://github.com/onqtam/doctest/blob/master/doc/markdown/reporters.md
*/

#include "doctest.h"
#include <iostream>
using namespace doctest;

const int MIN_TESTS = 20;

struct ReporterCounter: public IReporter {
    // caching pointers/references to objects of these types - safe to do
    std::ostream&         stdout_stream;
    const ContextOptions& options;
    const TestCaseData*   test_case_data;

    // constructor has to accept the ContextOptions by ref as a single argument
    ReporterCounter(const ContextOptions& input_options)
            : stdout_stream(*input_options.cout)
            , options(input_options) {}

    void report_query(const QueryData& /*in*/) override {}
    void test_run_start() override {}
    void test_run_end(const TestRunStats& run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            std::cout << 100 << std::endl;
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl << 0  << std::endl;
        }
    }
    void test_case_start(const TestCaseData& input_data) override { test_case_data = &input_data; }
    void test_case_reenter(const TestCaseData& /*in*/) override {}
    void test_case_end(const CurrentTestCaseStats& /*in*/) override {}
    void test_case_exception(const TestCaseException& /*in*/) override {}
    void subcase_start(const SubcaseSignature& /*in*/) override {}
    void subcase_end() override { }
    void log_assert(const AssertData& rb) override {  }
    void log_message(const MessageData& /*in*/) override {}
    void test_case_skipped(const TestCaseData& /*in*/) override {}
};


struct ReporterGrader: public IReporter {
    // caching pointers/references to objects of these types - safe to do
    std::ostream&         stdout_stream;
    const ContextOptions& options;
    const TestCaseData*   test_case_data;

    // constructor has to accept the ContextOptions by ref as a single argument
    ReporterGrader(const ContextOptions& input_options)
            : stdout_stream(*input_options.cout)
            , options(input_options) {}

    void report_query(const QueryData& /*in*/) override {}
    void test_run_start() override {}
    void test_run_end(const TestRunStats& run_stats) override {
        // std::cout << run_stats.numTestCasesFailed << " " << " out of " << run_stats.numTestCasesPassingFilters << " tests failed" << std::endl;
        // std::cout << run_stats.numAssertsFailed << " " << " out of " << run_stats.numAsserts << " asserts failed" << std::endl;
        int numAsserts = run_stats.numAsserts >=  MIN_TESTS? run_stats.numAsserts:  MIN_TESTS;
        float grade = (run_stats.numAsserts - run_stats.numAssertsFailed) * 100 / numAsserts;
        std::cout << "Grade: " << grade << std::endl;
    }
    void test_case_start(const TestCaseData& input_data) override { test_case_data = &input_data; }
    void test_case_reenter(const TestCaseData& /*in*/) override {}
    void test_case_end(const CurrentTestCaseStats& /*in*/) override {}
    void test_case_exception(const TestCaseException& /*in*/) override {}
    void subcase_start(const SubcaseSignature& /*in*/) override {}
    void subcase_end() override { }
    void log_assert(const AssertData& rb) override {  }
    void log_message(const MessageData& /*in*/) override {}
    void test_case_skipped(const TestCaseData& /*in*/) override {}
};


// "1" is the priority - used for ordering when multiple reporters are used
REGISTER_REPORTER("counter", 1, ReporterCounter);
REGISTER_REPORTER("grader", 1, ReporterGrader);
