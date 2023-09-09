/* Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.
r */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int* prices;
    int* spans;
    int top;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->prices = (int*)malloc(10005 * sizeof(int));
    obj->spans = (int*)malloc(10005 * sizeof(int));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->top >= 0 && price >= obj->prices[obj->top]) {
        span += obj->spans[obj->top];
        obj->top--;
    }
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->spans);
    free(obj);
}

// Example usage:
int main() {
    StockSpanner* obj = stockSpannerCreate();
    printf("%d\n", stockSpannerNext(obj, 100)); // Output: 1
    printf("%d\n", stockSpannerNext(obj, 80));  // Output: 1
    printf("%d\n", stockSpannerNext(obj, 60));  // Output: 1
    printf("%d\n", stockSpannerNext(obj, 70));  // Output: 2
    printf("%d\n", stockSpannerNext(obj, 60));  // Output: 1
    printf("%d\n", stockSpannerNext(obj, 75));  // Output: 4
    printf("%d\n", stockSpannerNext(obj, 85));  // Output: 6
    stockSpannerFree(obj);
    return 0;
}
