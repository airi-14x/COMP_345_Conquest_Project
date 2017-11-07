/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhaseView.cpp
 * Author: Airi
 * 
 * Created on 2017/11/04, 21:56
 */

#include "PhaseView.h"
#include "Observer.h"
#include "player.h"
#include <iostream>
using namespace std;

PhaseView::PhaseView() {
}

PhaseView::PhaseView(Player *p) {
    _subject = p;
    _subject->Attach(this);
    counter = 0; // To adjust in order to trigger certain display upon calling notify() //
}

PhaseView::~PhaseView() {
    _subject->Detach(this);
}

void PhaseView::Update() {
    display();
}

void PhaseView::display() {

    cout << "COUNTER: " << counter << endl;

    cout << "//==============================================\\\\" << endl
            << "||\t" << "Currently it's " << _subject->getName() << "'s turn~               ||" << endl;

    if (_subject->getCurrentPhase() == "Reinforce Phase") {
        counter++;
        reinforceDisplay();
        if (counter >= 2) // Reset after final Reinforce info is called //
            counter = 0; // Reset for next phase //
    } else if (_subject->getCurrentPhase() == "Attack Phase") {

        counter++;
        if (counter > 3 && _subject->getContinueAttacking() == 'n')
            counter = 0;
        if (counter > 3 && _subject->getContinueAttacking() == 'y')
            counter = 1;
        else
            attackDisplay();
        ;
    } else if (_subject->getCurrentPhase() == "Fortify Phase") {
        counter++;
        fortifyDisplay();
        if (counter > 2)
            counter = 0;
    }

}

void PhaseView::reinforceDisplay() {
    // Player's Reinforce Phase Info //
    cout << "COUNTER: " << counter << endl;
    cout << "||\t" << "Current Phase: Reinforce Phase          ||" << endl
            << "\\\\==============================================//" << endl;
    if (counter == 1) {
        cout << "||\t" << "Beginning " << _subject->getName() << "'s reinforcement phase.     ||" << endl;
        cout << "||\t" << _subject->getArmies() << " total armies granted.                 ||" << endl; // Get Player's #armies //
        cout << "||==============================================||" << endl;

    }

    // Player's Basic Reinforce Info //
    if (counter == 2) {
        cout << "||==============================================||" << endl;

        if (_subject->getCountryValid()) {
            cout << "||\t" << _subject->getCountryTo()->getName() << " reinforced with " << _subject->getArmyChange() << " armies           ||" << endl;
        }
        cout << "||\t" << _subject->getName() << " has " << _subject->getArmies() << " deployable armies.             ||" << endl;
        cout << "||==============================================||" << endl;

    }


}

void PhaseView::attackDisplay() {
    // Player's Attack Phase Info //
    cout << "||\t" << "Current Phase: Attack Phase             ||" << endl
            << "\\\\==============================================//" << endl;
    if (counter == 1) {
        cout << "||\t" << "Current Phase: Attack Phase             ||" << endl;
        cout << "||\t" << "Beginning " << _subject->getName() << "'s attack phase.            ||" << endl;
        cout << "||==============================================||" << endl;

    }
    // Attack info (Wins and losses) //
    if (counter == 2) {
        // First Best Attack Info //

        cout << "||\t" << "First Best Attack!                      ||" << endl;

        if (_subject->getBestAttack() > _subject->getBestDefense()) {
            cout << "||\t" << "Best attack (" << _subject->getBestAttack() << ") vs best defense (" <<
                    _subject->getBestDefense() << "):    ||" << endl << "||\t";
            cout << "\t" << "Attack wins.                    ||";
        } else {
            cout << "||\t" << "||\t" << "Best attack (" << _subject->getBestAttack() << ") vs best defense (" <<
                    _subject->getBestDefense() << "):    ||" << endl << "||\t";
            cout << "\t" << "Defense wins.            ||" << endl << "||\t";
        }
        //Second Best Attack Info//


        if (_subject->getDefenseDiceCount() == 2 && _subject->getAttackDiceCount() >= 2) {
            cout << endl << "||\t" << "Second best attack (" << _subject->getSecondBestAttack() << ") vs               ||" << endl
                    << "||\t Second best defense (" <<
                    _subject->getSecondBestDefense() << "):               || " << endl;
            if (_subject->getSecondBestAttack() > _subject->getSecondBestDefense()) {
                cout << "||\t\t" << "Attack wins.                    ||\t";
            } else {
                cout << "||\t\t" << "Defense wins.                   ||\t";
            }
        }
        cout << endl << "||==============================================||" << endl;

    }
    //Reports army losses//
    if (counter == 3) {
        // Report the losses on each side.
        if (_subject->getDefenseWins() == 1)
            cout << "||\t" << _subject->getName() << " lost an army!                        ||" << endl;
        else
            cout << "||\t" << _subject->getName() << " lost " << _subject->getDefenseWins() << " army!                         ||" << endl;

        if (_subject->getAttackWins() == 1)
            cout << "||\t" << _subject->getCountryTo()->getName() << " lost an army!                      ||" << endl;
        else
            cout << "||\t" << _subject->getCountryTo()->getName() << " lost " << _subject->getAttackWins() << " army!                       ||" << endl;

        // Report on the current state of the attacking country.
        cout << "||\t" << _subject->getName() << " now has " << _subject->getCountryFrom()->getArmyNum() << " armies in " << _subject->getCountryFrom()->getName() << ".            ||" << endl;
        if (_subject->getCountryFrom()->getArmyNum() == 1)
            cout << "||\t" << _subject->getCountryFrom()->getName() << " can no longer attack." << endl;

        // Report on the current state of the defending country.
        cout << "||\t" << _subject->getCountryTo()->getPlayerName() << " now has " << _subject->getCountryTo()->getArmyNum() << " armies in " << _subject->getCountryTo()->getName() << ".            ||" << endl;
        cout << "||==============================================||" << endl;

    }

    // Conquered Country Update Display and  Transfer Country Display //   
    if (_subject->getCountryTo() != nullptr && _subject->getCountryTo()->getArmyNum() == 0) {
        cout << "||\t" << _subject->getCountryFrom()->getName() << " has been conquered.                ||" << endl;
        cout << "||" << "Transferring ownership of " << _subject->getCountryTo()->getName() << " from " << _subject->getCountryTo()->getPlayerName() << " to " << _subject->getName() << ". ||" << endl;
    }
    cout << "||==============================================||" << endl;

}

void PhaseView::fortifyDisplay() {
    // Player's Fortify Phase Info //
    if (counter == 1) {
        cout << "||\t" << "Current Phase: Fortify Phase            ||" << endl;
        cout << "||\t" << "Beginning " << _subject->getName() << "'s fortification phase.     ||" << endl;
        cout << "||==============================================||" << endl;
    }

    if (counter == 2 && (_subject->getCountryFrom() != nullptr || _subject->getCountryTo() != nullptr)) {

        cout << "||\t" << _subject->getCountryFrom()->getName() << " has " << _subject->getCountryFrom()->getArmyNum() << " armies.                      ||" << endl;
        cout << "||\t" << _subject->getCountryTo()->getName() << " has " << _subject->getCountryTo()->getArmyNum() << " armies.                      ||" << endl;
        cout << "||==============================================||" << endl;

    }

    if (_subject->getArmyChange() > 0) {
        cout << "||\tSending " << _subject->getArmyChange() << " armies to " << _subject->getCountryTo()->getName() << ".               ||" << endl;

        cout << "||\t" << "Fortification complete.                 ||" << endl;

        cout << "||\t" << _subject->getCountryFrom()->getName() << " has " << _subject->getCountryFrom()->getArmyNum() << " armies.                      ||" << endl;
        cout << "||\t" << _subject->getCountryTo()->getName() << " has " << _subject->getCountryTo()->getArmyNum() << " armies.                      ||" << endl;
        cout << "||==============================================||" << endl;

    }

}

