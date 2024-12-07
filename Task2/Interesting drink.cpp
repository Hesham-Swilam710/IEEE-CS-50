


//Q01 A
#include <iostream>
#include <algorithm>
using namespace std;
int shopsNum(int arr[], int size, int price) {
    int low = 0, high = size - 1, result = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= price) {
            result = mid + 1;
            low = mid + 1;    
        }
        else {
            high = mid - 1;  
        }
    }
    return result; 
}

int main() {
    int shopNum;
    cin >> shopNum; 
    int* shopNumbers = new int[shopNum]; 

    for (int i = 0; i < shopNum; i++) {
        cin >> shopNumbers[i];
    }

  // sorte the array
    sort(shopNumbers, shopNumbers + shopNum);

    int numDays;
    cin >> numDays;

    while (numDays--) {
        int dayPrice;
        cin >> dayPrice; 
        int shopNums = shopsNum(shopNumbers, shopNum, dayPrice); 
        cout << shopNums << endl;
    }
        return 0;
}
