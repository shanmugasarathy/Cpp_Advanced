#include <iostream>

using namespace std;

//Sarathy: Order of the catch is important if the error types 
// caught are derived from exceptions (base).
// If both the base and dervied types are in catch blocks.


// custom type derived from std class exception
class MyError: public exception
{

public:
// Sarathy: this method cannot throw an exception
// const throw() alts the program at runtime
 virtual const char * what() const throw()
 {
     return "Its MyError ";
 }

};

void operation_produce_error()
{
    bool error = true;

    cout << " operation_produce_error " << endl;

    if(error == true)
    {
        throw MyError();
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

    // Sarathy: order of custom type MyError should
    // be before exception
    catch(const MyError &e) {
        cout << "Type MyError, Error descp: " << e.what() << endl;
    }

    catch(const exception &e) {
        cout << "Type exception(): Error descp: " << e.what() << endl;
    }

    cout << " Main continue operation" << endl;

    return 0;

}