



//getMin() in O(1) time

#include<bits/stdc++.h>
using namespace std;


class Stack{
    stack<int> s;
    int min_el;


    public:

    void push(int x){

        if(s.empty()){
            s.push(x);
            min_el=x;
            return;
        }
        
        else{

           if(x<min_el){
               s.push(2*x-min_el);
               min_el=x;
           }

           else{
               s.push(x);
           }

        }


    }


    void pop(){

        if(s.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }

        int t=s.top();

        s.pop();

         //indicates we didnt push the actual number in the stack
        if(t<min_el){
            cout<<min_el<<endl;
            min_el=2*min_el-t;
        }
        else{
            cout<<t<<endl;
        }
    }

    void getMin(){

         if(s.empty()){
             cout<<"Stack is empty"<<endl;
         }

         else{
 
              cout<<min_el<<endl;


         }

    }

    void peek()
    {
      if(s.empty()){
          cout<<"Stack is empty"<<endl;
          return;
      }
       s.top()<min_el?cout<<min_el:cout<<s.top();
    }
};


int main(){

    Stack S;

    S.push(3); 
    S.push(5); 
    S.getMin(); 
    S.push(2); 
    S.push(1); 
    S.getMin(); 
    S.pop(); 
    S.getMin(); 
    S.pop(); 
    S.peek(); 
    return 0;
}
