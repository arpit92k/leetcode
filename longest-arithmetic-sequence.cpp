class Solution {
    int ans = -1;
    map<int,map<int,int>> lap;
public:
    int longestArithSeqLength(vector<int>& A) {
        int l = A.size();
        for (int j=0; j < l; j++)
        {
            for(int i = 0; i < j; i++)
            {
                int d = A[j] - A[i];
                if(lap[i].find(d) == lap[i].end())
                {
                    lap[i][d] = 1;
                }
                lap[j][d] = lap[j][d] > lap[i][d] + 1 ? lap[j][d] : lap[i][d] + 1;
                if(ans < lap[j][d])
                {
                    ans = lap[j][d];
                }
            }
        }
        return ans;
    }
};
