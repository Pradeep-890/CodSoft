// THIS NUMBER GUESSING GAME
#include <iostream>
#include <ctime>
using namespace std;


int main () {

// Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

 // Generate a random number between 1 and 100
    int num = rand() % 100 + 1;

    int guess;
    

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have selected a random number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "Enter Your guess: ";
        cin>>guess;
    

        if(guess < num ) {
            cout<< "Your number is too small , Try again"<<endl;
        }
        else if(guess > num ) {
                cout<< "Your number is too large , Try again "<<endl;
            }
        else { 
            cout<<"Woohoo...Your guessed Correct number" <<endl;
        }
    }while (guess != num);

    cout<<"My number was "<<num<<endl;
    





    return 0;
}
