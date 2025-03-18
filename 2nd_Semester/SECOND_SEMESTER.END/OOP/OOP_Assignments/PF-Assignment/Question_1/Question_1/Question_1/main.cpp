#include<iostream>
//#include<Windows.h>
#include <cstdlib>
using namespace std;

void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


int main()
{
    char chr;
    cout << "Enter char to print: ";
    cin >> chr;

    int time = 0;

    do
    {
        cout << "Enter total time: ";
        cin >> time;

    } while (time <= 0);

    int rows = 0;
    do
    {
        cout << "Enter number of rows: ";
        cin >> rows;
    } while (rows < 5);
    

    
    int pre_row = 0, pre_col = 2, new_row = 0, new_col = 22;

    int last_moved_row = 0;
    for (int l = 1; l <= rows; l++)
    {
        new_row = 0, new_col = 22;
        int temp_pre_col = pre_col;
        if (time >= rows)
        {
            Sleep(1000 * (time / rows));
        }
        else
        {
            Sleep(1000 / rows);
        }
        Sleep(1000);
        last_moved_row++;
        system("cls");

        int inner_start = (rows * 2) - 1;
        for (int i = 1; i <= rows; i++)
        {

            if (i <= last_moved_row)
            {
                gotoxy(new_row, new_col);
                new_col--;
            }
            else
            {
                gotoxy(pre_row, pre_col);
                pre_col++;
            }

            for (int j = 1; j <= i; j++)
            {
                cout << " ";
            }

            for (int j = inner_start; j >= 1; j--)
            {
                cout << chr;
            }
            inner_start -= 2;
            cout << endl;
        }
        temp_pre_col++;
        pre_col = temp_pre_col;
    }

    gotoxy(0, 25);
}
