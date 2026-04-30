
class Solution {
public:
    int m, n;
    // Using a 1D vector to represent 3D to save memory and avoid stack issues
    // Size: m * n * (k + 1)
    vector<int> memo;

    int solve(int r, int c, int k, vector<vector<int>>& grid) {
        if (k < 0) return -1e9;
        if (r == m - 1 && c == n - 1) {
            // Check cost of the very last cell
            int final_cost = (grid[r][c] > 0) ? 1 : 0;
            return (k >= final_cost) ? grid[r][c] : -1e9;
        }
        
        // Indexing for 1D memo: (r * n * (max_k+1)) + (c * (max_k+1)) + k
        // But for simplicity, let's use a clear 3D structure if memory allows
        // Or just ensure the mapping is correct.
        
        // Let's stick to the 3D approach for clarity but fix the return
        return 0; // placeholder
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        
        // Use a 3D vector initialized to -2 (since -1 is a possible valid score)
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -2)));

        int result = helper(0, 0, k, grid, dp);
        
        // If result is still the "invalid" marker, return -1
        return (result <= -1e8) ? -1 : result;
    }

    int helper(int r, int c, int rem_k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // 1. Boundary Check
        if (r >= m || c >= n) return -1e9;

        // 2. Cost Calculation
        int cost = (grid[r][c] > 0) ? 1 : 0;
        if (rem_k < cost) return -1e9;

        // 3. Base Case: Destination
        if (r == m - 1 && c == n - 1) return grid[r][c];

        // 4. Memo Check
        if (dp[r][c][rem_k] != -2) return dp[r][c][rem_k];

        // 5. Explore
        int right = helper(r, c + 1, rem_k - cost, grid, dp);
        int down = helper(r + 1, c, rem_k - cost, grid, dp);

        int best = max(right, down);

        // 6. Store Result
        if (best <= -1e8) return dp[r][c][rem_k] = -1e9;
        return dp[r][c][rem_k] = grid[r][c] + best;
    }
};
