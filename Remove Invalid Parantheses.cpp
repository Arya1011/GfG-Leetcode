//https://leetcode.com/problems/remove-invalid-parentheses/
class Solution {
public:
    
    
    unordered_set<string> seen;
    
    unordered_set<string> sol;
    
    int count_removals(string s){
        
        stack<char> st;
        
        for(auto ch:s)
        {
            if(ch=='(')
            {
                st.push(ch);
            }
            
            else if(ch==')')
            {
                 if(st.empty())
                {
                    st.push(ch);
                }
                
                else 
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }
                    
                    else
                    {
                        st.push(ch);    
                    }
                }
                
               
            }    
        }
        return st.size();
    }
    
    
    void helper(string s,int remove){
        
        if(remove==0)
        {
            
            if(count_removals(s)==0 && sol.find(s)==sol.end()){
                
                if(s.empty()){
                    sol.insert("");
                    return;
                }
                
                sol.insert(s);
            }
            
            return;
        }
            
            
            //We will try for all possible strings by removing one character each
            for(int i=0;i<s.length();i++)
            {
                string temp=s.substr(0,i)+s.substr(i+1);
                if(seen.find(temp)==seen.end()){
                     seen.insert(temp);
                      helper(temp,remove-1);
                }
            }
        return;
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        
        
        vector<string> ans;
        
        
        //count min removals required to make it balanced
        
        int remove=count_removals(s);
        
        helper(s,remove);
        
        for(auto it:sol){
            ans.push_back(it);
        }
        
     
        
        return ans;
        
        
    }
};
