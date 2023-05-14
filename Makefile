compile: main.cpp 
	 g++ Node.cpp theater.cpp LL.cpp main.cpp -o Movie

run: Movie
	 ./Movie Coco 19.30 1 9far11111 20.10 2 9arm 23.20 3 Johnwack 23.25 4 Moonwalk 15.10 5 Harrywalker 11.50 6


clean: Movie
	 rm Movie