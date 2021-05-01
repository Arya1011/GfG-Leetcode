class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> ans(2);
        vector<int> slots(T,-1);
        //sort according to profit
        sort(arr,arr+n,[](Job &a,Job &b)
        {
           return a.profit>b.profit; 
        });
        
        
        int p=0;
        
     
        
        for(int idx=0;idx<n;idx++)
        {
             for(int i=arr[idx].dead-1;i>=0;i--)
             {
                 //slot is free
                 if(i<T && slots[i]==-1)
                 {
                     slots[i]=arr[idx].id;
                     p+=arr[idx].profit;
                     break;
                 }
             }
        }
        
        
        int j=0;
        
        for(int i=0;i<T;i++){
            if(slots[i]!=-1){
                j++;
            }
        }
        
        ans[0]=j;
        ans[1]=p;
        
        return ans;
    } 
};
