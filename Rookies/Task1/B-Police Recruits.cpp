//// B
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s; // size of array
    cin>>s;
    int value;
    int numsOfHired=0,numOfCrime=0;
     for(int i=0;i<s;i++){
           cin>> value;
               if(value<0){//-1
                     if(numsOfHired>0)
                     numsOfHired--;
                     else
                        numOfCrime++;

               }
               else{
                numsOfHired+=value;
               }

     }
     cout<<numOfCrime<<endl;
    return 0;
}


