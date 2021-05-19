//https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/
long long helper(char keypad[][3],int N){
	    
	    
	    
	    if(keypad==NULL || N==0){
	        return 0;
	    }
	    
	    if(N==1){
	        
	        return 10;
	        
	    }
	    
	    //same,left,right,top,down
	    vector<long long int> rows{0,0,0,-1,1};
	    vector<long long int> cols{0,-1,1,0,0};
	    
	    const long long int MOD=1e9+7;
	    
	    
	    //dp[i][j] means numbers starting with i and of length j
	    long long dp[10][N+1];
	    memset(dp,0,sizeof(dp));
	    for(long long int i=0;i<=9;i++){
	        dp[i][0]=0;
	        dp[i][1]=1;
	    }
	    
	    
	    for(long long int len=2;len<=N;len++){
	        
	        for(long long int i=0;i<4;i++){
	            
	            for(long long int j=0;j<3;j++){
	                
	               if(keypad[i][j]!='*' && keypad[i][j]!='#'){
	                   
	                   long long int num=keypad[i][j]-'0';
	                   
	                   for(int move=0;move<5;move++){
	                       
	                       
	                       long long int ro=i+rows[move];
	                       long long int co=j+cols[move];
	                       
	                       if(ro<=3 && co<=2 && ro>=0 && co>=0 && keypad[ro][co]!='*' && keypad[ro][co]!='#')
	                       {
	                           long long int next_num=keypad[ro][co]-'0';
	                           dp[num][len]=((dp[num][len])+(dp[next_num][len-1]));
	                       }
	                       
	                       
	                       
	                   }
	                   
	                   
	               }
	                
	                
	                
	                
	            }
	            
	            
	        }
	        
	        
	    }
	    
	    
	    long long int ans=0;
	    
	    for(int i=0;i<=9;i++){
	        
	        ans=(ans+dp[i][N]);
	        
	    }
	    
	    
	    return ans;
	    
	    
	}
	
	
	long long getCount(int N)
	{
		// Your code goes here
		
	
		  char keypad[4][3] = 
		                {{'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}};
                        
                        
       return helper(keypad,N);
		
		
		
		
		
	}
