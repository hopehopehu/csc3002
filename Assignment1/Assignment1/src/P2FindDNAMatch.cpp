/*
 * File: P2FindDNAMatch.cpp
 */

#include <iostream>
#include <string>
#include "P2FindDNAMatch.h"
#include"console.h"
using namespace std;


/* Function definition */

int findDNAMatch(string s1, string s2, int start) {//find the first place to match
   // TODO
    //default to start from the very first char
    int matchingpos; // find the place to match
    s1=matchingStrand(s1);
    matchingpos=s2.find(s1,start);
    return matchingpos;
}

/* Function definition */

string matchingStrand(string strand) {//convert the strand into the matching strand
   // TODO
    int strandlength=strand.length();
for(int i=0;i<strandlength;i++){
    switch(strand[i]){
        case'A':
               strand[i]='T';
               break;
        case'T':
               strand[i]='A';
               break;
        case'G':
               strand[i]='C';
               break;
        case'C':
               strand[i]='G';
               break;
    }
}
        return strand;
}

/* Function definition */

void findAllMatches(string s1, string s2) {
   // TODO
   int otherpos;//to find other positions
switch(findDNAMatch(s1, s2)){
case -1://when nowhere to connect
        cout<<"there is no match"<<endl;
        break;
default:
    cout<<"the first matching position is "<<findDNAMatch(s1,s2)<<endl;
     otherpos=findDNAMatch(s1, s2)+1;
    while((findDNAMatch(s1, s2, otherpos))!=-1){
        cout<<"and another position is:"<<findDNAMatch(s1, s2, otherpos)<<endl;
        otherpos=findDNAMatch(s1, s2, otherpos)+1;
        break;
    }
}
}



/* Function definition */

int P2FindDNAMatch() {
   findAllMatches("TTGCC", "TAACGGTACGTC");
   findAllMatches("TGC", "TAACGGTACGTC");
   findAllMatches("CCC", "TAACGGTACGTC");
   return 0;
}

