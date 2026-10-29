class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s ; 
        for(int i=0 ; i<nums.size() ; i++)
        {
            s.insert(nums[i]) ;
        }
        vector<int>starts ; 
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(s.contains(nums[i]-1)) continue ; 
            starts.push_back(nums[i]) ;
        }
        int ans = 0 ;
        for(int i=0 ; i<starts.size() ; i++)
        {
            int search = starts[i]+1 ;
            int tmp = 1 ;
            while(s.contains(search))
            {
                tmp++ ;
                search++ ;
            }
            ans = max(tmp , ans) ;
        }
        return ans ; 

       
            
    }
};
