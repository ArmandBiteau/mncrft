#include <string>
#include <stdexcept>
#include <sstream>
#include <exception>
#include <cstdio>
#include <algorithm>
#include <stdio.h>

#include "Level.hpp"


using std::string;
using std::cout;
using std::endl;


bool Level::output(const Json::Value & value){
    //exemple d'accés à chaque attribut :
  std::cout << value["hello"]  << std::endl;;
  std::cout << value["number"] << std::endl;

    //Pour afficher l'objet entier :
  cout<<"Json print: " <<endl<<value.toStyledString() <<endl;

  return 1;
}



bool Level::toObject(const std::string& stringJson, Json::Value & objectJson){

  //std::cout << "stringJson : " << stringJson << std::endl;
  //std::cout << "objectJson : " << objectJson << std::endl;

  // On parse
  Json::Reader reader;
  bool parsedSuccess = reader.parse(stringJson, objectJson, false);

  if(not parsedSuccess){
    cout<<"Failed to parse JSON"<<endl <<reader.getFormatedErrorMessages() <<endl;
    return 1;
  }

  // Si l'objet contient un tableau, on l'extrait en premier
  const Json::Value array = objectJson["array"];

  //on print les valeurs
  for (unsigned int index = 0; index < array.size(); index++) { // Iterates over the sequence elements.
    cout << "Element " << index << " in array: " << array[index].asString() << endl;
  }

  //Les éléments non contenus dans un tableau
  const Json::Value notAnArray = objectJson["not an array"];

  if(not notAnArray.isNull()){
    cout<<"Not an array: " <<notAnArray.asString() <<endl;
  }

  //On appel "output" qui print l'objet entier
  Level::output(objectJson);

  return 1;

}



bool Level::toString(std::string& stringJson, const Json::Value & objectJson){

  // ecrire l'objet en std::string
  Json::FastWriter fastWriter;
  stringJson = fastWriter.write(objectJson);

  return 1;
}













