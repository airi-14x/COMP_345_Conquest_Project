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
#include <iterator>
#include "Map.h"
using std::string;
using std::cout;
using std::endl;

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Continent nohr{"Nohr"};\
    Continent* pnohr = &nohr;
    Continent hoshido{"Hoshido"};\
    Continent* phoshido = &hoshido;
    Map ylisse{"Ylisse"};
    ylisse.addContinent(phoshido);
    ylisse.addContinent(pnohr);

    Continent oi{"what"};
    Continent* io = &oi;
    
    ylisse.addContinent(io);
    Country heh{"Ye"};
    Country* ehh = &heh;
    io->addCountry(ehh);
    

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
    
    ylisse.link(mokushu,kohga);
    ylisse.link(kohga,izumo);
    ylisse.link(izumo,sacae);

  //  links countries
    ylisse.link(valla, sagesse);
    ylisse.link(valla, nestra);
    ylisse.link(nestra, car);
    ylisse.link(car, plegia);
    ylisse.link(nestra, plegia);
    ylisse.link(plegia, valentia);
    ylisse.link(plegia, jugdral);
    ylisse.link(jugdral, archanea);
    ylisse.link(archanea, etruria);

    ylisse.link(etruria, gallia);


<<<<<<< HEAD
    face.link(oh6,ho2);
=======

    ylisse.link(jugdral,izumo);
>>>>>>> 0a6ca235e2b3d6d7e7b4b9172c0c259edca6123e

    ylisse.checkDuplicateCnts();

     ylisse.valiCont(phoshido);
     ylisse.validate(pnes);
    return 0;
}

