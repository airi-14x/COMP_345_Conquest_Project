/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Subject.h
 * Author: Earl
 *
 * Created on November 3, 2017, 4:23 PM
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <list>
using namespace std;

class Subject {
  public:
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    virtual void Notify();
    Subject();
    ~Subject();
  private:
    list<Observer*> *observers;
};


#endif /* SUBJECT_H */

