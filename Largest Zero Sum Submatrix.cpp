#include<bits/stdc++.h>
using namespace std;


const int MAX =100;


bool helper_util1(int temp[],int &up,int &down,int R){

      //this function finds max zero sum subarray

      int ans=0;

      unordered_map<int,int> mp;

     

      int curr_sum=0;

      for(int i=0;i<R;i++){

            curr_sum+=temp[i];
            if(temp[i]==0 && ans==INT_MIN)
            {
                      up=i;
                      down=i;
                      ans=1;
            }

            if(curr_sum==0)
            {
                  if(ans<i+1){
                      ans=i+1;
                      up=0;
                      down=i;
                  }
            }

            if(mp.find(curr_sum)!=mp.end()){
 
                  int old=ans;
                  ans=max(ans,i-mp[curr_sum]);
                  if(old<ans){
                      up=mp[curr_sum]+1;
                      down=i;
                  }
            }

            else{
                mp[curr_sum]=i;
            }


      }

      return ans!=0;



}


void helper(int a[][MAX],int R,int C){
  
     int fup=0;
     int fdown=0;
     int fleft=0;
     int fright=0;

      //will store the row values of max submatrix
      int up,down;
 
      //temp [i] denotes sum of submatrix between left and right cols for ith row
      int temp[R];

     int max_el=0;

     //Set left and right cols ,iterate over rows and call for max length subarray everytime

     for(int left=0;left<C;left++){

         //for every new left bound update the temp array
         memset(temp,0,sizeof(temp));


         for(int right=left;right<C;right++)
         {
              for(int row=0;row<R;row++)
              {
                       temp[row]+=a[row][right];
              }
              bool zero_sum=helper_util1(temp,up,down,R);
              int ele=(right-left+1)*(down-up+1);
              if(zero_sum && ele>max_el)
              {
                   fup=up;
                   fdown=down;
                   fleft=left;
                   fright=right;
                   max_el=ele;
              }


         }


     }

     for(int i=fup;i<=fdown;i++){
         for(int j=fleft;j<=fright;j++){
             cout<<a[i][j]<<" ";
         }

         cout<<endl;
     }



}


int main(){
    
    int a[][MAX] = { { 9, 7, 16, 5 }, { 1, -6, -7, 3 },
                      { 1, 8, 7, 9 }, { 7, -2, 0, 10 } };


    //Largest SubMatrix with sum 0

    int R=4;
    int C=4;

     helper(a,R,C);
    


}
