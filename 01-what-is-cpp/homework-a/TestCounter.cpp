#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 20;

struct ReporterCounter: public IReporter {
    std::ostream&         stdout_stream;
    const ContextOptions& options;
    const TestCaseData*   test_case_data;

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
REGISTER_REPORTER("counter", 1, ReporterCounter);

int main(int argc, char** argv) {
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
}
