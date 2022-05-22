#include<iostream>
using namespace std;

// void rotateMatrix(int row, int column, int** matrix)   {
//     for(int j=0; j<column; j++)    {
//         for(int i=row-1; i>=0; i--) {
//             cout<<*((matrix+i*column) + j)<<" ";
//         }
//         cout<<endl;
//     }
// }

int main()  {
    int row, column;
    cout<<"Enter number of rows and columns in a matrix: "<<endl;
    cin>>row>>column;
    cout<<"Enter matrix: "<<endl;
    int matrix[row][column];

    for(int i=0; i<row; i++)    {
        for(int j=0; j<column; j++) {
            cin>>matrix[i][j];
        }
    }

    for(int i=0; i<row; i++)    {
        for(int j=0; j<column; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    // rotateMatrix(row, column, (int **)matrix);
    // cout<<endl;

    for(int j=0; j<column; j++)    {
        for(int i=row-1; i>=0; i--) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}