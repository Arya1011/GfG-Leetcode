class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> ans;
        ans.push_back(1);
        for(int i=2;i<=N;i++){
            int c=0;
            for(int j=0;j<ans.size();j++){
                int n=i*ans[j]+c;
                ans[j]=n%10;
                c=n/10;
            }
            
            while(c!=0){
                ans.push_back(c%10);
                c/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
