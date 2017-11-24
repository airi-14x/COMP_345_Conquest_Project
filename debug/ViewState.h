#ifndef VIEWSTATE_H
#define VIEWSTATE_H

#include <map>
#include <string>
#include <vector>
#include "Map.h"
using namespace std;

class ViewState
{
    public:
        ViewState(vector<string> o, map<string, int> p , int n);
        virtual ~ViewState();
        map<string, int> players;
        int numOfCountries;
        vector<string> owners;
};

#endif // VIEWSTATE_H
