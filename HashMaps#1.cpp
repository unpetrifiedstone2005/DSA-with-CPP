/*Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.*/




class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> map1;
        for(int i = 0; i < s1.length(); i++) {
            map1[s1[i]]++;
        }

        unordered_map<int, int> map2;

        int i = 0;
        int count = 0;
        int j = 0;
        while(i < s2.length()) {
            map2[s2[i]]++;
            i++;
            count++;
            if(count == s1.length() && map2 == map1) {
                return true;
            }
            if(count > s1.length()) {
                j++;
                i = j;
                count = 0;
                map2.clear();
            }
        }

        return false;
    }
};
