class Solution {
public:
    
    vector<string> answer;
    
    void generate(string current, int open, int close, int n) {
        
        // If we used all parentheses, store the answer
        if (current.length() == 2 * n) {
            answer.push_back(current);
            return;
        }
        
        // We can add '(' if we still have some left
        if (open < n) {
            generate(current + "(", open + 1, close, n);
        }
        
        // We can add ')' only if there is an unmatched '('
        if (close < open) {
            generate(current + ")", open, close + 1, n);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        // Start with empty string
        generate("", 0, 0, n);
        
        return answer;
    }
};