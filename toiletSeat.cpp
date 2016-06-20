#include <iostream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int numRotForUP(string curStruct,int len){
  string tmpStr = curStruct;
  int val = 0;
  char initPos = curStruct[0];
  FOR(i,1,len){
    if (tmpStr[i] != initPos){
      val ++;
      initPos = tmpStr[i];
    }
    if(initPos != 'U'){
      val++;
      initPos = 'U';
    }
  }
  return val;
}
int numRotForDOWN(string curStruct,int len){
  string tmpStr = curStruct;
  int val = 0;
  char initPos = curStruct[0];
  FOR(i,1,len){
    if (tmpStr[i] != initPos){
      val ++;
      initPos = tmpStr[i];
    }
    if(initPos != 'D'){
      val++;
      initPos = 'D';
    }
  }
  return val;
}
int numRotForLIKE(string curStruct,int len){
  string tmpStr = curStruct;
  int val = 0;
  char initPos = curStruct[0];
  FOR(i,1,len){
    if (tmpStr[i] != initPos){
      val ++;
      initPos = tmpStr[i];
    }
  }
  return val;
}


int main(){
  string toiletCh;
  cin>>toiletCh;
  cout<<numRotForUP(toiletCh,toiletCh.length())<<endl;
  cout<<numRotForDOWN(toiletCh,toiletCh.length())<<endl;
  cout<<numRotForLIKE(toiletCh,toiletCh.length())<<endl;

  return 0;
}
