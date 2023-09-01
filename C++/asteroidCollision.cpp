/* You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s.*/



#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> asteroidStack;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                asteroidStack.push(asteroid);
            } else {
                while (!asteroidStack.empty() && asteroidStack.top() > 0 && asteroidStack.top() < -asteroid) {
                    asteroidStack.pop();
                }

                if (asteroidStack.empty() || asteroidStack.top() < 0) {
                    asteroidStack.push(asteroid);
                } else if (asteroidStack.top() == -asteroid) {
                    asteroidStack.pop();
                }
            }
        }

        std::vector<int> result(asteroidStack.size());
        for (int i = asteroidStack.size() - 1; i >= 0; --i) {
            result[i] = asteroidStack.top();
            asteroidStack.pop();
        }

        return result;
    }
};


int main() {
    Solution solution;

    std::vector<int> asteroids1 = {5, 10, -5};
    std::vector<int> result1 = solution.asteroidCollision(asteroids1);
    for (int asteroid : result1) {
        std::cout << asteroid << " ";
    }
    std::cout << std::endl; // Output: 5 10

    std::vector<int> asteroids2 = {8, -8};
    std::vector<int> result2 = solution.asteroidCollision(asteroids2);
    for (int asteroid : result2) {
        std::cout << asteroid << " ";
    }
    std::cout << std::endl; // Output: 

    std::vector<int> asteroids3 = {10, 2, -5};
    std::vector<int> result3 = solution.asteroidCollision(asteroids3);
    for (int asteroid : result3) {
        std::cout << asteroid << " ";
    }
    std::cout << std::endl; // Output: 10

    return 0;
}

