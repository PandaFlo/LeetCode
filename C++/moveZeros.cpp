/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done? */



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i];

                if (i != nonZeroIndex) {
                    nums[i] = 0;
                }

                nonZeroIndex++;
            }
        }
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums1);
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {0};
    solution.moveZeroes(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
