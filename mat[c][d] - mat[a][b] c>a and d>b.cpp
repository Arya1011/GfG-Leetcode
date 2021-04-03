
//O(n^2)
void solve()
{
    int max_val=mat[n-1][n-1];
    
    int maxarr[n][n];
    maxarr[n-1][n-1]=mat[n-1][n-1];

    //last row
    for(int i=n-2;i>=0;i--){
        maxarr[n-1][i]=max(max_val,mat[n-1][i]);
    }

    //last col
    for(int i=n-2;i>=0;i--){
        maxarr[i][n-1]=max(max_val,mat[i][n-1]);
    }


    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){

            if(maxarr[i+1][j+1]-mat[i][j]>max_val){
               max_val=maxarr[i+1][j+1]-mat[i][j];
            }
            maxarr[i][j]=max(mat[i][j],max(maxarr[i+1][j],maxarr[i][j+1]));
        }
    }
 cout<<max_val<<endl;


}
