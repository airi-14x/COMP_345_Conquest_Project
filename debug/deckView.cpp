#include "deckView.h"
#include <vector>
#include <iostream>
using namespace std;
deckView::deckView(){
};

void deckView::add(Hand* h){
    hands.push_back(h);
}

void deckView::Update(){
    cout << "updating deck view" << endl;
}

deckView::~deckView(){
};
