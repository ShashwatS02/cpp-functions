#include <bits/stdc++.h>
using namespace std;

int main() {

    //prefix code
    int arr[] = {6,4,5,-3,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> suffix(n);
    suffix[0] = arr[0];
    for(int i = 1; i < n; i++) {
       suffix[i] = suffix[i - 1] + arr[i]; 
    }
    
    for (int i = 0; i < n; i++) {
        cout << suffix[i] << " ";
    }

    // suffix code
    // int arr[] = {6,4,5,-3,2,8};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // vector<int> suffix(n);
    // suffix[n - 1] = arr[n - 1];
    // for(int i = n-2; i >= 0; i--) {
    //    suffix[i] = suffix[i + 1] + arr[i]; 
    // }
    
    // for (int i = 0; i < n; i++) {
    //     cout << suffix[i] << " ";
    // }

    return 0;
}