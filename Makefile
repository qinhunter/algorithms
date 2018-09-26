.PHONY:all
all: 131.o watercup.o 264.ugly_number2.o 300.Longest_Increasing_Subsequence.o splitstring.o 301.Remove_Invalid_Parentheses.o 199.Binary_Tree_Right_Side_View.o 200.Number_of_Islands.o 329.Longest_Increasing_Path_in_a_Matrix.o

.PHONY:clean
clean:
	@echo "Cleaning *.o"
	@rm -rf *.o
131.o:131.Palindrome_Partitioning.cc
	@echo "g++ -o $@ 131.Palindrome_Partitioning.cc -std=c++11"
	@g++ -o $@ 131.Palindrome_Partitioning.cc -std=c++11

watercup.o:WaterCup.cc
	@echo "g++ -o $@ WaterCup.cc -std=c++11"
	@g++ -o $@ WaterCup.cc -std=c++11

264.ugly_number2.o:264.ugly_number2.cc
	@echo "g++ -o $@ 264.ugly_number2.cc -std=c++11"
	@g++ -o $@ 264.ugly_number2.cc -std=c++11

300.Longest_Increasing_Subsequence.o:300.Longest_Increasing_Subsequence.cc
	@echo "g++ -o $@ 300.Longest_Increasing_Subsequence.cc -std=c++11"
	@g++ -o $@ 300.Longest_Increasing_Subsequence.cc -std=c++11

splitstring.o:splitstring.cc
	@echo "g++ -o $@ splitstring.cc -std=c++11"
	@g++ -o $@ splitstring.cc -std=c++11

301.Remove_Invalid_Parentheses.o:301.Remove_Invalid_Parentheses.cc
	@echo "g++ -o $@ 301.Remove_Invalid_Parentheses.cc -std=c++11"
	@g++ -o $@ 301.Remove_Invalid_Parentheses.cc -std=c++11

199.Binary_Tree_Right_Side_View.o:199.Binary_Tree_Right_Side_View.cc
	@echo "g++ -o $@ 199.Binary_Tree_Right_Side_View.cc -std=c++11"
	@g++ -o $@ 199.Binary_Tree_Right_Side_View.cc -std=c++11

200.Number_of_Islands.o:200.Number_of_Islands.cc
	@echo "g++ -o $@ 200.Number_of_Islands.cc -std=c++11"
	@g++ -o $@ 200.Number_of_Islands.cc -std=c++11

329.Longest_Increasing_Path_in_a_Matrix.o:329.Longest_Increasing_Path_in_a_Matrix.cc
	@echo "g++ -o $@ 329.Longest_Increasing_Path_in_a_Matrix.cc -std=c++11"
	@g++ -o $@ 329.Longest_Increasing_Path_in_a_Matrix.cc -std=c++11
