class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # 状态转移方程: f[i][j] = f[i-1][j] + f[i][j-1]
        # 增量:步数+1，x/y坐标+1
        f = [[0 for i in range(n)] for j in range(m)]
        for i in range(m):
            for j in range(n):
                if((not i) or (not j)):
                    f[i][j] = 1
                else:
                    f[i][j] = f[i-1][j] + f[i][j-1]
        return f[m-1][n-1]
