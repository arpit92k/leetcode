class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        int l = s.length();
        int ll = l-1;
        while(i < l)
        {
            if(s[i] == 'M')
            {
                result += 1000;
                ++i;
                continue;
            }
            if(s[i] == 'C' && i< ll && s[i + 1] == 'M')
            {
                result += 900;
                i+=2;
                continue;
            }
            if(s[i] == 'D')
            {
                result += 500;
                ++i;
            }
            if(s[i] == 'C' && i< ll && s[i+1] == 'D')
            {
                result+=400;
                i+=2;
            }
            if(s[i] =='C')
            {
                result += 100;
                ++i;
            }
            if(s[i] == 'X' && i< ll && s[i+1] == 'C')
            {
                result += 90;
                i+=2;
            }
            if(s[i] == 'L')
            {
                result+= 50;
                ++i;
            }
            if(s[i] == 'X' && i< ll && s[i+1] == 'L')
            {
                result +=40;
                i+=2;
            }
            if(s[i] == 'X')
            {
                result += 10;
                ++i;
            }
            if(s[i] == 'I' && i< ll && s[i+1] == 'X')
            {
                result += 9;
                i+=2;
            }
            if(s[i] == 'V')
            {
                result += 5;
                ++i;
            }
            if(s[i] == 'I' && i< ll && s[i+1] == 'V')
            {
                result+=4;
                i+=2;
            }
            if(s[i] == 'I')
            {
                ++result;
                ++i;
            }
        }
        return result;
        
        
    }
};
