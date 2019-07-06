class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        string ans = "";
        int l,s,e;
        int carry = 0;
        while(l1 >0 && l2 > 0)
        {
            s = (num1[--l1] - '0') + (num2[--l2] - '0') + carry;
            carry = s / 10;
            s%=10;
            ans += char('0' + s);
        }
        while(l1 > 0)
        {
            if(carry)
            {
                s = (num1[--l1] - '0') + carry;
                carry = s / 10;
                s%=10;
                ans += char('0' + s);
            }
            else
            {
                ans += num1[--l1];
            }
        }
        while(l2 > 0)
        {
            if(carry)
            {
                s = (num2[--l2] - '0') + carry;
                carry = s / 10;
                s%=10;
                ans += char('0' + s);
            }
            else
            {
                ans += num2[--l2];
            }
        }
        if(carry)
        {
            ans += char('0' + carry);
        }
        l = ans.length();
        s = 0;
        e = l-1;
        while(s < e)
        {
            char c = ans[s];
            ans[s] = ans[e];
            ans[e] = c;
            ++s;
            --e;
        }
        return ans;
    }
};
