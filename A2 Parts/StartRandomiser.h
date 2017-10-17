/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StartRandomiser.h
 * Author: Airi Chow (#40003396)
 *
 * Created on 2017/10/08, 20:31
 */

#ifndef STARTRANDOMISER_H
#define STARTRANDOMISER_H

#include <vector>
#include "player.h"
using std::vector;

class StartRandomiser {
public:
    StartRandomiser();
    StartRandomiser(const StartRandomiser& orig);
    virtual ~StartRandomiser();
    void round_robin_randomiser(const vector<Player*>); // Setting order within class //
    vector<Player*> getTurnPlayerVector();
    void assignCountries(int, const vector<Country*>); // Assign countries in Round-Robin-Order //
    void assignNumArmies();
    void display(const vector<Country*>); // Calls toString of Countries //
    void setArmiesOnCountries(const vector<Country*>); // Set armies according to # Players in vector //
    int RNG_countries(int); // Distribute the countries in RNG fashion //
    
    
private:
    // Dice order makes sure that the player has been only assigned once //
    int dice_order_one;
    int dice_order_two;
    int dice_order_three;
    int dice_order_four;
    int dice_order_five;
    int dice_order_six;
    int num_of_players;
    int assign_order; // Maximum assignment order //
    int randomiser_number; // RNG order number //
    int number_of_players(); // Range 2 - 6 --> Requires to input the same value as # Player created in Driver//
    int player_index; // Starts at 0 //
    int armies; // Armies to assign //
    vector<Player*> players_turn; // RNG turn order //
    
};

#endif /* STARTRANDOMISER_H */

