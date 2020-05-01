#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int box[1000] = { 0 };
int boxptr = 0;
string command;
int commandnumber = 0;

void push(int a){
    box[boxptr] = a;
    boxptr++;
}

void pop(){
    if (boxptr > 0)
        {
            cout<<box[boxptr - 1]<<endl;
            boxptr--;
        }
}

void peek(){
    if (boxptr > 0)
    cout<<box[boxptr - 1]<<endl;
}

void empty(){
    if (boxptr == 0)
    cout<<"empty"<<endl;
    else
    cout<<"not empty"<<endl;
}

int main()
{
    while (1) {

        cin>>command;
        

        if (command == "push")
        {
            cin>>commandnumber;
            push(commandnumber);
        }

        if (command == "pop")
        {
            pop();
        }

        if (command == "peek")
        {
            peek();
        }

        if (command == "empty")
        {
            empty();
        }

        if (command == "break")
        {
            return 0;
        }


    }
}