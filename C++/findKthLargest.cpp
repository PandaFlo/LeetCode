/* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 */


#include <iostream>
#include <vector>
#include <algorithm>  // Include this header

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        nth_element(nums.begin(), nums.end() - k, nums.end());

        return nums[nums.size()-k];
    }
};

void testFindKthLargest() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int result1 = solution.findKthLargest(nums1, k1);
    std::cout << "Test case 1: Kth largest element is " << result1 << std::endl;

    // Test case 2
    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    int result2 = solution.findKthLargest(nums2, k2);
    std::cout << "Test case 2: Kth largest element is " << result2 << std::endl;

    // Add more test cases here if needed
}

int main() {
    testFindKthLargest();
    return 0;
}

