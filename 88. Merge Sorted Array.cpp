class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        nums1[m] = INT_MAX;
        int pos = m+1;
        nums2.push_back(INT_MAX);
        int i=0,j=0;
        
        while(i<=m && j<nums2.size()){
            if(nums1[i] == nums2[j] && nums1[i] == INT_MAX)
                break;
            if(nums1[i]<=nums2[j]){
                if(pos<nums1.size()){
                    nums1[pos] = nums1[i];
                }
                else{
                    nums1.push_back(nums1[i]);
                }
                i++;
                pos++;
            }
            else{
                if(pos<nums1.size()){
                    nums1[pos] = nums2[j];
                }
                else{
                    nums1.push_back(nums2[j]);
                }
                j++;
                pos++;
            }
        }
        nums1.erase(nums1.begin(),nums1.begin()+m+1);
    }
};
