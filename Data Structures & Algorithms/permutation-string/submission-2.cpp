class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // cals s1 freq char 26 
         int m = s2.size() ;
        vector<int>ch1(26 , 0) ;
        vector<vector<int>>ch2(26 , vector<int>(s2.size() , 0)) ;
        for(int i=0 ; i<s1.size() ; i++) ch1[s1[i]-'a']++ ;
        for(int i=0 ; i<s2.size() ; i++) ch2[s2[i]-'a'][i]++ ;
        for(int i=0 ; i<26 ; i++)
            for(int j=1 ; j<s2.size() ; j++)
                ch2[i][j] += ch2[i][j-1] ;
        
        bool ans = 0 ;
        for(int i=0 ; i<s2.size() ; i++)
        {
            int l=i , r=i+s1.size()-1 ;
            if(r>=s2.size()) break ;
            bool ok = true ; 
            for(int j=0 ; j<26 ; j++)
            {
                int s2ch = ch2[j][r] ;
                if(l-1 >= 0) s2ch-= ch2[j][l-1] ;
                if(s2ch != ch1[j]) ok = false ;
            }
            ans|=ok ; 
        }
        return ans ; 
    }
};
