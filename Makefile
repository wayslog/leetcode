all:build test

build:
	clang++ main.cpp -o demo

test:
	echo "" && ./demo && echo "" && echo "test OK"
