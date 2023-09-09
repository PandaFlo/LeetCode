'''Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
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
'''
def minFlips(a, b, c):
    flips = 0
    
    while a != 0 or b != 0 or c != 0:
        bit_a = a & 1
        bit_b = b & 1
        bit_c = c & 1
        
        if bit_c == 1:
            if bit_a == 0 and bit_b == 0:
                flips += 1
        else:
            flips += bit_a + bit_b
        
        a >>= 1
        b >>= 1
        c >>= 1
    
    return flips

def tester():
    test_cases = [
        (2, 6, 5),  # Expected: 3
        (4, 2, 7),  # Expected: 2
        (1, 2, 3)   # Expected: 0
    ]

    for a, b, c in test_cases:
        result = minFlips(a, b, c)
        print(f"Input: a={a}, b={b}, c={c}")
        print(f"Output: {result}\n")

if __name__ == "__main__":
    tester()
