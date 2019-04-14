class Solution {
public:
    int maxArea(vector<int>& height) {
        int e = height.size() - 1;
        int s = 0;
        int max_area = 0;
        int area;
        while(s<e){
            if(height[s] < height[e])
            {
                area = height[s] * (e - s);
                ++s;
            }
            else
            {
                area = height[e] * (e - s);
                --e;
            }
            if(area > max_area){
                max_area = area;
            }
        }
        return max_area;
    }
};
