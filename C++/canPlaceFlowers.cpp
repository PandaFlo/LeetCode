/*

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


*/






#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0; // Count of flowers that can be planted
        int size = flowerbed.size();
        
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) { // Check if the current plot is empty
                // Check if the previous and next plots are also empty or out of bounds
                bool canPlant = (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0);
                if (canPlant) {
                    flowerbed[i] = 1; // Plant a flower in the current plot
                    count++; // Increment the count of planted flowers
                }
            }
        }
        
        return count >= n; // Check if enough flowers have been planted
    }
};

int main() {
    Solution solution;
    
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << "Result 1: " << solution.canPlaceFlowers(flowerbed1, n1) << endl;
    
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    cout << "Result 2: " << solution.canPlaceFlowers(flowerbed2, n2) << endl;
    
    vector<int> flowerbed3 = {0, 0, 0, 0, 0};
    int n3 = 3;
    cout << "Result 3: " << solution.canPlaceFlowers(flowerbed3, n3) << endl;
    
    return 0;
}
