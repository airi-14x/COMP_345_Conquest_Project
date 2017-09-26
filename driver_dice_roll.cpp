/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *
 *
 * File:   main.cpp
 * Author: Airi Chow (#40003396)
 *
 * Created on 2017/09/18, 12:11
 */


#include <iostream>
#include <ctime>
#include "Dice.h"
#include "player.h"

using std::cout;
using std::cin;

int main() {
    srand(time(NULL));

    // Player 1 //
    cout << "Player 1: Turn~ \n";
    Player* p1 = new Player();
    Dice d = p1->getDice();
    //Dice *d = p1->getDice();

    //Dice *d = new Dice();
    int d_rolls = d.num_rolls();
    cout << "\n";

    // ---- ROUND 1 ---- //
    // Add # Player rolls //
    for (int i = 0; i < d_rolls; i++) {
        d.randomiser();
        d.showValue();
        cout << "\n";
    }

    d.printDiceSequence();
    d.clearVector();

    // ---- ROUND 2 ---- //
    d_rolls = d.num_rolls();

    for (int i = 0; i < d_rolls; i++) {
        d.randomiser();
        d.showValue();
        cout << "\n";
    }
    d.printDiceSequence();
    d.percentage();

    cout << std::endl;

    // Player 2 //
    cout << "\nPlayer 2's turn~ \n";
    Player* p2 = new Player();
    Dice c = p2->getDice();

    int c_rolls = c.num_rolls();
    cout << "\n";

    // ---- ROUND 1 ---- //
    // Add # Player rolls //
    for (int i = 0; i < c_rolls; i++) {
        c.randomiser();
        c.showValue();
        cout << "\n";
    }

    c.printDiceSequence();
    c.clearVector();

    c_rolls = c.num_rolls();

    // ---- ROUND 2 ---- //
    for (int i = 0; i < c_rolls; i++) {
        c.randomiser();
        c.showValue();
        cout << "\n";
    }
    c.printDiceSequence();
    c .percentage();

    delete p1;
    p1 = NULL;
    delete p2;
    p2 = NULL;

}
