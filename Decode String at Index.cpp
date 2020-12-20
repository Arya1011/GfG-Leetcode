
//https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3572/

//Traditional method will give MLE so we have to use the length of the decode string

class Solution {
public:
    string decodeAtIndex(string S, int K) 
    {
        long long size=0;
        //length of decoded string
        for(int i=0;i<S.size();i++){
            if(isalpha(S[i])){
                size++;
            }
            else if(isdigit(S[i])){
                size*=S[i]-'0';
            }
        }
        
        
        for(int i=S.size()-1;i>=0;i--)
        {   
             K%=size;
            
             if(K==0 && isalpha(S[i])){
                 string ans="";
                 ans.push_back(S[i]);
                 return ans;
             }
            
             //means string before it has been repeated digit-1 times
             else if(isdigit(S[i])){
                 size/=S[i]-'0';
             }
            
             //simply decrease length
             else{
                 size--;
             }
        }
        return "";
    }
};
