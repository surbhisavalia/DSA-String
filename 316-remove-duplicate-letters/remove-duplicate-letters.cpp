class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        // Count how many times each character appears
        int count[26] = {0};
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Store the answer
        string stack = "";
        
        // Check which characters are already used
        bool used[26] = {false};
        
        for (char c : s) {
            
            // This character is already in answer
            if (used[c - 'a']) {
                count[c - 'a']--;
                continue;
            }
            
            // Character is still available
            count[c - 'a']--;
            
            // Remove bigger characters if they appear again later
            while (!stack.empty() &&
                   stack.back() > c &&
                   count[stack.back() - 'a'] > 0) {
                
                used[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            // Add current character
            stack.push_back(c);
            used[c - 'a'] = true;
        }
        
        return stack;
    }
};