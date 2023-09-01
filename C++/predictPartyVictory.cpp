/* In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

 

Example 1:

Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:

Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, predictPartyVictory */


#include <iostream>
#include <string>  // Include this header for the string type

using namespace std;  // This is used for convenience in the example

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        int radiant_count = 0, dire_count = 0;
        
        // Count the number of Radiant and Dire senators
        for (char party : senate) {
            if (party == 'R') {
                radiant_count++;
            } else {
                dire_count++;
            }
        }
        
        while (radiant_count > 0 && dire_count > 0) {
            for (int i = 0; i < n; i++) {
                if (senate[i] == 'R') {
                    int j = (i + 1) % n; // Find next available Dire senator
                    while (j != i && senate[j] != 'D') {
                        j = (j + 1) % n;
                    }
                    if (senate[j] == 'D') {
                        senate[j] = 'X';  // Mark as banned
                        dire_count--;
                    }
                } else if (senate[i] == 'D') {
                    int j = (i + 1) % n; // Find next available Radiant senator
                    while (j != i && senate[j] != 'R') {
                        j = (j + 1) % n;
                    }
                    if (senate[j] == 'R') {
                        senate[j] = 'X';  // Mark as banned
                        radiant_count--;
                    }
                }
            }
        }
        
        return (radiant_count > 0) ? "Radiant" : "Dire";
    }
};

int main() {
    Solution solution;

    string senate1 = "RD";
    string senate2 = "RDD";

    cout << solution.predictPartyVictory(senate1) << endl;  // Output: "Radiant"
    cout << solution.predictPartyVictory(senate2) << endl;  // Output: "Dire"

    return 0;
}
