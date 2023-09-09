/* You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.
Return the total cost to hire exactly k workers.

 

Example 1:

Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8]. The lowest cost is 2, and we break the tie by the smallest index, which is 3. The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8]. The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker with index 3 was common in the first and last four workers.
The total hiring cost is 11.
Example 2:

Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost is 1, and we break the tie by the smallest index, which is 0. The total cost = 0 + 1 = 1. Notice that workers with index 1 and 2 are common in the first and last 3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The total cost = 2 + 2 = 4.
The total hiring cost is 4.
 

Constraints:

1 <= costs.length <= 105 
1 <= costs[i] <= 105
1 <= k, candidates <= costs.length
 */
/**
 * @param {number[]} costs
 * @param {number} k
 * @param {number} candidates
 * @return {number}
 */
var totalCost = function(costs, k, candidates) {
    const minHeapLeft = new Heap((a, b) => a - b);
    const minHeapRight = new Heap((a, b) => a - b);
    let left = 0, right = costs.length - 1;
    let i = 0;
    while (i < candidates && left <= right) {
        minHeapLeft.push(costs[left]);
        left++;
        if (left <= right) {
            minHeapRight.push(costs[right]);
            right--;
        }
        i++;
    }

    let ans = 0;
    while (k > 0) {
        const headLeft = minHeapLeft.peek() || Number.MAX_SAFE_INTEGER;
        const headRight = minHeapRight.peek() || Number.MAX_SAFE_INTEGER;
        if (headLeft <= headRight) {
            ans += minHeapLeft.pop();
            if (left <= right) {
                minHeapLeft.push(costs[left]);
                left++;
            }
        } else {
            ans += minHeapRight.pop();
            if (left <= right) {
                minHeapRight.push(costs[right]);
                right--;
            } 
        }
        k--;
    }
    return ans;
};

class Heap {
    constructor(comparator) {
        this.arr = [null];  // 1 index-based, virtual tree: root -> leaf is left -> right
        this.size = 0;
        this.comparator = comparator;
    }
    
    push(element) {
        this.arr.push(element);
        this.size++;
        let currIndex = this.arr.length - 1;
        let parentIndex = Math.floor(currIndex / 2);
        while (parentIndex > 0 && this.comparator(this.arr[currIndex], this.arr[parentIndex]) < 0) {
            [this.arr[currIndex], this.arr[parentIndex]] = [this.arr[parentIndex], this.arr[currIndex]];
            currIndex = parentIndex;
            parentIndex = Math.floor(currIndex / 2);
        }
    } 
    
    pop() {
        if (this.size === 0) {
            return null;
        }
        const head = this.arr[1];
        const tail = this.arr.pop();
        this.size--;
        if (this.size === 1) {
            this.arr[1] = tail;
        } else if (this.size > 1) {
            // bubble down
            this.arr[1] = tail;
            let currIndex = 1;
            let leftChild = currIndex * 2;
            let rightChild = currIndex * 2 + 1;
            let targetChild = (this.arr[rightChild] === undefined ||  this.comparator(this.arr[leftChild], this.arr[rightChild]) < 0) ? leftChild : rightChild;
            while (this.arr[targetChild] !== undefined && this.comparator(this.arr[currIndex], this.arr[targetChild]) > 0) {
                [this.arr[currIndex], this.arr[targetChild]] = [this.arr[targetChild], this.arr[currIndex]];
                currIndex = targetChild;
                leftChild = currIndex * 2;
                rightChild = currIndex * 2 + 1;
                targetChild = (this.arr[rightChild] === undefined ||  this.comparator(this.arr[leftChild], this.arr[rightChild]) < 0) ? leftChild : rightChild;
            }
        }
        return head;
    }
    
    peek() {
        return this.arr[1];
    }
}

// Define the totalCost function and Heap class here...

// Test case 1
const costs1 = [17, 12, 10, 2, 7, 2, 11, 20, 8];
const k1 = 3;
const candidates1 = 4;
const result1 = totalCost(costs1, k1, candidates1);
console.log("Test Case 1 Result: " + result1);  // Expected Output: 11

// Test case 2
const costs2 = [1, 2, 4, 1];
const k2 = 3;
const candidates2 = 3;
const result2 = totalCost(costs2, k2, candidates2);
console.log("Test Case 2 Result: " + result2);  // Expected Output: 4

// Add more test cases as needed...


