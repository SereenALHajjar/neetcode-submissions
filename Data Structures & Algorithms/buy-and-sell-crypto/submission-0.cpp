class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx[prices.size()] ; 
        mx[prices.size()-1] = prices[prices.size()-1] ;
        for(int i=prices.size()-2 ; i>=0 ; i--) 
        {
            mx[i] = max(prices[i] , mx[i+1]) ;
        }
        int ans = 0 ;
        for(int i=0 ; i<prices.size()-1 ; i++) 
        {
            ans = max(ans , mx[i+1] - prices[i]) ;
        }
        return ans ; 

    }
};
