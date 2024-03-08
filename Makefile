CXX ?= clang++
CXXFLAGS += $(FUZZ_TEST_CFLAGS)
LDFLAGS += $(FUZZ_TEST_LDFLAGS)


.PHONY: all clean

all: fuzz_lodepng_decode


lodepng.o: lodepng/lodepng.cpp lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) -c -I lodepng -o $@ $<

lodepng.a: lodepng.o
	ar rc $@ $^

fuzz_lodepng_decode.o: fuzz_lodepng_decode.cpp
	$(CXX) $(CXXFLAGS) -c -I lodepng -o $@ $<

fuzz_lodepng_decode: fuzz_lodepng_decode.o lodepng.a
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	rm -f lodepng.o lodepng.a fuzz_lodepng_decode.o fuzz_lodepng_decode
