class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ze = 0;
        int l = 0, r = 0;
        int len = 0;
        int n = nums.size();

        while (r < n) {
            if (nums[r] == 0) {
                ze++;
            }
            while (ze > k) {
                if (nums[l] == 0) {
                    ze--;
                }
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};