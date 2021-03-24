//https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int MOD=1e9+7;
        
        //O(n)
        unordered_map<int,int> mp;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
              ans=(ans+mp[target-arr[i]])%MOD;
              for(int j=0;j<i;j++){
                  mp[arr[j]+arr[i]]++;
              }
        }
        return ans;
    }
};

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {
           sort(arr.begin(),arr.end());
           int ans=0;
           int MOD=1e9+7;
        
           for(int i=0;i<arr.size();i++){
               
               int j=i+1;
               int k=arr.size()-1;
               int remaining=target-arr[i];
               while(j<k){
                   if(arr[j]+arr[k]>remaining){
                       k--;
                   }
                   
                   else if(arr[j]+arr[k]<remaining){
                       j++;
                   }
                   
                   else{
                       
                       if(arr[j]!=arr[k]){
                           int left=1;
                           int right=1;
                           
                           while(j+1<k && arr[j]==arr[j+1]){
                               left++;
                               j++;
                           }
                           
                           while(k-1>j && arr[k]==arr[k-1]){
                               right++;
                               k--;
                           }
                           
                           ans=ans+(left*right);
                           ans%=MOD;
                           j++;
                           k--;
                           
                       }
                       
                       else{
                           int M=k-j+1;
                           ans=ans+(M*(M-1))/2;
                           ans%=MOD;
                           break;
                       }
                       
                   }
               }
               
               
           }
        
         
        return ans;
        
        
    }
};
