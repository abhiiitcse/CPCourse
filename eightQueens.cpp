#include <iostream>
using namespace std;
#define BOARD_SIZE 8
#define FOR(i,a,b) for(int i=a;i<b;i++)

bool isOkayPos(int board[BOARD_SIZE][BOARD_SIZE],int row, int col){
  FOR(i,0,BOARD_SIZE){
    if(board[row][i] == 1){
      return false;
    }
  }
  FOR(i,0,BOARD_SIZE){
    if(board[i][col] == 1){
      return false;
    }
  }
  for(int i=row,j=col;i>=0 && j>=0; i--,j--){
    if(board[i][j] == 1){
      return false;
    }
  }
  for(int i=row,j=col;i<BOARD_SIZE && j>=0;i++,j--){
    if(board[i][j] == 1){
      return false;
    }
  }
  return true;
}

bool isValidSolution(int board[BOARD_SIZE][BOARD_SIZE]){
  FOR(i,0,BOARD_SIZE){
    FOR(j,0,BOARD_SIZE){
      if(board[i][j] == 1){
	board[i][j]=0;
	if(!isOkayPos(board,i,j)){
	  //cout<<"Failed at ("<<i<<","<<j<<")."<<endl;
	  return false;
	}
	board[i][j] = 1;
      }
    }
  }
  return true;
}

int main(){
  int numLines=8;
  string inpLine;
  int board[BOARD_SIZE][BOARD_SIZE]; 
  FOR(i,0,BOARD_SIZE){
      getline(cin,inpLine);
      FOR(j,0,inpLine.length()){
	if (inpLine[j] == '*'){
	  board[i][j] = 1;
	}
	else{
	  board[i][j] = 0;
	}
      }
  }
  if (!isValidSolution(board)){
    cout<<"invalid"<<endl;
  }
  else{
    cout<<"valid"<<endl;
  }
  return 0;
}
