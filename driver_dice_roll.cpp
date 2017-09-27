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

<<<<<<< HEAD
    // !! NEED TO CREATE PLAYER OBJECTS TO CAST THE DICE //
=======
    // Player 1 //
>>>>>>> 8bf31e72ec9d88f442a3cdf0bd84f7021bb79209
    cout << "Player 1: Turn~ \n";
    Player* p1 = new Player();
    Dice d = p1->getDice();
    //Dice *d = p1->getDice();
<<<<<<< HEAD
    
    //Dice *d = new Dice();
    int d_rolls = d.num_rolls();
    cout << "\n";
    
    
=======

    //Dice *d = new Dice();
    int d_rolls = d.num_rolls();
    cout << "\n";

    // ---- ROUND 1 ---- //
>>>>>>> 8bf31e72ec9d88f442a3cdf0bd84f7021bb79209
    // Add # Player rolls //
    for (int i = 0; i < d_rolls; i++) {
        d.randomiser();
        d.showValue();
        cout << "\n";
    }

    d.printDiceSequence();
    d.clearVector();
<<<<<<< HEAD
    
    
=======

    // ---- ROUND 2 ---- //
>>>>>>> 8bf31e72ec9d88f442a3cdf0bd84f7021bb79209
    d_rolls = d.num_rolls();

    for (int i = 0; i < d_rolls; i++) {
        d.randomiser();
        d.showValue();
        cout << "\n";
    }
    d.printDiceSequence();
    d.percentage();
<<<<<<< HEAD

    cout << std::endl;
    cout << "\nPlayer 2's turn~ \n";
    Player* p2 = new Player();
    Dice c = p2->getDice();
    
=======

    cout << std::endl;

    // Player 2 //
    cout << "\nPlayer 2's turn~ \n";
    Player* p2 = new Player();
    Dice c = p2->getDice();

>>>>>>> 8bf31e72ec9d88f442a3cdf0bd84f7021bb79209
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
<<<<<<< HEAD
    
    delete p1;
    p1 = NULL;
    delete p2;
    p2 = NULL;
    //delete d;
    //d = NULL;
    
    //delete c;
    //c = NULL;
    
}
=======
>>>>>>> 8bf31e72ec9d88f442a3cdf0bd84f7021bb79209

    delete p1;
    p1 = NULL;
    delete p2;
    p2 = NULL;

}
