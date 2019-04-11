class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > query;
        int index = 0;
        for_each(nums.begin(), nums.end(), [&](int v){
            int val = v;
           query.push_back(make_pair(val, index++));
        });
        sort(query.begin(), query.end(), [](pair<int,int> a, pair<int, int>b){
            return a.first < b.first;
        });
        int s = 0;
        int e = query.size()-1;
        int sum;
        vector<int> result;
        while(s<e){
            sum = query[s].first + query[e].first;
            if(sum == target)
            {
                
                result.push_back(query[s].second);
                result.push_back(query[e].second);
                break;
            }
            else if(sum < target)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return result;
    }
    
};
