all:build test

build:
	clang++ main.cpp -o demo.out

test:
	echo "" && ./demo.out && echo "" && echo "test OK"
