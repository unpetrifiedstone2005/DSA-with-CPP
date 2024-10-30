class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int maxindex = -1;

        for (int num = 1; num < n; num++) {
            if (nums[num - 1] <= nums[num]) {
                if (nums[num] > max) {
                    max = nums[num];
                    maxindex = num;
                }
            }
        }

        int i = 0;
        while (i < maxindex) {
            if (i == 0 && nums[i] >= max) {
                nums.erase(nums.begin() + i);
                maxindex--;
            } else if (i > 0 && nums[i - 1] >= nums[i]) {

                nums.erase(nums.begin() + i);
                maxindex--;
            } else {
                i++;
            }
        }

        i = maxindex; 
        while (i < nums.size() - 1) {
            if (nums[i] <= nums[i + 1]) {
                nums.erase(nums.begin() + i + 1);
            } else {
                i++;
            }
        }

        return n - nums.size();
    }
};
