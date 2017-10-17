/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A2_Part2_Driver.cpp
 * Author: Airi Chow (#40003396)
 *
 * Created on 2017/10/08, 20:38
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Map.h"
#include "player.h"
#include "StartRandomiser.h"
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {

    srand(time(NULL));

    // Create # of Players // --> Uncomment out in order to test cases where # Players = 2 ~ 6. 
    Player *p1 = new Player("Player 1");
    Player *p2 = new Player("Player 2");
    Player *p3 = new Player("Player 3");
    //Player *p4 = new Player("Player 4");
    //Player *p5 = new Player("Player 5");
    //Player *p6 = new Player("Player 6");
   
    StartRandomiser *r1 = new StartRandomiser();
    
    // Create vectors of Players in increasing order //
    vector<Player*> increasing_order_player; // [P1, P2, P3]
    increasing_order_player.push_back(p1);
    increasing_order_player.push_back(p2);
    increasing_order_player.push_back(p3);
    //increasing_order_player.push_back(p4);
    //increasing_order_player.push_back(p5);
    //increasing_order_player.push_back(p6);
    
    // Round_Robin_Randomiser will RNG the player's turn order //
    r1->round_robin_randomiser(increasing_order_player);
    vector<Player*> turns_order(r1->getTurnPlayerVector()); // Get Turn order //
    
    // Create a vector in order to store the countries to distribute //
    vector<Country*> given_out_countries;

    //---- Map + Continents + Countries --- being added --> From Earl's Map Driver //
    Continent nohr{"Nohr"}; //continent 2
    Continent* pnohr = &nohr;
    Continent hoshido{"Hoshido"}; //continent 1
    Continent* phoshido = &hoshido;
    
    Map ylisse{"Ylisse"}; //Map name
    ylisse.addContinent(phoshido);
    ylisse.addContinent(pnohr);
    
    //countries that belong to nohr
    Country valla{"Valla"};
    Country sagesse{"Sagesse"};
    Country nestra{"Nestra"};
    Country car{"Carrion"};
    Country plegia{"Plegia"};
    Country valentia{"Valentia"};
    Country jugdral{"Jugdral"};
    Country archanea{"Archanea"};
    Country etruria{"Etruria"};
    Country gallia{"Gallia"};

    //pointers for nohrian countries
    Country* pval = &valla;
    Country* psag = &sagesse;
    Country* pnes = &nestra;
    Country* pcar = &car;
    Country* ppleg = &plegia;
    Country* plentia = &valentia;
    Country* pjugd = &jugdral;
    Country* parch = &archanea;
    Country* petr = &etruria;
    Country* pgal = &gallia;
    
    // Add countries to vector //
    given_out_countries.push_back(pval);
    given_out_countries.push_back(psag);
    given_out_countries.push_back(pnes);
    given_out_countries.push_back(pcar);
    given_out_countries.push_back(ppleg);
    given_out_countries.push_back(plentia);
    given_out_countries.push_back(pjugd);
    given_out_countries.push_back(parch);
    given_out_countries.push_back(petr);
    given_out_countries.push_back(pgal);

    //shoving ccountries in nohr
    pnohr->addCountry(pval);
    pnohr->addCountry(psag);
    pnohr->addCountry(pnes);
    pnohr->addCountry(pcar);
    pnohr->addCountry(ppleg);
    pnohr->addCountry(plentia);
    pnohr->addCountry(pjugd);
    pnohr->addCountry(parch);
    pnohr->addCountry(petr);
    pnohr->addCountry(pgal);

    //Hoshido countries
    Country mokushu{"Mokushu"};
    Country kohga{"Kohga"};
    Country izumo{"Izumo"};
    Country sacae{"Sacae"};

    Country* pmokushu = &mokushu;
    Country* pkohga = &kohga;
    Country* pizumo = &izumo;
    Country* psacae = &sacae;

    phoshido->addCountry(pmokushu);
    phoshido->addCountry(pkohga);
    phoshido->addCountry(pizumo);
    phoshido->addCountry(psacae);
    
    // Add countries to vector //
    given_out_countries.push_back(pmokushu);
    given_out_countries.push_back(pkohga);
    given_out_countries.push_back(pizumo);
    given_out_countries.push_back(psacae);
    
    cout << "Size : " << given_out_countries.size();
    
    //  ------------------------ //
 
    int countries_left_to_assign = given_out_countries.size();
    cout << "\nCountries Left " << countries_left_to_assign;
    int player_index = 0;
 
    // 
    r1->assignCountries(countries_left_to_assign,given_out_countries);
    r1->setArmiesOnCountries(given_out_countries);
    r1->display(given_out_countries);
    
   
    delete p1;
    delete p2;
    delete p3;
    delete r1;

    p1 = NULL;
    p2 = NULL;
    p3 = NULL;
    r1 = NULL;


}

