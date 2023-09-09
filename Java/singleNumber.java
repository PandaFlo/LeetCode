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
class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
}


public class singleNumber {
public static void main(String[] args) {
 

    Solution solution = new Solution();
    int[][] testCases = {
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {1}
    };

    for (int[] nums : testCases) {
        int result = solution.singleNumber(nums);
        System.out.print("Input: [");
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]);
            if (i < nums.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
        System.out.println("Output: " + result);
        System.out.println();
    }



}
}