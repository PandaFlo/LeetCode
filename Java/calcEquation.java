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





import java.util.*;

class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, Map<String, Double>> graph = new HashMap<>();

        // Build the graph
        for (int i = 0; i < equations.size(); i++) {
            String u = equations.get(i).get(0);
            String v = equations.get(i).get(1);
            double weight = values[i];

            graph.putIfAbsent(u, new HashMap<>());
            graph.putIfAbsent(v, new HashMap<>());

            graph.get(u).put(v, weight);
            graph.get(v).put(u, 1.0 / weight);
        }

        double[] results = new double[queries.size()];

        for (int i = 0; i < queries.size(); i++) {
            String src = queries.get(i).get(0);
            String dest = queries.get(i).get(1);
            Set<String> visited = new HashSet<>();
            Double val = dfs(graph, src, dest, 1.0, visited);

            results[i] = (val != null) ? val : -1.0;
        }

        return results;
    }

    private Double dfs(Map<String, Map<String, Double>> graph, String src, String dest, double quotient, Set<String> visited) {
        if (!graph.containsKey(src) || !graph.containsKey(dest)) {
            return null;
        }

        if (src.equals(dest)) {
            return quotient;
        }

        visited.add(src);

        Map<String, Double> neighbors = graph.get(src);

        for (String neighbor : neighbors.keySet()) {
            if (!visited.contains(neighbor)) {
                Double val = dfs(graph, neighbor, dest, quotient * neighbors.get(neighbor), visited);
                if (val != null) {
                    return val;
                }
            }
        }

        visited.remove(src);

        return null;
    }
}






public class calcEquation {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        List<List<String>> equations1 = new ArrayList<>();
        List<String> equation1a = new ArrayList<>();
        equation1a.add("a");
        equation1a.add("b");
        equations1.add(equation1a);

        List<String> equation1b = new ArrayList<>();
        equation1b.add("b");
        equation1b.add("c");
        equations1.add(equation1b);

        double[] values1 = {2.0, 3.0};
        List<List<String>> queries1 = new ArrayList<>();

        List<String> query1a = new ArrayList<>();
        query1a.add("a");
        query1a.add("c");
        queries1.add(query1a);

        List<String> query1b = new ArrayList<>();
        query1b.add("b");
        query1b.add("a");
        queries1.add(query1b);

        List<String> query1c = new ArrayList<>();
        query1c.add("a");
        query1c.add("e");
        queries1.add(query1c);

        List<String> query1d = new ArrayList<>();
        query1d.add("a");
        query1d.add("a");
        queries1.add(query1d);

        List<String> query1e = new ArrayList<>();
        query1e.add("x");
        query1e.add("x");
        queries1.add(query1e);

        double[] results1 = solution.calcEquation(equations1, values1, queries1);
        System.out.println("Example 1 Results: " + Arrays.toString(results1));

        // Example 2
        List<List<String>> equations2 = new ArrayList<>();
        List<String> equation2a = new ArrayList<>();
        equation2a.add("a");
        equation2a.add("b");
        equations2.add(equation2a);

        List<String> equation2b = new ArrayList<>();
        equation2b.add("b");
        equation2b.add("c");
        equations2.add(equation2b);

        List<String> equation2c = new ArrayList<>();
        equation2c.add("bc");
        equation2c.add("cd");
        equations2.add(equation2c);

        double[] values2 = {1.5, 2.5, 5.0};
        List<List<String>> queries2 = new ArrayList<>();

        List<String> query2a = new ArrayList<>();
        query2a.add("a");
        query2a.add("c");
        queries2.add(query2a);

        List<String> query2b = new ArrayList<>();
        query2b.add("c");
        query2b.add("b");
        queries2.add(query2b);

        List<String> query2c = new ArrayList<>();
        query2c.add("bc");
        query2c.add("cd");
        queries2.add(query2c);

        List<String> query2d = new ArrayList<>();
        query2d.add("cd");
        query2d.add("bc");
        queries2.add(query2d);

        double[] results2 = solution.calcEquation(equations2, values2, queries2);
        System.out.println("Example 2 Results: " + Arrays.toString(results2));

        // Example 3
        List<List<String>> equations3 = new ArrayList<>();
        List<String> equation3a = new ArrayList<>();
        equation3a.add("a");
        equation3a.add("b");
        equations3.add(equation3a);

        double[] values3 = {0.5};
        List<List<String>> queries3 = new ArrayList<>();

        List<String> query3a = new ArrayList<>();
        query3a.add("a");
        query3a.add("b");
        queries3.add(query3a);

        List<String> query3b = new ArrayList<>();
        query3b.add("b");
        query3b.add("a");
        queries3.add(query3b);

        List<String> query3c = new ArrayList<>();
        query3c.add("a");
        query3c.add("c");
        queries3.add(query3c);

        List<String> query3d = new ArrayList<>();
        query3d.add("x");
        query3d.add("y");
        queries3.add(query3d);

        double[] results3 = solution.calcEquation(equations3, values3, queries3);
        System.out.println("Example 3 Results: " + Arrays.toString(results3));
    }
}
