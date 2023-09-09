/* There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
 

Constraints:

2 <= n <= 5 * 104
connections.length == n - 1
connections[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
 */
#include <stdio.h>
#include <stdlib.h>

// Define the struct for ll_node
struct ll_node {
    struct ll_node* next;
    struct ll_node* prv;
    int val;
    int link_dir; // 0: 0->1, 1: 1->0
};

// Your minReorder function
int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize){
    int adj_list_num[100000] = {0};
    int node_visit[100001] = {0};
    struct ll_node* adj_list[100000];
    struct ll_node* tmp;
    int output = 0;
    int stack[100001];
    int stack_size = 0;
    int pop_idx = 0;
    int i = 0;

    // construct adj list
    for (i = 0; i < connectionsSize; i++) {
        if (adj_list_num[connections[i][0]] == 0) {
            adj_list[connections[i][0]] = (struct ll_node*)malloc(sizeof(struct ll_node));
            adj_list[connections[i][0]]->val = connections[i][1];
            adj_list[connections[i][0]]->next = NULL;
            adj_list[connections[i][0]]->prv = NULL;
            adj_list[connections[i][0]]->link_dir = 0;
        } else {
            adj_list[connections[i][0]]->next = (struct ll_node*)malloc(sizeof(struct ll_node));
            tmp = adj_list[connections[i][0]];
            adj_list[connections[i][0]] = adj_list[connections[i][0]]->next;
            adj_list[connections[i][0]]->val = connections[i][1];
            adj_list[connections[i][0]]->next = NULL;
            adj_list[connections[i][0]]->prv = tmp;
            adj_list[connections[i][0]]->link_dir = 0;
        }

        if (adj_list_num[connections[i][1]] == 0) {
            adj_list[connections[i][1]] = (struct ll_node*)malloc(sizeof(struct ll_node));
            adj_list[connections[i][1]]->val = connections[i][0];
            adj_list[connections[i][1]]->next = NULL;
            adj_list[connections[i][1]]->prv = NULL;
            adj_list[connections[i][1]]->link_dir = 1;
        } else {
            adj_list[connections[i][1]]->next = (struct ll_node*)malloc(sizeof(struct ll_node));
            tmp = adj_list[connections[i][1]];
            adj_list[connections[i][1]] = adj_list[connections[i][1]]->next;
            adj_list[connections[i][1]]->val = connections[i][0];
            adj_list[connections[i][1]]->next = NULL;
            adj_list[connections[i][1]]->prv = tmp;
            adj_list[connections[i][1]]->link_dir = 1;
        }
        adj_list_num[connections[i][0]]++;
        adj_list_num[connections[i][1]]++;
    }

    stack[stack_size++] = 0;
    node_visit[0] = 1;
    while (stack_size > 0) {
        pop_idx = stack[--stack_size];
        //printf("pop index = %d\n", pop_idx);
        for (i = 0; i < adj_list_num[pop_idx]; i++) {
            if (node_visit[adj_list[pop_idx]->val] == 0) {
                stack[stack_size++] = adj_list[pop_idx]->val;
                node_visit[adj_list[pop_idx]->val] = 1;
                if (adj_list[pop_idx]->link_dir == 0) {
                    output++;
                    //printf("dir occur %d\n", adj_list[pop_idx]->val);
                }
            }
            adj_list[pop_idx] = adj_list[pop_idx]->prv;
        }
    }


    return output;
}

int main() {
    // Test cases
    int n1 = 6;
    int connections1[][2] = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int colSize1[] = {2, 2, 2, 2, 2};
    int* conn1[5];
    for (int i = 0; i < 5; i++) {
        conn1[i] = connections1[i];
    }
    int result1 = minReorder(n1, conn1, 5, colSize1);
    printf("Test 1: %d\n", result1);  // Output should be 3

    int n2 = 5;
    int connections2[][2] = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
    int colSize2[] = {2, 2, 2, 2};
    int* conn2[4];
    for (int i = 0; i < 4; i++) {
        conn2[i] = connections2[i];
    }
    int result2 = minReorder(n2, conn2, 4, colSize2);
    printf("Test 2: %d\n", result2);  // Output should be 2

    int n3 = 3;
    int connections3[][2] = {{1, 0}, {2, 0}};
    int colSize3[] = {2, 2};
    int* conn3[2];
    for (int i = 0; i < 2; i++) {
        conn3[i] = connections3[i];
    }
    int result3 = minReorder(n3, conn3, 2, colSize3);
    printf("Test 3: %d\n", result3);  // Output should be 0

    // You can add more test cases here...

    return 0;
}