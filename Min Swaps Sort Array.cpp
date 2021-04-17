 void swap_el(vector<int>&nums,int i,int j){
       swap(nums[i],nums[j]);
       return;
   }

	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int> mp;
	    for(int i=0;i<nums.size();i++)
	    {
	        mp[nums[i]]=i;
	    }
	    int ans=0;
	    vector<int> temp=nums;
	    sort(temp.begin(),temp.end());
	    for(int i=0;i<nums.size();i++)
	    {
	        if(temp[i]!=nums[i])
	        {
	            ans++;
	            int a=nums[i];
	            swap_el(nums,i,mp[temp[i]]);
	            mp[a]=mp[temp[i]];
	            mp[temp[i]]=i;
	        }
	    }
	    return ans;
	}
