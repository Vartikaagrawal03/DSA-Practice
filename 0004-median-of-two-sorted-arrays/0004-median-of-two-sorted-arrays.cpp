class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int x=nums1.size();
        int y=nums2.size();
        int i=0,j=0;
        while(i<x && j<y){
            if(nums1[i]<nums2[j])
            v.push_back(nums1[i++]);
            else
            v.push_back(nums2[j++]);
        }
        while(i<x)v.push_back(nums1[i++]);
        while(j<y)v.push_back(nums2[j++]);
        int n=v.size();
        if(n%2==1)
        return v[n/2];
        return (v[n/2-1] + v[n/2])/2.0;
    }
};