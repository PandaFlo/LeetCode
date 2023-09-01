/* You have a RecentCounter class which counts the number of recent requests within a certain time frame.

Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

 

Example 1:

Input
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output
[null, 1, 2, 3, 3]

Explanation
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
 

Constraints:

1 <= t <= 109
Each test case will call ping with strictly increasing values of t.
At most 104 calls will be made to ping.*/

#include <stdlib.h>
#include <stdio.h>
typedef struct {
    int* queue;
    int size;
    int front;
    int rear;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->queue = (int*)malloc(10000 * sizeof(int)); // You can adjust the size as needed
    obj->size = 10000;
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    // Remove requests that are outside the time frame
    while (obj->front <= obj->rear && obj->queue[obj->front] < t - 3000) {
        obj->front++;
    }
    
    // Add the new request to the queue
    obj->rear++;
    obj->queue[obj->rear] = t;
    
    // The number of requests within the time frame is given by rear - front + 1
    return obj->rear - obj->front + 1;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}

int main() {
    RecentCounter* obj = recentCounterCreate();
    int param_1 = recentCounterPing(obj, 1);
    printf("%d\n", param_1); // Output: 1
    
    param_1 = recentCounterPing(obj, 100);
    printf("%d\n", param_1); // Output: 2
    
    param_1 = recentCounterPing(obj, 3001);
    printf("%d\n", param_1); // Output: 3
    
    param_1 = recentCounterPing(obj, 3002);
    printf("%d\n", param_1); // Output: 3
    
    recentCounterFree(obj);
    
    return 0;
}
