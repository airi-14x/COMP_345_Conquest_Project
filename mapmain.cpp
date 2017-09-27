/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Earl Steven Aromin 40004997
 *
 * Created on September 19, 2017, 7:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
//#include "Map.h"
//#include <iterator>
#include "cards.h"
#include "player.h"
using std::string;
using std::cout;
using std::endl;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(NULL));
    
    Continent yo{"Dead"};\
    Continent* yoo = &yo;
    Map face{"ye"};
    face.addContinent(yoo);


    Country oh{"Ye"};
    Country oh1{"Ye1"};
    Country oh2{"Ye2"};
    Country oh3{"Ye3"};
    Country oh4{"Ye4"};
    Country oh5{"Ye5"};
    Country oh6{"Ye6"};
    Country oh7{"Ye7"};
    Country oh8{"Ye8"};
    Country oh9{"Ye9"};


    Country* ohh = &oh;
    Country* ohh1 = &oh1;
    Country* ohh2 = &oh2;
    Country* ohh3 = &oh3;
    Country* ohh4 = &oh4;
    Country* ohh5 = &oh5;
    Country* ohh6 = &oh6;
    Country* ohh7 = &oh7;
    Country* ohh8 = &oh8;
    Country* ohh9 = &oh9;


    yo.addCountry(ohh);
    yo.addCountry(ohh1);
    yo.addCountry(ohh2);
    yo.addCountry(ohh3);
    yo.addCountry(ohh4);
    yo.addCountry(ohh5);
    yo.addCountry(ohh6);
    yo.addCountry(ohh7);
    yo.addCountry(ohh8);
    yo.addCountry(ohh9);

    //links countries
    face.link(oh, oh1);
    face.link(oh, oh2);
    face.link(oh2, oh3);
    face.link(oh3, oh4);
    face.link(oh2, oh4);
    face.link(oh4, oh5);
    face.link(oh4,oh6);
    face.link(oh6, oh7);
    face.link(oh7, oh8);

    face.link(oh8, oh9);

    //face.link(oh9,oh1);

    cout << face.getContinent(0)->nameCountries(); //pointer testing
    cout << yo.nameCountries();//pointer testing p2
    cout << face.validate() << endl;
    
    Deck newDeck(face);
    
    newDeck.listCards();
    
    return 0;
}

