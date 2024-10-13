/*
Time limit exceed but logic is correct

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> map;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            map[i] = nums[i];
        }

        int count = 0;
        int minVal = map[0][0];
        int minKey;
        int maxVal = 0;
        int minDiff = INT_MAX; 
        vector<int> pair;
        int i = 0;

        while (count != map.size() - 2) {
            if (!map[i].empty()) {
                maxVal = max(map[i][0], maxVal);
            }

            if (!map[i].empty() && minVal == map[i][0]) {
                minVal = map[i][0];
                minKey = i;
            }
            if (map[i].empty()) {
                count++;
            }

            if (i == map.size() - 1) {
                vector<int> list = map[minKey];
                list.erase(list.begin());
                if (pair.empty() || (maxVal - minVal < minDiff)) {
                    pair = {minVal, maxVal};
                    minDiff = maxVal - minVal;
                }
                i = 0;
            } else {
                i++;
            }
        }

        return pair;
    }
};*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            min_heap;

        int maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int minVal = nums[i][0];
            min_heap.push({minVal, i, 0});
            maxVal = max(maxVal, minVal);
        }

        vector<int> minRange = {0, INT_MAX};
        while (true) {
            vector<int> top = min_heap.top();
            min_heap.pop();
            int minElement = top[0], listIndex = top[1], elementIndex = top[2];
            if (maxVal - minElement < minRange[1] - minRange[0]) {
                minRange[0] = minElement;
                minRange[1] = maxVal;
            }
            if (elementIndex == nums[listIndex].size() - 1)
                break;
            int next = nums[listIndex][elementIndex+1];
            maxVal = max(maxVal, next);
            min_heap.push({next, listIndex, elementIndex+1});
        }
        return minRange;
    }
};
