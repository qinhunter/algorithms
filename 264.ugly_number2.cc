#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		int index2 = 0;
		int index3 = 0;
		int index5 = 0;
		int tmp2 = 0;
		int tmp3 = 0;
		int tmp5 = 0;
		vector<int> store;
		store.push_back(1);
		for(int i = 1;i < n;i++) {
			tmp2 = store[index2] * 2;
			tmp3 = store[index3] * 3;
			tmp5 = store[index5] * 5;
			if(tmp2 < tmp3 && tmp2 < tmp5) {
				index2++;
				store.push_back(tmp2);
				continue;
			} else if(tmp3 < tmp2 && tmp3 < tmp5) {
				index3++;
				store.push_back(tmp3);
				continue;
			} else if(tmp5 < tmp2 && tmp5 < tmp3) {
				index5++;
				store.push_back(tmp5);
				continue;
			} else if(tmp2 == tmp3 && tmp2 == tmp5) {
				index2++;
				index3++;
				index5++;
				store.push_back(tmp2);
				continue;
			} else if(tmp2 == tmp3) {
				index2++;
				index3++;
				store.push_back(tmp2);
				continue;
			} else if(tmp3 == tmp5) {
				index3++;
				index5++;
				store.push_back(tmp5);
				continue;
			} else if(tmp2 == tmp5) {
				index2++;
				index5++;
				store.push_back(tmp2);
				continue;
			}
		}
		for(int i = 0;i < store.size();i++) {
			cout << store[i] << " ";
		}	
		cout << endl;
		return store[n - 1];
    }
};

int main() {
	Solution sol;
	int n = 100;
	int ans = sol.nthUglyNumber(n);
	cout << "n = " << n << ", nth ugly number = " << ans << endl;
    return 0;
}
