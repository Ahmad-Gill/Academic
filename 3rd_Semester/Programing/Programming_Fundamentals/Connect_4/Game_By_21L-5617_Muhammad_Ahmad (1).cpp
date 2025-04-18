#include <iostream>
#include <string>
#include<fstream>
using namespace std;

char playerXorO; 
char Board[6][7];
int columnNumber; 
int Count[8] = { 5, 5, 5, 5, 5, 5, 5, 5};
bool columnFull = true;
char XorO[2] = { 'X', 'O' };

void board_Create() 
{
	for (int j = 0; j <= 5; j++){
		 for (int i = 0; i <= 6; i++)
			Board [j][i] = '.';
	}
}
void column_Select()
{
	for (int i = 1; i <= 7; i++) {	
	if (columnNumber == i)
	{
	if (isalpha(columnNumber))
	columnFull = true;
	if (Count[i] == -1)
	{
	cout << "Please select valid column number" << endl;
	columnFull = true;
	}
	if (columnFull == false)
	{
	Board[Count[i]][i - 1] = playerXorO;
	Count[i]--;
}
}
}
}

void columnPrint()
{
	if (columnFull == false) {				
	for (int j = 0; j <= 5; j++)
	{
	cout << " " << endl;
	for (int i = 0; i <= 6; i++)
	cout << " " << Board[j][i];
	cout << " " << endl;
	}
	cout << " " << endl;
}
}
void Game_Is_On(){

string String;
string name1, name2, name; 
int turn = 0;
bool winFlag1 = false;
int winFlagCount = 0, winFlagCount1 = 0, winFlagCount2 = 0, winFlagCount3 = 0;
bool gameLoop = true;
cout << "Welcome to connect 4!" << endl;
while (gameLoop == true) {
cout << "Would you like to start the game " "Yes or NO" << endl; 
cin >> String;
if (String == "yes" || String == "YES")
{
gameLoop = false;
board_Create();
cout << " player 1's name is " << endl; 
cin >> name1;
cout << " player 2's name is" << endl;
cin >> name2;
cout << name1 << " won the toss and selcet to play first" << endl;
 while (turn < 42 && winFlag1 == false)	
{
 winFlagCount = 0;
 winFlagCount1 = 0;
 winFlagCount2 = 0;
 winFlagCount3 = 0;
 columnFull = false;
 if (turn % 2 == 0) 
{
 name = name1;
 cout << name1 << " Enter your Favourite  Column Number " << endl;
 playerXorO = 'X';
}
else
{
name = name2;
cout << name2 << "  enter your favoutite column Number" << endl;
playerXorO = 'O';
}
cin >> columnNumber;
if (columnNumber <= 0 || columnNumber >= 8)
{
columnFull = true;
cout << " please be serious !!!! Select the valid column Number " << endl;
}
column_Select();
columnPrint();
	if (columnFull == false)
	turn++;
	for (int j = 0; j < 4; ++j)
	{
	for (int i = 5; i > 2; --i)
{
	if (Board[j][i] == playerXorO)
{
	winFlagCount++;
	if (Board[j + 1][i - 1] == playerXorO)
{
	winFlagCount++;
	if (Board[j + 2][i - 2] == playerXorO)
{
	winFlagCount++;
	if (Board[j + 3][i - 3] == playerXorO)
{
	winFlagCount++;
	if (winFlagCount == 4) {
	cout << name << " wins congratulations!" << endl;
	winFlag1 = true;
	break;
}
}
}
}
}
}
}
	for (int j = 0; j < 4; ++j)
{
	for (int i = 5; i > 2; --i)
{
	if (Board[j][i - 3] == playerXorO)
{
	winFlagCount1++;
	if (Board[j + 1][i - 2] == playerXorO)
{
	winFlagCount1++;
	if (Board[j + 2][i - 1] == playerXorO)
{
	winFlagCount1++;
	if (Board[j + 3][i] == playerXorO)
{
	winFlagCount1++;
	if (winFlagCount1 == 4) {
	cout << name << " wins congratulations!" << endl;
	winFlag1 = true;
	break;
}
}
}
}
}
}
}
	for (int numColumn = 0; numColumn < 7; ++numColumn)
{
	for (int check = 5; check > 2; --check)
{
	if (Board[numColumn][check] == playerXorO)
{
	winFlagCount2++;
	if (Board[numColumn][check - 1] == playerXorO)
{
	winFlagCount2++;
	if (Board[numColumn][check - 2] == playerXorO)
{
	winFlagCount2++;
	if (Board[numColumn][check - 3] == playerXorO)
{
	winFlagCount2++;
	if (winFlagCount2 == 4) {
	cout << name << " wins congratulations!" << endl;
	winFlag1 = true;
	break;
}
}
}
}
}
}
}
	for (int numRow = 0; numRow < 6; ++numRow)
{
	for (int check1 = 6; check1 > 2; --check1)
{
	if (Board[check1][numRow] == playerXorO)
{
	winFlagCount3++;
	if (Board[check1 - 1][numRow] == playerXorO)
{
	winFlagCount3++;
	if (Board[check1 - 2][numRow] == playerXorO)
{
	winFlagCount3++;
	if (Board[check1 - 3][numRow] == playerXorO)
{
	winFlagCount3++;
	if (winFlagCount3 == 4) {
	cout << name << " wins congratulations!" << endl;
	winFlag1 = true;
	break;
}
}
}
}
}
}
}
	if (winFlag1 == true)
	turn = 45;
	if (turn == 42)
{
	cout << "The game has ended in a draw!" << endl;
	turn = 45;
}
}
}
}
}
void Load_Game(){
	 ifstream FIN;
	 FIN.open("E:/New_folder");
	 FIN.close();
	 
}
 void SaveGame() {
      
      
    ofstream FOUT; 
    FOUT.open("E:/New_folder");
     FOUT << Game_Is_On;
    FOUT.close();
}
int Menu(){
    int Choice;
    do{
        cout<<"1. Play"<<endl
            <<"2. Save Game"<<endl
            <<"3. Load Game"<<endl
            <<"4. Exit"<<endl
            <<"Enter You Choice (1 - 4)";
            cin>> Choice;
    }while(Choice < 1 || Choice > 4);
    return Choice;
}

 
int main()
{
	string FileName;
    int Choice ;
  
    do{
        Choice = Menu();
        switch(Choice)
        {
        case 1:
           
            Game_Is_On();
            break;
        case 2:
             cout<<"enter file name";
             cin>>FileName;
				SaveGame();
            break;

        case 3:
        	cout<<"enter file location";
        	cin>>FileName;
			Load_Game();
            break;
        }

    }while(Choice != 4);
    return 0;
}