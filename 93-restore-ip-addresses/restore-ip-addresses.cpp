class Solution {
public:
    
    vector<string> answer;
    
    void makeIP(string s, int index, int parts, string current) {
        
        // If we have 4 parts
        if (parts == 4) {
            
            // All digits must be used
            if (index == s.length()) {
                current.pop_back(); // Remove last '.'
                answer.push_back(current);
            }
            
            return;
        }
        
        // Try 1, 2, or 3 digits
        for (int length = 1; length <= 3; length++) {
            
            // Don't go outside the string
            if (index + length > s.length()) {
                break;
            }
            
            string number = s.substr(index, length);
            
            // Leading zero is not allowed
            if (number.length() > 1 && number[0] == '0') {
                continue;
            }
            
            // Number must be <= 255
            if (stoi(number) > 255) {
                continue;
            }
            
            // Add this part and continue
            makeIP(s, index + length, parts + 1,
                   current + number + ".");
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        makeIP(s, 0, 0, "");
        
        return answer;
    }
};