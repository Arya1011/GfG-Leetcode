class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        bool flag=false;
        int ans=-1;
        //try and choose ever index as starting point
        for(int start=0;start<n;start++){
            int petrol=0;
            int to=-1;
            //can never be a starting point
            if(gas[start]<cost[start]){
                continue;
            }
            else{
                int petrol=gas[start];
                int i=start;
                while(petrol>=cost[i])
                {
                        petrol=petrol-cost[i];
                        to=(i+1)%n;
                       //means we have completed a round trip back to start
                       if(to==start)
                       {
                        ans=start;
                        return ans;
                       }
                    //if not visited there yet,then add fuel
                    petrol+=gas[to];
                    //assign
                    i=to;
                }
            }
            
        }
        return ans;
    }
};
