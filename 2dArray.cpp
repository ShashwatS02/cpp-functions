#include <bits/stdc++.h>
using namespace std;

void printcol(int arr[][4], int row, int col) {
    for (int j = 0; j <col; j++) {
        for (int i = 0; i < row; i++) {
            cout << arr[i][j] << " ";
        }
    }
}

void printrowmax(int arr[][4], int row, int col) {
    int index = -1, sum = INT_MIN;

    for (int i = 0; i < row; i++){
        int total = 0;
        for (int j = 0; j < col; j++) {
            total += arr[i][j];
        }
        if (total > sum) {
            sum = total;
            index = i;
        }
    }
    cout << index;
}

void printsumdiag(int matrix[][3], int row, int col) {
    int first = 0;
    int sec = 0;

    //first diagonal sum 
    int i = 0;
    while (i < row) {
        first += matrix[i][i];
        i++;
    }

    //second diagonal
    i = 0;
    int j = col - 1;
    while (j >= 0) {
        sec+=matrix[i][j];
        j--;
        i++; 
    }
    cout << first << " " << sec << " ";
}

void printreverseRow(int matrix[][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        int start = 0, end = col - 1;
        while (start < end) {
            swap (matrix[i][start], matrix[i][end]);
            start++;
            end--;
        }
    }

    for (int j = 0; j <row; j++) {
        for (int i = 0; i < col; i++) {
            cout << matrix[j][i] << " ";
        }
    }
}

int main() {

    //create 2d array
    int arr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr2[3][4] = {0,1,3,4,6,7,10,11,41,18,9,11};
    int ans[3][4];

    // //Print all the value in array row wise
    // for (int row = 0; row < 3; row++) {
    //     for (int col = 0; col < 4; col++) {
    //         cout << arr[row][col] << " ";
    //     }
    // }

    // //print all the values in array col wise, function call
    // printcol(arr,3,4);

    //Find an element in our array
    // int x = 17;

    // for (int row = 0; row < 3; row++) {
    //     for (int col = 0; col < 4; col++) {
    //         if (arr[row][col] == x) {
    //             cout << "Yes";
    //             return 0;
    //         }
    //     }
    // }
    // cout << "No";

    //Add 2 matrix
    // for (int row = 0; row<3; row++) {
    //     for (int col = 0; col < 4; col++) {
    //         ans[row][col] = arr1[row][col]+arr2[row][col];
    //     }
    // }

    // for (int row = 0; row<3; row++) {
    //     for (int col = 0; col < 4; col++) {
    //         cout << ans[row][col] << " ";
    //     }
    // }

    //Print row index with maximum sum
    // printrowmax(arr1, 3, 4);

    //Print diagonal sum
    int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    // printsumdiag(matrix, 3, 3);
    printreverseRow(matrix, 3, 3);

    return 0;
}