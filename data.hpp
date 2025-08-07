
template <class C, class D>
// C for command, D for definition 
class Data
{
private:
    C cmd;
    D def; 
    int pointVal; 

public:

    Data(C newCmd = "\0", D newDef = "\0", int newPointVal = 0)
    {
        cmd = newCmd;
        def = newDef; 
        pointVal = newPointVal;
        //cout << "Data constructor called!" << endl; 
    }

    friend ostream& operator<<(ostream& lhs, Data& rhs)
    {
        lhs << "Command: " << rhs.cmd << " " << "Definition: " << rhs.def << endl; 
        return lhs; 
    }

}; 

