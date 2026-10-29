class Solution {
public:
    bool alpha(char c)
    {
        if (c<='z' && c>='a') return 1 ; 
        if(c<='Z' && c>='A') return 1  ;
        if(c<='9' && c>='0') return 1 ;
        return 0 ;
    }
    bool isPalindrome(string s) {
        string ss = "" ;
        for(int i=0 ; i<s.size() ; i++) 
        {
            if(alpha(s[i]))
                ss += tolower(s[i]) ;
        }
        string t = ss ;
        reverse(t.begin() , t.end()) ;
        cout<<ss<<"\n"<<t<<endl ;
        if(ss==t) return true ; 
        return false ;
    }
};
