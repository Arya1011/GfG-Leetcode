

//https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size()==0){
             return ans;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int>a,vector<int>b){
           return a[0]<b[0];
        });
      
        int i=0;
        int j=i+1;
        vector<int>merged=intervals[0];
        while(i<intervals.size() && j<intervals.size()){
              if(merged[1]>=intervals[j][0]){
                  merged={intervals[i][0],max(intervals[j][1],merged[1])};
                  j++;
              }else{
                  ans.push_back(merged);
                  merged=intervals[j];
                  i=j;
                  j+=1;
              }
        }
      
       //for the last pair
       if(j==intervals.size()){
         
         ans.push_back(merged);
         
       }
      
        return ans;
    }
};
