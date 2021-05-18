
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    
	    //dp[i][0] denotes  length of subseq ending at idx i with last ele  greater than previous element in the subseq
	    //dp[i][1] dnotes length of subseq ending at idx i with last ele smaller than previous element in the subseq
	    int dp[n][2];
	    int ans=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<2;j++){
	            dp[i][j]=1;
	        }
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            
	              if(v[i]>v[j]){
	                  dp[i][0]=max(dp[i][0],dp[j][1]+1);
	              }
	              
	              else if(v[i]<v[j]){
	                  
	                  dp[i][1]=max(dp[i][1],dp[j][0]+1);
	              }
	              
	              
	              
	        }
	        
	        ans=max(ans,max(dp[i][1],dp[i][0]));
	       
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
