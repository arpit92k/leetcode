class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int l = nums.size();
        int product = 1;
        for(int i = 0; i<l; ++i)
        {
            product *= nums[i];
            max_product =  product > max_product ? product : max_product;
            product = product == 0 ? 1 : product; 
        }
        product = 1;
        for(int i = l - 1; i>=0; --i)
        {
            product *= nums[i];
            max_product =  product > max_product ? product : max_product;
            product = product == 0 ? 1 : product; 
        }
        return max_product;
    }
};
