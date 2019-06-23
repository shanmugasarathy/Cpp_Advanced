#include <iostream>

using namespace std;

class MyError: public exception
{

public:
//Sarathy: this method cannot throw an exception
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
        // Sarathy: no need to use new and delete
        // exception spec defines direct class usage
        // new and delete are taken care implicitly
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

    catch(const MyError e) {
        cout << " Error descp: " << e.what() << endl;
    }

    cout << " Main continue operation" << endl;

    return 0;

}