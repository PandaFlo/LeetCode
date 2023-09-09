/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int city) {
        visited[city] = 1;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 && !visited[i]) {
                dfs(isConnected, visited, i);
            }
        }
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> isConnected1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int provinces1 = solution.findCircleNum(isConnected1);
    cout << "Test case 1: Expected output 2, Actual output: " << provinces1 << endl;

    // Test case 2
    vector<vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int provinces2 = solution.findCircleNum(isConnected2);
    cout << "Test case 2: Expected output 3, Actual output: " << provinces2 << endl;

    return 0;
}
