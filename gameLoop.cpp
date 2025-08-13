
#include "fileHandling.cpp"
//#include "linkedList.hpp"
class Game
{

public:

    // these need to be redone I'm just testing stuff rn 
    void printGameList()
    {
        //initGame();
        gameList.printList();
    }

    void deleteFront()
    {
        gameList.deleteAtFront();
    }

    void deleteBack()
    {
        gameList.deleteAtBack();
    }

    void deleteSpec()
    {
        gameList.deleteSpecificNode();
    }

    // the main game list populated with commands file
    LinkedList<Data<string, string> > gameList;

    // Sets up environment for the game to begin 
    void initGame()
    {
        LinkedList<Data<string, string> > testList; 
        // testList.insertAtBack(Data<string, string>("example", "example definition")); 

        // testList.insertAtFront(Data<string, string>("second example", "second definition")); 
        // testList.printList(); 
        std::ifstream inputStream("commands.csv");
        gameList = importQuestionsFromFile(inputStream);
    }


   

    
};

 