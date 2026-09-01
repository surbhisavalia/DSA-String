class Solution {
public:

    // Check if the sequence works from this position
    bool check(string num, int start, long long first, long long second) {
        
        // We need to find the next number
        while (start < num.length()) {
            
            // Calculate next number
            long long next = first + second;
            
            string nextString = to_string(next);
            
            // Check if next number matches the string
            if (num.substr(start, nextString.length()) != nextString) {
                return false;
            }
            
            // Move forward
            start += nextString.length();
            
            // Move numbers forward
            first = second;
            second = next;
        }
        
        return true;
    }

    bool isAdditiveNumber(string num) {
        
        int n = num.length();
        
        // Choose the first number
        for (int i = 1; i <= n / 2; i++) {
            
            // First number cannot have leading zero
            if (num[0] == '0' && i > 1) {
                break;
            }
            
            long long first = stoll(num.substr(0, i));
            
            // Choose the second number
            for (int j = 1; 
                 max(i, j) + i + j <= n; 
                 j++) {
                
                // Second number cannot have leading zero
                if (num[i] == '0' && j > 1) {
                    break;
                }
                
                long long second = stoll(num.substr(i, j));
                
                // Check the rest of the string
                if (check(num, i + j, first, second)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};