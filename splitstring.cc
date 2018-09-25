#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<string> splitstring(const string& s, char separator) {
	vector<string> splited;
	for(int i = 0;i < s.size();i++) {
		int start = i;
		while(s[i] != separator && s[i] != '\0') {
			i++;
		}
		//we can pass the empty string
		if(i == start) {
			continue;
		}
		string tmp(s.substr(start, i - start));
		splited.push_back(tmp);
	}

	return splited;
}

int main() {
	string needtosplit("AB  asd * * **  S ABSOIBDSA Asubduiaebd asodas");
	cout << "The string need to be splited is: " << needtosplit << endl;
	vector<string> splited = splitstring(needtosplit, ' ');
	for(int i = 0; i < splited.size();i++) {
		cout << "i = " << i << ",\tsize = " << splited[i].size() << "\t" << splited[i] << endl;
	}
    return 0;
}
