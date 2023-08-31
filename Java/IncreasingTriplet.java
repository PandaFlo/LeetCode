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


public class IncreasingTriplet {
    public boolean increasingTriplet(int[] nums) {
        int firstMin = Integer.MAX_VALUE;
        int secondMin = Integer.MAX_VALUE;
        
        for (int num : nums) {
            if (num <= firstMin) {
                firstMin = num;
            } else if (num <= secondMin) {
                secondMin = num;
            } else {
                return true; // Found the triplet
            }
        }
        
        return false; // No triplet found
    }
    
    public static void main(String[] args) {
        IncreasingTriplet solution = new IncreasingTriplet();
        
        int[] nums1 = {1, 2, 3, 4, 5};
        System.out.println(solution.increasingTriplet(nums1)); // Output: true
        
        int[] nums2 = {5, 4, 3, 2, 1};
        System.out.println(solution.increasingTriplet(nums2)); // Output: false
        
        int[] nums3 = {2, 1, 5, 0, 4, 6};
        System.out.println(solution.increasingTriplet(nums3)); // Output: true
    }
}