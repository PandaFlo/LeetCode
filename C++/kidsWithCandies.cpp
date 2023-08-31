/*

There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

 

Example 1:

Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 
Explanation: If you give all extraCandies to:
- Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
- Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
- Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
- Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
- Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
Example 2:

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false] 
Explanation: There is only 1 extra candy.
Kid 1 will always have the greatest number of candies, even if a different kid is given the extra candy.
Example 3:

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
 

Constraints:

n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50



*/






#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end()); // Find the maximum number of candies
        
        vector<bool> result;
        
        for (int i = 0; i < candies.size(); ++i) {
            result.push_back(candies[i] + extraCandies >= maxCandies);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    vector<bool> result1 = solution.kidsWithCandies(candies1, extraCandies1);
    
    cout << "Result 1: ";
    for (bool val : result1) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    vector<bool> result2 = solution.kidsWithCandies(candies2, extraCandies2);
    
    cout << "Result 2: ";
    for (bool val : result2) {
        cout << val << " ";
    }
    cout << endl;
    
    vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;
    vector<bool> result3 = solution.kidsWithCandies(candies3, extraCandies3);
    
    cout << "Result 3: ";
    for (bool val : result3) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
