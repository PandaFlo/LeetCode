/* Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
 */
#include <vector>
#include <stack>
#include <ostream>
#include <iostream>
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n, 0);
        std::stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int j = st.top();
                st.pop();
                result[j] = i - j;
            }
            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    std::vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> result1 = solution.dailyTemperatures(temperatures1);
    for (int i = 0; i < result1.size(); i++) {
        std::cout << result1[i] << " ";
    }
    std::cout << std::endl;

    // Test case 2
    std::vector<int> temperatures2 = {30, 40, 50, 60};
    std::vector<int> result2 = solution.dailyTemperatures(temperatures2);
    for (int i = 0; i < result2.size(); i++) {
        std::cout << result2[i] << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::vector<int> temperatures3 = {30, 60, 90};
    std::vector<int> result3 = solution.dailyTemperatures(temperatures3);
    for (int i = 0; i < result3.size(); i++) {
        std::cout << result3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
