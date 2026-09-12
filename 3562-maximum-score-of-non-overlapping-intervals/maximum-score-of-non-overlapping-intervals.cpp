class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<vector<int>, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i], i});
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x.first[1] < y.first[1];
        });

        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int low = 0;
            int high = i - 1;
            int pos = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (a[mid].first[1] < a[i].first[0]) {
                    pos = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            prev[i] = pos + 1;
        }

        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> path(5, vector<vector<int>>(n + 1));

        for (int i = 1; i <= n; i++) {
            int current = i - 1;

            for (int k = 1; k <= 4; k++) {

                dp[k][i] = dp[k][i - 1];
                path[k][i] = path[k][i - 1];

                long long value =
                    dp[k - 1][prev[current]] + a[current].first[2];

                vector<int> candidate =
                    path[k - 1][prev[current]];

                candidate.push_back(a[current].second);
                sort(candidate.begin(), candidate.end());

                if (value > dp[k][i] ||
                    (value == dp[k][i] &&
                     candidate < path[k][i])) {

                    dp[k][i] = value;
                    path[k][i] = candidate;
                }
            }
        }

        vector<int> ans;

        for (int k = 0; k <= 4; k++) {
            if (dp[k][n] > dp[ans.size()][n] ||
                (dp[k][n] == dp[ans.size()][n] &&
                 path[k][n] < ans)) {

                ans = path[k][n];
            }
        }

        return ans;
    }
};