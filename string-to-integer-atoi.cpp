
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int l = str.length();
        int i = -1;
        long result = 0;
        while(str[++i] == ' ');
        if(str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else if(str[i] == '+')
        {
            ++i;
        }
        int overflow = 0;
        while(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
            if(sign > 0 && result > numeric_limits<int>::max())
            {
                overflow =  numeric_limits<int>::max();
                break;
            }
            else if(sign < 0 && result > (long)-1 * numeric_limits<int>::min())
            {
                overflow = numeric_limits<int>::min();
                break;
            }
            ++i;
        }
        if(overflow)
        {
            return overflow;
        }
        return result*sign;
    }
};
