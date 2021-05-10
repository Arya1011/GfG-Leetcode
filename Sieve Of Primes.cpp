class Solution {
public:
    int countPrimes(int n) {
        
        
        vector<int> primes(n);
        
        
        for(int i=2;i<n;i++){
            primes[i]=1;
        }
        
        
        for(int i=2;i*i<n;i++){
            if(!primes[i]){
                continue;
            }
            
            for(int j=i*i;j<n;j+=i){
                primes[j]=0;
            }
            
        }
        
        
        int ans=0;
        
        for(int i=2;i<n;i++){
            if(primes[i]!=0){
                ans++;
            }
        }
        
        
        return ans;
        
        
        
    }
};
