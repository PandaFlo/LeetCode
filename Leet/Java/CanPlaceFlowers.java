
import java.util.*;
/**
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

**/




public class CanPlaceFlowers {

    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 1) {
                i++;  // Skip the next position since it's occupied.
                continue;
            }
            if (i == 0 || flowerbed[i - 1] == 0) {
                if (i == flowerbed.length - 1 || flowerbed[i + 1] == 0) {
                    count++;  // Increment count for a potential flower placement.
                    i++;  // Skip the next position since it's adjacent.
                }
            }
        }
        return count >= n;  // Check if enough flowers can be placed.
    }

    public static void main(String[] args) {
        int[] flowerbed1 = {1, 0, 0, 0, 1};
        int n1 = 1;
        System.out.println("Can place flowers in flowerbed1: " + canPlaceFlowers(flowerbed1, n1));

        int[] flowerbed2 = {1, 0, 0, 0, 1};
        int n2 = 2;
        System.out.println("Can place flowers in flowerbed2: " + canPlaceFlowers(flowerbed2, n2));

        int[] flowerbed3 = {0, 0, 0, 0, 0};
        int n3 = 3;
        System.out.println("Can place flowers in flowerbed3: " + canPlaceFlowers(flowerbed3, n3));
    }
}

