#ifndef DECKVIEW_H
#define DECKVIEW_H

#include "Observer.h"
#include "hand.h"
#include <vector>
using namespace std;

class deckView : public Observer
{
    public:
        deckView();
        virtual ~deckView();
        void add(Hand* h);
        void Update();
    protected:

    private:
        vector<Hand*> hands;
};

#endif // DECKVIEW_H
