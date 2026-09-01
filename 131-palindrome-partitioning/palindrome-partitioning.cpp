class Solution {
public:
    
    vector<vector<string>> answer;
    
    // Check if a string is palindrome
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            
            if (s[left] != s[right]) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
    
    void makePartitions(string s, int index, vector<string> current) {
        
        // If we reached the end, store the partition
        if (index == s.length()) {
            answer.push_back(current);
            return;
        }
        
        // Try every possible substring
        for (int i = index; i < s.length(); i++) {
            
            // Take substring from index to i
            string part = s.substr(index, i - index + 1);
            
            // Only continue if it is palindrome
            if (isPalindrome(part)) {
                
                // Add palindrome to current partition
                current.push_back(part);
                
                // Move to next part
                makePartitions(s, i + 1, current);
                
                // Remove last part
                current.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> current;
        
        makePartitions(s, 0, current);
        
        return answer;
    }
};