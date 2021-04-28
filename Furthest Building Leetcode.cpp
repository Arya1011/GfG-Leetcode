class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
      
        /*
        
           Put ladder number of height differenece in the pq and iterate over remaining differences. If curr diff in height is smaller than pq.top(),we use bricks
           ,else we reduce pq.top() from bricks and push the diff into the pq(essentially maintaining at least ladder number of differnces in the queue)
        
        */
      
        int n=heights.size();
        int diff;
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        //maintain only ladder number of diff in pq
        while(i<n-1 && pq.size()<ladders)
        {
            diff=heights[i+1]-heights[i];
           
            if(diff>0){
                pq.push(diff);
            }
            
            i++;
            
        }
        
        
        while(i<n-1)
        {
            diff=heights[i+1]-heights[i];
            if(diff>0)
            {
                 //we try to use max bricks for shorter jumps
                 if(!pq.empty() && diff>pq.top())
                 {
                        bricks-=pq.top();
                        pq.pop();
                        pq.push(diff);
                 }
                 else
                 {
                      bricks-=diff;
                 }   
            }
            if(bricks<0) return i;
            i++;
        }
        return i;
    }
};
