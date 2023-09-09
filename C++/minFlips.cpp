/* Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

Example 1:
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0
 

Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
 */


#include <iostream>

class Solution {
public:
    int minFlips(int a, int b, int c);
};

int Solution::minFlips(int a, int b, int c) {
    int flips = 0;
    
    while (a != 0 || b != 0 || c != 0) {
        int bitA = a & 1;
        int bitB = b & 1;
        int bitC = c & 1;
        
        if (bitC == 1) {
            if (bitA == 0 && bitB == 0) {
                flips += 1;
            }
        } else {
            flips += bitA + bitB;
        }
        
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    
    return flips;
}

void tester() {
    Solution solution;

    int testCases[][3] = {
        {2, 6, 5},  // Expected: 3
        {4, 2, 7},  // Expected: 2
        {1, 2, 3}   // Expected: 0
    };

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        int a = testCases[i][0];
        int b = testCases[i][1];
        int c = testCases[i][2];
        
        int result = solution.minFlips(a, b, c);
        
        std::cout << "Input: a=" << a << ", b=" << b << ", c=" << c << std::endl;
        std::cout << "Output: " << result << std::endl << std::endl;
    }
}

int main() {
    tester();
    return 0;
}
