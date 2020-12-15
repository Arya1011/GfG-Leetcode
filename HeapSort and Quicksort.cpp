
//Heap sort O(nlogn)

#include<bits/stdc++.h>
using namespace std;


//O(n)


void upHeapify(vector<int>&arr,int idx){
 
      if(idx==0){
          return;
      }
      int parent_idx=floor((idx-1)/2);
      if(arr[parent_idx]<arr[idx]){
          swap(arr[parent_idx],arr[idx]);
      }
      upHeapify(arr,parent_idx);
}


void downHeapify(vector<int>&arr,int idx)
{
      if(idx>=arr.size()){
          return;
      }
      int left=2*idx+1;
      int right=2*idx+2;
      int max_idx=idx;
      if(left>=arr.size() && right>=arr.size()){
          return;
      }
      if(left<arr.size() && arr[max_idx]<arr[left]){
          max_idx=left;
      }
      if(right<arr.size() && arr[max_idx]<arr[right]){
          max_idx=right;
      }
      if(idx==max_idx){
          return;
      }
      swap(arr[idx],arr[max_idx]);
      downHeapify(arr,max_idx);
}


void buildHeap2(vector<int>&arr){
         for(int i=0;i<arr.size();i++){
             upHeapify(arr,i);
         }
}


void buildHeap1(vector<int>&arr){
         for(int i=arr.size()-1;i>=0;i--){
             downHeapify(arr,i);
         }
}

void downHeapifyHelper(vector<int>&arr,int idx,int heapsize)
{
      if(idx>=arr.size()){
          return;
      }
      int left=2*idx+1;
      int right=2*idx+2;
      int max_idx=idx;
      if(left>=heapsize && right>=heapsize){
          return;
      }
      if(left<heapsize && arr[max_idx]<arr[left]){
          max_idx=left;
      }
      if(right<heapsize && arr[max_idx]<arr[right]){
          max_idx=right;
      }
      if(idx==max_idx){
          return;
      }
      swap(arr[idx],arr[max_idx]);
      downHeapifyHelper(arr,max_idx,heapsize);
}


void heapsort(vector<int>&arr){
        int heapsize=arr.size();
        for(int i=arr.size()-1;i>=0;i--){
                swap(arr[0],arr[i]);
                heapsize--;
                downHeapifyHelper(arr,0,heapsize);
        }
}

int partition(vector<int>&arr,int s,int e)
{
        int i=s-1;
        int j=s;
        int pivot=arr[e];
        for(;j<=e-1;j++){
            if(arr[j]<pivot){
                 i++;
                 swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[e]);
        return i+1;
}





void quicksort(vector<int>&arr,int s,int e)
{
         if(s>=e){
             return;
         }
         int p=partition(arr,s,e);
         quicksort(arr,s,p-1);
         quicksort(arr,p+1,e);
         return;
}

int main()
{
     vector<int> arr={18,-7,6,2,9,0,1,-13};
     //buildHeap2(arr);

     clock_t start,end;

     start = clock(); 
     quicksort(arr,0,arr.size()-1);
     end=clock();

     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

     cout<<fixed<<time_taken<<setprecision(5)<<endl;

     for(auto it:arr){
         cout<<it<<" ";
     }
}
