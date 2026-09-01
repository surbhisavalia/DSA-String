class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        
        // dp[i] = number of ways to decode first i characters
        vector<int> dp(n + 1, 0);
        
        // Empty string has 1 way
        dp[0] = 1;
        
        // If first character is not 0
        if (s[0] != '0') {
            dp[1] = 1;
        }
        
        // Check every character
        for (int i = 2; i <= n; i++) {
            
            // Take one digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            
            // Take two digits
            int number = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            
            if (number >= 10 && number <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};