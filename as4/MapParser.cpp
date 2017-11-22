#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>
#include "MapParser.h"
#include "Map.h"
using namespace std;

InvalidMapException::InvalidMapException() throw(){}

char const * InvalidMapException::what() const throw()
{
    return "invalid map";
}

FileOpenException::FileOpenException() throw(){}
char const * FileOpenException::what() const throw()
{
    return "File could not be opened";
}

MapParser::MapParser() {
    m = new Map;
}
Map* MapParser::getMap(){
    return m;
}
vector<string> MapParser::lineToVector(string line, string delimiter) {
    vector<string> data;
    string token;
    int startPos = 0;
    do {
        token = line.substr(startPos, line.find(delimiter, startPos) - (startPos));
        startPos = startPos + token.length() + 1;
        data.push_back(token);
    } while (startPos < line.length());

    return data;
}

void MapParser::validateMapLine(string line){
    vector<string> data = lineToVector(line, "=");
    regex key("author|image|wrap|scroll|warn");

    if (data.size() != 2) { // must be 2 (key, value)
        throw InvalidMapException();
    }
    if (!regex_match(data[0],key)) {
        throw InvalidMapException();
    }
}


void MapParser::validateContient(vector<string> data){
    regex text("[a-zA-Z ]*");
    regex number("[0-9]*");


    if (data.size() != 2) { // must be 2 (name, value)
        throw InvalidMapException();
    }
    // only need to validate value, name can be anything
    if (!regex_match(data[1],number)) {
        throw InvalidMapException();
    }
}

void MapParser::validateTerritory(vector<string> data){
    regex text("[a-zA-Z.-_ ]*");
    regex number("[0-9]*");

    if (data.size() < 5) { // must be at least 5 long (name, x, y, continent, connected-contries)
        throw InvalidMapException();
    }

    // only need to validate x,y coordinates (names can be anything)
    if (!regex_match(data[1],number)) {
        throw InvalidMapException();
    }
    if (!regex_match(data[2],number)) {
        throw InvalidMapException();
    }
}

void MapParser::createTerriotry(string line) {
    vector<string> data = lineToVector(line, ",");
    validateTerritory(data);

    string name = data[0];
    int x = stoi(data[1]);
    int y = stoi(data[2]);
    string continent = data[3];

    data.erase(data.begin(), data.begin() + 4);
    vector<string> connected = data;

    Country *c = new Country(name);
    m->getContinent(continent)->addCountry(c);

    connections.insert(std::pair<string,vector<string> >(name, connected));
}

void MapParser::createContinent(string line) {
    vector<string> data = lineToVector(line, "=");
    validateContient(data);
    string name = data[0];
    int value = stoi(data[1]);

    Continent *c = new Continent(name, value);
    m->addContinent(c);
}

void MapParser::readFile(string fileName){
    ifstream input(fileName); // open world.map file
    bool mapEntries = 0;
    bool contientEntries = 0;
    bool TerriotryEntries = 0;

    if (input.is_open()) { // make sure file was opened

        string mode = "";
        string line;
        while (!input.eof()) { // loop until end of file
            while (getline(input, line, '\n')) { // get each line from the file
                if (line == "[Map]") { // if line contains only [Map] switch to map mode
                    mode = "map";
                } else if (line == "[Continents]") { // if line contains only [Continents] switch to contients mode
                    mode = "continents";
                } else if (line == "[Territories]") { // if line contains only [Territories] switch to territories mode
                    mode = "territories";
                    // as long as the line isn't empty and the mode is set to something other then map
                } else if (line != "" && mode.compare("") != 0) {
                    // convert the line to a vector. it will contains each peice of data as a seperate entries inside the vector
                    // ie "Argentina,263,407,South America,Peru,Brazil" will become [ Argentina, 263, 407, South America, Peru, Brazil ]
                    if (mode == "map") {
                        validateMapLine(line);
                        mapEntries++;
                    }
                    else if (mode == "continents") {
                        createContinent(line);
                        contientEntries++;
                    }
                    else if (mode == "territories") {
                        createTerriotry(line);
                        TerriotryEntries++;
                    }
                }
            }
        }

        for (std::map<string, vector<string>>::iterator it = connections.begin(); it != connections.end(); ++it)
        {
          Country* country = m->findCountry(it->first);
          vector<string> connected = it->second;
          for(int i = 0; i < connected.size(); i++){
                Country* connectedCountry = m->findCountry(connected[i]);
                m->link(connectedCountry, country);
;          }
        }

        if (contientEntries == 0 || TerriotryEntries == 0) { // could also check if there are map entries but I don't think its nessary
            throw InvalidMapException();
        }
    } else {
        throw FileOpenException();
    }
}
