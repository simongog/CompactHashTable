g++ -O3 -Wall -fpermissive -std=c++11 -w -Wall  -Wextra  -DNDEBUG  -g -ffast-math -funroll-loops -msse4.2 -I ~/include -L ~/lib  cht.cpp main.cpp -o main -lsdsl -ldivsufsort -ldivsufsort64

./main 700000 200000 0.25 10
