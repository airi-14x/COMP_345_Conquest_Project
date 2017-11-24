#include <iostream>
#include <ctime>
#include "strategy.h"
using std::cout;
using std::cin;
using std::endl;

/*
 * STRATEGY IMPLEMENTATION
 */

void Strategy::reinforce(int armiesSent, Country* target)
{
    // Uncomment for testing purposes.

    // Add armies to the country and announce its new army count.
    target->setArmyNum(target->getArmyNum() + armiesSent);
}

void Strategy::grantArmies()
{
    // Uncomment for testing purposes.


    // One army for every third country.
    if (playerCountries->size()/3 > 3)
        armies += playerCountries->size()/3;
    else
        armies += 3;

    // A continent's control value for each continent owned entirely.
    for(int i = 0; i < gameMap->getContiSize(); i++)
    {
        bool fullControl = true;

        // Goes through the entire continent, looking for a country not owned by this player.
        // If such a country is found, the country isn't fully controlled by them and they don't get the bonus.
        for(int j = 0; j < gameMap->getContinent(i)->getCntsSize(); j++)
        {
            if(gameMap->getContinent(i)->getCountry(j)->getPlayerName() != playerName)
            {
                fullControl = false;
                break;
            }
        }

        if (fullControl)
        {
            armies += gameMap->getContinent(i)->getControl();
        }
    }

    // Allow the player to exchange cards
    exchangeLoop();
}

int Strategy::determineDiceCount(Country* c)
{
    // Uncomment for testing purposes.

    // Determine max dice count based on offense or defense
    int maxCount;

    // Set max. If attacking, names will match.
    if (c->getPlayerName() == playerName)
    {
        // Set max to no more than 3 and no less than the country's armies + 1.
        maxCount = c->getArmyNum() - 1;

        if (maxCount > 3)
            maxCount = 3;
    }
    else
    {
        // Set max to no more than 2 and no less than the country's armies.
        maxCount = c->getArmyNum();

        if (maxCount > 2)
            maxCount = 2;
    }

    int diceCount;

    // If the owner is human, take input for the actual dice count.
    // Otherwise use max.
    diceCount = maxCount;

    return diceCount;
}

void Strategy::attack(Country* origin, int attackDiceCount, Country* target, int defenseDiceCount)
{
    // Uncomment for testing purposes.
    //// cout << "in strategy attack" << endl;

    int attackRoll1 = 0;
    int attackRoll2 = 0;
    int attackRoll3 = 0;
    int defenseRoll1 = 0;
    int defenseRoll2 = 0;

    switch(attackDiceCount)
    {
    case 3:
        attackRoll3 = playerDice->randomiser();
    case 2:
        attackRoll2 = playerDice->randomiser();
    default:
        attackRoll1 = playerDice->randomiser();
    }

    switch(defenseDiceCount)
    {
    case 2:
        defenseRoll2 = playerDice->randomiser();
    default:
        defenseRoll1 = playerDice->randomiser();
    }

    // Sort the roll results by category and value
    int tempRoll;

    // Make sure attackRoll1 is the biggest attack value
    if (attackRoll2 > attackRoll1 && attackRoll2 >= attackRoll3)
    {
        tempRoll = attackRoll1;
        attackRoll1 = attackRoll2;
        attackRoll2 = tempRoll;
    }
    else if (attackRoll3 > attackRoll1 && attackRoll3 >= attackRoll2)
    {
        tempRoll = attackRoll1;
        attackRoll1 = attackRoll3;
        attackRoll3 = tempRoll;
    }

    // Sort attackRoll2 and 3
    if (attackRoll3 > attackRoll2)
    {
        tempRoll = attackRoll2;
        attackRoll2 = attackRoll3;
        attackRoll3 = tempRoll;
    }

    // Sort defense rolls
    if (defenseRoll2 > defenseRoll1)
    {
        tempRoll = defenseRoll1;
        defenseRoll1 = defenseRoll2;
        defenseRoll2 = tempRoll;
    }

    // Counters to tally lost troops.
    int attackWins = 0;
    int defenseWins = 0;

    if (attackRoll1 > defenseRoll1)
    {
        attackWins++;
    }
    else
    {
        defenseWins++;
    }

    // check second-best dice if both players used two dice or more.
    if (defenseDiceCount == 2 && attackDiceCount >= 2)
    {
        // cout << endl << "Second best attack (" << attackRoll2 << ") vs second best defense (" << defenseRoll2 << "): " << endl;
        if (attackRoll2 > defenseRoll2)
        {
            attackWins++;
            // cout << "Attack wins." << endl;
        }
        else
        {
            defenseWins++;
            // cout << "Defense wins." << endl;
        }
    }

    // Adjust the armies in each country as a result of the attack.
    origin->setArmyNum(origin->getArmyNum() - defenseWins);
    target->setArmyNum(target->getArmyNum() - attackWins);

    // Report on the current state of the attacking country.
    // cout << playerName << " now has " << origin->getArmyNum() << " armies in " << origin->getName() << "." << endl;
    if (origin->getArmyNum() == 1)
        // cout << origin->getName() << " can no longer attack." << endl;

    // Report on the current state of the defending country.
    // If conquered, move troops and transfer ownership.
    // cout << target->getPlayerName() << " now has " << target->getArmyNum() << " armies in " << target->getName() << "." << endl;
    if (target->getArmyNum() == 0)
    {
        // Keep track of the armies selected to move.
        int movedArmies = 0;

        // Inform on the status of the country.
        // cout << endl << origin->getName() << " has been conquered." << endl;

        if (origin->isHuman())
        {
            // cout << playerName << " must move at least " << attackDiceCount << " armies to " << target->getName() << "." << endl;

            // Loop until a valid number of armies is selected.
            while (movedArmies < attackDiceCount || movedArmies >= origin->getArmyNum())
            {
                // cout << "Enter the number of armies to move: ";
                cin >> movedArmies;
            }

            // cout << "Transferring " << movedArmies << " armies from " << origin->getName() << " to " << target->getName() << "." << endl;
            // cout << "Transferring ownership of " << target->getName() << " from " << target->getPlayerName() << " to " << playerName << "." << endl;

            // Transfer ownership and troops.
            string defendingPlayer = target->getPlayerName();

            gameMap->exchangeCountry(target, playerName);

            target->setPlayerName(playerName);

            playerCountries->push_back(target);


            target->setArmyNum(movedArmies);
            origin->setArmyNum(origin->getArmyNum() - movedArmies);
        }
        else
        {
            // Computers move minimum number of armies.
            movedArmies = attackDiceCount;
            // cout << "Transferring " << movedArmies << " armies from " << origin->getName() << " to " << target->getName() << "." << endl;
            // cout << "Transferring ownership of " << target->getName() << " from " << target->getPlayerName() << " to " << playerName << "." << endl;

            // Transfer ownership and troops.
            string defendingPlayer = target->getPlayerName();

            gameMap->exchangeCountry(target, playerName);
            playerCountries->push_back(target);
            target->setArmyNum(movedArmies);
            origin->setArmyNum(origin->getArmyNum() - movedArmies);
        }

        // Mark the player as having earned a card.
        *hasConquered = true;
    }
}

void Strategy::fortify(int armiesSent, Country* origin, Country* target)
{
    // Remove armies from the origin and announce its new army count.
    origin->setArmyNum(origin->getArmyNum() - armiesSent);
    // Add armies to the target and announce its new army count.
    target->setArmyNum(target->getArmyNum() + armiesSent);
}

/*
 * HUMAN STRATEGY IMPLEMENTATION
 */

// Returns false; used for map compatibility.
bool HumanStrategy::isHuman()
{
    return true;
}

void HumanStrategy::exchangeLoop()
{
    // Uncomment for testing purposes.

    // Check how many cards the player has. If more than 5, force an exchange.
    while (playerHand->getSize() > 5)
    {
        // Announce the forced exchange.
        // cout << endl << "The number of cards in hand exceeds 5; cards must be exchanged." << endl << endl;

        playerHand->listCards();

        // Initiate an exchange and add the returned number of armies to the total of armies granted.
        armies += playerHand->exchange();
    }

    if (playerHand->getSize() >= 3)
    {
        // Allow the player to exchange extra cards if desired.
        char exchangeMore = 'n';

        cin >> exchangeMore;
        // cout << endl;

        while(exchangeMore == 'y')
        {
            playerHand->listCards();

            armies += playerHand->exchange();

            // cout << "Would you like to exchange additional cards? y/n ";
            cin >> exchangeMore;
            // cout << endl;
        }
    }

}

void HumanStrategy::reinforceLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    //// cout << "in human reinforce loop" << endl;
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    armies = 0;

    // Get new armies
    grantArmies();

    // Announce the number of armies to reinforce with.
    // cout << armies << " total armies granted." << endl << endl;
    // cout << "Beginning reinforcement phase..." << endl;

    // Reinforce until no armies are left.
    while (armies > 0)
    {
        int armiesSelected;
        string countrySelectedName;
        Country* countrySelected = nullptr;

        bool countryExists = false;

        // Make sure the selected country exists.
        while (countrySelected == nullptr)
        {
            // cout << "Which country do you wish to reinforce? ";
            cin >> countrySelectedName;

            countrySelected = gameMap->findCountry(countrySelectedName);

        }

        /*
         * Confirm that the player has enough armies, otherwise give an error
         * message and let the function terminate.
         */
        if (armiesSelected <= armies && armiesSelected > 0)
        {
            // Marker to validate the presence of the country in the player's collection.
            bool countryValid = false;

            // Check the player's collection, validate if the country is found.
            for (int i = 0; i < playerCountries->size(); i++)
            {
                if (playerCountries->at(i)->getName() == countrySelectedName)
                {
                    countryValid = true;
                    break;
                }
            }

            // If the country is found, add parametized armies to it and subtract them from the player's troops.
            if (countryValid)
            {
                reinforce(armiesSelected, countrySelected);
                armies -= armiesSelected;
            }

        }
    }
}

void HumanStrategy::attackLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    //// cout << "in human attack loop" << endl;
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    char continueAttacking = 'y';

    if (playerCountries->size() != gameMap->getMapSize())
    {
        // cout << "Do you wish to attack? (y/n):";
        cin >> continueAttacking;
    }
    else
    {
        continueAttacking = 'n';
    }

    while (continueAttacking == 'y')
    {
        string countryName;
        Country* origin = nullptr;
        Country* target = nullptr;

        // Make sure the attacking country exists.
        while (origin == nullptr)
        {
            // cout << "Which country do you wish to attack from? ";
            cin >> countryName;

            origin = gameMap->findCountry(countryName);

        }

        // Make sure the defending origin exists.
        while (target == nullptr)
        {

            target = gameMap->findCountry(countryName);

        }

        /*
         * The following conditions must be met for a valid attack:
         * - The attacking country belongs to the attacker.
         * - The defending country does not belong to the attacker.
         * - The two countries are adjacent.
         * - The attacking country has more than 1 army in it.
         */

        // Markers to ensure the attacking country is owned by the correct player
        // and that the attack as a whole is valid.
        bool originValid = false;
        bool attackValid = false;

        // Check the player's collection, validate if the country is found.
        for (int i = 0; i < playerCountries->size(); i++)
        {
            if (playerCountries->at(i)->getName() == origin->getName())
            {
                originValid = true;
                break;
            }
        }

        // Continue if the attacking country is owned by the attacking player.
        if (originValid)
        {
            // Check if the defending country belongs to an opponent.
            if (target->getPlayerName() != playerName)
            {
                // Check if the two countries are adjacent.
                if (gameMap->areAdjacent(origin, target))
                {
                    if (origin->getArmyNum() > 1)
                    {
                        attackValid = true;
                    }
                }
            }
        }

        // If the attack conditions are met
        if (attackValid)
        {
            // Number of dice used by each player.
            int attackDiceCount = determineDiceCount(origin);
            int defenseDiceCount = determineDiceCount(target);

            attack(origin, attackDiceCount, target, defenseDiceCount);
        }

        if (playerCountries->size() != gameMap->getMapSize())
        {
            // cout << "Do you wish to continue attacking? (y/n):";
            cin >> continueAttacking;
        }
        else
        {
            continueAttacking = 'n';
        }
    }
}

void HumanStrategy::fortifyLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    //// cout << "in human fortify loop" << endl;
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    string countryName;
    Country* origin = nullptr;
    Country* target = nullptr;
    bool hasFortified = false;

    char proceed = 'y';

    // cout << "Do you wish to fortify a country? ";
    cin >> proceed;

    if (proceed == 'y')
    {
        while (!hasFortified)
        {
            // Make sure the attacking country exists.
            while (origin == nullptr)
            {
                // cout << endl << "Which country do you wish to fortify from? ";
                cin >> countryName;

                origin = gameMap->findCountry(countryName);

            }

            // Make sure the defending origin exists.
            while (target == nullptr)
            {
                // cout << "Which country do you wish to fortify? ";
                cin >> countryName;

                target = gameMap->findCountry(countryName);

            }

            // Ensure that the fortification is valid.
            bool validFort = gameMap->checkAlliedReach(origin, target);

            // If the fortification is valid, proceed. Otherwise, announce the error.
            if (validFort)
            {
                // cout << target->getName() << " can be fortified from " << origin->getName() << endl;
                // cout << origin->getName() << " has " << origin->getArmyNum() << " armies." << endl;
                // cout << target->getName() << " has " << target->getArmyNum() << " armies." << endl;

                int armiesSent = -1;

                // Ask for armies, must be between 0 and cannot leave a country empty.
                while (armiesSent < 0 || armiesSent >= origin->getArmyNum())
                {
                    // cout << "Send how many armies?" << endl;
                    cin >> armiesSent;
                }

                // Commit to fortification if more than zero armies were sent.
                // Otherwise don't mark fortifications as complete. The user's turn is not over.
                if (armiesSent > 0)
                {
                    fortify(armiesSent, origin, target);
                    hasFortified = true;
                }
            }
        }

    }
}

/*
 * COMPUTER STRATEGY IMPLEMENTATION
 */

// Returns false; used for map compatibility.
bool ComputerStrategy::isHuman()
{
    return false;
}

// Exchanges as many cards as possible
void ComputerStrategy::exchangeLoop()
{
    // Uncomment for testing purposes.

    int infCards = 0;
    int artCards = 0;
    int cavCards = 0;

    // Count cards
    for (int i = 0; i < playerHand->getSize(); i++)
    {
        switch(playerHand->cardAt(i)->getCardType())
        {
        case ct_infantry:
            infCards++;
            break;
        case ct_artillery:
            artCards++;
            break;
        default:
            cavCards++;
        }
    }

    // Loop as long as an exchange is possible
    while((infCards >= 1 && artCards >= 1 && cavCards >= 1) || infCards >= 3 || artCards >= 3 || cavCards >= 3)
    {
        int firstIndex = -1;
        int secondIndex = -1;
        int thirdIndex = -1;

        // Find the first three indices relevant to the first possible kind of exchange.
        if (infCards >= 1 && artCards >= 1 && cavCards >= 1)
        {
            for (int i = 0; i < playerHand->getSize(); i++)
            {
                // Seek out one of each card type.
                switch(playerHand->cardAt(i)->getCardType())
                {
                case ct_infantry:
                    firstIndex = i;
                    break;
                case ct_artillery:
                    secondIndex = i;
                    break;
                default:
                    thirdIndex = i;
                }
            }

            // Take the cards out of the count
            infCards--;
            artCards--;
            cavCards--;
        }
        else if(infCards >= 3)
        {
            for (int i = 0; i < playerHand->getSize(); i++)
            {
                // Seek out three infantry cards.
                if (playerHand->cardAt(i)->getCardType() == ct_infantry)
                {
                    if (firstIndex == -1)
                        firstIndex = i;
                    else if (secondIndex == -1)
                        secondIndex = i;
                    else
                        thirdIndex = i;
                }
            }

            // Take the cards out of the count
            infCards -= 3;
        }
        else if(artCards >= 3)
        {
            for (int i = 0; i < playerHand->getSize(); i++)
            {
                // Seek out three artillery cards.
                if (playerHand->cardAt(i)->getCardType() == ct_artillery)
                {
                    if (firstIndex == -1)
                        firstIndex = i;
                    else if (secondIndex == -1)
                        secondIndex = i;
                    else
                        thirdIndex = i;
                }
            }

            // Take the cards out of the count
            artCards -= 3;
        }
        else
        {
            for (int i = 0; i < playerHand->getSize(); i++)
            {
                // Seek out three cavalry cards.
                if (playerHand->cardAt(i)->getCardType() == ct_cavalry)
                {
                    if (firstIndex == -1)
                        firstIndex = i;
                    else if (secondIndex == -1)
                        secondIndex = i;
                    else
                        thirdIndex = i;
                }
            }

            // Take the cards out of the count
            cavCards -= 3;
        }

        armies += playerHand->exchange(firstIndex, secondIndex, thirdIndex);
    }
}

/*
 * AGGRESSIVE STRATEGY IMPLEMENTATION
 */

// Reinforces the strongest owned that can attack
void AggressiveStrategy::reinforceLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    armies = 0;

    // Get new armies
    grantArmies();

    // Find country with the most armies owned by this player, ignoring countries with no enemy neighbours
    int strongestIndex = 0;

    for (int i = 0; i < playerCountries->size(); i++)
    {
        // Check for enemy neighbours
        for (int j = 0; j < gameMap->getContiSize(); j++)
        {
            for (int k = 0; k < gameMap->getContinent(j)->getCntsSize(); k++)
            {
                if (gameMap->areAdjacent(gameMap->getContinent(j)->getCountry(k), playerCountries->at(i)) &&
                    gameMap->getContinent(j)->getCountry(k)->getPlayerName() != playerName)
                {
                    // Compare army sizes
                    if (playerCountries->at(i)->getArmyNum() > playerCountries->at(strongestIndex)->getArmyNum());
                    {
                        strongestIndex = i;
                    }
                }
            }
        }
    }

    //send all available armies to the strongest country owned by this player.
    reinforce(armies, playerCountries->at(strongestIndex));
}

// Attacks as many times as possible with strongest country
void AggressiveStrategy::attackLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Find country with the most armies owned by this player
    int strongestIndex = 0;

    for (int i = 0; i < playerCountries->size(); i++)
    {
        // Compare army sizes
        if (playerCountries->at(i)->getArmyNum() > playerCountries->at(strongestIndex)->getArmyNum());
        {
            strongestIndex = i;
        }
    }

    bool canAttack = true;

    // Make sure there are enemy countries left on the map.
    if (playerCountries->size() == gameMap->getMapSize())
    {
        canAttack = false;
    }

    // Attack until no longer possible
    while(canAttack && playerCountries->at(strongestIndex)->getArmyNum() > 1)
    {
        Country* target = playerCountries->at(strongestIndex);

        // Check for enemy neighbours if the previous target is now allied
        if (target->getPlayerName() == playerName)
        {
            for (int j = 0; j < gameMap->getContiSize(); j++)
            {
                for (int k = 0; k < gameMap->getContinent(j)->getCntsSize(); k++)
                {
                    // If enemy and neighbour
                    if (gameMap->areAdjacent(gameMap->getContinent(j)->getCountry(k), playerCountries->at(strongestIndex)) &&
                        gameMap->getContinent(j)->getCountry(k)->getPlayerName() != playerName)
                    {
                        target = gameMap->getContinent(j)->getCountry(k);
                    }
                }
            }
        }

        // If a new target is found, attack, otherwise exit loop.
        if (target->getPlayerName() != playerName)
        {
            // Attack target until conquered or no more armies.
            while(target->getPlayerName() != playerName && playerCountries->at(strongestIndex)->getArmyNum() > 1)
            {
                int attackDiceCount = determineDiceCount(playerCountries->at(strongestIndex));
                int defenseDiceCount = determineDiceCount(target);

                attack(playerCountries->at(strongestIndex), attackDiceCount, target, defenseDiceCount);
            }
        }
        else
            canAttack = false;
    }
}

// Reinforces the strongest country with neighbouring enemies from the second strongest country.
void AggressiveStrategy::fortifyLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Find country with the most armies owned by this player, ignoring countries with no enemy neighbours
    int strongestIndex = 0;

    for (int i = 0; i < playerCountries->size(); i++)
    {
        // Check for enemy neighbours
        for (int j = 0; j < gameMap->getContiSize(); j++)
        {
            for (int k = 0; k < gameMap->getContinent(j)->getCntsSize(); k++)
            {
                if (gameMap->areAdjacent(gameMap->getContinent(j)->getCountry(k), playerCountries->at(i)) &&
                    gameMap->getContinent(j)->getCountry(k)->getPlayerName() != playerName)
                {
                    // Compare army sizes
                    if (playerCountries->at(i)->getArmyNum() > playerCountries->at(strongestIndex)->getArmyNum());
                    {
                        strongestIndex = i;
                    }
                }
            }
        }
    }

    int secondStrongestIndex = 0;

    // Check allied countries.
    for (int i = 0; i < playerCountries->size(); i++)
    {
        // Compare army sizes
        if (playerCountries->at(i)->getArmyNum() > playerCountries->at(secondStrongestIndex)->getArmyNum() &&
            i != strongestIndex &&
            gameMap->checkAlliedReach(playerCountries->at(secondStrongestIndex), playerCountries->at(strongestIndex)));
        {
            secondStrongestIndex = i;
        }
    }

    // Fortify with as many armies as possible.
    fortify(playerCountries->at(secondStrongestIndex)->getArmyNum() - 1, playerCountries->at(secondStrongestIndex), playerCountries->at(strongestIndex));
}

/*
 * BENEVOLENT STRATEGY IMPLEMENTATION
 */

// Reinforces weakest countries in round-robin
void BenevolentStrategy::reinforceLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    armies = 0;

    // Get new armies
    grantArmies();

    int weakestIndex = 0;

    while (armies > 0)
    {
        for (int i = 0; i < playerCountries->size(); i++)
        {
            if (playerCountries->at(i)->getArmyNum() <= playerCountries->at(weakestIndex)->getArmyNum())
            {
                weakestIndex = i;
            }
        }

        reinforce(1, playerCountries->at(weakestIndex));
        armies--;
    }
}

// Benevolent computers never attack
void BenevolentStrategy::attackLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;
}

// Moves armies from strongest country to weakest country so their army count is equal
void BenevolentStrategy::fortifyLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    int strongestIndex = 0;
    int weakestIndex = 0;
    bool goodPair = false;

    vector<int> checked;

    while (!goodPair)
    {
        // Find weakest country.
        for (int i = 0; i < playerCountries->size(); i++)
        {
            if (playerCountries->at(i)->getArmyNum() <= playerCountries->at(weakestIndex)->getArmyNum())
            {
                // Ensure the index hasn't failed previously.
                for (int j = 0; j < checked.size(); j++)
                {
                    if (checked.at(j) != i)
                    {
                        weakestIndex = i;
                    }
                }
            }
        }

        // Find the strongest country that can fortify the weakest.
        for (int i = 0; i < playerCountries->size(); i++)
        {
            if (playerCountries->at(i)->getArmyNum() >= playerCountries->at(strongestIndex)->getArmyNum() &&
                gameMap->checkAlliedReach(playerCountries->at(i), playerCountries->at(weakestIndex)))
            {
                strongestIndex = i;
            }
        }

        // Check if strongest is stronger than weakest.
        if (playerCountries->at(weakestIndex)->getArmyNum() < playerCountries->at(strongestIndex)->getArmyNum())
        {
            goodPair = true;
        }
        else
        {
            // If no valid pair was found, take note of the unusable weakest country index.
            checked.push_back(weakestIndex);
        }

        // If no fortification fitting the benevolent strategy is available, exit the loop.
        if (checked.size() == playerCountries->size())
        {
            break;
        }
    }

    // If a valid fortification was found, do it
    if (goodPair)
    {
        int armiesSent = (playerCountries->at(strongestIndex)->getArmyNum() - playerCountries->at(weakestIndex)->getArmyNum())/2;

        if (armiesSent > 0)
        {
            fortify(armiesSent, playerCountries->at(strongestIndex), playerCountries->at(weakestIndex));
        }
    }

}

/*
 * RANDOM STRATEGY IMPLEMENTATION
 */

// Reinforces random countries with a random amount of armies.
void RandomStrategy::reinforceLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    armies = 0;

    // Get new armies
    grantArmies();

    int targetIndex;
    int armiesSent;

    while (armies > 0)
    {
        // Select a country at random
        targetIndex = rand() % playerCountries->size(); // [0, countries owned - 1]

        // Select a random number of armies.
        armiesSent = (rand() % armies) + 1; // [0, armies - 1] + 1 = [1, armies]

        // Update total army count.
        armies -= armiesSent;

        reinforce(armiesSent, playerCountries->at(targetIndex));
    }
}

// Attacks a random country a random number of times.
void RandomStrategy::attackLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Make a list of countries that have enemy neighbours and enough armies to attack.
    vector<Country*> validAttackers;

    for (int k = 0; k < playerCountries->size(); k++)
    {
        bool added = false;

        for (int i = 0; i < gameMap->getContiSize(); i++)
        {
            for (int j = 0; j < gameMap->getContinent(i)->getCntsSize(); j++)
            {
                // If the two countries are adjacent, opponents, and the attacker's country can attack...
                if (gameMap->areAdjacent(playerCountries->at(k), gameMap->getContinent(i)->getCountry(j)) &&
                    gameMap->getContinent(i)->getCountry(j)->getPlayerName() != playerName &&
                    playerCountries->at(k)->getArmyNum() > 1)
                {
                    validAttackers.push_back(playerCountries->at(k));
                    added = true;
                }

                // If the country has already been added, go to the next one to avoid repetitions
                if (added)
                {
                    break;
                }
            }

            // If the country has already been added, go to the next one to avoid repetitions
            if (added)
            {
                break;
            }
        }
    }

    // Select a random country from the previous list
    Country* origin = validAttackers.at(rand() % validAttackers.size());

    // Make a list of enemy countries neighbouring the attacking country.
    vector<Country*> validDefenders;

    for (int i = 0; i < gameMap->getContiSize(); i++)
    {
        for (int j = 0; j < gameMap->getContinent(i)->getCntsSize(); j++)
        {
            // If the two countries are adjacent, opponents, and the attacker's country can attack...
            if (gameMap->areAdjacent(origin, gameMap->getContinent(i)->getCountry(j)) &&
                gameMap->getContinent(i)->getCountry(j)->getPlayerName() != playerName)
            {
                validDefenders.push_back(gameMap->getContinent(i)->getCountry(j));
            }
        }
    }

    // Select a random country from the previous list
    Country* target = validDefenders.at(rand() % validDefenders.size());

    bool keepAttacking = true;

    while (keepAttacking)
    {
        // Set up the attack
        int attackDiceCount = determineDiceCount(origin);
        int defenseDiceCount = determineDiceCount(target);

        // Attack
        attack(origin, attackDiceCount, target, defenseDiceCount);

        // Randomly decide to attack again or not if an attack is possible.
        if (origin->getArmyNum() > 1 && target->getPlayerName() != playerName)
        {
            int decision = rand() % 2; // [0,1]

            if (decision != 1)
            {
                keepAttacking = false;
            }
        }
        else
        {
            keepAttacking = false;
        }
    }
}

// Fortifies from a random country to a random country by a random amount.
void RandomStrategy::fortifyLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Find all friendly countries that have neighbours.
    vector<Country*> possibleOrigins;

    for (int i = 0; i < playerCountries->size(); i++)
    {
        // If the current country has enough armies to fortify
        if (playerCountries->at(i)->getArmyNum() > 1)
        {
            for (int j = 0; j < playerCountries->size(); j++)
            {
                // If the second country and the second country are connected
                if (i != j &&
                    gameMap->checkAlliedReach(playerCountries->at(i), playerCountries->at(j)))
                {
                    // Add the country to the list and leave the loop to avoid repetition
                    possibleOrigins.push_back(playerCountries->at(i));
                    break;
                }
            }
        }
    }

    // Only continue if there are possible origins.
    if (possibleOrigins.size() > 0)
    {
        // Select a random country from the list of valid fortifiers
        Country* origin = possibleOrigins.at(rand() % possibleOrigins.size());

        // Find all friendly countries that are connected to the selected origin.
        vector<Country*> possibleTargets;

        for (int i = 0; i < playerCountries->size(); i++)
        {
            // If the selected country isn't the origin and can be reached from the origin, add it to the list.
            if (origin->getName() != playerCountries->at(i)->getName() &&
                gameMap->checkAlliedReach(origin, playerCountries->at(i)))
            {
                possibleTargets.push_back(playerCountries->at(i));
            }
        }

        // Only continue if there are possible targets.
        if (possibleTargets.size() > 0)
        {
            // Select a target from the new list.
            Country* target = possibleTargets.at(rand() % possibleTargets.size());

            // Select the number of armies to fortify with
            int armiesSent = rand() % origin->getArmyNum();

            // Fortify
            fortify(armiesSent, origin, target);
        }
    }
}

/*
 * CHEATER STRATEGY IMPLEMENTATION
 */

// Doubles armies on all countries owned by this player
void CheaterStrategy::reinforceLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Iterate through all countries owned by this player
    for (int i = 0; i < playerCountries->size(); i++)
    {
        // Double each country's army number.
        playerCountries->at(i)->setArmyNum(playerCountries->at(i)->getArmyNum() * 2);
    }
}

// Conquers all neighbours of all neighbouring enemy countries.
void CheaterStrategy::attackLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Make a list of all enemy neighbours
    vector<Country*> enemyNeighbours;


    for (int i = 0; i < gameMap->getContiSize(); i++)
    {
        for (int j = 0; j < gameMap->getContinent(i)->getCntsSize(); j++)
        {
            // If the country is an enemy, check if it's a neighbour and if so conquer it.
            if (gameMap->getContinent(i)->getCountry(j)->getPlayerName() != playerName)
            {
                for (int k = 0; k < playerCountries->size(); k++)
                {
                    if (gameMap->areAdjacent(gameMap->getContinent(i)->getCountry(j), playerCountries->at(k)))
                    {
                        // cout << endl << gameMap->getContinent(i)->getCountry(j)->getName() << " has been conquered by " << playerName << endl;
                        Country* country = gameMap->getContinent(i)->getCountry(j);
                        enemyNeighbours.push_back(country);

                        gameMap->exchangeCountry(country, playerName);

                        *hasConquered = true;

                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < enemyNeighbours.size(); i++){
        playerCountries->push_back(enemyNeighbours[i]);
    }
}

// Doubles the number of armies on countries that have enemy neighbours.
void CheaterStrategy::fortifyLoop(string playerName,vector<Country*>* playerCountries, Hand* playerHand, Dice* playerDice, bool* hasConquered, Map* gameMap, Deck* gameDeck)
{
    // Uncomment for testing purposes.
    // Initialize all members
    this->playerCountries = playerCountries;
    this->playerHand = playerHand;
    this->playerDice = playerDice;
    this->playerName = playerName;
    this->gameMap = gameMap;
    this->gameDeck = gameDeck;
    this->hasConquered = hasConquered;

    // Find all friendly countries that have enemy neighbours.
    vector<Country*> countriesToFortify;

    // Iterate through own countries.
    for (int i = 0; i < playerCountries->size(); i++)
    {
        bool added = false;

        // Iterate through all countries, checking for enemy neighbours.
        for (int j = 0; j < gameMap->getContiSize(); j++)
        {
            for (int k = 0; k < gameMap->getContinent(j)->getCntsSize(); k++)
            {
                if (gameMap->getContinent(j)->getCountry(k)->getPlayerName() != playerName &&
                    gameMap->areAdjacent(gameMap->getContinent(j)->getCountry(k), playerCountries->at(i)))
                {
                    countriesToFortify.push_back(playerCountries->at(i));
                    added = true;
                }

                // Break out of loop if this country has already been validated.
                if (added)
                {
                    break;
                }
            }

            // Break out of loop if this country has already been validated.
            if (added)
            {
                break;
            }
        }
    }

    for (int i = 0; i < countriesToFortify.size(); i++)
    {
        // Double each country's army number.
        countriesToFortify.at(i)->setArmyNum(countriesToFortify.at(i)->getArmyNum() * 2);
    }
}
