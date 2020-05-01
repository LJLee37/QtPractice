#include <iostream>
#include <string>
using namespace std;
    enum gender_t {male, female};

typedef struct JJ {
    int age;
    string name;
    gender_t gender;
} person_t;

person_t JJ;


int main ()
{
cout<<"나이를 입력해주세요."<<endl;
cin>>JJ.age;
cout<<"이름를 입력해주세요."<<endl;
cin>>JJ.name;
cout<<"성별을 입력해주세요. (male : 0, female : 1)"<<endl;
int i = 0;
cin>>i;
if (i == 0)
JJ.gender = male;
else
JJ.gender = female;

cout<<JJ.age<<endl;
cout<<JJ.name<<endl;
cout<<JJ.gender<<endl;

}