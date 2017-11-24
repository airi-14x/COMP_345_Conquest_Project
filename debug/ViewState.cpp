#include "ViewState.h"
#include "Map.h"
#include <string>
#include <vector>

ViewState::ViewState(vector<string> o, map<string, int> p, int n)
{
    owners = o;
    players = p;
    numOfCountries = n;
}

ViewState::~ViewState()
{

}
