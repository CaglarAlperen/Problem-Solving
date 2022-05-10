class WordDictionary {
private:
    bool end;
    WordDictionary* child[26];
public:
    WordDictionary() {
        end = false;
        memset(child, 0, 26*sizeof(WordDictionary*));
    }
    
    void addWord(string word) {
        if (word.length() == 0)
        {
            end = true;
            return;
        }
        if (!child[word[0]-97])
            child[word[0]-97] = new WordDictionary();
        child[word[0]-97]->addWord(word.substr(1, word.length()-1));
    }
    
    bool search(string word) {
        if (word.length() == 0)
            return end;
        if (word[0] == '.')
        {
            bool res = false;
            for (int i = 0; i < 26; i++)
            {
                if (child[i])
                    res = res || child[i]->search(word.substr(1, word.length()-1));
            }
            return res;
        }
        else
        {
            if (child[word[0]-97])
                return child[word[0]-97]->search(word.substr(1, word.length()-1));
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */