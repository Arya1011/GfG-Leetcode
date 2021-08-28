class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        string ans="";
        stack<char>st;
        for(int i=0;i<n;i++)
        {
              while(k && !st.empty() && st.top()>num[i])
              {
                  st.pop();
                  k--;
              }
             st.push((char)num[i]);
        }
          //Remove any extra digits from the number
          while(k--)
          {
              st.pop();
          }
          while(!st.empty())
          {
              ans.push_back(st.top());
              st.pop();
          }
         int i=0;
         string s="";
         reverse(ans.begin(),ans.end());
        //No leading zeros
         while(i<ans.size() && ans[i]=='0')
         {
             i++;
         }
        ans=ans.substr(i);
        return ans.size()==0?"0":ans;
    }
};
