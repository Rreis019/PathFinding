g++ -c src/*.cpp -std=c++14 -m64 -O3 -Wall -I include
g++ *.o -o bin/Release/main -s && start bin/Release/main