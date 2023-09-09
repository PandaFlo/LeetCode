/* Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

Example 1:
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

Example 2:
Input: a = 4, b = 2, c = 7
Output: 1

Example 3:
Input: a = 1, b = 2, c = 3
Output: 0
 

Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
 */


/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
function dec2bin(dec){
    return dec.toString(2);
 }
 var minFlips = function(a, b, c) {
     let flip =0;
     a=dec2bin(a).toString(2).split('')
     b=dec2bin(b).toString(2).split('')
     c=dec2bin(c).toString(2).split('')
 
     let maxbit = Math.max(a.length, b.length, c.length)
 
     while(maxbit)
     {
         maxbit--;
         const charA = a.length ? a.pop() : '0';
         const charB = b.length ? b.pop() : '0';
         const charC = c.length ? c.pop() : '0';
 
         if(charC ==='0'){
             if(charA ==='1') flip++;
             if(charB=== '1') flip++;
         }
         else {
             if(charA === '0' && charB ==='0') flip++
         }
     }
     return flip
 };


function tester() {
    const testCases = [
        { a: 2, b: 6, c: 5, expected: 3 },
        { a: 4, b: 2, c: 7, expected: 1 },
        { a: 1, b: 2, c: 3, expected: 0 },
    ];

    for (const testCase of testCases) {
        const { a, b, c, expected } = testCase;
        const result = minFlips(a, b, c);
        console.log(`Input: a=${a}, b=${b}, c=${c}`);
        console.log(`Output: ${result}`);
        console.log(`Expected: ${expected}`);
        console.log(result === expected ? "Test Passed\n" : "Test Failed\n");
    }
}

tester();
