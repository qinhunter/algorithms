#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> power;
    int temp = 0;
    for(int i = 0;i < n;i++) {
        cin >> temp;
        power.push_back(temp);
    }
    int k = 0;
    int d = 0;
    cin >> k >> d;
//    cout << "n = " << n << " k = " << k << " d = " << d << endl;
//    for(auto it = power.begin();it != power.end();it++) {
//        cout << *it;
//    }
//    cout << endl;

    long long maxtemp[k][n];
    long long mintemp[k][n];
    memset(maxtemp, LONG_LONG_MIN, sizeof(long long) * k * n);
    memset(mintemp, LONG_LONG_MAX, sizeof(long long) * k * n);
    for(int j = 0;j < n;j++) {
        maxtemp[0][j] = power[j];
        mintemp[0][j] = power[j];
    }
    for(int i = 1;i < k;i++) {
        for(int j = i;j <= n - k + i;j++) {
            for(int x = 1;x <= d && j - x >= 0;x++) {
                if(maxtemp[i - 1][j - x] > maxtemp[i][j]) {
                    maxtemp[i][j] = maxtemp[i - 1][j - x];
                }
                if(mintemp[i - 1][j - x] < mintemp[i][j]) {
                    mintemp[i][j] = mintemp[i - 1][j - x];
                }
            }
            maxtemp[i][j] *= power[j];
            mintemp[i][j] *= power[j];
            if(mintemp[i][j] > maxtemp[i][j]) {
                long long temp = maxtemp[i][j];
                maxtemp[i][j] = mintemp[i][j];
                mintemp[i][j] = temp;
            }
        }
    }

    long long maxans = INT_MIN;
    for(int j = k - 1;j < n;j++) {
        if(maxtemp[k - 1][j] > maxans) {
            maxans = maxtemp[k - 1][j];
        }
        if(mintemp[k - 1][j] > maxans) {
            maxans = mintemp[k - 1][j];
        }
    }
    cout << maxans;
    return 0;
}