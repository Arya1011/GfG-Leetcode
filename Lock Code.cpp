//https://leetcode.com/problems/open-the-lock/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
         unordered_set<string> dead(deadends.begin(),deadends.end()),mp;
         if(target=="0000")return 0;
         if(dead.find("0000")!=dead.end())return -1;
         mp.insert("0000");
         queue<string> q;
         q.push("0000");
         int moves=0,sz;
         while(!q.empty())
         {
             sz=q.size();
             moves++;
             for(int i=0;i<sz;i++)
             {
                  auto curr=q.front();
                  q.pop();
                  for(int j=0;j<4;j++){
                      for(auto v:helper(curr,j))
                      {
                          if(dead.find(v)==end(dead) && mp.find(v)==end(mp))
                          {
                               if(v==target)
                               {
                                   return moves;
                               }                
                               
                               else
                               {
                                   q.push(v);
                                   mp.insert(v);
                               }
                          }
                      }
                  }   
             }   
         }
        return -1;
    }
    
    
    vector<string> helper(string s,int i){
        vector<string> res(2,s);
        res[0][i]='0'+(s[i]-'0'+1)%10;
        res[1][i]='0'+(s[i]-'0'-1+10)%10;
        return res;
    }
    
    
    
};
