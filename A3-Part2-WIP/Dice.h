/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Dice.h
 * Author: Airi Chow (#40003396)
 *
 * Created on 2017/09/19, 19:09
 */

#ifndef DICE_H
#define DICE_H

#include <vector>
#include <string>
using std::vector;
using std::string;
class Dice {
public:
    Dice();
    int randomiser();
    void trackValue(int);
    void showValue();
    int getTotal();    // Total # of Rolls

    int num_rolls();   // Allows Player to choose 1~3 6-sided dice to roll //
    void percentage(); // Keeps track of % value rolled, add Dice() //
    void clearVector();
    void printDiceSequence();

private:
    int counter; // For array's index //
    int track_one;
    int track_two;
    int track_three;
    int track_four;
    int track_five;
    int track_six;
    vector<int> dice_sequence; // Sequence of rolls in vector //
};


#endif /* DICE_H */
