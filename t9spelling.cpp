#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <utility>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)

pair<int,int> find_index(string str[],int len,char ch){
  pair <int ,int> retval;
  bool finished = false;
  FOR(i,0,len){
    if(finished) break;
    FOR(j,0,str[i].length()){
      if(finished) break;
      if(str[i][j] == ch){
	retval = make_pair(i,j);
	finished = true;
      }
    }
  }
  return retval;
}


string decodePad(string str,int len){
  string output;
  pair<int,int> pos;
  ostringstream stm;
  string padStruct[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  int prev_index = -1,curr_index;
  FOR(i,0,len){
    pos = find_index(padStruct,10,str[i]);
    if(pos.first == prev_index){
      output += ' ';
    }
    FOR(j,0,pos.second+1){
      stm<<pos.first;
      output += stm.str();
      stm.str("");
    }
    prev_index = pos.first;
  }
  return  output;
}

int main(){
  int tt;
  string str;
  cin>>tt;
  cin.ignore();
  FOR(tcase,1,tt+1){
    getline(cin,str);
    cout<<"Case #"<<tcase<<": "<<decodePad(str,str.length())<<endl;
  }


  return 0;
}
