
//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

long long merge(long long arr[],long long temp[],long long s,long long mid,long long e,long long N){
    
    
        long long int i=s;
        long long int k=s;
        
        long long int j=mid+1;
        
        long long inversions=0;
        while(i<=mid && j<=e){
            
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }
            
            else{
                temp[k++]=arr[j++];
                inversions+=mid-i+1;
            }
        }
        
        //copy remaining of first array
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        
        while(j<=e){
            temp[k++]=arr[j++];
        }
        
        for(int i=s;i<=e;i++){
            arr[i]=temp[i];
        }
        
    return inversions;
    
    
}


long long mergeSort(long long arr[],long long temp[],long long s,long long e,long long N){
    
        if(s==e){
            return 0;
        }
        
        
        long long int mid=(s+((e-s)>>2));
        
        long long inversionCounts=0;
        
        inversionCounts+=mergeSort(arr,temp,s,mid,N);
        
        inversionCounts+=mergeSort(arr,temp,mid+1,e,N);
        
        inversionCounts+=merge(arr,temp,s,mid,e,N);
        
        return inversionCounts;
    
    
    
}


long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    
    int s=0;
    int e=N-1;
    long long temp[N];
    for(int i=0;i<N;i++){
        temp[i]=arr[i];
    }
    return mergeSort(arr,temp,s,e,N);
    
    
      
    
}
