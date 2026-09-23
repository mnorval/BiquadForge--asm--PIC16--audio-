CC?=gcc
all:
	mkdir -p build
	$(CC) -std=c11 -O2 -Wall src/host_ref.c -o build/biquad_ref
clean:
	rm -rf build
