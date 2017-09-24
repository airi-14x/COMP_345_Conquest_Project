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
using std::string;
using std::cout;
using std::endl;

/*
 * 
 */
int main(int argc, char** argv) {

    Country kaz {"Kazakhstan","Continentazkstan", "Earl"};
    Country mr ("Paradise", "HAHAHAHA", "No one");
    Continent yo{"Dead"};
    
    yo.addCountry(kaz);
    yo.addCountry(mr);
    Country temp = yo.getCountry("Paradise");
    cout <<  yo.nameCountries() << endl;
    return 0;
}

