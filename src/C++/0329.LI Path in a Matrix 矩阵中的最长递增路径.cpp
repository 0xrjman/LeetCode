class Solution {    
public:
    vector<vector<int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        if (!m || !n) return 0;
        int res = 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {   //以每个点为起点,寻找最大递增长度
            for (int j = 0; j < n; ++j) {
                res = max(res,dfs(matrix,dp,i,j,m,n));  
            }
        }
        return res;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j,int m,int n) {
        if (dp[i][j]) return dp[i][j];  //该节点已记录最大长度
        int maxn = 1;
        for (auto d : dir) {    //遍历四个方向
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix,dp,x,y,m,n);   //优先进行深度搜索
            maxn = max(maxn,len);
        }
        dp[i][j] = maxn;   //记忆搜索结果
        return maxn;
    }
};
