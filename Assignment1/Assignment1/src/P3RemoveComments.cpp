/*
 * File: P3RemoveComments.cpp
 */
// Name: Zhouliang Yu
// Student ID:120040077
#include <iostream>
#include "console.h"
#include "filelib.h"     // promptUserForFile
#include "P3RemoveComments.h"
using namespace std;

/* Function definition */

void removeComments(istream & is, ostream & os) {
   // TODO
    int ch1;//ch1 is used to traverse the file
    int ch2;//the next char of ch1
    while((ch1=is.get())!=EOF){
        //if ((ch2=is.get())==EOF){//the next char goes to the end
          //  break;
        //}
        ch2=is.get();

        is.unget();//goes back to the former char
        if((ch1=='/')&&(ch2=='/')){// "//"case
            while(true){
                ch1=is.get();
                if (ch1==EOF||ch1=='\n'){//the file goes to the end or
                    break;               //goes to the nextline
                }
            }
        }
        else if((ch1=='/')&&(ch2=='*')){// "/*"case
            while(true){
                ch1=is.get();
                ch2=is.get();
                is.unget();
                if ((ch1=='*')&&(ch2=='/')){
                    is.get();
                    break;
                }
                if(ch1==EOF){
                    break;
                }
            }
        }
        else{
            os.put(ch1);
        }
    }
}

/* Function definition */

int P3RemoveComments() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   removeComments(infile, cout);
   infile.close();
   return 0;
}
/*int main() {
   ifstream infile;
   promptUserForFile(infile, "Input file: ");
   removeComments(infile, cout);
   infile.close();
   return 0;
}*/
