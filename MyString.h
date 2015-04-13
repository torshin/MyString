#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
		char* ptr;
		size_t* count;
	public:
		MyString ();
		MyString (const char* const s);
		MyString (const MyString& s);
		size_t length() const;
		void copy (MyString& s);
		size_t findChr (const char ch) const ;
		size_t findStr (const MyString& s) const ;
		size_t findStr (const char* const s) const ;
		void swap (MyString& s);
		bool insert (const char ch, size_t pos);
		bool insert (const char* const s, size_t pos);
		bool insert (const MyString& s, size_t pos);
		bool erase (const size_t pos, const size_t amount);

		void delAndNewCount();

		MyString operator = (const MyString& s);
		MyString operator = (const char* const s);
		char operator [] (size_t pos);
		MyString operator + (const MyString& s);
		MyString operator + (const char* const s);
		bool operator == (const MyString& s);
		bool operator == (const char* const s);
		bool operator != (const MyString& s);
		bool operator != (const char* const s);
		friend std::ostream& operator<< (std::ostream& out, const MyString& s);
		friend std::istream& operator>> (std::istream& in, MyString& s);

		~MyString();
};

#endif // MyString_H
