#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

bool sortforpair( const pair<int, int>& p1, const pair<int, int>& p2) {
	if(p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;

}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int size = envelopes.size();
		if(size <= 1) {
			return size;
		}
		for(auto it = envelopes.begin();it != envelopes.end();it++) {
			if(it->second > it->first) {
				int tmp = it->first;
				it->first = it->second;
				it->second = tmp;
			}
		}    
		sort(envelopes.begin(), envelopes.end(), sortforpair);
		int max = 1;
		vector<int> store(size, 1);
		for(int i = 0;i < size;i++) {
			for(int j = i + 1;j < size;j++) {
				if(envelopes[i].first < envelopes[j].first && envelopes[i].second < envelopes[j].second) {
					if(store[i] + 1 > store[j]) {
						store[j] = store[i] + 1;
						if(store[j] > max) {
							max = store[j];
						}
					}
				}
			}
		}
		return max;
    }
};

int main() {
	Solution sol;
    return 0;
}
