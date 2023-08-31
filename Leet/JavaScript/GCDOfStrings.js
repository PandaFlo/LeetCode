/* 
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.




*/



var gcdOfStrings = function(str1, str2) {
    // Helper function to calculate the GCD of two numbers
    const gcd = (a, b) => (b === 0 ? a : gcd(b, a % b));
    
    const len1 = str1.length;
    const len2 = str2.length;
    
    // Calculate the GCD of the lengths of str1 and str2
    const lengthGCD = gcd(len1, len2);
    
    // Extract the potential common divisor string 'x' from str1
    const x = str1.substring(0, lengthGCD);
    
    // Check if 'x' can divide both str1 and str2
    if (x.repeat(len1 / lengthGCD) === str1 && x.repeat(len2 / lengthGCD) === str2) {
        return x;
    } else {
        return "";
    }
};

// Test cases
console.log(gcdOfStrings("ABCABC", "ABC")); // Output: "ABC"
console.log(gcdOfStrings("ABABAB", "ABAB")); // Output: "AB"
console.log(gcdOfStrings("LEET", "CODE")); // Output: ""

