/*
link.c
Application of linked list using link.h header file


Akshay
CSE, 3rd sem

*/


#include "link.h"




int main()
{
	struct link *list = new_list("3,4,5,6");
	display(list);

}


 /*Output

 { 3 4 5 6 }


*/
