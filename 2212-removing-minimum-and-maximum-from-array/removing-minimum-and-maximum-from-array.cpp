class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();

        int minIdx = 0;
        int maxIdx = 0;

        // Find min and max indices
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) {
                minIdx = i;
            }

            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        // Case 1: both from front
        int front = right + 1;

        // Case 2: both from back
        int back = n - left;

        // Case 3: one from front, one from back
        int both = (left + 1) + (n - right);

        return min({front, back, both});
    }
};