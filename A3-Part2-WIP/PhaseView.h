/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhaseView.h
 * Author: Airi
 *
 * Created on 2017/11/04, 21:56
 */

#ifndef PHASEVIEW_H
#define PHASEVIEW_H
#include "Observer.h"
#include "player.h"

class PhaseView : public Observer {
public:
    PhaseView();
    PhaseView(Player* p);
    virtual ~PhaseView();
    void Update();
    void display();
    void reinforceDisplay(); // Displays Player's Reinforcement Phase Info //
    void attackDisplay();   // Displays Player's Attack Phase Info //
    void fortifyDisplay(); // Displays Player's Fortification Phase Info //
private:
    Player *_subject;
    int counter;
};

#endif /* PHASEVIEW_H */

