class Solution {
public:
 /**
 * @param A: an integer array.
 * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
  int kSum(vector<int> A, int K, int target) {
    int n = A.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(target+1, vector<int>(K+1, 0)));
    dp[n][0][0] = 1;
    for (int i = n-1; i >= 0; i--)
      for (int j = 0; j <= target; j++)
        for (int k = 0; k <= K; k++)
          dp[i][j][k] = dp[i+1][j][k] + (j >= A[i] && k ? dp[i+1][j-A[i]][k-1] : 0);
    return dp[0][target][K];
  }
};

// slightly faster, can be further improve space complexity by using i&1
int kSum(vector<int> A, int K, int target) {
  int n = A.size();
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(target+1, vector<int>(K+1, 0)));
  for (int i = 0; i <= n; i++)
    dp[i][0][0] = 1;
  for (int i = n-1; i >= 0; i--)
    for (int j = 1; j <= target; j++)
      for (int k = 1; k <= K; k++)
        dp[i][j][k] = dp[i+1][j][k] + (j >= A[i] ? dp[i+1][j-A[i]][k-1] : 0);
  return dp[0][target][K];
}
