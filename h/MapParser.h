#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Map.h"
using namespace std;


class InvalidMapException : public std::runtime_error
{
public:
    InvalidMapException() throw();
    virtual char const* what() const throw();
};

class FileOpenException : public std::runtime_error
{
public:
    FileOpenException() throw();
    virtual char const* what() const throw();
};

class MapParser {
        Map *m;
	private:
		vector<string> lineToVector(string line, string delimiter);
		void validateMapLine(string line);
		void validateContient(vector<string> data);
		void validateTerritory(vector<string> data);
		void createTerriotry(string line);
		void createContinent(string line);
	public:
		MapParser();
		void readFile(string fileName);
};

#endif

