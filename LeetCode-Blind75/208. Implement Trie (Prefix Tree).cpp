class Trie {
private:
    bool end;
    Trie* child[26];
public:
    Trie() {
        end = false;
        memset(child, 0, 26*sizeof(Trie*));
    }
    
    void insert(string word) {
        if (word.length() == 0)
        {
            end = true;
            return;
        }
        if (!child[word[0]-97])
            child[word[0]-97] = new Trie();
        child[word[0]-97]->insert(word.substr(1, word.length()-1));
    }
    
    bool search(string word) {
        if (word.length() == 0)
            return end;
        if (child[word[0]-97])
            return child[word[0]-97]->search(word.substr(1, word.length()-1));
        return false;
    }
    
    bool startsWith(string prefix) {
        if (prefix.length() == 0)
            return true;
        if (child[prefix[0]-97])
            return child[prefix[0]-97]->startsWith(prefix.substr(1, prefix.length()-1));
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */