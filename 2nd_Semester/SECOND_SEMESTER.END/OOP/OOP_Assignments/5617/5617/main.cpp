#include<iostream>
#include <unistd.h>
using namespace std;

void gotoxy(int x, int y)
{
    crood c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(std_OUTPUT_HANDLE), c);
}

int main()
{
    int x = 20;
    gotoxy(x, x / 2);
    cout << "ABCDEF" << endl;
    
    gotoxy(20, 5);
    cout << "Hello World !!!" << endl;

    gotoxy(23, 5);
    cout << "*****" << endl;

    system("pause");
    return 0;
}
