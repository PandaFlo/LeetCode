'''Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

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
'''
class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        n = len(temperatures)
        arr = [0] * n
        maxTemp = 0
        for i in range(n - 1, -1, -1):
            temp = temperatures[i]
            if temp >= maxTemp:
                maxTemp = temp
                continue

            day = 1
            while temp >= temperatures[i + day]:
                day += arr[i + day]
            
            arr[i] = day
        
        return arr
solution = Solution()

temperatures1 = [73, 74, 75, 71, 69, 72, 76, 73]
output1 = solution.dailyTemperatures(temperatures1)
print(output1)  # Expected output: [1, 1, 4, 2, 1, 1, 0, 0]

temperatures2 = [30, 40, 50, 60]
output2 = solution.dailyTemperatures(temperatures2)
print(output2)  # Expected output: [1, 1, 1, 0]

temperatures3 = [30, 60, 90]
output3 = solution.dailyTemperatures(temperatures3)
print(output3)  # Expected output: [1, 1, 0]
