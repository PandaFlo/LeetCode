/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

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
-1000 <= arr[i] <= 1000�� */
import java.util.HashMap;
import java.util.HashSet;


class Solution {
    public boolean uniqueOccurrences(int[] arr) {
                // Create a hash map to store occurrences of each value
        HashMap<Integer, Integer> occurrences = new HashMap<>();

        // Populate the occurrences hash map
        for (int num : arr) {
            occurrences.put(num, occurrences.getOrDefault(num, 0) + 1);
        }

        // Create a hash set to store unique occurrences
        HashSet<Integer> unique = new HashSet<>();

        // Check for unique occurrences
        for (int count : occurrences.values()) {
            if (unique.contains(count)) {
                return false; // Non-unique occurrence found
            }
            unique.add(count);
        }

        return true; // All occurrences are unique
    }
}

public class uniqueOccurrences{
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] arr1 = {1, 2, 2, 1, 1, 3};
        System.out.println("Test 1: " + solution.uniqueOccurrences(arr1)); // Expected output: true

        int[] arr2 = {1, 2};
        System.out.println("Test 2: " + solution.uniqueOccurrences(arr2)); // Expected output: false

        int[] arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
        System.out.println("Test 3: " + solution.uniqueOccurrences(arr3)); // Expected output: true
    }
}
