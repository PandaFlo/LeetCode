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
#include <stdio.h>

    int minFlips(int a, int b, int c) {
        int answer = 0;
        while (a != 0 | b != 0 | c != 0) {
            /* we need a resulting 1 */
            if ((c & 1) == 1) {
                /* we need to flip one digit */
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++;
                }
            } else {
                /* both need to be 0, so add how many should be flipped */
                answer += (a & 1) + (b & 1);
            }
            /* process the next digit */
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }



int minFlips(int a, int b, int c);

void tester() {
    int testCases[][3] = {
        {2, 6, 5},
        {4, 2, 7},
        {1, 2, 3}
    };

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; i++) {
        int a = testCases[i][0];
        int b = testCases[i][1];
        int c = testCases[i][2];
        
        int result = minFlips(a, b, c);
        
        printf("Input: a=%d, b=%d, c=%d\n", a, b, c);
        printf("Output: %d\n\n", result);
    }
}

int main() {
    tester();
    return 0;
}


