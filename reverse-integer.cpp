class Solution {
public:
    int reverse(int x) {
        long long rn;
        int sign=1;
        if(x<0){
            sign=-1;
            x*=sign;
        }
        rn=0;
        while(x){
            rn*=10;
            rn+=(x%10);
            x/=10;
        }
        return rn*sign;
    }
};
