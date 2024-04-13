#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int attempts = 0;
    int num;
    int guess;
    cout << "Hello welcome to Guessing game" << endl;
    cout << "Enter your guess between 1 and 100: " << endl;

    cin >> guess;

    srand(time(NULL));
    num = 1 + rand() % 100;
    if (guess > 100 || guess < 0)
    {
        cout << "Guess a number within range (0-100)" << endl;
        cout << "Guess again: ";
        cin >> guess;
    }

    while (num != guess)
    {
        attempts++;
        if (num < guess)
        {
            cout << "Too high... Try again" << endl;
        }
        else if (num > guess)
        {
            cout << "Too low... Try again" << endl;
        }

        cout << "Guess again: ";
        cin >> guess;
    }
    if (attempts == 1)
    {
        cout << "Hurray you guessed correctly!! in " << attempts << " Attempts " << endl;
        exit(1);
    }
    else
    {
        cout << "Hurray you guessed correctly!! in " << attempts << " Attempts " << endl;
    }
    return 0;
}