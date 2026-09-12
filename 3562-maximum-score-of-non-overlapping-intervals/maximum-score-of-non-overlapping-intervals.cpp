class Solution {
public:

    struct State {
        long long score = 0;
        vector<int> indices;
    };

    // Returns the better of two answers
    State better(State a, State b) {

        // Higher score wins
        if (a.score > b.score)
            return a;

        if (b.score > a.score)
            return b;

        // Same score -> lexicographically smaller indices win
        if (a.indices < b.indices)
            return a;

        return b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Store:
        // {left, right, weight, originalIndex}
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {

            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort based on starting point
        sort(arr.begin(), arr.end());

        // Store all starting points
        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = arr[i][0];
        }

        // ------------------------------------------------
        // nextIndex[i] =
        // first interval whose start > current interval end
        // ------------------------------------------------

        vector<int> nextIndex(n);

        for (int i = 0; i < n; i++) {

            long long end = arr[i][1];

            nextIndex[i] =
                upper_bound(
                    starts.begin(),
                    starts.end(),
                    end
                ) - starts.begin();
        }

        /*
            dp[k][i]

            Best answer starting from interval i
            when we can select at most k intervals.

            k = 0,1,2,3,4
        */

        vector<vector<State>> dp(
            5,
            vector<State>(n + 1)
        );

        // dp[0][i] = score 0
        // dp[k][n] = score 0
        // already initialized

        for (int k = 1; k <= 4; k++) {

            for (int i = n - 1; i >= 0; i--) {

                // -----------------------
                // OPTION 1: Skip interval
                // -----------------------

                State skip = dp[k][i + 1];

                // -----------------------
                // OPTION 2: Take interval
                // -----------------------

                State take;

                take.score =
                    arr[i][2] +
                    dp[k - 1][nextIndex[i]].score;

                take.indices =
                    dp[k - 1][nextIndex[i]].indices;

                // Original index
                int originalIndex = arr[i][3];

                /*
                    Result indices must be lexicographically
                    compared in sorted order.

                    Since maximum size = 4,
                    sorting this is extremely cheap.
                */

                take.indices.push_back(originalIndex);

                sort(
                    take.indices.begin(),
                    take.indices.end()
                );

                // Choose best option
                dp[k][i] = better(skip, take);
            }
        }

        return dp[4][0].indices;
    }
};