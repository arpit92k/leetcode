class Solution {
    int indexof[256];
public:
    int lengthOfLongestSubstring(string s) {
        for(int i = 0; i<256;i++)
        {
            indexof[i] = -1;
        }
        int current_length = 0;
        int longest_length = 0;
        int length = s.length();
        int index = 0;
        int start_index = 0;
        while(index<length)
        {
            if(indexof[s[index]] != -1){
                if(current_length > longest_length)
                {
                    longest_length = current_length;
                }
                current_length = index - indexof[s[index]];
                while(start_index <= indexof[s[index]])
                {
                    indexof[s[start_index++]] = -1;
                }
                indexof[s[index]] = index;
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
