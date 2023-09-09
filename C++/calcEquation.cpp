/* You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 */


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];

            graph[u][v] = weight;
            graph[v][u] = 1.0 / weight;
        }

        // Perform queries
        vector<double> results;
        for (vector<string>& query : queries) {
            string src = query[0];
            string dest = query[1];

            if (!graph.count(src) || !graph.count(dest)) {
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(graph, src, dest, visited);
                results.push_back(result);
            }
        }

        return results;
    }

private:
    double dfs(const unordered_map<string, unordered_map<string, double>>& graph, const string& src, const string& dest, unordered_set<string>& visited) {
        if (src == dest) {
            return 1.0;
        }

        visited.insert(src);
        for (auto& neighbor : graph.at(src)) {
            if (visited.count(neighbor.first) == 0) {
                double result = dfs(graph, neighbor.first, dest, visited);
                if (result > 0.0) {
                    return result * neighbor.second;
                }
            }
        }

        return -1.0;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<vector<string>> equations1 = {{"a", "b"}, {"b", "c"}};
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    
    vector<vector<string>> equations2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values2 = {1.5, 2.5, 5.0};
    vector<vector<string>> queries2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    
    vector<vector<string>> equations3 = {{"a", "b"}};
    vector<double> values3 = {0.5};
    vector<vector<string>> queries3 = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};

    vector<double> results1 = solution.calcEquation(equations1, values1, queries1);
    vector<double> results2 = solution.calcEquation(equations2, values2, queries2);
    vector<double> results3 = solution.calcEquation(equations3, values3, queries3);

    // Display the results
    for (double result : results1) {
        cout << result << " ";
    }
    cout << endl;

    for (double result : results2) {
        cout << result << " ";
    }
    cout << endl;

    for (double result : results3) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
