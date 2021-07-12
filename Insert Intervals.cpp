class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        
        int i=0;
        
        int n=intervals.size();
        
        
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        
        //Merge overlapping intervals
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        
        //push merged interval
        ans.push_back(newInterval);
        
        //push remaining
        for(;i<n;i++){
            ans.push_back(intervals[i]);
        }
        
        return ans;
        
        
    }
};
