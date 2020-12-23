
//https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    
    map<int,bool> mp;
    map<int,bool>visited;
    bool canReach(vector<int>& arr, int start) {
        
         if(start>arr.size() || start<0){
             return false;
         }
        
         if(visited[start]){
             return mp[start];
         }
        
         if(!visited[start] && arr[start]==0){
              return true;
         }
        
         visited[start]=true;
        
         return mp[start]=canReach(arr,start-arr[start]) || canReach(arr,start+arr[start]);
    }
};
