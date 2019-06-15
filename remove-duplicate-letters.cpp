class Solution {
    int lastIndex['z' + 1];
    bool inAns['z' + 1];
public:
    string removeDuplicateLetters(string text) {
        for(int i =0; i<text.length(); ++i)
        {
            lastIndex[text[i]] = i;
        }
        std::stack<char> ansStack;
        ansStack.push(text[0]);
        inAns[text[0]] = true;;
        for(int i=1;i<text.length(); ++i)
        {
            if(inAns[text[i]])
            {
                continue;
            }
            while(!ansStack.empty() && ansStack.top() > text[i] && lastIndex[ansStack.top()] > i)
            {
                inAns[ansStack.top()] = false;
                ansStack.pop();
            }
            ansStack.push(text[i]);
            inAns[text[i]] = true;
        }
        string ans_r = "";
        while(!ansStack.empty())
        {
            ans_r+=ansStack.top();
            ansStack.pop();
        }
        string ans = "";
        for(int i=ans_r.length()-1;i>=0;--i)
        {
            ans+=ans_r[i];
        }
        return ans;
    }
};
