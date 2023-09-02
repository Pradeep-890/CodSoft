#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Constants for the number of rows and columns in the theater
const int NUM_ROWS = 5;
const int NUM_COLS = 5;

// Function to display the available seats in the theater
void DisplaySeats(const vector<vector<char>>& seats) {
    cout << "Available Seats:" << endl;
    cout << "  ";
    for (int col = 0; col < NUM_COLS; ++col) {
        cout << setw(3) << col + 1;
    }
    cout << endl;
    for (int row = 0; row < NUM_ROWS; ++row) {
        cout << static_cast<char>('A' + row) << " ";
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << setw(3) << seats[row][col];
        }
        cout << endl;
    }
}

// Function to calculate the total cost based on the number of tickets
double CalculateTotalCost(int numTickets) {
    const double TICKET_PRICE = 10.0;
    return numTickets * TICKET_PRICE;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O')); // Initialize all seats as available
    int totalSeats = NUM_ROWS * NUM_COLS;
    int numTickets;

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        DisplaySeats(seats);
        cout << "Enter the number of tickets you want to book (0 to exit): ";
        cin >> numTickets;

        if (numTickets == 0) {
            cout << "Thank you for using our system. Goodbye!" << endl;
            break;
        } else if (numTickets > 0 && numTickets <= totalSeats) {
            // Allow seat selection
            cout << "Select " << numTickets << " seats (e.g., A1 B2 C3): ";
            vector<string> selectedSeats(numTickets);
            bool validSelection = true;

            for (int i = 0; i < numTickets; ++i) {
                cin >> selectedSeats[i];
                int row = selectedSeats[i][0] - 'A';
                int col = selectedSeats[i][1] - '1';

                if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seats[row][col] == 'O') {
                    seats[row][col] = 'X'; // Mark the seat as booked
                } else {
                    validSelection = false;
                    cout << "Invalid seat selection. Please try again." << endl;
                    break;
                }
            }

            if (validSelection) {
                DisplaySeats(seats);
                double totalCost = CalculateTotalCost(numTickets);
                cout << "Booking successful!" << endl;
                cout << "Total Cost: $" << totalCost << endl;
            }
        } else {
            cout << "Invalid number of tickets. Please try again." << endl;
        }
    }

    return 0;
}
