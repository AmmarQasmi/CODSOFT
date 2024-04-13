#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print(string arr[][3])
{
    cout << "\n-------------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(string arr[][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != " | ")
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[0][j] != " | ")
            return true;
    }

    // Check diagonals
    if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != " | ") ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != " | "))
        return true;

    return false;
}

bool checkDraw(string arr[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == " | ")
                return false;
        }
    }
    return true;
}

int main()
{
    string board[3][3] = {{" | ", " | ", " | "}, {" | ", " | ", " | "}, {" | ", " | ", " | "}};
    int count = 0;
nn 
    string ans;
    cout << "Play a match ? ";
    cin >> ans;
    while (count < 9)
    {
        int x, y;
        string fill;        //each player gets equal and alternate turns
        if (count % 2 == 0)
        {
            fill = "X";
        }
        else
        {
            fill = "O";
        }
        print(board);
        cout << "Enter your move player " << fill << ": ";
        cin >> x >> y;
        board[x][y] = fill;
        count++;

        if (checkWin(board))
        {
            cout << "Congrats!!! Player " << fill << " has won the match" << endl;
            print(board);
            break;
        }
        else if (checkDraw(board))
        {
            cout << "The game is a draw!" << endl;
            print(board);
            break;
        }
    }

    return 0;
}
