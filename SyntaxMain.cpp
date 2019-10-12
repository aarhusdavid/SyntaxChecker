#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// https://stackoverflow.com/questions/8004303/missing-template-arguments-before-token?rq=1
// https://www.geeksforgeeks.org/exception-handling-c/

int main (int argc, char **argv)
{
    string input = argv[1];
    string strand;
    //reads files
    ifstream infile;
    infile.open(input);
    GenStack <char> myStack(2);
    int line = 0;
    while(infile.peek() != EOF)
    {
        line++;
        //gets line from file
        for(int i = 0; i < strand.size(); ++i)
        {
            if(strand[i] == '{' || strand[i] == '(' || strand[i] == '[' )
            {
                if(myStack.pop() == '{' && strand[i] == '{')
                    cout << "Error: Missing '}' at end of file" << endl;
                else if(myStack.pop() == '(' && strand[i] == '(')
                    cout << "Error: Missing ')' at line " << line << endl;
                else if(myStack.pop() == '[' && strand[i] == '[')
                    cout << "Error: Missing ']' at line " << line << endl;
                else
                    myStack.push(strand[i]);

            }
        }
    }

    infile.close();
    cout << "File has no errors, congrats!" << endl;
    return 0;

}





    // cout << endl;
    // cout << "Array size : " << myStack.getSize() << endl;
    // myStack.push('0');
    // myStack.push('1');
    // myStack.push('2');
    // myStack.push('3');
    // cout << "Array size : " << myStack.getSize() << endl;
    // myStack.push('4');
    // myStack.push('5');
    // myStack.push('6');
    // myStack.push('7');
    // cout << endl;
    // cout << "Array size : " << myStack.getSize() << endl;
    // cout << "popping : " << myStack.pop() << endl;
    // cout << "popping : " << myStack.pop() << endl;
    // cout << "popping : " << myStack.pop() << endl;
