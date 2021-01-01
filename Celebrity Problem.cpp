
//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#

O(n)
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n1=arr.size();
        int n2=pieces.size();
        
        
        if(n1==n2 && n1==1 && n2==1){
            return arr[0]==pieces[0][0];
        }
        
        unordered_map<int,int>mp;
        
        for(auto i=0;i<n1;i++){
            mp[arr[i]]=i;
        }
        
        bool flag=true;
        for(auto it:pieces){
            for(auto i=0;i<it.size()-1;i++){
                if(mp[it[i]]+1==mp[it[i+1]]){
                    continue;
                }
                else{
                    flag=false;
                    break;
                }
            }
        }
        
        
        return flag;
        
    }
};
