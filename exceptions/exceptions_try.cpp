#include <iostream>

using namespace std;

//Sarathy: Try, Catch and Throw operations
// Types of Errors can be threw and caught


void operation_produce_error()
{
    bool error = true;

    cout << " operation_produce_error " << endl;

    if(error == true)
    {
        throw "something is wrong";
    }

}

void wrapper_operation_produce_error()
{
    cout << " wrapper_operation_produce_error " << endl;
    operation_produce_error();
}

int main()
{

    cout << " Main " << endl;

    try{
        wrapper_operation_produce_error();
    }

    catch(int e) {
        cout << " Error code " << e << endl;
    }

    catch(const char *e) {
        cout << " Error descp: " << e << endl;
    }

    cout << " Main continue operation" << endl;

    return 0;

}