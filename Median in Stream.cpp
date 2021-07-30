class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        int sz1=maxheap.size();
        int sz2=minheap.size();
        
        if(sz1==0){
            maxheap.push(num);
        }
        
        else if(sz1==sz2)
        {
            if(num<minheap.top()){
                maxheap.push(num);
            }
            
            else{
                
                int t=minheap.top();
                minheap.pop();
                maxheap.push(t);
                minheap.push(num);
                
            }
        }
        
        else{
        
            
             if(minheap.size()==0){
                 
                 if(num>maxheap.top()){
                     minheap.push(num);
                 }
                 
                 else{
                     int t=maxheap.top();
                     maxheap.pop();
                     minheap.push(t);
                     maxheap.push(num);
                 }
                 
                 
             }
            
             else if(num>=minheap.top()){
                 
                 minheap.push(num);
                 
             }
            
             else
             {
                 
                 if(num<maxheap.top()){
                      int t=maxheap.top();
                     maxheap.pop();
                     minheap.push(t);
                     maxheap.push(num);
                    
                 }
                 
                 else
                 {
                 
                      minheap.push(num);
                     
                     
                 }
                 
                 
                 
             }
             
            
            
            
            
        }
        
        
    }
    
    double findMedian() {
        
        int sz1=maxheap.size();
        int sz2=minheap.size();
        
        if((sz1+sz2)%2==0){
            return (double)(maxheap.top()+minheap.top())/2.0;
        }
        
        return (double)(maxheap.top());
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
