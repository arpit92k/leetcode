class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        if(l > 0)
        {
            int j = 0;
            merged.push_back(intervals[0]);
            for (int i = 1; i < l; ++i)
            {
                if(merged[j][1] >= intervals[i][0])
                {
                    merged[j][1] = merged[j][1] > intervals[i][1] ? merged[j][1] : intervals[i][1];
                }
                else
                {
                    merged.push_back(intervals[i]);
                    ++j;
                    cout<<j<<endl;
                }
            }    
        }
        return merged;
    }
};
