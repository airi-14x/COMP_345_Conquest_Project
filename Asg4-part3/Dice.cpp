/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Dice.cpp
 * Author: Airi Chow (#40003396)
 *
 * Created on 2017/09/19, 19:09
 */

#include "Dice.h"
#include <limits>
#include <iostream>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

Dice::Dice() {
    track_one = 0;
    track_two = 0;
    track_three = 0;
    track_four = 0;
    track_five = 0;
    track_six = 0;
    counter = 1;

    vector<int> dice_sequence(1);
}

int Dice::randomiser() {
    int dice_number = rand() % 6 + 1;  // Dice's Range //
    dice_number = rand() % 6 + 1;
    trackValue(dice_number);
    return dice_number;
}

// Increment Dice Counter //
void Dice::trackValue(int dice_number) {
    switch (dice_number) {
        case 1:
            track_one = track_one + 1;
            break;
        case 2:
            track_two = track_two + 1;
            break;
        case 3:
            track_three = track_three + 1;
            break;
        case 4:
            track_four = track_four + 1;
            break;
        case 5:
            track_five = track_five + 1;
            break;
        case 6:
            track_six = track_six + 1;
            break;
    }
    cout << "Roll #" << counter << ": You rolled a: " << dice_number << endl;
    counter++;

    // Add Value to Sequence //
    dice_sequence.push_back(dice_number);
}

// Number of times each # roll happened //
void Dice::showValue() {
    cout << "\n1's Dice Roll: " << track_one;
    cout << "\n2's Dice Roll: " << track_two;
    cout << "\n3's Dice Roll: " << track_three;
    cout << "\n4's Dice Roll: " << track_four;
    cout << "\n5's Dice Roll: " << track_five;
    cout << "\n6's Dice Roll: " << track_six;
}

// Used in percentage //
int Dice::getTotal() {
    int total = track_one + track_two + track_three + track_four + track_five +
            track_six;
    return total;
}

// Delete all values in Vector //
void Dice::clearVector()
{
    dice_sequence.clear();
}

// Prints what is in the Vector for current roll //
void Dice::printDiceSequence()
{
    int index = 0;
    for(auto &i : dice_sequence) // Goes through each element of the collection //
    {
        cout << "\nAt index " << index << " " << i;
        index++;
    }
}

// # Rolls requested, 1-3 rolls. Error is handled. //
int Dice::num_rolls() {
    int rolls;
    bool isInvalid = true;

    while (isInvalid) {
        cout << "\nHow many Rolls do you wish for? Acceptable values are 1, 2 or 3: ";
        cin >> rolls;
        // Invalid Values //
        if (rolls < 1 || rolls > 3) {
            cout << "Error, invalid value. Try Again. ";
            cin.clear(); // Gets rid of error flag //
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Stop ignoring after \n // --> Fixed by adding header
        } else {
            cout << "\nYou have requested " << rolls << " roll(s)";
            isInvalid = false;
        }
    }
    return rolls;
}

// Calculate Percentage of Rolls //
void Dice::percentage() {

    cout << "\n-------- Stats ---------";
    double perc_one = ((double)track_one) / getTotal() * 100.0;
    cout << "\nPercentage of 1's roll: " << perc_one << "%";
    double perc_two = ((double)track_two) / getTotal() * 100.0;
    cout << "\nPercentage of 2's roll: " << perc_two << "%";
    double perc_three = ((double)track_three) / getTotal() * 100.0;
    cout << "\nPercentage of 3's roll: " << perc_three << "%";

    double perc_four = ((double)track_four) / getTotal() * 100.0;
    cout << "\nPercentage of 4's roll: " << perc_four << "%";
    double perc_five = ((double)track_five) / getTotal() * 100.0;
    cout << "\nPercentage of 5's roll: " << perc_five << "%";
    double perc_six = ((double)track_six) / getTotal() * 100.0;
    cout << "\nPercentage of 6's roll: " <<perc_six << "%";
}
