# Lodepng fuzz test with CI Fuzz

This is an example fuzz test using CI Fuzz to test the lodepng library. The test file `fuzz_lodepng_decode.cpp` serves as a wrapper for the original test `lodepng/lodepng_fuzzer.cpp`, which is written for the libFuzzer interface.

**Building and running the test**

```sh
# Clone the repository, including submodules
git clone --recurse-submodules https://github.com/henrikschnor/lodepng_cifuzz.git
cd lodepng_cifuzz

# Build and run the fuzz test with CI Fuzz
cifuzz run fuzz_lodepng_decode
```
