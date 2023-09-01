/* Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> list1, list2;
        
        unordered_set<int> set1, set2;
        
        for (int num : nums1) {
            set1.insert(num);
        }
        
        for (int num : nums2) {
            set2.insert(num);
        }
        
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                list1.push_back(num);
            }
        }
        
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                list2.push_back(num);
            }
        }
        
        vector<vector<int>> answer;
        answer.push_back(list1);
        answer.push_back(list2);
        
        return answer;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    
    vector<vector<int>> result = solution.findDifference(nums1, nums2);
    
    cout << "Example 1:" << endl;
    cout << "[" << result[0][0];
    for (int i = 1; i < result[0].size(); i++) {
        cout << ", " << result[0][i];
    }
    cout << "]" << endl;
    
    cout << "[" << result[1][0];
    for (int i = 1; i < result[1].size(); i++) {
        cout << ", " << result[1][i];
    }
    cout << "]" << endl;
    
    // Clear the vectors for the next example
    nums1.clear();
    nums2.clear();
    
    nums1 = {1, 2, 3, 3};
    nums2 = {1, 1, 2, 2};
}