#include <string>
#include <stdexcept>
#include <sstream>

#include "File.hpp"
#include "Level.hpp"





int main(int argc, char** argv) {


    std::string stringJson = "{\"hello\":\"world\",\"number\":12,\"marche\":true,\"marchePas\":false}";

    File::write("../data.json", stringJson);

    File::read("../data.json", stringJson);

    Json::Value objectJson;

    Level::toObject(stringJson, objectJson);


	Json::Value newArray;
	array.append("Cube1");
	array.append("Cube2");

	objectJson["Listes des Cubes"] = newArray;

    Level::toString(stringJson, objectJson);

    File::write("../data.json", stringJson);

    return 0;
}
