/* Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.�?�� */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_length = 0;
        int left = 0; // Left pointer of the sliding window
        int count_zeros = 0; // Count of zeros in the current window
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                count_zeros++;
            }
            
            // Shrink the window if there's more than one zero
            while (count_zeros > 1) {
                if (nums[left] == 0) {
                    count_zeros--;
                }
                left++;
            }
            
            max_length = max(max_length, right - left);
        }
        
        return max_length;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {1, 1, 0, 1};
    cout << solution.longestSubarray(nums1) << endl; // Output: 3
    
    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << solution.longestSubarray(nums2) << endl; // Output: 5
    
    vector<int> nums3 = {1, 1, 1};
    cout << solution.longestSubarray(nums3) << endl; // Output: 2
    
    return 0;
}
