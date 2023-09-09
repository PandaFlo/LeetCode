/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
 */



#include <iostream>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};


void tester() {
    Solution solution;
    std::vector<std::vector<int>> testCases = {
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {1}
    };

    for (auto& nums : testCases) {
        int result = solution.singleNumber(nums);
        std::cout << "Input: [";
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i];
            if (i < nums.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        std::cout << "Output: " << result << std::endl << std::endl;
    }
}

int main() {
    tester();
    return 0;
}
