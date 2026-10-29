class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int>mp ; 
        vector<int>ans ; 
        vector<pair<int , int>>v ; 
        for(int i=0 ; i<nums.size() ; i++) mp[nums[i]]++ ; 
        for(auto e : mp) v.push_back({e.first , e.second}) ;
        sort(v.begin(), v.end(),[] (pair<int , int>p1 , pair<int , int>p2)
    {
        if(p1.second > p2.second) return true ; 
        return false ;
    }) ; 
        for(int i=0 ; i<k ; i++) ans.push_back(v[i].first) ;
        return ans ; 
    }
};
