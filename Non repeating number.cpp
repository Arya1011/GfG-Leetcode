public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        
        int n=nums.size();
        
        int _xor=0;
        
        for(int i=0;i<n;i++){
            _xor=_xor^nums[i];
        }
        
        int x=0;
        int y=0;
        
        //method to find rightmost set bit
        int set_bit=_xor & ~(_xor-1);
        
        // int temp=_xor;
        // int pos=0;
        // while((temp & 1)==0){
        //     pos++;
        //     temp>>1;
        // }
        
        // int set_bit=1<<pos;
        
        
        for(int i=0;i<n;i++){
            
            if(nums[i]&set_bit){
                x=x^nums[i];
            }
            
            else{
                y=y^nums[i];
            }
            
            
        }
        
            
    
        return {min(x,y),max(x,y)};
        
        
        
    }
