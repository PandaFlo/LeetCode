'''Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000��'''


class Solution(object):
    def uniqueOccurrences(self, arr):
        # Create a dictionary to store occurrences of each value
        occurrences = {}

        # Populate the occurrences dictionary
        for num in arr:
            occurrences[num] = occurrences.get(num, 0) + 1

        # Create a set to store unique occurrences
        unique = set()

        # Check for unique occurrences
        for count in occurrences.values():
            if count in unique:
                return False  # Non-unique occurrence found
            unique.add(count)

        return True  # All occurrences are unique


def test_uniqueOccurrences():
    solution = Solution()

    test_cases = [
        {'arr': [1, 2, 2, 1, 1, 3], 'expected': True},
        {'arr': [1, 2], 'expected': False},
        {'arr': [-3, 0, 1, -3, 1, 1, 1, -3, 10, 0], 'expected': True}
    ]

    for test_case in test_cases:
        result = solution.uniqueOccurrences(test_case['arr'])
        print(f"Input: {test_case['arr']}, Expected: {test_case['expected']}, Result: {result}")

test_uniqueOccurrences()
