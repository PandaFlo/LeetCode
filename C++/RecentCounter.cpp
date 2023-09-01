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
At most 104 calls will be made to ping. */

#include <iostream>
#include <queue> // Include this header for using the queue class

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // Remove requests that are outside the time frame
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        // Add the new request to the queue
        requests.push(t);
        
        // The size of the queue represents the number of requests within the time frame
        return requests.size();
    }
    
private:
    queue<int> requests;
};

int main() {
    RecentCounter obj;
    int param_1 = obj.ping(1);
    cout << param_1 << endl; // Output: 1
    
    param_1 = obj.ping(100);
    cout << param_1 << endl; // Output: 2
    
    param_1 = obj.ping(3001);
    cout << param_1 << endl; // Output: 3
    
    param_1 = obj.ping(3002);
    cout << param_1 << endl; // Output: 3
    
    return 0;
}
