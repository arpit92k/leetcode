class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        long reverse = 0;
        int xt = x;
        while(xt)
        {
            reverse = reverse * 10 + xt % 10;
            xt/=10;
        }
        return reverse == x;
    }
};
