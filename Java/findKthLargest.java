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





class Solution {
    public int findKthLargest(int[] nums, int k) {
        
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;

        for(int i:nums) {
            if(i>max)max=i;
            if(i<min)min=i;
        }

        int[] arr = new int[max-min+1];

        for(int i:nums) arr[i-min]++;

        for(int i=max-min; i>=0; i--) {
            k-=arr[i];
            if(k<=0) return i+min;
        }
        return -1;
    }
}
public class findKthLargest {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[] nums1 = {3, 2, 1, 5, 6, 4};
        int k1 = 2;
        int result1 = solution.findKthLargest(nums1, k1);
        System.out.println("Test case 1: Kth largest element is " + result1);

        // Test case 2
        int[] nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
        int k2 = 4;
        int result2 = solution.findKthLargest(nums2, k2);
        System.out.println("Test case 2: Kth largest element is " + result2);

        // Add more test cases here if needed
    }
}
