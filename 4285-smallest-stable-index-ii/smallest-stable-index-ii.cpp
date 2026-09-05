class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
           int n = nums.size();

        // Step 1: suffix minimum
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        // Step 2: prefix maximum + check
        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {

            prefixMax = max(prefixMax, nums[i]);

            int score = prefixMax - suffixMin[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
        
    }
};