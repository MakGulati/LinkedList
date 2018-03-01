#include <iostream>
using namespace std;


class student {
   public:
      int rollno;
	  char gender;
};

int main()

{ 	student mak;
	student *makptr;
	makptr=&mak;
	makptr->rollno=29;
	makptr->gender='m';
	cout<<"student's rollno= "<<makptr->rollno<<endl;
	cout<<"student's gender= "<<makptr->gender<<endl;


	/* code */
	return 0;
}