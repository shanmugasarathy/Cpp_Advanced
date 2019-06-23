#include <iostream>

using namespace std;

//Sarathy: Throw a standard exception type std:bad_alloc()
// it implements by default what() method.
// these are derived from base class "exception"


void operation_produce_error()
{
    bool error = true;

    cout << " operation_produce_error " << endl;

    if(error == true)
    {
        throw std::bad_alloc();
    }

}


int main()
{

    cout << " Main " << endl;

    try{
        operation_produce_error();
    }

    catch(bad_alloc &e) {
        cout << " Error  " << e.what() << endl;
    }

    catch(const char *e) {
        cout << " Error descp: " << e << endl;
    }

    cout << " Main continue operation" << endl;

    return 0;

}