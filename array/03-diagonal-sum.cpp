#include <iostream>
using namespace std;


// diagonal sum calculation

void diagonalSum(int arr[][4], int n){
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i][i];
        if(i != n - i -1){
            sum += arr[i][n-i-1];
        }
    }

    cout << "Sum:" << sum << endl;
}

void searchKey(int arr[][4], int n, int m, int key){
    int srow=0, scol=0;
    int erow = n-1, ecol = m-1; 
    for(int i = srow; i <= erow; i++){
        for(int j = scol; j <= ecol; j++){
            if(key == arr[i][j]){
                cout << i << "," << j << ";";
            }else{
                break;
            }
        }

    }
    cout << endl;
}

int main() {
    int arr[4][4] = {{1, 2, 3, 4}, 
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}, 
                     {13, 14, 15, 16}};
    int arr2[4][4] = {{10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};

    // diagonalSum(arr, 4);
    searchKey(arr2, 4, 4, 10);

    return 0;
}