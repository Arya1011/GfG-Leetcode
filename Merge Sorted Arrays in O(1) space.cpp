//N=m+n
//O(logN * N)
void merge(vector<int>&arr1,vector<int>&arr2){

         int n=arr1.size();
         int m=arr2.size();
         int gap=m+n;
         int i,j;
         for(int gap=nextgap(gap);gap>0;gap=nextgap(gap))
         {
              for(i=0;i+gap<n;i++){
                  if(arr1[i]>arr1[i+gap]){
                      swap(arr1[i],arr1[i+gap]);
                  }
              }

              for(j=gap>n?gap-n:0;j<m && i<n;i++,j++){
                  if(arr1[i]>arr2[j]){
                      swap(arr1[i],arr2[j]);
                  }
              }

              if(j<m){
                  for(int j=0;j+gap<m;j++){
                      if(arr2[j]>arr2[j+gap]){
                          swap(arr2[j],arr2[j+gap]);
                      }
                  }
              }    
         }

         for(auto i:arr1) cout<<i<<" ";
         cout<<endl;
         for(auto i:arr2) cout<<i<<" ";
}
