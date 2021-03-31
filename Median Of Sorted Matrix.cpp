//https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

//O(nm + nmlog(nm))
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        // code here   
        
        vector<int> elements;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                elements.push_back(matrix[i][j]);
            }
        }
        sort(elements.begin(),elements.end());
        int n=elements.size();
        if(n%2==0){
            return (elements[n/2]+elements[n/2 - 1])/2;
        }    
        
        return elements[n/2];
        
    }
};

//O(32*rows*log(cols))
int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];
  
        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }
  
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
  
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
