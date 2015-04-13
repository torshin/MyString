#include <iostream>
#include "MyString.h"
#include "test.h"
using std::endl;
using std::cout;
using std::cin;

int main()
{
	testCompare();
	testCopy();
	testSwap();
	testAssign();
	testFindStr();
	testFindChar();
	testInsert();
	testErase();
	testSquare();
	testPlus();


	MyString str("arst");
	MyString str1;
	str.copy(str1);
	size_t pos = str.findStr("rs");
	cout << "length == " << str.length() << "\n position ==" << pos << endl;
	cout << "\n" << str << " ==  " << str1 << "\n";
	cin>>str;
	cout<<"after cin: "<< str << endl;

	MyString str2("Destination  <-here");
	MyString strSr("INSERT THIS ");
	str2.insert(strSr, 13);
	cout << "\n" << str2 << endl;

	str2.erase(2, 2);
	cout << "\n" << str2 << " \n   " << str2[2] << endl;

	MyString str3;
	str3 = (str2 + strSr);

	str2 = str3;

	cout << "\nstr3: " << str3 << " \nstr2:   "<< str2 << endl;
	return 0;
}
