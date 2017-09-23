/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *
 * 
 * File:   main.cpp
 * Author: Airi
 *
 * Created on 2017/09/18, 12:11
 */


#include <iostream>
#include <ctime>
#include "Dice.h"

using std::cout;
using std::cin;

int main() {
    srand(time(NULL));

    // !! NEED TO CREATE PLAYER OBJECTS TO CAST THE DICE //
    Dice *d = new Dice();
    int d_rolls = d->num_rolls();
    cout << "\n";

    // Add # Player rolls //
    for (int i = 0; i < d_rolls; i++) {
        d->randomiser();
        d->showValue();
        cout << "\n";
    }

    d->printDiceSequence();
    d->clearVector();
    
    d_rolls = d->num_rolls();

    for (int i = 0; i < d_rolls; i++) {
        d->randomiser();
        d->showValue();
        cout << "\n";
    }
    
    d->percentage();

    Dice *c = new Dice();
    int c_rolls = c->num_rolls();
    cout << "\n";

    // Add # Player rolls //
    for (int i = 0; i < c_rolls; i++) {
        c->randomiser();
        c->showValue();
        cout << "\n";
    }

    c->printDiceSequence();
    c->clearVector();

    // TO DO: Clear array after ... Re-initialise ... //
    c_rolls = c->num_rolls();

    for (int i = 0; i < c_rolls; i++) {
        c->randomiser();
        c->showValue();
        cout << "\n";
    }
    
    c ->percentage();
    delete d;
    d = NULL;
    
    delete c;
    c = NULL;
}

