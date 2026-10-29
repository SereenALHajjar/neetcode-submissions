class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> mp ; 
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(mp.contains(nums[i]))
                continue ; 
            mp[nums[i]] = i ; 
        }
        vector<int>v ; 
        for(int i=0 ; i<nums[i] ; i++)
        {
            if(mp.contains(target-nums[i]) && i != mp[target-nums[i]])
            {
                v.push_back(i) ;
                v.push_back(mp[target-nums[i]]) ; 
                sort(v.begin() , v.end()) ; 
                return v ; 
            }
        }
    }
};
