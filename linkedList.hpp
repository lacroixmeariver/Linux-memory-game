using namespace std; 
template <class T>
class LinkedList
{


private:
    // packaging up the contents of the node within this same class
    struct Node 
    {
        T data;
        Node* ptrNext; 
        Node* ptrPrev; 
        Node(T newData){
            data = newData;
            ptrNext = nullptr;
            ptrPrev = nullptr; 
        }
    };

    // pointer to a node that acts as the start of the list 
    Node* listHead; 
    int size; 

public:
    LinkedList()
    {
        listHead = nullptr; 
        size = 0; 
        //std::cout << "List created" << std::endl; // debug print 
    }

    ~LinkedList()
    {
        //cout << "Linked list destructor called!" << endl;
        //delete listHead; 
    }

    T printHead()
    {
        cout << "Data associated with head of list is: " << listHead->data << endl;
        return listHead->data;  
    }

    void printList()
    {
        Node* tempNodePtr = listHead; 
        for(int i = 0; i < size; i++)
        {
            cout << tempNodePtr->data << endl; 
            tempNodePtr = tempNodePtr->ptrNext; 
        }
    }
    bool isListEmpty()
    {
        return listHead; 
    }

    Node* insertAtBack(T newData)
    {
        Node* nodeToAdd = new Node(newData);
        if (!isListEmpty())
        {
            listHead = nodeToAdd;
            size++; 
            return listHead; 
        }
        
        Node* tempNodePtr = listHead;  
        while(tempNodePtr->ptrNext)
        {
            tempNodePtr = tempNodePtr->ptrNext; 
            // after this tempNodePtr should be the last node in the list 
        }        
        
        tempNodePtr->ptrNext = nodeToAdd; // connecting the next pointer
        nodeToAdd->ptrPrev = tempNodePtr; // connecting the previous pointer
        size++; 
        return nodeToAdd; 
    }

    Node* insertAtFront(T newData)
    {
        Node* nodeToAdd = new Node(newData);
        if (!isListEmpty())
        {
            listHead = nodeToAdd;
            size++;
            return listHead; 
        }
        nodeToAdd->ptrNext = listHead; 
        listHead = nodeToAdd; 
        size++;
        return nodeToAdd; 
    }

    Node* deleteAtFront()
    {
        if (!isListEmpty())
        {
            cout << "No items currently in the list, nothing to delete." << endl;
        }

        Node* tempNodePtr = listHead; 
        listHead = tempNodePtr->ptrNext;
        listHead->ptrPrev = nullptr; 
        delete tempNodePtr; 
        size--;
        return listHead; 
    }

    Node* deleteAtBack()
    {
        if (!isListEmpty())
        {
            cout << "No items currently in the list, nothing to delete." << endl;
        }
        Node* tempNodePtr = listHead;
        while(tempNodePtr)
        {
            if (tempNodePtr->ptrNext == nullptr)
            {
                break; 
            }
            tempNodePtr = tempNodePtr->ptrNext;
        }
        Node* tempPrevPtr = tempNodePtr; // to keep track of the last node in the list 
        //cout << "Temp ptr is " << tempPrevPtr->data << endl; 
        delete tempNodePtr;
        //tempPrevPtr->ptrNext = nullptr; 
        size--; 
        return tempPrevPtr; 
    }

    Node* deleteSpecificNode()
    {
        system("clear"); 
        int menuChoice = -1;
        cout << "**************************** Node Removal ****************************" << endl;
         
        while(menuChoice != 0)
        {
            
            cout << "[1] List all nodes available to delete " << endl << "[2] I know which number node I wish to delete. " << endl << "[0] Back to main menu " << endl;   
            cin >> menuChoice;
            if (menuChoice > 2 || menuChoice < 0)
            {
                cout << "[1] List all nodes available to delete " << endl << "[2] I know which number node I wish to delete. " << endl << "[0] Back to main menu " << endl;   
                cin >> menuChoice;
            }

            switch(menuChoice) 
            { 
                case 0:
                {
                    //break; 
                    return nullptr; 
                }
                case 1: 
                {
                    system("clear"); 
                    int i = 1; 
                    Node* tempNodePtr = listHead; 
                    for(int j = 0; j < size; j++)
                    {
                        cout << "[" << i << "] " <<  tempNodePtr->data << endl; 
                        tempNodePtr = tempNodePtr->ptrNext;
                        i++; 
                    }
                    break;
                }
                case 2:
                {
                    cout << "Please enter ID number of node you wish to delete: " << endl;
                    cin >> menuChoice;
                    while (menuChoice > size || menuChoice < 1)
                    {
                        cout << "Invalid number chosen." << endl;
                        cout << "Please enter ID number of node you wish to delete: " << endl;
                        cin >> menuChoice;
                    }

                    deleteSpecHelper(menuChoice);
                    break;
                }
            }
        
            
        }

    }

    // returns a pointer to the node prior to the deleted node
    Node* deleteSpecHelper(int n)
    {
        cout << "n = " << n << endl;
        if (n == 1)
        {
            return deleteAtFront();
           
        }
        if (isListEmpty())
        {
            Node* tempNodePtr = listHead; 
            for(int i = 1; i < n; i++)
            {
                tempNodePtr = tempNodePtr->ptrNext; 
                cout << i << endl; 
            }
            cout << tempNodePtr->data << " " << tempNodePtr->ptrPrev << " " << tempNodePtr->ptrNext << endl; 
            Node* tempPrev;
            Node* tempNext;
            tempPrev = tempNodePtr->ptrPrev; 
            tempNext = tempNodePtr->ptrNext; 
            //cout << endl << tempPrev->data << " " << tempNext->data << endl;
            tempPrev->ptrNext = tempNext; 
            tempNext->ptrPrev = tempPrev;
            delete tempNodePtr;
            size--; 
            return tempPrev; 
            
        }
            
        
        
        
    }
        
}; 