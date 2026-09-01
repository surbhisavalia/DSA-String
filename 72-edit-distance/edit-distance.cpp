class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        // dp[i][j] = minimum operations
        // to convert first i characters into first j characters
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        // If word1 is empty, we need to insert all characters
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        
        // If word2 is empty, we need to delete all characters
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        
        // Compare both strings
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                // Characters are same
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                
                // Characters are different
                else {
                    
                    // Insert
                    int insert = dp[i][j - 1];
                    
                    // Delete
                    int deleteChar = dp[i - 1][j];
                    
                    // Replace
                    int replace = dp[i - 1][j - 1];
                    
                    // Choose minimum + 1 operation
                    dp[i][j] = 1 + min({insert, deleteChar, replace});
                }
            }
        }
        
        return dp[n][m];
    }
};