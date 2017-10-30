/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StartRandomiser.cpp
 * Author: Airi Chow (#40003396)
 * 
 * Created on 2017/10/08, 20:31
 */

#include "player.h"
#include "StartRandomiser.h"
#include <ctime> // For Randomiser //
#include <limits>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

StartRandomiser::StartRandomiser() {
    dice_order_one = 1;
    dice_order_two = 1;
    dice_order_three = 1;
    dice_order_four = 1;
    dice_order_five = 1;
    dice_order_six = 1;
    assign_order = number_of_players();
    num_of_players = assign_order;
    player_index = 0;
    armies = 0;
    value_index = 0;
}

// Set number_of_player which will be used in this class //
int StartRandomiser::number_of_players() {
    cout << "Number of Players(min. 2 ~ max. 6)? ";
    int number_of_players;
    cin >> number_of_players;
    bool isValid = false;

    while (isValid == false)
        if (number_of_players < 2 || number_of_players > 6) {
            cout << "Error, invalid value. Try Again. ";
            cin.clear(); // Gets rid of error flag //
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Stop ignoring after \n // --> Fixed by adding header
        } else {
            cout << "Number of Players Requested: " << number_of_players << endl;
            isValid = true;
        }

    return number_of_players;

}

// Takes player_order which is a vector of Player* in order [P1,P2....]//
// Set turns_order vector which is and RNG version of player_order //
void StartRandomiser::round_robin_randomiser(const vector<Player*> player_order) {
    while (assign_order > 0) {
        randomiser_number = rand() % num_of_players + 1; // ( 1 - #Players value)
        cout << "Current Random Number for Turns: " << randomiser_number << endl;
        cout << "Current assign_order : " << assign_order << endl;
        switch (randomiser_number) {
            case 1:
            {
                if (dice_order_one == 1) {
                    cout << "1: Hello~" << endl;
                    players_turn.push_back(player_order.at(0));
                    dice_order_one--;
                    assign_order--;
                }
                break;
            }

            case 2:
            {
                if (dice_order_two == 1) {
                    cout << "2: Hello~" << endl;
                    players_turn.push_back(player_order.at(1));
                    dice_order_two--;
                    assign_order--;
                }
                break;
            }

            case 3:
            {
                if (dice_order_three == 1) {
                    cout << "3: Hello~" << endl;
                    players_turn.push_back(player_order.at(2));
                    dice_order_three--;
                    assign_order--;
                }
                break;
            }

            case 4:
            {
                if (dice_order_four == 1) {
                    cout << "4: Hello~" << endl;
                    players_turn.push_back(player_order.at(3));
                    dice_order_four--;
                    assign_order--;
                }
                break;
            }
            case 5:
            {
                if (dice_order_five == 1) {
                    cout << "5: Hello~" << endl;
                    players_turn.push_back(player_order.at(4));
                    dice_order_five--;
                    assign_order--;
                }
                break;
            }

            case 6:
            {
                if (dice_order_six == 1) {
                    cout << "6: Hello~" << endl;
                    players_turn.push_back(player_order.at(5));
                    dice_order_six--;
                    assign_order--;
                }
                break;
            }
        }
    }

}

// RNG number for country selection //
/*
int StartRandomiser::RNG_countries(int num_countries) {
    int rng_countries_index = rand() % num_countries;
    return rng_countries_index;
} */

// Assigns countries if they haven't been assigned. Loops otherwise //
// Loop terminates when all countries are assigned //
void StartRandomiser::assignCountries(int countries_left_to_assign, const vector<Country*> given_out_countries) {
    while (countries_left_to_assign > 0) {
        //int value = RNG_countries(given_out_countries.size());
        
        cout << "\n value index: " << value_index;
        if (given_out_countries[value_index]->getHasBeenAssigned() == false) {
            cout << "\n Player index: " << player_index;
            if (player_index < players_turn.size()) //Turn order is max 3 //
            {
                cout << "Here??1";
                players_turn[player_index]->addCountry(given_out_countries[value_index]);
                given_out_countries[value_index]->setHasBeenAssigned();
                countries_left_to_assign--;
                player_index++; // Move index //
                if (player_index >= players_turn.size()) {
                    player_index = 0;
                }
            } else {
                cout << "Here2~!";
                //player_index = 0; // Wrap around vector and restart //
                players_turn[player_index]->addCountry(given_out_countries[value_index]);
                given_out_countries[value_index]->setHasBeenAssigned();
                countries_left_to_assign--;
            }

        }
        value_index++;
        cout << "\n Countries Left after the loops: " << countries_left_to_assign;
    }
}

// Used by setArmiesOnCountries to set according # players in game //
void StartRandomiser::assignNumArmies() {
    switch (players_turn.size()) {
        case 2:
            armies = 40;
            break;
        case 3:
            armies = 35;
            break;
        case 4:
            armies = 30;
            break;
        case 5:
            armies = 25;
            break;
        case 6:
            armies = 20;
            break;
    }

}

// Iterates through all the countries and sets the armies size //
void StartRandomiser::setArmiesOnCountries(const vector<Country*> given_out_countries) {
    assignNumArmies();
    for (int i = 0; i < given_out_countries.size(); i++) {
        given_out_countries[i]->setArmyNum(armies);
    }
}

// Calls Countries' toString() //
void StartRandomiser::display(const vector<Country*> given_out_countries) {
    for (int i = 0; i < given_out_countries.size(); i++) {
        cout << given_out_countries[i]->toString();
        cout << "index number: ";
        cout << i ;
        cout << endl;
    }
}

// Get vectors for Player's turn order //
vector<Player*> StartRandomiser::getTurnPlayerVector() {
    return players_turn;
}

StartRandomiser::StartRandomiser(const StartRandomiser& orig) {
}

StartRandomiser::~StartRandomiser() {
}

