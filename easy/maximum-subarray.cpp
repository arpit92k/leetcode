class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums.size();
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < l; ++i)
        {
            sum += nums[i];
            if(sum > max_sum)
            {
                max_sum = sum;
            }
            if(sum <= 0)
            {
                sum = 0;
            }
        }
        return max_sum;
    }
};
