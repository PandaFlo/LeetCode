/* Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length� */


class Solution {
    public int longestOnes(int[] nums, int k) {
        int maxOnes = 0;  // To keep track of the maximum consecutive ones
        int left = 0;     // Left pointer of the sliding window
        int zeros = 0;    // Count of zeros inside the current window
        
        // Iterate through the array using the right pointer
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                zeros++;  // Increment zero count
                
                // If zero count exceeds k, move the left pointer
                while (zeros > k) {
                    if (nums[left] == 0) {
                        zeros--;
                    }
                    left++;
                }
            }
            
            // Calculate the maximum length of consecutive ones
            maxOnes = Math.max(maxOnes, right - left + 1);
        }
        
        return maxOnes;
    }
}

public class longestOnes{
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        int[] nums1 = {1,1,1,0,0,0,1,1,1,1,0};
        int k1 = 2;
        System.out.println(solution.longestOnes(nums1, k1));  // Output: 6
        
        int[] nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int k2 = 3;
        System.out.println(solution.longestOnes(nums2, k2));  // Output: 10
    }
}

