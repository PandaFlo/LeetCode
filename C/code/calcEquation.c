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



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *variable;
    double value;
} Equation;

double findValue(char *start, char *end, Equation *equations, int equationsSize, int *visited) {
    for (int i = 0; i < equationsSize; i++) {
        if (!visited[i] && strcmp(equations[i].variable, start) == 0) {
            visited[i] = 1;
            if (strcmp(equations[i].variable, end) == 0) {
                return equations[i].value;
            } else {
                double subResult = findValue(equations[i].variable, end, equations, equationsSize, visited);
                if (subResult != -1.0) {
                    return equations[i].value * subResult;
                }
            }
            visited[i] = 0;
        }
    }
    return -1.0;
}

double *calcEquation(char ***equations, int equationsSize, int *equationsColSize, double *values, int valuesSize, char ***queries, int queriesSize, int *queriesColSize, int *returnSize) {
    Equation *equationList = (Equation *)malloc(2 * equationsSize * sizeof(Equation));
    int equationListSize = 0;

    // Create equation list
    for (int i = 0; i < equationsSize; i++) {
        char *var1 = equations[i][0];
        char *var2 = equations[i][1];
        double value = values[i];

        equationList[equationListSize].variable = strdup(var1);
        equationList[equationListSize].value = value;
        equationListSize++;

        equationList[equationListSize].variable = strdup(var2);
        equationList[equationListSize].value = 1.0 / value;
        equationListSize++;
    }

    double *results = (double *)malloc(queriesSize * sizeof(double));
    for (int i = 0; i < queriesSize; i++) {
        char *var1 = queries[i][0];
        char *var2 = queries[i][1];
        int visited[equationsSize];
        memset(visited, 0, sizeof(visited));
        double result = findValue(var1, var2, equationList, equationListSize, visited);
        results[i] = result;
    }

    *returnSize = queriesSize;
    return results;
}

int main() {
    char *equations1[][2] = {{"a", "b"}, {"b", "c"}};
    double values1[] = {2.0, 3.0};
    char *queries1[][2] = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    int returnSize1;
    double *results1 = calcEquation(equations1, 2, NULL, values1, 2, queries1, 5, NULL, &returnSize1);
    for (int i = 0; i < returnSize1; i++) {
        printf("%.5lf ", results1[i]);
    }
    printf("\n");
    free(results1);

    char *equations2[][2] = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    double values2[] = {1.5, 2.5, 5.0};
    char *queries2[][2] = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    int returnSize2;
    double *results2 = calcEquation(equations2, 3, NULL, values2, 3, queries2, 4, NULL, &returnSize2);
    for (int i = 0; i < returnSize2; i++) {
        printf("%.5lf ", results2[i]);
    }
    printf("\n");
    free(results2);

    char *equations3[][2] = {{"a", "b"}};
    double values3[] = {0.5};
    char *queries3[][2] = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
    int returnSize3;
    double *results3 = calcEquation(equations3, 1, NULL, values3, 1, queries3, 4, NULL, &returnSize3);
    for (int i = 0; i < returnSize3; i++) {
        printf("%.5lf ", results3[i]);
    }
    printf("\n");
    free(results3);

    return 0;
}
