class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string result = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ')
            {
                word+=s[i];
            }
            else if(word.length() > 0)
            {
                result = word + " " + result;
                word = "";
            }
        }
        if(word.length() > 0)
        {
            result = word + " " + result;
            word = "";
        }
        return result.substr(0, result.length()-1);
    }
};
