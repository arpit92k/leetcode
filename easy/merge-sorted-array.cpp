class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //shift nums1 to end
        int l = m + n;
        for(int i = m-1; i >= 0; --i)
        {
            nums1[--l] = nums1[i];
        }
        //merge 
        int i = l;
        int j = 0;
        l = 0;
        while(l < m + n)
        {
            if(i < m + n && j < n)
            {
                if(nums1[i] < nums2[j])
                {
                    nums1[l++] = nums1[i++];
                }
                else
                {
                    nums1[l++] = nums2[j++];
                }
            }
            else if(i < m + n)
            {
                nums1[l++] = nums1[i++];
            }
            else if(j < n)
            {
                nums1[l++] = nums2[j++];
            }
        }
    }
};
