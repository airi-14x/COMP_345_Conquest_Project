/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Earl
 *
 * Created on September 19, 2017, 7:31 PM
 */

#include <cstdlib>
#include <iostream>
#include "Continent.h"
#include "Country.h"
#include "Map.h"
#include <iterator>
using std::string;
using std::cout;
using std::endl;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Continent yo{"Dead"};
    Map face{"ye"};
    face.addContinent(yo);


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



    face.addCountry(oh,0);
    face.addCountry(oh1,0);
    face.addCountry(oh2,0);
    face.addCountry(oh3,0);
    face.addCountry(oh4,0);
    face.addCountry(oh5,0);
    face.addCountry(oh6,0);
    face.addCountry(oh7,0);
    face.addCountry(oh8,0);
    face.addCountry(oh9,0);
    /*  
    yo.addCountry(oh);
    yo.addCountry(oh1);
    yo.addCountry(oh2);
    yo.addCountry(oh3);
    yo.addCountry(oh4);
    yo.addCountry(oh5);
    yo.addCountry(oh6);
    yo.addCountry(oh7);
    yo.addCountry(oh8);
    yo.addCountry(oh9);
   */

    face.link(oh,oh1);
    face.link(oh,oh2);
    face.link(oh2,oh3);
    face.link(oh3,oh4);
    face.link(oh2,oh4);
    face.link(oh4,oh5);
    face.link(oh4,oh6);
    face.link(oh6,oh7);
    face.link(oh7,oh8);
    
    face.link(oh8,oh9);
    
    //face.link(oh9,oh1);
    
    


    
    
    cout << face.validate()<< endl;
    return 0;
}

