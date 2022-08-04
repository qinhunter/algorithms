#include <iostream>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int times = p / gcd(p, q);
        int i = times % 2;
        int j = times * q / p % 2;
        // printf("t %d, i %d, j %d\n", times, i, j);
        if (i == 1 && j == 0) {
            return 0;
        } else if (i == 1 && j == 1) {
            return 1;
        } else if (i == 0 && j == 1) {
            return 2;
        }
        return -1;
    }
    int gcd(int a, int b) {
        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};

int main() {
    Solution sol;
    std::cout << sol.mirrorReflection(2, 1) << std::endl;
}
