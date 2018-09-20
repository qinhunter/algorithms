.PHONY:all
all: 131.o watercup.o 264.ugly_number2.o

.PHONY:clean
clean:
	@echo "Cleaning *.o"
	@rm -rf *.o
131.o:131.Palindrome_Partitioning.cc
	@g++ -o $@ 131.Palindrome_Partitioning.cc -std=c++11

watercup.o:WaterCup.cc
	@g++ -o $@ WaterCup.cc -std=c++11

264.ugly_number2.o:264.ugly_number2.cc
	@g++ -o $@ 264.ugly_number2.cc -std=c++11