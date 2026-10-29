class Solution {
public:
    int str2int(string s)
    {
        int num=0 ; 
        for(int i=0 ; i<s.size() ; i++)
        {
            int digit = s[i]-'0' ;
            num*=10 ; 
            num+=digit ;
        }
        return num ; 
    }
    string int2str(int x)
    {
        string str="" ;
        if(x == 0)
        {
            str = "0" ; 
        }
        while(x)
        {
            int digit = x%10 ; 
            str+=(digit+'0') ;
            x/=10 ;
        }
        reverse(str.begin() , str.end()) ;
        return str ; 
    }
    string encode(vector<string>& strs) {
        string s="" ;
        s+=int2str(strs.size()) ;
        for(int i=0 ; i<strs.size() ; i++)
        {
            s+='*' ;
            s+=int2str(strs[i].size()) ;
        } 
        s+='*';

        for(int i=0 ; i<strs.size() ; i++)
        {
            s+=strs[i] ;
        }
        // cout<<s; 
        return s; 

    }
    pair<int , int> getnumber(string & s , int pos)
    {
        int last ;
        string str = "" ;
        for(int i=pos ; i<s.size() ; i++)
        {
            if(s[i] == '*') 
            {
                last = i+1 ; 
                break ;
            }
            str+=s[i] ;
        }
        return {str2int(str) , last} ;
    }
    pair<string , int> getstring(string & s , int pos , int si)
    {
        string str ="" ;
        for(int i=pos ; str.size()<si ; i++)
        {
            str+=s[i] ;
        }

        return {str , pos+si} ;
    }
    vector<string> decode(string s) {
        vector<string>res ;
        vector<int>sizes ; 
        pair<int , int>p = getnumber(s , 0) ;
        int n = p.first ; 
        int pos = p.second ;
        while(n--)
        {
           pair<int , int> element = getnumber(s , pos) ;
           sizes.push_back(element.first) ;
           pos = element.second ; 
        }
        int i=0 ;
        n = p.first ;
        while(n--)
        {
            pair<string , int> element = getstring(s , pos , sizes[i]) ;
            res.push_back(element.first) ;
            pos = element.second ; 
            i++ ;
        }

        for(int i=0 ; i<sizes.size() ; i++) cout<<res[i]<<" " ;

        return res ;
    }
};
