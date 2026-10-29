class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        string s1 = "0000000000" , s2 = "0000000000";
        bool ans = 1 ; 
        for(int i=0 ; i<9 ; i++)
        {
            s1= "0000000000" ;
            s2= "0000000000" ;
            for(int j=0 ; j<9 ; j++)
            {
                char num = board[i][j] ;
                char num2 = board[j][i] ;
                if(num >='1' && num <= '9')
                {
                    int index = num-'0' ;
                    if(s1[index] == '1') ans = false ;
                    else s1[index]='1' ;
                }
                if(num2 >='1' && num2 <= '9')
                {
                    int index = num2-'0' ;
                    if(s2[index] == '1') ans = false ;
                    else s2[index]='1' ;
                }
            }
        }
        if(!ans) return ans ;
        int row = 0 , col=0 ; 
        while(row < 9 && col < 9)
        {
            string sq = "0000000000" ;
            for(int i=row ; i<row+3 ; i++)
            {
                for(int j=col ; j<col+3 ; j++)
                {
                    char num = board[i][j] ;
                    if(num >='1' && num <= '9')
                    {
                        int index = num-'0' ;
                        if(sq[index] == '1') ans = false ;
                        else sq[index]='1' ;
                    }
                }
            }
            cout<<row<<" "<<col<<endl ;
            col+=3 ; 
            if(col == 9)
            {
                row +=3 ;
                col = 0 ; 
            }
            if(row == 9) break ; 
        
        }
        return ans ; 
    
    }
};
