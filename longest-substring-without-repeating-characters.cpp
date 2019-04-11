class Solution {
    map<char, int> indexof;
public:
    int lengthOfLongestSubstring(string s) {
        int current_length = 0;
        int longest_length = 0;
        int length = s.length();
        int index = 0;
        while(index<length)
        {
            if(indexof.find(s[index]) != indexof.end()){
                if(current_length > longest_length)
                {
                    longest_length = current_length;
                }
                index  = indexof[s[index]];
                indexof.clear();
                current_length = 0;
            }
            else
            {
                indexof[s[index]] = index;
                current_length++;
            }
            index ++;
        }
        if(current_length > longest_length)
        {
            longest_length = current_length;
        }
        return longest_length;
    }
};
