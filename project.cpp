#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Game
{
public:

    Game(string t) {
        title = t;
    }

    virtual void play() = 0;

private:

    string title;
};

class NumberNinja : public Game {

private:
    int score;

public:

    NumberNinja() : Game("Number Ninja") {
        score = 0;
    }

    void play() override {

        int level = 1;
        char cont = 'y';

        cout <<endl<< "--- Number Ninja ---"<<endl;

        while(cont == 'y' || cont == 'Y') {

            int correctCount = 0;

            cout <<endl<< "======================"<<endl;
            cout << "LEVEL " << level << endl;
            cout << "======================"<<endl;

            for(int i = 1; i <= 3; i++) {

                int a = rand() % (10 * level + 5);
                int b = rand() % (10 * level + 1);
                int userAns;

                int op = rand() % 4;
                char symbol;
                int answer;

                switch(op) {

                    case 0:
                        symbol = '+';
                        answer = a + b;
                        break;

                    case 1:
                        symbol = '-';
                        answer = a - b;
                        break;

                    case 2:
                        symbol = '*';
                        answer = a * b;
                        break;

                    case 3:
                        symbol = '/';

                        b = (b == 0) ? 1 : b;

                        answer = a / b;

                        break;
                }

                cout<<endl << "Q" << i << ": "
                     << a << " "
                     << symbol << " "
                     << b << " = ";

                time_t start = time(0);

                bool beepDone = false;
                bool answered = false;

                while(true) {

                    int elapsed = difftime(time(0), start);

                    if(elapsed >= 5 && !beepDone) {

                        cout << "\a";
                        cout <<endl<< "⚠ 5 sec warning!\n"<<endl;
                        

                        beepDone = true;
                    }

                    if(elapsed >= 10) {

                        cout << " Time up!"<<endl;
                       

                        break;
                    }

                    if(cin.peek() != EOF) {

                        cin >> userAns;

                        answered = true;

                        break;
                    }
                }

                if(answered && userAns == answer) {

                    cout << "Correct!"<<endl;

                    score += 10;

                    correctCount++;
                }
                else {

                    cout << "Wrong! Answer = "
                         << answer << endl;

                    score -= 5;
                }
            }

            if(correctCount == 3) {

                cout <<endl<< "🎉 Level Completed!"<<endl;

                level++;
            }
            else {

                cout <<endl<< "❌ Level Failed!"<<endl;
            }

            cout << "Continue? (y/n): ";
            cin >> cont;
        }

        cout <<endl<< "Final Score: "
             << score << endl;
    }
};


class GuessNumber : public Game {

private:
    int score;

public:

    GuessNumber() : Game("Guess Number") {
        score = 0;
    }

    void play() override {

        cout <<endl<< "--- Guess Number ---"<<endl;

        char again = 'y';

        while(again == 'y' || again == 'Y') {

            int secret = rand() % 10 + 1;

            int guess;

            cout <<endl<< "Guess a number between 1 to 10: ";
            cin >> guess;

            if(guess == secret) {

                cout << "🎉 Correct Guess!\n";

                score += 10;
            }
            else {

                cout << "❌ Wrong Guess!"<<endl;

                cout << "Correct Number was: "
                     << secret << endl;

                score -= 5;
            }

            cout <<endl<< "Current Score: "
                 << score << endl;

            cout <<endl<< "Play Again? (y/n): ";
            cin >> again;
        }

        cout <<endl<< "Final Score: "
             << score << endl;
    }
};

int main() {

    srand(time(0));

    int choice;

    cout << "========== GAME MENU =========="<<endl;

    cout << "1. Number Ninja"<<endl;
    cout << "2. Guess Number"<<endl;

    cout <<endl<< "Enter Choice: ";
    cin >> choice;

    Game* game;

    if(choice == 1) {

        game = new NumberNinja();
    }
    else {

        game = new GuessNumber();
    }

    game->play();

    delete game;

    return 0;
}