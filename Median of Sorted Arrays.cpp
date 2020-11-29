//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int len1=nums1.size();
        int len2=nums2.size();
        
        if(len1>len2){

          return findMedianSortedArrays(nums2,nums1);
        
        }
        
        
        int lo=0;
        int hi=len1;
        
        //apply binary search on the smaller of the two arrays(in this case its always the nums1)
        while(lo<=hi){
            
            int partX=lo+(hi-lo)/2;
            int partY=(len1+len2+1)/2-partX;
            
            int maxLeftX=(partX==0)?INT_MIN:nums1[partX-1];
            int minRightX=(partX==len1)?INT_MAX:nums1[partX];
            
            int maxLeftY=(partY==0)?INT_MIN:nums2[partY-1];
            int minRightY=(partY==len2)?INT_MAX:nums2[partY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                 if((len1+len2)%2==0){
                     return ((double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY)))/2;
                 }
                 else{
                     return (double)max(maxLeftX,maxLeftY);
                 }
            }
            
            else if(maxLeftX>minRightY){
                hi=partX-1;
            }
            else{
                lo=partX+1;
            }
            
        }
        return -1.0;
    }
};


