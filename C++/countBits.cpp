/* Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
 

Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
 */



#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // To calculate the count of 1's in binary representation of i,
            // use the fact that dp[i] = dp[i >> 1] + (i & 1).
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void tester() {
    Solution solution;
    std::vector<int> testCases = {0, 1, 2, 5, 10};

    for (int n : testCases) {
        std::vector<int> result = solution.countBits(n);
        std::cout << "n = " << n << ", Output: ";
        printVector(result);
    }
}

int main() {
    tester();
    return 0;
}

