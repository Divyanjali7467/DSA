class Solution {
public:
    int binarysearch(vector<int>& nums, int s, int e, int target){
        if(s>e)
            return -1;

        int mid =s+(e-s)/2;    
        
        if(nums[mid] == target)
            return mid;
        
        if(nums[mid]<target)
            return binarysearch(nums,mid+1,e,target);
        
        else
            return binarysearch(nums,s,mid-1,target);
        
    
    } 
    int search(vector<int>& nums, int target) {
         int s= 0;
         int e =nums.size()-1;

         return binarysearch(nums,s,e,target);
      
    }
};