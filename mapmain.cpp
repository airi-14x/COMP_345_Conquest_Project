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
using std::string;
using std::cout;
using std::endl;

/*
 * 
 */
int main(int argc, char** argv) {

    Country kaz{"Kazakhstan"};
    Country mr("Paradise");
    Continent yo{"Dead"};

    yo.addCountry(kaz);
    yo.addCountry(mr);

    Map face{"ye"};
    face.addContinent(yo);
    Country temp = yo.getCountry("Paradise");


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
    Country oh10{"Ye10"};
    Country oh11{"Ye11"};
    Country oh12{"Ye12"};
    Country oh13{"Ye13"};
    Country oh14{"Ye14"};



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
    yo.addCountry(oh10);
    yo.addCountry(oh11);
    yo.addCountry(oh12);
    yo.addCountry(oh13);
    yo.addCountry(oh14);

    face.link(oh, oh1);
    face.link(oh, oh2);
    face.link(oh2, oh3);
    face.link(oh3, oh4);
    face.link(oh3, oh5);
    face.link(oh5, oh6);
    face.link(oh7, oh8);
    face.link(oh4, oh9);
    face.link(oh9, oh10);
    face.link(oh10, oh11);
    face.link(oh11, oh12);
    face.link(oh14, oh);


    face.link(kaz, mr);

    

    cout << face.validate() << endl;
    return 0;
}

