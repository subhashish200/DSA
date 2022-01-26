/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

/******************************* N Queen Problem *********************************************/

/// global array..
int board[11][11];
bool isPossible(int n,int row,int column){
    
    // same column
    /// checking the same column whether queen is present at upper portion..
    for(int i=row-1;i>=0;i--){
       if(board[i][column]==1){
           return false;
       } 
    }
    
    // Upper left Diagonal..
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 1){
            return false;
        }
    }
    
    // Upper Right Diagonal..
    for(int i=row-1,j=column+1;i>=0 && j<n ; i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n,int row){ // create to place queen row wise..
    if(row==n){
        // We have reached some solution..
        // Print the board matrix..
        // return 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
        
        
    }
    
    // place at all possible position..and move to smaller problem..
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j] = 1;
            nQueenHelper(n,row+1);
            board[row][j] = 0;
        }
    }
    return ;
    
}
void placeNQueens(int n){
    
    memset(board,0,11*11*sizeof(int));
    
    nQueenHelper(n,0);
    
    
}
int main()
{
    //printf("Hello World");
    int n;
    cin>>n;
    placeNQueens(n);

    return 0;
}
