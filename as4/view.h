#ifndef VIEW_H
#define VIEW_H

#include "view.h"
#include "Observer.h"
#include "Map.h"
#include <iostream>
#include <string>
using namespace std;

typedef map<string,int>::iterator MapIterator;

class view : public Observer
{
    public:
        view(Map* m);
        virtual ~view();
        void Update();
        void print();
    private:
        Map* subject;
        ViewState* state;
};

#endif // VIEW_H
