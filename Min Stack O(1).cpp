class MinStack {
public:
    /** initialize your data structure here. */
    
     stack<int> st;
     int min_el;
    
    MinStack() {
        
        min_el=0;
       
    }
    
    void push(int val) 
    {
        if(st.empty()){
            st.push(val);
            min_el=val;
        }
        
        else {
            if(val>=min_el){
                st.push(val);
            }
            
            else{
                st.push(2*val-min_el);
                min_el=val;
            }
        }    
    }
    
    void pop() 
    {
        
        if(st.top()<min_el){
            min_el=2*min_el-st.top();
            st.pop();
        }
        
        else{
            st.pop();
        }
    }
    
    int top() {
        
        if(st.top()<=min_el){
            
            return min_el;
            
            
        }
        
        else{
            return st.top();
        }
        
        
    }
    
    int getMin() {
        
        return min_el;
        
        
    }
};
