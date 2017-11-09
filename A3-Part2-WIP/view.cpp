#include "view.h"
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

view::view(Map* m)
{
    subject = m;
    subject->Attach(this);
}

view::~view()
{
    //dtor
}

void view::Update() {
    state = subject->getState();
    print();
}


void view::print() {
    map<string,int> players = state->players;

    cout << "-----------------------------------------------------------------" << endl;
    for (MapIterator it=players.begin(); it!=players.end(); ++it) {
        double percentageOwned = it->second / (double)state->numOfCountries * 100;
        cout << it->first << "\t" << std::fixed << setprecision(1) << percentageOwned << "%\t";
        for(int i = 2; i < 100; i = i + 2){
            if(percentageOwned >= i)
                cout << "|";
            else
                break;
        }
        cout << endl;
    }
}

/*

    map<string, int> state;

    for (int i = 0; i < state.size() * 9; i++){
        cout << "_";
    }
    cout << endl;

    for (int i = 10; i > 0; i--){
        for (std::map<string,int>::iterator it=state.begin(); it!=state.end(); ++it) {
            if (it->second < i * 10 && it->second >= (i - 1) * 10) {
                cout << " _ ";
            } else if (it->second >= i * 10) {
                cout << "| | ";
            }
            cout << "\t";
        }
        cout << endl;
    }
    for (std::map<string,int>::iterator it=state.begin(); it!=state.end(); ++it) {
        cout << it->second << "%\t";
    }
    cout << endl;
    for (int i = 0; i < state.size(); i++){
        cout << "P" << i << "\t";
    }

    cout << endl;
    for (int i = 0; i < state.size() * 8; i++){
        cout << "-";
    }
    cout << endl;

    for (std::map<string,int>::iterator it=state.begin(); it!=state.end(); ++it) {
        cout << it->first << endl;
    }
}
*/
