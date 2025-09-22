# https://github.com/happylife10201020/SortingAlgorithm?tab=readme-ov-file

all: compile run

compile: main.cpp
	g++ main.cpp -o sorting

run: sorting
	./sorting

clean:
	rm sorting