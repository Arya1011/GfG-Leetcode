
int minSwap(int *arr, int n, int k) {
    // Complet the function
    
    int swaps=1000007;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        {
            cnt++;
        }
        
    }
    
    int bad=0;
    
    for(int i=0;i<cnt;i++){
        if(arr[i]>k){
            bad++;
        }
    } 
 
 
    int i=0;
    int j=cnt-1;
    
    while(j<n){
        
        swaps=min(swaps,bad);
        j++;
        if(j<n && arr[j]>k){
            bad++;
        }
        
        if(arr[i]>k)bad--;
        i++;
        
        
        
    }
 
    return swaps;
}
