class WordDictionary {
public:

    // Trie node
    WordDictionary* children[26];

    // True if a complete word ends here
    bool isEnd;

    // Constructor
    WordDictionary() {
        isEnd = false;

        // Initially no children
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    void addWord(string word) {

        WordDictionary* current = this;

        // Add every character
        for (char c : word) {

            int index = c - 'a';

            // Create node if it doesn't exist
            if (current->children[index] == NULL) {
                current->children[index] = new WordDictionary();
            }

            // Move to next node
            current = current->children[index];
        }

        // Word is completely stored
        current->isEnd = true;
    }

    // Helper function for search
    bool check(string word, int position, WordDictionary* current) {

        // If all characters are checked
        if (position == word.length()) {
            return current->isEnd;
        }

        char c = word[position];

        // If character is '.'
        if (c == '.') {

            // Try all 26 letters
            for (int i = 0; i < 26; i++) {

                if (current->children[i] != NULL) {

                    // Check next character
                    if (check(word, position + 1,
                              current->children[i])) {
                        return true;
                    }
                }
            }

            return false;
        }

        // Normal character
        int index = c - 'a';

        // Character does not exist
        if (current->children[index] == NULL) {
            return false;
        }

        // Move to next character
        return check(word, position + 1,
                     current->children[index]);
    }

    bool search(string word) {

        return check(word, 0, this);
    }
};