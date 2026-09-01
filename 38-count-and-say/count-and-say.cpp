class Solution {
public:
    string countAndSay(int n) {
        
        // First term is always "1"
        string current = "1";
        
        // Generate terms from 2 to n
        for (int i = 2; i <= n; i++) {
            
            string next = "";
            
            int j = 0;
            
            // Read the current string
            while (j < current.length()) {
                
                char digit = current[j];
                int count = 0;
                
                // Count consecutive same digits
                while (j < current.length() && current[j] == digit) {
                    count++;
                    j++;
                }
                
                // Add count followed by digit
                next += to_string(count);
                next += digit;
            }
            
            // Move to next term
            current = next;
        }
        
        return current;
    }
};