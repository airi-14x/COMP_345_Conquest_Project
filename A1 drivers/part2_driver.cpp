#include "MapParser.h"

int main() {
	vector<string> mapFiles = { "World.map", "Alabama.map", "Aden.map", "AdvantageComputer.map", "Africa.map",
								"invalid1.map", "invalid2.map", "invalid3.map", "invalid4.map" };

	for (int i = 0; i < mapFiles.size(); i++) {
		MapParser m;
		try {
			m.readFile("map/" + mapFiles[i]);
			cout << mapFiles[i] << " was valid" << endl;
		} catch (InvalidMapException e){
			cout << mapFiles[i] << " was not valid" << endl;
		} catch (FileOpenException e) {
			cout << mapFiles[i] << " could not be opened" << endl;
		}
	}

	cin.ignore();
    return 0;
}

