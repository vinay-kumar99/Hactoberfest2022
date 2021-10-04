#include <iostream>
using namespace std;

class N_Queens
{
    public:

    int n, board[8][8];


    bool underAttack(int i,int j)
    {
        
        for(int k = 0 ; k < n; k++)
            if(board[i][k] == 1 || board[k][j] == 1)
                return true;

        for(int k = 0 ; k < n ; k++)
            for(int l = 0 ; l < n ; l++)
                if( (k + l) == (i + j) || (k - l) == (i - j) )
                    if(board[k][l] == 1)
                        return true;
        return false; 
    }


    bool queenPos(int n1)
    {
        if(n1 == 0)
        return true;

        for(int i = 0 ; i < n ; i++)
            for(int j = 0; j < n ; j++)
                if(!underAttack(i,j) && board[i][j] != 1)
                {
                    board[i][j]=1;

                    if(queenPos(n1-1))
                        return true;           
                    
                    board[i][j]=0;
                }
       
        return false;
    }
};


int main()
{   
    N_Queens q;

    cout << "Enter the value of n for nxn chessboard : ";
    cin >> q.n;
    
    for(int i = 0 ; i < q.n ; i++)
    {
       for(int j = 0 ; j < q.n ; j++)
       {
           q.board[i][j] = 0;
       }
            
    }
        
   
    q.queenPos(q.n);

    cout << endl << "Chessboard : " << endl;
   
    for(int i = 0 ; i < q.n ; i++)
    {
        for(int j = 0; j< q.n ; j++)
        {
            cout << q.board[i][j] << " "; 
        }

        cout << endl;
    }

    return 0;
}

