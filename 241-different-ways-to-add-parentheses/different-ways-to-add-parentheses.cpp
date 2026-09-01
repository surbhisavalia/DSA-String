class Solution {
public:
    
    vector<int> solve(string expression) {
        
        vector<int> answer;
        
        // Try every operator
        for (int i = 0; i < expression.length(); i++) {
            
            char op = expression[i];
            
            // If it is an operator
            if (op == '+' || op == '-' || op == '*') {
                
                // Left part
                string left = expression.substr(0, i);
                
                // Right part
                string right = expression.substr(i + 1);
                
                // Get all possible results
                vector<int> leftResults = solve(left);
                vector<int> rightResults = solve(right);
                
                // Combine left and right results
                for (int a : leftResults) {
                    for (int b : rightResults) {
                        
                        if (op == '+') {
                            answer.push_back(a + b);
                        }
                        
                        else if (op == '-') {
                            answer.push_back(a - b);
                        }
                        
                        else {
                            answer.push_back(a * b);
                        }
                    }
                }
            }
        }
        
        // If there is no operator, it is just a number
        if (answer.empty()) {
            answer.push_back(stoi(expression));
        }
        
        return answer;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};