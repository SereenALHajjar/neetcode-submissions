class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1,zeros = 0 ; 
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] ==0) zeros++ ;
            else 
            {
                mul*=nums[i] ;
            }
        }
        vector<int>v  ;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0)
            {
                if(zeros > 1) v.push_back(0) ;
                else v.push_back(mul) ;
            }
            else
            {
                if(zeros >= 1) v.push_back(0) ;
                else v.push_back(mul/nums[i]) ;
            }
            
        }
        return v ; 
    }
};
