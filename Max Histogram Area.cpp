
//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/1/?undefined#

long long getMaxArea(long long arr[], int n){
    
    // Your code here
    
    
    long long i=0;
    
    stack<long long> s;
    
    long long max_area=LLONG_MIN;
    
    while(i<n){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i);
            i++;
            continue;
        }
        
        //means wr have reached the right boundary of the topmost bar o we can calculate the area with respect to the topmost bar as the smallest bar
        else if(arr[s.top()]>arr[i])
        {
            long long x=s.top();
            
            s.pop();
            
            //empty would mean it has no left boundary and if left boundary exists then we find the number of bars in between and multiply
            long long area=arr[x] * (s.empty()?i:i-1-s.top());
            
            max_area=max(max_area,area);
        }
    }
    
    
    //if any more bars are left in the stack then repeat the same process for them also
    while(!s.empty()){
        long long x=s.top();
        
        s.pop();
        
        long long area=arr[x]* (s.empty()?i:i-s.top()-1);
        
        max_area=max(max_area,area);
    }
    
    return max_area;
    
}
