 
 //https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3581/
 
 class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(s[0]=='0'){
            return 0;
        }
        
        vector<int> dp(n+1,0);
        
        dp[0]=1;
        //only one character available
        dp[1]=1;
        
        //dp[i] denotes number of ways possible with i length string
        
        for(int i=2;i<=n;i++){
            
            //check if previous character is greater than zero
            if(s[i-1]-'0'>0){
                dp[i]=dp[i-1];
            }
            
            //taking 2 characters at once 
            if(s[i-2]=='1' || (s[i-2]-'0'==2 && s[i-1]-'0'<7)){
                dp[i]+=dp[i-2];
            }   
        }
        return dp[n];
    }
};
