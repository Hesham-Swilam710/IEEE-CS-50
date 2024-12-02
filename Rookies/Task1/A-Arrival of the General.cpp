 //// A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s;// size of array
    cin>>s;
    int *arr=new int[s];
    int maxIndex=0,minIndex=0;
    for(int i=0;i<s;i++){
        cin>>arr[i];
        if(arr[i]>arr[maxIndex])
            maxIndex=i;
            if(arr[i]<=arr[minIndex]) // So I can take the closest minimum value to the end of the array.
                minIndex=i;
    }
    // i full array and i know the palces of max index and min index
             // i will write to loops one for max and another for mini
             int sum=0;
             if(maxIndex> minIndex)
                minIndex++;// to ensure the min index is the closest minimum value to the end of the array.
             // loop for max
             // to set max value in right place
             for(int i=maxIndex;i>0;i--){
                    swap(arr[i],arr[i-1]);
                 sum++;
             }
             // for set min index min value place
              for(int i=minIndex;i<s-1;i++){
                    swap(arr[i],arr[i+1]);
                     sum++;
             }
             cout<<sum<<endl;

    return 0;
}
