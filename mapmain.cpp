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
#include "Map.h"
#include "player.h"
#include <iterator>
using std::string;
using std::cout;
using std::endl;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Continent yo{"Dead"};\
    Continent* yoo = &yo;
    Continent ya{"Alive"};\
    Continent* yas = &ya;
    Map face{"ye"};
    face.addContinent(yas);
    face.addContinent(yoo);

    Continent oi{"what"};
    Continent* io = &oi;
    
   // face.addContinent(io);
    Country heh{"Ey3"};
    Country* ehh = &heh;
    io->addCountry(ehh);
    

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


    yoo->addCountry(ohh);
    yoo->addCountry(ohh1);
    yoo->addCountry(ohh2);
    yoo->addCountry(ohh3);
    yoo->addCountry(ohh4);
    yoo->addCountry(ohh5);
    yoo->addCountry(ohh6);
    yoo->addCountry(ohh7);
    yoo->addCountry(ohh8);
    yoo->addCountry(ohh9);

    Country ho{"Ey"};
    Country ho1{"Ey1"};
    Country ho2{"Ey2"};
    Country ho3{"Ey3"};

    Country* ha = &ho;
    Country* ha1 = &ho1;
    Country* ha2 = &ho2;
    Country* ha3 = &ho3;

    yas->addCountry(ha);
    yas->addCountry(ha1);
    yas->addCountry(ha2);
    yas->addCountry(ha3);
    
    face.link(ho,ho1);
    face.link(ho1,ho2);
    face.link(ho2,ho3);

  //  links countries
    face.link(oh, oh1);
    face.link(oh, oh2);
    face.link(oh2, oh3);
    face.link(oh3, oh4);
    face.link(oh2, oh4);
    face.link(oh4, oh5);
    face.link(oh4, oh6);
    face.link(oh6, oh7);
    face.link(oh7, oh8);

    face.link(oh8, oh9);

    //face.link(oh9,oh1);


    face.link(oh6,ho2);

    face.checkDuplicateCnts();

    //cout << face.getContinent(0)->nameCountries(); //pointer testing
    //cout << yo.nameCountries(); //pointer testing p2
    face.valiCont(yas);
    face.validate();
     
    Player me("Alexia");
    
    me.addCountry(ha);
    me.addTroops(10);
    
    me.reinforce(0, ha);
    me.reinforce(15, ha);
    me.reinforce(10, ha3);
    me.reinforce(10, ha);
    
    cout << ha->getArmyNum() << " troops currently occupy " << ha->getName() << "." << endl;
    
    return 0;
}

