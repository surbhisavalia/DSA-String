class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        set<char> characters;   // Stores characters in current window
        
        int left = 0;            // Start of window
        int right = 0;           // End of window
        int maxLength = 0;       // Answer
        
        while (right < s.length()) {
            
            // If character is not repeated
            if (characters.find(s[right]) == characters.end()) {
                characters.insert(s[right]);
                
                // Calculate current window length
                maxLength = max(maxLength, right - left + 1);
                
                right++;
            }
            else {
                // Remove the left character
                characters.erase(s[left]);
                left++;
            }
        }
        
        return maxLength;
    }
};