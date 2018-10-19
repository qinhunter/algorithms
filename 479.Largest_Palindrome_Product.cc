#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    int largestPalindrome(int n) {
        long long int start = 1;
        for(int i = 1;i < n;i++) {
            start *= 10;
        }
        long long int end = start * 10 - 1;
        for(int i = end;i >= start;i--) {
            for(int j = end;j >= start;j--) {
                if(valid(i, j)) {
		    cout << "i = " << i << ", j = " << j << endl;
		    cout << "i * j = " << i * j << endl;
                    return (i*j)%1337;
                }
            }
        }
        return (start * start) % 1337;
    }
    bool valid(long long int i, long long int j) {
        long long product = i * j;
        string test = to_string(product);
        int m = 0;
        int n = test.size() - 1;
        while(m < n) {
            if(test[m] != test[n]) {
                return false;
            }
            m++;
            n--;
        }
        return true;
    }
};


int main() {
	Solution sol;
    return 0;
}
