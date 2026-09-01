class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string, int> count;
        vector<string> answer;
        
        // Check every 10-letter substring
        for (int i = 0; i + 9 < s.length(); i++) {
            
            string dna = s.substr(i, 10);
            
            count[dna]++;
            
            // Add only when count becomes 2
            if (count[dna] == 2) {
                answer.push_back(dna);
            }
        }
        
        return answer;
    }
};