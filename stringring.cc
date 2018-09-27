#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace std;
//KMP is a good way but is hard to realize
bool checksame(const string& s1, const string& s2) {
	int size1 = s1.size();
	int size2 = s2.size();
	if(size1 != size2) {
		return false;
	}

	int i = 0;
	int j = 0;
	while(i < size1) {

	}

	return true;
}


int main() {
	string s1 = "abdaoisjfoiwenfoiwvnsdc";
	string s2 = "asiocnoeiw";
	bool result = checksame(s1, s2);
	cout << "result is " << result << endl;
    return 0;
}


