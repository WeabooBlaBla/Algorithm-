#include "iostream"
using namespace std;

void nQueen(int **a, int column);

int main() {

  int **a;
  int n=4;
  a = new int*(nothrow)[n];
  for(int i=0;i<n;i++)
  {
    a[i]=new int(nothrow)[n];
  }
  return 0;
}

bool nQueen(int **board, int column, int boardSize)
{
  if(column >= boardSize) return true; //s
  else
  {

  }
}

bool isSafe(int **board, int currentRow, int currentColumn, int boardSize)
{
  int queenColumn = 0, queenRow = 0;
  for(queenColumn = 0; queenColumn < currentColumn; queenColumn++)
  {
    queenRow = findColumnQueen(board, queenColumn, boardSize);
    if(currentRow == queenRow ) return false;
    for(int queenRange = 1; (queenColumn + queenRange) <= currentColumn; queenColumn++)
    {
      //Queen attack range
      bool aboveDiag = currentRow==(queenRow - queenRange) && currentColumn==(queenColumn+queenRange);
      bool belowDiag = currentRow==(queenRow + queenRange) && currentColumn==(queenColumn+queenRange);

      if(queenRow == 0)
      {
        if((queenColumn + queenRange) >= boardSize) // column out of the edge of the board
          return true;

        else if(belowDiag)
          return false;
      }

      else if(queenRow == boardSize -1)
      {
        if((queenColumn + queenRange) >= boardSize) // column out of the edge of the board
          return true;

        else if(aboveDiag)
          return false;
      }

      else
      {
        if((queenColumn + queenRange) >= boardSize){// column out of the edge of the board
          return true;
        }
        else if((queenRow-queenRange)<0){//row out of the edge of the board
          if(belowDiag)
            return false;
        }
        else{
          if(belowDiag || aboveDiag) return false;
        }
      }

    }
    
    return true;
  }
}

int findColumnQueen(int **board, int currentColumn, int boardSize)
{
  for(int currentRow=0; currentRow< boardSize; currentRow++)
  {
    if(board[currentRow][currentColumn]==1) return currentRow;
  }
  return -1;
}
