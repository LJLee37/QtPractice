#include <iostream>
#include <string>
using namespace std;

double number1 = 0;
double number2 = 0;
char sign = '+';
double answer = 0;

int main () 
{

    cout<<"첫 번째 숫자를 입력해주세요."<<endl;
    cin>>number1;
    cout<<"기호를 입력해주세요. (+ - * /)"<<endl;
    cin>>sign;
    cout<<"두 번째 숫자를 입력해주세요."<<endl;
    cin>>number2;

    switch (sign)
    {

    case '+' : answer = number1 + number2;
    break;
    case '-' : answer = number1 - number2;
    break;
    case '*' : answer = number1 * number2;
    break;
    case '/' : answer = number1 / number2;
    break;

    }

    cout<<answer<<endl;

}