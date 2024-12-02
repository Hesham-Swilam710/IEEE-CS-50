//// E
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char theNextRight(char x){
     char next='0';
     switch(x){
        case 'q': next='w';
        break;
         case 'w': next='e';
        break;
         case 'e': next='r';
        break;
         case 'r': next='t';
        break;
         case 't': next='y';
        break;
         case 'y': next='u';
        break;
         case 'u': next='i';
        break;
         case 'i': next='o';
        break;
         case 'o': next='p';
        break;
        ///
          case 'a': next='s';
        break;
         case 's': next='d';
        break;
         case 'd': next='f';
        break;
         case 'f': next='g';
        break;
         case 'g': next='h';
        break;
         case 'h': next='j';
        break;
         case 'j': next='k';
        break;
         case 'k': next='l';
        break;
         case 'l': next=';';
        break;
        /////
          case 'z': next='x';
        break;
         case 'x': next='c';
        break;
         case 'c': next='v';
        break;
         case 'v': next='b';
        break;
         case 'b': next='n';
        break;
         case 'n': next='m';
        break;
         case 'm': next=',';
        break;
         case ',': next='.';
        break;
         case '.': next='/';
        break;

     }


 return next;
}
char thePervLeft(char x){
     char prev='0';
     switch(x){
         case 'w': prev='q';
        break;
         case 'e': prev='w';
        break;
         case 'r': prev='e';
        break;
         case 't': prev='r';
        break;
         case 'y': prev='t';
        break;
         case 'u': prev='y';
        break;
         case 'i': prev='u';
        break;
         case 'o': prev='i';
        break;
         case 'p': prev='o';
        break;
        ///

         case 's': prev='a';
        break;
         case 'd': prev='s';
        break;
         case 'f': prev='d';
        break;
         case 'g': prev='f';
        break;
         case 'h': prev='g';
        break;
         case 'j': prev='h';
        break;
         case 'k': prev='j';
        break;
         case 'l': prev='k';
        break;
        case ';': prev='l';
        break;
        /////

         case 'x': prev='z';
        break;
         case 'c': prev='x';
        break;
         case 'v': prev='c';
        break;
         case 'b': prev='v';
        break;
         case 'n': prev='b';
        break;
         case 'm': prev='n';
        break;
        case ',': prev='m';
        break;
         case '.': prev=',';
        break;
         case '/': prev='.';
        break;

     }


 return prev;
}
int main()
{
  char dir;
  string sentance,original;
  cin>>dir;
  cin>>sentance;
  original=sentance;
  if(dir=='L'||dir=='l'){
     for(int i=0;i<sentance.length();i++){
         original[i]=theNextRight(sentance[i]);
     }

  }
   if(dir=='R'||dir=='r'){
     for(int i=0;i<sentance.length();i++){
         original[i]=thePervLeft(sentance[i]);
     }
   }
          cout<<original<<endl;

    return 0;
}



