//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3729/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
          priority_queue<int> pq;
          
          sort(courses.begin(),courses.end(),[](vector<int>&a,vector<int>&b){
              return a[1]<b[1]; 
          });
        
        int time=0;
        
        for(auto it:courses)
         {
             if(time+it[0]<=it[1])
             {
                  time+=it[0];
                  pq.push(it[0]);
             }
             else if(!pq.empty() && pq.top()>it[0])
             {
               
                   time=time-pq.top()+it[0];
                   pq.pop();
                  pq.push(it[0]);
             }
         }
        return pq.size();
        
    }
};
