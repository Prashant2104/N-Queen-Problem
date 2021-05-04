#include<iostream>

using namespace std;
int grid[15][15];

void print(int n) 
{
    for (int i = 0;i <= n - 1; i++) 
    {
        for (int j = 0;j <= n - 1; j++) 
        {
            cout << grid[i][j] <<" ";
        }
        cout <<"\n";
    }
    cout << "\n\n";
}

bool isSafe(int col, int row, int n) 
{
    //check for same column
    for (int i = 0; i < row; i++) 
    {
        if (grid[i][col]) 
        {
            return false;
        }
    }
    //check for left diagonal
    for (int i = row, j = col;i >= 0 && j >= 0; i--, j--) 
    {
        if (grid[i][j]) 
        {
            return false;
        }
    }
    //check for right diagonal
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) 
    {
        if (grid[i][j]) 
        {
            return false;
        }
    }
    return true;
}

bool solve(int n, int row) 
{
    if (n == row) 
    {
        print(n);
        return true;
    }

    bool res = false;
    for (int i = 0; i <= n - 1; i++) 
    {
        if (isSafe(i, row, n)) 
        {
            grid[row][i] = 1;
            res = solve(n, row + 1) || res;
            grid[row][i] = 0;
        }
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the number of queen \n";
    cin >> n;
    cout << "\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            grid[i][j] = 0;
        }
    }
    bool result = solve(n, 0);
    if (result == false) 
    {
        cout <<"No solution\n" ;
    }
    else 
    {
        cout <<"\n";
    }
    return 0;
}