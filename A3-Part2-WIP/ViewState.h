#ifndef VIEWSTATE_H
#define VIEWSTATE_H

#include <map>
using namespace std;

class ViewState
{
    public:
        ViewState(map<string, int> p , int n);
        virtual ~ViewState();
        map<string, int> players;
        int numOfCountries;
};

#endif // VIEWSTATE_H
