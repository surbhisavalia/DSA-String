class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> stack;
        
        string current = "";
        
        // Go through every character
        for (int i = 0; i <= path.length(); i++) {
            
            // If we reach '/' or end of string
            if (i == path.length() || path[i] == '/') {
                
                // Ignore empty part and "."
                if (current == "" || current == ".") {
                    // Do nothing
                }
                
                // ".." means go to parent directory
                else if (current == "..") {
                    
                    // If stack is not empty, remove last directory
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                }
                
                // Normal directory name
                else {
                    stack.push_back(current);
                }
                
                // Start reading next directory
                current = "";
            }
            
            else {
                // Add character to current directory name
                current += path[i];
            }
        }
        
        // Build final answer
        string answer = "";
        
        for (string folder : stack) {
            answer += "/" + folder;
        }
        
        // If nothing is left, we are at root
        if (answer == "") {
            return "/";
        }
        
        return answer;
    }
};