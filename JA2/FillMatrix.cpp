#include<iostream>

using namespace std;

void fillMatrix(int, int, char[][20], const int, const int, const char, const char);
int main()
{
    int rows, columns;
    cin >> rows;
    cin >> columns;
    char matrix[rows][20];
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            char c;
            cin >> c;
            matrix[i][j] = c;
        }
    }

    char fillChar;
    cin >> fillChar;

    int startRow, startCol;
    cin >> startRow;
    cin >> startCol;

    char startChar = matrix[startRow][startCol];

    fillMatrix(startRow, startCol, matrix, rows, columns, fillChar, startChar);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << matrix[i][j];
        }

        cout << endl;
    }

    return 0;
}

void fillMatrix(int row, int col, char matrix[][20], int rows, int columns, char fillChar, char startChar)
{
    matrix[row][col] = fillChar;
    if (matrix[row + 1][col] == startChar && row+1 < rows){
        fillMatrix(row + 1, col, matrix, rows, columns, fillChar, startChar);
    }

    if (matrix[row - 1][col] == startChar && row-1 >= 0){
        fillMatrix(row - 1, col, matrix, rows, columns, fillChar, startChar);
    }

    if (matrix[row][col + 1] == startChar && col+1 < columns){
        fillMatrix(row, col + 1, matrix, rows, columns, fillChar, startChar);
    }

    if (matrix[row][col-1] == startChar && col-1 >= 0){
        fillMatrix(row, col - 1, matrix, rows, columns, fillChar, startChar);
    }
}
