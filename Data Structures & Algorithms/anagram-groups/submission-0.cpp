class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> v ; 
        for(int i=0 ; i<strs.size() ; i++)
        {
            string s = strs[i] ;
            sort(s.begin(), s.end()) ; 
            v.push_back({s , strs[i]}) ;
        }
        sort(v.begin(), v.end()) ;
        vector<vector<string>> ans ; 
        vector<string> tmp ; 
        tmp.push_back(v[0].second) ;
        for(int i=1 ; i<v.size() ; i++)
        {
            if(v[i].first == v[i-1].first) 
            {
                tmp.push_back(v[i].second) ; 
                continue ; 
            }
            ans.push_back(tmp) ;
            tmp.clear() ;
            tmp.push_back(v[i].second) ;
        }
        if(tmp.size()!=0) ans.push_back(tmp) ;
        return ans ; 
    }
};
