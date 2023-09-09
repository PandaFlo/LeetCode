/* Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
 */


import java.util.Arrays;
class Solution {
    public int[] dailyTemperatures(int[] a) {
        int n = a.length;
        int hot = Integer.MIN_VALUE;
        int it = 0;
        int[] ans = new int[n];
        for(int i = n-1; i >= 0 ; i--){
           if(a[i] >= hot){
               hot = a[i];
           }else{
               it = i+1;
               while(a[it] <= a[i]){
                   it += ans[it];
               }
               ans[i] = it-i;
           }
        }
        return ans;
    }
}

public class dailyTemperatures {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
        int[] output1 = solution.dailyTemperatures(temperatures1);
        System.out.println(Arrays.toString(output1)); // Expected output: [1, 1, 4, 2, 1, 1, 0, 0]

        int[] temperatures2 = {30, 40, 50, 60};
        int[] output2 = solution.dailyTemperatures(temperatures2);
        System.out.println(Arrays.toString(output2)); // Expected output: [1, 1, 1, 0]

        int[] temperatures3 = {30, 60, 90};
        int[] output3 = solution.dailyTemperatures(temperatures3);
        System.out.println(Arrays.toString(output3)); // Expected output: [1, 1, 0]
    }
}
