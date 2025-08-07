#include <fstream>
#include <string>
#include "linkedList.hpp"
#include "data.hpp"
#include <iostream> 

LinkedList<Data<string, string> > importQuestionsFromFile(ifstream& fileName)
{
    LinkedList<Data<string, string> > returnList; 
    std::string cmdBuffer, defBuffer, pointValue;
    int intPointVal; 
    while(getline(fileName, cmdBuffer, ','))
    {
        getline(fileName, defBuffer, ','); // definition 
        getline(fileName, pointValue); // point value
        
        //intPointVal = stoi(pointValue); 
        returnList.insertAtBack(Data<string, string>(cmdBuffer, defBuffer, stoi(pointValue)));
        //std::cout << "Able to insert" << endl; 
    }
    return returnList; 
}