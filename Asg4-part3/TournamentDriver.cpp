/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TournamentDriver.cpp
 * Author: Airi Chow (#40003396), Earl Aromin (#40004997)
 *
 * Created on November 17, 2017, 5:12 PM
 */

#include <cstdlib>
#include "Tournament.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Tournament tt;
    tt.createMaps();
    tt.createPlayers();
    tt.setGameNumber();
    tt.setMaxTurns();
    tt.play();
    return 0;
}

