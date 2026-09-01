class Trie {
public:

    // Each node has 26 possible letters
    Trie* children[26];

    // True if a complete word ends here
    bool isEnd;

    // Constructor
    Trie() {
        isEnd = false;

        // Initially no children
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }

    void insert(string word) {

        Trie* current = this;

        // Go through every character
        for (char c : word) {

            int index = c - 'a';

            // If character does not exist, create it
            if (current->children[index] == NULL) {
                current->children[index] = new Trie();
            }

            // Move to next node
            current = current->children[index];
        }

        // Word is completely inserted
        current->isEnd = true;
    }

    bool search(string word) {

        Trie* current = this;

        // Search every character
        for (char c : word) {

            int index = c - 'a';

            // Character not found
            if (current->children[index] == NULL) {
                return false;
            }

            current = current->children[index];
        }

        // Word must completely exist
        return current->isEnd;
    }

    bool startsWith(string prefix) {

        Trie* current = this;

        // Search every character of prefix
        for (char c : prefix) {

            int index = c - 'a';

            // Prefix not found
            if (current->children[index] == NULL) {
                return false;
            }

            current = current->children[index];
        }

        // Prefix exists
        return true;
    }
};