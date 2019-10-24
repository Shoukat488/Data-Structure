#include <iostream>
#include "SLL.h"

int main() {
	SLL s;
	cout << "inserting 5 at end: " << endl;
	s.Insert_at_End(5);
	s.Display();
	cout << "inserting 4 at head: " << endl;
	s.Insert_at_Head(4);
	s.Display();
	cout << "inserting 3, 1 at end: " << endl;
	s.Insert_at_End(3);
	s.Insert_at_End(1);
	s.Display();
	cout << "inserting 6 before 3: " << endl;
	s.Insert_Before(6, 3);
	s.Display();
	cout << "inserting 7 after 1: " << endl;
	s.Insert_After(7, 1);
	s.Display();
	cout << "inserting 8 at index 5: " << endl;
	s.Insert_at(8, 5);
	s.Display();
	cout << "deleting from end: " << endl;
	s.Delete_from_End();
	s.Display();
	cout << "deleting from front: " << endl;
	s.Delete_from_front();
	s.Display();
	cout << "deleting at index 2: " << endl;
	s.Delete_at(2);
	s.Display();
	cout << "deleting before 8: " << endl;
	s.Delete_before(8);
	s.Display();
	cout << "deleting after 3: " << endl;
	s.Delete_After(3);
	s.Display();
	cout << "searching for index of 3 (-1 if not found): " << endl;
	cout << s.Search_data(3) << endl;
	cout << "searching for index of 6 (-1 if not found): " << endl;
	cout << s.Search_data(6) << endl;
	cout << "size of list: " << endl;
	cout << s.Length_of_list() << endl;
	
}
