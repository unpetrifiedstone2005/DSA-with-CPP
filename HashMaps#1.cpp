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
