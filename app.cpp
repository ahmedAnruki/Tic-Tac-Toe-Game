#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char GameOrdar[9];
char ResetGameOrdar[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int winPlayer = 0, winComputer = 0, Equal = 0;

void ResetGame()
{
    for (int i = 0; i < 9; i++)
        GameOrdar[i] = ResetGameOrdar[i];
    
    system("cls");
    system("color 3F");
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void PrintOrderGame()
{
    system("cls");
    cout << "\n\tTIC-TAC-TOE\n\n";
    cout << "   " << GameOrdar[0] << " | " << GameOrdar[1] << " | " << GameOrdar[2] << "\n";
    cout << "  ---|---|---\t" << "Player:" << winPlayer << endl;
    cout << "   " << GameOrdar[3] << " | " << GameOrdar[4] << " | " << GameOrdar[5] << "\t" << "Computer:" << winComputer << endl;
    cout << "  ---|---|---\t" << "Equal:" << Equal << endl;
    cout << "   " << GameOrdar[6] << " | " << GameOrdar[7] << " | " << GameOrdar[8] << "\n\n";
}

int GetPlayerOprator()
{
    int Oprator;
    do
    {
        cout << "  Enter X Poisaen Number?";
        cin >> Oprator;
        if (Oprator > 9 || Oprator <= 0)
        {
            cout << "\a";
        }
        
    } while (Oprator > 9 || Oprator <= 0);

    return Oprator;
}

bool IsGameOrdarAvailable()
{
    for (int i = 0; i < 9; i++)
    {
        if (GameOrdar[i] != 'X' && GameOrdar[i] != 'O')
            return true;
    }
    return false;
}

bool CheckOpratorPosition(int Oprator)
{
    if (GameOrdar[Oprator - 1] != 'X' && GameOrdar[Oprator - 1] != 'O')
        return true;
    else
        return false;
}

int GetComputerOprator()
{
    return RandomNumber(1, 9);
}

void AddOpratorInOrder(int position, char Type)
{
    GameOrdar[position - 1] = Type;
}

void GetOprators()
{
    int PlayerOprator = GetPlayerOprator();
    int ComputerOprator = GetComputerOprator();

    while (!CheckOpratorPosition(PlayerOprator))
    {
        cout << "  Wrong Position...!\n";
        PlayerOprator = GetPlayerOprator();
    }
    AddOpratorInOrder(PlayerOprator, 'X');

    if (IsGameOrdarAvailable())
    {
        while (!CheckOpratorPosition(ComputerOprator))
        {
            ComputerOprator = GetComputerOprator();
        }
        AddOpratorInOrder(ComputerOprator, 'O');
    }
    else
    {
        return;
    }
}

void PrintGameWinner(int num)
{
    if (num == 1)
    {
        PrintOrderGame();
        cout << "Player Wins :-)\n";
        system("color 2F"); // Turn Screen to Green
        cout << "\a";
        system("pause");
        winPlayer++;
        ResetGame();
    }
    if (num == 2)
    {
        PrintOrderGame();
        cout << "Computer Wins :-(\n";
        system("color 4F"); // Turn Screen to Rad
        cout << "\a";
        system("pause");
        winComputer++;
        ResetGame();
    }
    if (num == -1)
    {
        PrintOrderGame();
        cout << "No Winner...!\n";
        system("color 6F"); // Turn Screen to Yellow
        cout << "\a";
        system("pause");
        Equal++;
        ResetGame();
    }
}

void CheckDraw()
{
    if (GameOrdar[0] == 'X' && GameOrdar[1] == 'X' && GameOrdar[2] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[0] == 'O' && GameOrdar[1] == 'O' && GameOrdar[2] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[3] == 'X' && GameOrdar[4] == 'X' && GameOrdar[5] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[3] == 'O' && GameOrdar[4] == 'O' && GameOrdar[5] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[6] == 'X' && GameOrdar[7] == 'X' && GameOrdar[8] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[6] == 'O' && GameOrdar[7] == 'O' && GameOrdar[8] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[0] == 'X' && GameOrdar[4] == 'X' && GameOrdar[8] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[0] == 'O' && GameOrdar[4] == 'O' && GameOrdar[8] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[2] == 'X' && GameOrdar[4] == 'X' && GameOrdar[6] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[2] == 'O' && GameOrdar[4] == 'O' && GameOrdar[6] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[0] == 'X' && GameOrdar[3] == 'X' && GameOrdar[6] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[0] == 'O' && GameOrdar[3] == 'O' && GameOrdar[6] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[1] == 'X' && GameOrdar[4] == 'X' && GameOrdar[7] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[1] == 'O' && GameOrdar[4] == 'O' && GameOrdar[7] == 'O')
        return PrintGameWinner(2);

    if (GameOrdar[2] == 'X' && GameOrdar[5] == 'X' && GameOrdar[8] == 'X')
        return PrintGameWinner(1);

    if (GameOrdar[2] == 'O' && GameOrdar[5] == 'O' && GameOrdar[8] == 'O')
        return PrintGameWinner(2);

    if (!IsGameOrdarAvailable())
    {
        return PrintGameWinner(-1);
    }
}

void TourStart()
{
    while (IsGameOrdarAvailable())
    {
        PrintOrderGame();
        GetOprators();
        CheckDraw();
    }
    PrintOrderGame();
}

void StartGame()
{
    ResetGame();
    TourStart();
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}
