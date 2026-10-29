class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0 , r=nums.size()-1 ; 
        vector<int>ans ; 
        vector<pair<int , int>>v ;
        for(int i=0 ; i<nums.size(); i++) v.push_back({nums[i], i}) ; 
        sort(v.begin(), v.end()) ;
        while(l<r)
        {
            if(v[l].first+v[r].first == target)
            {
                ans.push_back(v[l].second); 
                ans.push_back(v[r].second) ;
                sort(ans.begin(), ans.end()) ; 
                return ans ; 
            }
            if(v[l].first+v[r].first < target) l++ ;
            else if(v[l].first+v[r].first > target) r-- ; 
        }
    }
};
