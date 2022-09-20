class Solution {
public:
    bool isValid(string s) {
        
        vector<char> stack;
        
        for (char c : s)
        {
            switch (c)
            {
                case ')':
                    if (!stack.size())
                        return false;
                    if (stack.back() != '(')
                        return false;
                    else 
                        stack.pop_back();
                    break;
                case '}':
                    if (!stack.size())
                        return false;
                    if (stack.back() != '{')
                        return false;
                    else 
                        stack.pop_back();
                    break;
                case ']':
                    if (!stack.size())
                        return false;
                    if (stack.back() != '[')
                        return false;
                    else 
                        stack.pop_back();
                    break;
                default:
                    stack.push_back(c);
            }
        }
        
        return stack.size() == 0;
    }
};