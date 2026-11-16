#include <iostream>
using namespace std;
// Topic: 2D Arrays

// 2D array initialized

int main() {
    int arr[3][4];
    int n = 3, m = 4;

    // outer loop run row wise
    for(int i = 0; i < n; i++){
        // inner loop run column wise
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    // outer loop run row wise
    for(int i = 0; i < n; i++){
        // inner loop run column wise
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
 
    
    return 0;
}