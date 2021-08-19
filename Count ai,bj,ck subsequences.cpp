class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        long long int a=0;
        long long int ab=0;
        long long int abc=0;
        const int MOD=1e9+7;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                
                a=((2*a)%MOD+1)%MOD;
                
            }
            
            else if(s[i]=='b')
            {
                
              ab=((2*ab)%MOD+a)%MOD;
                
            }
            
            else if(s[i]=='c')
            {
                abc=((2*abc)+ab)%MOD;
            }
        }
        
        return (int)abc;
        
    }
};
