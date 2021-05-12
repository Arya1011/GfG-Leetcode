class Solution {
public:
    string longestPalindrome(string s) {
        
        //O(n^3)
        int n=s.length();
        int dp[n][n];
        int start;
        memset(dp,0,sizeof(dp));
        if(n==0){
            return "";
        }
        
        if(n==1){
            return s;
        }
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int max_len=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                max_len=2;
                start=i;
            }
        }
        
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=1;
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,max_len);
    }
};
