



//In place merge sort
int nextGap(int g){
    if(g<=1){
        return 0;
    }

    return (int)ceil(gap/2.0);
}


void merge(int arr[],int s,int mid,int e){


      int gap=(e-s+1);

      for(gap=nextGap(gap);gap>0;gap=nextGap(gap)){
          for(int i=0;i+gap<=e;i++){
              int j=i+gap;
              if(arr[i]>arr[j]){
                  swap(arr[i],arr[j]);
              }
          }
      }

      return;


}

void mergeSort(int arr[],int s,int e){
    if(s>e){
        return;
    }

    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
    return;

}
