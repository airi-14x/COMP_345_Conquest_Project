/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Observer.h
 * Author: Earl
 *
 * Created on November 3, 2017, 4:24 PM
 */

#ifndef OBSERVER_H
#define OBSERVER_H


class Observer {
  public:
    ~Observer();
    virtual void Update() = 0;
  protected:
    Observer();
};



#endif /* OBSERVER_H */

