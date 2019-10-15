#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char **argv) //main method
{
    int bol = 1; //var for while loop
    while(bol == 1) //while program is running
    {
        string input = argv[1]; //takes in command line argument
        string strand; // initializes strand
        ifstream infile; //enables reading files
        infile.open(input); //opens input file
        GenStack <char> myStack(2); //creates stack
        int line = 0; //var for line count
        while(infile.peek() != EOF) //while input file has lines
        {
            getline(infile, strand); //gets line from file
            ++line; //increments line counter
            for(int i = 0; i < strand.size(); ++i) //iterates through whole line
            {
                if(strand[i] == '{' || strand[i] == '(' || strand[i] == '[' || strand[i] == '}' || strand[i] == ')' || strand[i] == ']' ) //enters if comes across delimiter
                {
                    if(myStack.isEmpty()) // if stack is empty
                    {
                        myStack.push(strand[i]); //push element to top
                    }
                    else if(myStack.peek() == '{' && strand[i] != '}') // checks {} condition
                    {
                        cout << "Error: Missing '}' at line " << line << "." << endl; //tells user where error is
                        infile.close(); //closes file
                        exit(0); //exits program
                    }
                    else if(myStack.peek() == '(' && strand[i] != ')') // checks () condition
                    {
                        cout << "Error: Missing ')' at line " << line-1 << "."  << endl; //tells user where error is
                        infile.close(); //closes file
                        exit(0); //exits program
                    }
                    else if(myStack.peek() == '[' && strand[i] != ']') // checks {} condition
                    {
                        cout << "Error: Missing ']' at line " << line-1 << "."  << endl; //tells user where error is
                        infile.close(); //closes file
                        exit(0); //exits program
                    }
                    myStack.push(strand[i]); //push element to top
                }
            }
        }

        getline(infile, strand); //gets last line of file
        if(strand[0] != '}') // if last line doesnt have a }
        {
            cout << "Error: Missing '}' at the end of the file" << endl;
            infile.close(); //closes file
            exit(0); //exits program
        }

        bol = 2; //exits while loop
        infile.close(); //closes file
    }


    string ans; //initializes user input
    cout << "Delimiter syntax is correct" << endl;
    cout << "Would you like to analyze another file? (yes/no)" << endl;
    cout << "If you choose yes, simply type './a.out' followed by the name of your desired file. (eg. ./a.out foo.cpp). " << endl;
    cin >> ans; //takes in user input

    if (ans == "no")
    {
        exit(0); //exits program
    }
    else if (ans == "yes")
    {
        bol = 1; //loops back to beginning of the program
    }
    return 0;

}
