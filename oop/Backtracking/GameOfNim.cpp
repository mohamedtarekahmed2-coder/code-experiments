#include <iostream>
#include <random>
#include <cmath>
using namespace std;
const int NO_GOOD_MOVE = 0;

enum player
{
    Human,
    AI
};

void reversePlayer(player &whoseTurn)
{
    if (whoseTurn == Human)
        whoseTurn = AI;
    else
        whoseTurn = Human;
}

int getRandomNumber(int min, int max)
{
    random_device rd;
    return uniform_int_distribution<int>{min, max}(rd);
}

void giveInstructions(int nCoins)
{
    cout << "===================================\n";
    cout << "            Game of Nim            \n";
    cout << "===================================\n";
    cout << "Starting with " << nCoins << " coins.\n";
    cout << "You can take 1 or 2 or 3 coins.\n";
    cout << "The player who takes the last coin loses.\n\n";
}

int getUserMove(int nCoins)
{
    int n;
    while (true)
    {
        cout << "Take 1 or 2 or 3 coins (and no more than remaining coins): ";
        cin >> n;
        cout << '\n';
        if (1 <= n && n <= 3 && n <= nCoins)
            return n;
        cout << "Invalid move.\n";
    }
}

int algoByMath(int nCoins)
{
    return (nCoins - 1) % 4;
}

bool isBadPosition(int);

int findGoodMove(int nCoins)
{
    for (int num = 1; num <= 3; num++)
    {
        if (1 <= nCoins - num && isBadPosition(nCoins - num))
        {
            return num;
        }
    }
    return NO_GOOD_MOVE;
}

bool isBadPosition(int nCoins)
{
    if (nCoins == 1)
        return true;
    return findGoodMove(nCoins) == NO_GOOD_MOVE;
}

int algoByBacktracking(int nCoins)
{
    return findGoodMove(nCoins);
}

int chooseAIMove(int nCoins)
{
    // int num = algoByMath;
    int num = algoByBacktracking(nCoins);
    if (num == NO_GOOD_MOVE)
        num = getRandomNumber(1, min(3, nCoins));
    cout << "AI takes " << num << " coin.\n\n";
    return num;
}

void updateState(int &nCoins, int num, player &whoseTurn)
{
    nCoins -= num;
    reversePlayer(whoseTurn);
}

void announceWinner(player whoseTurn)
{
    reversePlayer(whoseTurn);
    switch (whoseTurn)
    {
    case Human:
        cout << "Human wins, in the next time AI will kill u.\n";
        break;
    case AI:
        cout << "AI wins, AI will take your job.\n";
        break;
    }
}

void gameOfNim()
{
    int nCoins = getRandomNumber(15, 35), num = 0;
    player whoseTurn = Human;
    giveInstructions(nCoins);
    while (nCoins > 1)
    {
        cout << "Number of Coins is " << nCoins << ".\n";
        switch (whoseTurn)
        {
        case Human:
            num = getUserMove(nCoins);
            break;
        case AI:
            num = chooseAIMove(nCoins);
            break;
        }
        updateState(nCoins, num, whoseTurn);
    }
    announceWinner(whoseTurn);
}

int main()
{
    gameOfNim();
    return 0;
}