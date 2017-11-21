#include <iostream>
#include <ctime>
#include "player.h"
using namespace std;

int main()
{
    srand(time(NULL));

    Map m;

    Continent* a = new Continent("A", 5);
    Continent* b = new Continent("B", 5);

    Country* ac1 = new Country("AC1", "P1", 5);
    Country* ac2 = new Country("AC2", "P1", 5);
    Country* ac3 = new Country("AC3", "P1", 5);
    Country* bc1 = new Country("BC1", "P2", 5);
    Country* bc2 = new Country("BC2", "P3", 5);
    Country* bc3 = new Country("BC3", "P3", 5);

    a->addCountry(ac1);
    a->addCountry(ac2);
    a->addCountry(ac3);
    b->addCountry(bc1);
    b->addCountry(bc2);
    b->addCountry(bc3);

    m.addContinent(a);
    m.addContinent(b);

    m.link(ac1, ac2);
    m.link(ac1, bc1);

    m.link(ac2, bc2);
    m.link(ac2, ac3);

    m.link(ac3, bc3);

    m.link(bc1, bc2);

    m.link(bc2, bc3);

    char stratChar = 'Z';
    Strategy* demoStrat;

    while (!(stratChar == 'H' || stratChar == 'A' || stratChar == 'B'))
    {
        cout << "Select demo strategy (H/A/B): ";
        cin >> stratChar;
    }

    switch (stratChar)
    {
    case 'B':
        demoStrat = new BenevolentStrategy;
        cout << "=====================================" << endl;
        cout << "Demoing benevolent computer strategy." << endl;
        cout << "=====================================" << endl;
        break;
    case 'A':
        demoStrat = new AggressiveStrategy;
        cout << "=====================================" << endl;
        cout << "Demoing aggressive computer strategy." << endl;
        cout << "=====================================" << endl;
        break;
    default:
        demoStrat = new HumanStrategy;
        cout << "=======================" << endl;
        cout << "Demoing human strategy." << endl;
        cout << "=======================" << endl;
    }

    Player* p1 = new Player("P1", demoStrat);
    Player* p2 = new Player("P2", new AggressiveStrategy);
    Player* p3 = new Player("P3", new BenevolentStrategy);

    p1->addCountry(ac1);
    p1->addCountry(ac2);
    p1->addCountry(ac3);
    p2->addCountry(bc1);
    p3->addCountry(bc2);
    p3->addCountry(bc3);

    Deck* d = new Deck(&m);

    for (int i = 0; i < m.getContiSize(); i++)
    {
        for (int j = 0; j < m.getContinent(i)->getCntsSize(); j++)
        {
            cout << m.getContinent(i)->getCountry(j)->getName()
                 << " owned by " << m.getContinent(i)->getCountry(j)->getPlayerName()
                 << " with " << m.getContinent(i)->getCountry(j)->getArmyNum() << "." << endl;
        }
    }

    p1->takeTurn(&m, d);

    return 0;
}
