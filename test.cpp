// *** ADDED BY HEADER FIXUP ***
#include <cassert>
// *** END ***
#include <iostream>
#include <limits>
#include "MyString.h"


void testCompare()
{
	MyString s1 ("the string"), s2 ("not the same string"), s3 ("the string"), s4, s5;
	const char *c2 = "the string";
	const char *c3 = "not the same";
	char *c1 = nullptr;
	assert (s1 == s3);
	assert (s1 == "the string" );
	assert (! (s1 == s2));
	assert (s1 != s2);
	assert (! (s1 != s3));
	assert (s4 == s5);
	assert (! (s4 != s5));
	assert (s1 == c2);
	assert (! (s1 != c2));
	assert (s1 != c3);
	assert (s1 != c1);
	assert (s4 == c1);
	assert (s4 != c3);
	char *null1="";
	assert(s4==null1);
}

void testCopy()
{
	MyString s1 ("the string"), s2 ("arst"), s3 ("the string"), s4 ("not the same");
	s1.copy (s2);
	assert (s2 == s3);
	assert (s1 == s3);
	assert (! (s2 == s4));
	assert (s1 != s4);
	MyString s5, s6, s7;
	s5.copy (s6);
	s5.copy (s2);
	assert (s5 == s6);
	assert (s6 == s7);
	assert (s2 == s7);
	s1.copy (s7);
	assert (s7 == s3);
}

void testAssign()
{
	MyString s1 ("the string"), s2 ("twilight sparkl"), s3 ("twilight sparkl"), s4 ("not the same"), s5 ("long string is long");
	s1 = s2;
	assert (s1 == s2);
	assert (s2 == s3);
	assert (! (s2 == s4));
	assert (! (s1 == s4));
	s5 = s1;
	assert (s5 == s2);
	assert (s2 == s3);
	assert (! (s2 == s4));
	assert (! (s1 == s4));
	s5 = "arst";
	char *s6 = "arst";
	MyString s7 ("arst");
	assert (s5 == s6);
	assert (s5 == s7);
	MyString s8, s9, s10, s11;
	s8 = s2;
	assert (s8 == s2);
	assert (s2 == s3);
	assert (! (s2 == s4));
	assert (! (s8 == s4));
	s2 = s9;
	assert (s9 == s10);
	assert (s2 == s11);

	MyString null1, null2(""), null3;
	assert(null1==null2);
	assert(null1==null3);
	assert(null2==null3);
	null1=s5;
	s1=s5;
	null1=null3;

}

void testFindChar()
{
	MyString s1 ("123456789 123456789 123456789 123456789");
	char ch1 = '5', ch2 = 'N', ch3 ;
	size_t answ = 4;
	size_t pos = s1.findChr (ch1);
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s1.findChr (ch2);
	size_t max = std::numeric_limits<size_t>::max();
	assert (pos == max);
	assert (! (pos == answ));
	pos = s1.findChr (ch3);
	assert (pos == max);
	assert (! (pos == answ));
	MyString s2;
	pos = s2.findChr (ch1);
	assert (pos == max);
	assert (! (pos == answ));
	pos = s2.findChr (ch3);
	assert (pos == max);
	assert (! (pos == answ));
}

void testFindStr()
{
	MyString s ("Twilight Sparkl 123 12"), sub1 ("light"), sub2 ("12"), sub5 ("not");
	char sub3[6] = "light";
	char sub4[3] = "12";
	char sub6[4] = "NOT";
	size_t pos = s.findStr (sub1);
	size_t answ = 3;
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s.findStr (sub2);
	answ = 16;
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s.findStr (sub3);
	answ = 3;
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s.findStr (sub4);
	answ = 16;
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s.findStr (sub5);
	answ = std::numeric_limits<size_t>::max();
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s.findStr (sub6);
	assert (pos == answ);
	assert (! (pos == answ + 10));
	MyString s1, sub7;
	pos = s1.findStr (sub1);
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s.findStr (sub7);
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s1.findStr (sub1);
	assert (pos == answ);
	assert (! (pos == answ + 10));
	pos = s1.findStr (sub7);
	assert (pos == answ);
	assert (! (pos == answ + 10));
	char *ch = nullptr;
	pos = s1.findStr (ch);
	assert (pos == answ);
	assert (! (pos == answ + 10));
}

void testSwap()
{
	MyString s1 ("the first string");
	MyString s2 ("the second string");
	MyString answ1 ("the second string"), answ2 ("the first string"), notansw ("NOOOO");
	s1.swap (s2);
	assert (s1 == answ1);
	assert (s2  == answ2);
	assert (! (s1 == notansw));
	assert (! (s2 == notansw));
	MyString nullstr;
	nullstr.swap (s2);
	assert (nullstr == answ2);
	assert (s2 == nullptr);
	MyString n1("");
	s2.swap(n1);
	assert(s2==n1);
	assert (s2 == nullptr);
}

void testInsert()
{
	size_t pos = 5;
	MyString strDest ("The destination string");
	MyString strSourceS ("insert this ");
	MyString strSourceL ("please insert this string to dest ");
	char ch = '!';
	char *sourceCharS = "ins this ";
	char *sourceCharL = "ins this in the destination string, please ";
	MyString answ1 ("The insert this destination string");
	char *answer2 = "The please insert this string to dest destination string";
	MyString answ2 (answer2);
	MyString answ3 ("The !destination string");
	MyString answ4 ("The ins this destination string");
	MyString answ5 ("The ins this in the destination string, please destination string");
	MyString notansw ("THIS IS NOT ANSWER");
	assert (strDest.insert (strSourceS, pos));
	assert (strDest == answ1);
	assert (! (strDest == notansw));
	strDest = "The destination string";
	assert (strDest.insert (ch, pos));
	assert (strDest == answ3);
	assert (! (strDest == notansw));
	strDest = "The destination string";
	assert (strDest.insert (sourceCharS, pos));
	assert (strDest == answ4);
	assert (! (strDest == notansw));
	strDest = "The destination string";
	assert (strDest.insert (strSourceL, pos));
	assert (strDest == answ2);
	assert (! (strDest == notansw));
	strDest = "The destination string";
	assert (strDest.insert (sourceCharL, pos));
	assert (strDest == answ5);
	assert (! (strDest == notansw));
	MyString s1, s2;
	assert(!s1.insert(s2,1));
	assert (s1 == s1);
	assert(s1.insert(answ1,1));
	assert(answ1==s1);
	assert(!answ1.insert(s2,1));
	assert(answ1=="The insert this destination string");

}

void testErase()
{
	MyString s1 ("This is bad sentense"), s2 ("short");
	MyString answ1 ("This is sentense");
	assert (s1.erase (9, 4));
	assert (s1 == answ1);
	assert (! (s1 == s2));
	assert (! (s2.erase (4, 6)));
	assert (! (s2.erase (6, 0)));
	MyString s3, s4;
	assert(!s3.erase(1,1));
	assert(s3==s4);
	s2.erase(1,5);
	assert(s2==s3);
}

void testSquare()
{
	MyString s1 ("This is bad sentence");
	MyString answ1 ("This is sentence");
	char ch1 = 'b', ch2 = 'T';
	assert (ch1 == s1[9]);
	assert (! (ch1 == s1[0]));
	MyString s2;
	std::cout<<s2[1];
}

void testPlus()
{
	MyString s1 ("first part "), s2 ("second part"), s4 ("a");
	char *s3 = "third part";
	MyString answ1 ("first part second part"), answ2 ("first part third part"), notansw ("NOOO");
	assert (answ1 == s1 + s2);
	assert (! (notansw == s1 + s2));
	MyString s5 (s1 + s2);
	assert (s5 == answ1);
	s4 = s1 + s2;
	assert ( (s1 + s2) == answ1);
	assert (s4 == answ1);
	s4=s4+s2;
	answ1=answ1+s2;
	assert (s4 == answ1);
	assert (s4 == "first part second partsecond part");
	MyString s6;
	assert(s6+s6 == s6);
	MyString s7=s6+s4;
	assert(s7==s4);
	assert(s4+s6==s4);
}


