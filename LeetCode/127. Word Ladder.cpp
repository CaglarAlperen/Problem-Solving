class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        unordered_set<string> hm(wordList.begin(), wordList.end());
        unordered_map<string, bool> visited;
        
        vector<string> queue = {beginWord};
        int step = 1;
        
        while (queue.size() > 0)
        {
            int size = queue.size();
            for (int i = 0; i < size; i++)
            {
                string word = queue[i];
                for (int n = 0; n < word.size(); n++)
                {
                    word = queue[i];
                    for (int k = 0; k < 26; k++)
                    {
                        word[n] = 'a'+k;
                        if (visited[word])
                            continue;
                        if (hm.find(word) != hm.end())
                        {
                            if (word == endWord)
                                return step+1;
                            visited[word] = true;
                            queue.push_back(word);
                        }
                    }                
                }
            }
            for (int i = 0; i < size; i++)
                queue.erase(queue.begin());
            step++;
        }
        
        return 0;
    }
};