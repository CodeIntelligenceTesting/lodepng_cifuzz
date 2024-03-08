#include <cifuzz/cifuzz.h>
#include <cstddef>
#include <cstdint>

// Include the existing libfuzzer fuzztest.
// We need to make sure that the functions
// LLVMFuzzerInitialize and LLVMFuzzerTestOneInput
// get renamed as they're used internally by cifuzz.
extern "C" int LLVMFuzzInit(int *argc, char ***argv) __attribute__((weak));
extern "C" int LLVMFuzzTest(const uint8_t *Data, size_t Size);
#define LLVMFuzzerInitialize LLVMFuzzInit
#define LLVMFuzzerTestOneInput LLVMFuzzTest
#include "lodepng/lodepng_fuzzer.cpp"
#undef LLVMFuzzerInitialize
#undef LLVMFuzzerTestOneInput

FUZZ_TEST_SETUP() {
    if(LLVMFuzzInit) {
        int argc = 0;
        char **argv = NULL;
        LLVMFuzzInit(&argc, &argv);
    }
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    LLVMFuzzTest(data, size);
}
