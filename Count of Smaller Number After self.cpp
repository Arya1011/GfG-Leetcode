class Solution {
public:
    
    
    void merge(vector<pair<int,int>>&v,vector<int>&count,int s,int e){
        
        int m=e-s+1;
        vector<pair<int,int>> temp(m);
        int mid=(s+e)>>1;
        int i=s;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=e){
            if(v[i].first<=v[j].first){
                temp[k++]=v[j++];
            }
            
            else
            {
            
                  count[v[i].second]+=(e-j+1);
                  temp[k++]=v[i++];
                
            }
        }
        
        
        while(i<=mid){
            temp[k++]=v[i++];
        }
        
        while(j<=e){
            temp[k++]=v[j++];
        }
        
        
        for(int i=s;i<=e;i++){
            v[i]=temp[i-s];
        }
        
        
    }
    
    
    
    void mergeSort(vector<pair<int,int>>&v,vector<int>&count,int s,int e){
        
        if(s>=e){
            return;
        }
        
        int mid=(s+e)>>1;
        mergeSort(v,count,s,mid);
        mergeSort(v,count,mid+1,e);
        merge(v,count,s,e);
        return;
    }
    
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<pair<int,int>> v;
        for(auto i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        int n=nums.size();
        vector<int>count(n,0);
        mergeSort(v,count,0,n-1);
        return count;    
    }
};
