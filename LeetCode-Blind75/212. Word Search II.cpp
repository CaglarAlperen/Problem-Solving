class Trie {
public:
    bool end;
    Trie* child[26];
    
    Trie() {
        end = false;
        memset(child, 0, 26*sizeof(Trie*));
    }
    
    void addWord(string word) {
        if (word.length() == 0)
        {
            end = true;
            return;
        }
        if (!child[word[0]-97])
            child[word[0]-97] = new Trie();
        child[word[0]-97]->addWord(word.substr(1, word.length()-1));
    }
    
    bool search(string word, bool& prefix) {
        if (word.length() == 0)
        {
            prefix = true;
            return end;
        }
        if (word[0] == '.')
        {
            bool res = false;
            for (int i = 0; i < 26; i++)
            {
                if (child[i])
                    res = res || child[i]->search(word.substr(1, word.length()-1), prefix);
            }
            return res;
        }
        else
        {
            if (child[word[0]-97])
                return child[word[0]-97]->search(word.substr(1, word.length()-1), prefix);
            prefix = false;
            return false;
        }
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, Trie* trie, int i, int j, string word, vector<string>& res)
    {      
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || !trie || board[i][j] == '*')
            return;
        
        word.push_back(board[i][j]);
        if (trie->end)
        {
            trie->end = false;
            res.push_back(word);
        }
        
        board[i][j] = '*';
        
        if (i > 0 && board[i-1][j] != '*')
            dfs(board, trie->child[board[i-1][j]-97], i-1, j, word, res);
        if (j > 0 && board[i][j-1] != '*')
            dfs(board, trie->child[board[i][j-1]-97], i, j-1, word, res);
        if (i < board.size()-1 && board[i+1][j] != '*')
            dfs(board, trie->child[board[i+1][j]-97], i+1, j, word, res);
        if (j < board[0].size()-1 && board[i][j+1] != '*')
            dfs(board, trie->child[board[i][j+1]-97], i, j+1, word, res);
        
        board[i][j] = word[word.length()-1];
        word.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> res;
        Trie *trie = new Trie();
        
        for (string word : words)
            trie->addWord(word);
        
        bool prefix = true;
        string word;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, trie->child[board[i][j]-97], i, j, "", res);
            }
        }
        
        return res;
    }
};