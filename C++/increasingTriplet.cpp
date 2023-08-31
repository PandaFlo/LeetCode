/*Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
Example 3:

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

Constraints:

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
 * 
 * 
 * 
 */



#include <vector>
#include <ostream>
#include <iostream>
class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int first = INT_MAX;  // Initialize with a very large value
        int second = INT_MAX; // Initialize with a very large value
        
        for (int num : nums) {
            if (num <= first) {
                first = num;
            } else if (num <= second) {
                second = num;
            } else {
                // num is greater than both first and second, triplet found
                return true;
            }
        }
        
        return false; // No valid triplet found
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::cout << solution.increasingTriplet(nums1) << std::endl; // Output: true
    
    std::vector<int> nums2 = {5, 4, 3, 2, 1};
    std::cout << solution.increasingTriplet(nums2) << std::endl; // Output: false
    
    std::vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    std::cout << solution.increasingTriplet(nums3) << std::endl; // Output: true
    
    return 0;
}
