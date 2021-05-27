class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    int largestPowerof2(int n){
        
        int x=0;
        
        while((1<<x) <= n){
            
            x++;
        }
        
        return x-1;
        
    }
    
    
    int countSetBits(int n)
    {
        // Your logic here
        
        if(n==0){
            return 0;
        }
        int x=largestPowerof2(n);
        int upto2powerx=(x)*(1<<(x-1));
        int msbfrom2xton=n-(1<<x)+1;
        int rest=n-(1<<x);
        int ans=upto2powerx+ msbfrom2xton+countSetBits(rest);
        return ans;
    }
