#include "gmock/gmock.h"

#include "MultipleTest.h"

using namespace vsampler;

int main(int argc, char *argv[]) {
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);
    return MultipleTest::run(argc, argv);
}
