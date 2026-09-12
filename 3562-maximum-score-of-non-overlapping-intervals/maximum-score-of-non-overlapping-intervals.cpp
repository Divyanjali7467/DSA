class Solution {
public:

    struct Node {
        long long score;
        vector<int> ids;
    };

    vector<vector<Node>> dp;
    vector<vector<int>> a;
    int n;

    Node solve(int i, int k) {

        if (i == n || k == 0)
            return {0, {}};

        if (dp[i][k].score != -1)
            return dp[i][k];

        // Don't take current interval
        Node skip = solve(i + 1, k);

        // Take current interval
        int r = a[i][1];

        // Find first interval with start > r
        int lo = i + 1, hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid][0] > r)
                hi = mid;
            else
                lo = mid + 1;
        }

        int next = lo;

        Node take = solve(next, k - 1);

        take.score += a[i][2];
        take.ids.push_back(a[i][3]);

        // Sort original indices for lexicographical comparison
        sort(take.ids.begin(), take.ids.end());

        // Choose better score
        if (take.score > skip.score)
            return dp[i][k] = take;

        // If same score, choose lexicographically smaller
        if (take.score == skip.score && take.ids < skip.ids)
            return dp[i][k] = take;

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // [start, end, weight, original_index]
        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start
        sort(a.begin(), a.end());

        dp.assign(n, vector<Node>(5, {-1, {}}));

        return solve(0, 4).ids;
    }
};