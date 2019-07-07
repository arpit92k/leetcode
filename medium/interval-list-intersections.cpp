class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> intersection;
        int l1 = A.size();
        int l2 = B.size();
        int i = 0;
        int j = 0;
        int start, end;
        while(i < l1 && j < l2)
        {
            start = A[i][0] > B[j][0] ? A[i][0] : B[j][0];
            end = A[i][1] < B[j][1] ? A[i][1] : B[j][1];
            if(start <= end)
            {
                //valid overlapping interval
                vector<int> interval;
                interval.push_back(start);
                interval.push_back(end);
                intersection.push_back(interval);
            }
            A[i][1] < B[j][1] ? ++i : ++j;
        }
        return intersection;
    }
};
