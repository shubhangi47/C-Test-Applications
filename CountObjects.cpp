#include <iostream>
#include <string>

class Countobj
{
private:
    std::string objId;
    static int nObjcon; // number of object constructor
    static int nObjdes; // number of object destructor
public:
    Countobj(const std::string &id) : objId(id)
    {
        ++nObjcon;
        std::cout << " ctor: " << objId << std::endl;
        getLiveObjCount();
    }
    ~Countobj()
    {
        ++nObjdes;
        std::cout << " dtor: " << objId << std::endl;
        getLiveObjCount();
    }
    static int getObjcreated()
    {
        return nObjcon;
    }

    static int getObjdestroyed()
    {
        return nObjdes;
    }

    static int getLiveObjCount()
    {
        int liveobj = nObjcon - nObjdes;
        std::cout << "live objects = " << liveobj << std::endl;
        return liveobj;
    }
};

int Countobj::nObjcon = 0;
int Countobj::nObjdes = 0;

/* Before main, lets count objects*/
int beforemainObjno = Countobj::getLiveObjCount();
Countobj objbeforemain("objbeforemain");

int main()
{
    Countobj::getLiveObjCount();
    Countobj obj1("obj1");
    Countobj obj2("obj2");
    Countobj *obj3 = new Countobj("obj3");
    {
        Countobj obj4("obj4");
        delete obj3;
    }
    Countobj::getLiveObjCount();

    return 0;
}

/* Output
live objects = 0    // before any object 
 ctor: objbeforemain
live objects = 1    // before main
live objects = 1
 ctor: obj1        // entered in main 
live objects = 2
 ctor: obj2
live objects = 3
 ctor: obj3
live objects = 4
 ctor: obj4
live objects = 5
 dtor: obj3
live objects = 4
 dtor: obj4
live objects = 3
live objects = 3
 dtor: obj2
live objects = 2   
 dtor: obj1
live objects = 1   // exited main
 dtor: objbeforemain
live objects = 0
*/