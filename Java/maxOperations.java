/* You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109 */


import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxOperations(int[] nums, int k) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;
            
            if (freqMap.containsKey(complement) && freqMap.get(complement) > 0) {
                operations++;
                freqMap.put(complement, freqMap.get(complement) - 1);
            } else {
                freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
            }
        }

        return operations;
    }
}

public class maxOperations {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        int[] nums1 = {1, 2, 3, 4};
        int k1 = 5;
        int result1 = solution.maxOperations(nums1, k1);
        System.out.println("Result 1: " + result1); // Output: 2
        
        int[] nums2 = {3, 1, 3, 4, 3};
        int k2 = 6;
        int result2 = solution.maxOperations(nums2, k2);
        System.out.println("Result 2: " + result2); // Output: 1
    }
}
