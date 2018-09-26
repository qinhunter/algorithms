.PHONY:all
all: 131.o watercup.o 264.ugly_number2.o 300.Longest_Increasing_Subsequence.o splitstring.o 301.Remove_Invlid_Parentheses.o

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

300.Longest_Increasing_Subsequence.o:300.Longest_Increasing_Subsequence.cc
	@g++ -o $@ 300.Longest_Increasing_Subsequence.cc -std=c++11

splitstring.o:splitstring.cc
	@g++ -o $@ splitstring.cc -std=c++11

301.Remove_Invlid_Parentheses.o:301.Remove_Invlid_Parentheses.cc
	@g++ -o $@ 301.Remove_Invlid_Parentheses.cc -std=c++11
