/*
 * File: P4BanishLetters.cpp
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "filelib.h"
#include "simpio.h"
#include "strlib.h"
#include "P4BanishLetters.h"
using namespace std;


/* Function definition */



int P4BanishLetters() {//act as main()
   // TODO
  string banish="";
  string str;
  string path;
  ifstream infile;
  promptUserForFile(infile,"Inputfile:");
  cout<<"Outputfilepath:";
  cin>>path;
  ofstream outfile( path,ios::app);//输入路径
  string filename;
  cout<<"Letters to banish：";
  cin>>banish;
  cin.get();//吸收'\n'
  while(getline(infile,str)){
      cout<<str<<endl;
  }

      for(int i=0;i<banish.length();i++){
          for(int j=0;j<str.length();j++){
              if (tolower(banish[i])==tolower(str[j])){
                  str[j]='0';
              }
          }
      }
      cout<<str<<endl;
      infile.close();
  for(int i=0;i<str.length();i++){
      if(str[i]!='0'){
          cout<<str[i];
          outfile.put(str[i]);
      }
  }
  outfile.close();
  return 0;
}

