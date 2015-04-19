#include <iostream>
#include <limits>
#include "MyString.h"
#include "stringOperation.h"

size_t  maxSize_t = std::numeric_limits<size_t >::max();

size_t MyString::length() const
{
	size_t len = 0;
	if (ptr != nullptr)
	{
		const char *cur = ptr;
		while (* (cur++));
		len = cur - ptr - 1 ;
	}
	return len;
}

void MyString::delAndNewCount()
{
	if (count != nullptr)
	{
		if (*count < 2)
		{
			delete []ptr;
		}
		else
		{
			(*count)--;
			count = new size_t;
			*count = 1;
		}
	}
	else
	{
		count = new size_t;
		*count = 1;
	}
}

MyString::MyString()
{
	ptr = nullptr;
	count = nullptr;
}

MyString::MyString (const char *const s)
{
	size_t len = strlength (s);
	if (len > 0)
	{
		ptr = new char[len + 1];
		for (size_t i = 0; i < len ; i++)
		{
			ptr[i] = s[i];
		}
		ptr[len] = '\0';
		count = new size_t;
		*count = 1;
	}
	else
	{
		ptr = nullptr;
		count = nullptr;
	}
}

MyString::MyString (const MyString &s)
{
	size_t len = s.length();
	ptr = new char[len + 1];
	for (size_t i = 0; i < len; i++)
	{
		ptr[i] = s.ptr[i];
	}
	ptr[len] = '\0';
	count = new size_t;
	*count = 1;
}

void MyString::copy (MyString &s)
{
	if (ptr != nullptr)
	{
		size_t len = length();
		s.delAndNewCount();
		s.ptr = new char[len + 1];
		for (size_t i = 0; i < len; i++)
		{
			s.ptr[i] = ptr[i];
		}
		s.ptr[len] = '\0';
	}
	else
	{
		if (s.count != nullptr)
		{
			if (*s.count == 1)
			{
				delete[] s.ptr;
				delete s.count;
			}
			else
			{
				(*s.count)--;
			}
		}
		//		s.~MyString();
		s.ptr = ptr;
		s.count = count;
	}
}

size_t  MyString::findChr (char ch) const
{
	size_t pos = maxSize_t;
	for (size_t i = 0; i < length(); i++)
	{
		if (ptr[i] == ch)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

size_t  MyString::findStr (const MyString &s) const
{
	size_t pos = maxSize_t;
	size_t flag = 0;
	size_t len = length();
	size_t sublen = s.length();
	if (sublen <= len)
	{
		for (size_t i = 0; i < len - sublen + 1 ; i++)
		{
			for (size_t j = 0; j < sublen; j++)
			{
				pos = i;
				if (ptr[i + j] == s.ptr[j])
				{
					if (j == sublen - 1)
					{
						flag = 1;
					}
				}
				else
				{
					pos = maxSize_t;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}
	return pos;
}

size_t  MyString::findStr (const char *s) const
{
	size_t pos = maxSize_t;
	size_t flag = 0;
	size_t len = length();
	size_t sublen = strlength (s);
	if (sublen <= len)
	{
		for (size_t i = 0; i < len - sublen + 1; i++)
		{
			for (size_t j = 0; j < sublen; j++)
			{
				if (ptr[i + j] == s[j])
				{
					pos = i;
					if (j == sublen - 1)
					{
						flag = 1;
					}
				}
				else
				{
					pos = maxSize_t;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}
	return pos;
}

void MyString::swap (MyString &s)
{
	//	if (*count >= 1 && *s.count >= 1)
	//	{
	char *temp = s.ptr;
	s.ptr = ptr;
	ptr = temp;
	size_t *tempcount = s.count;
	s.count = count;
	count = tempcount;
	//	}
}

bool MyString::insert (const char ch, size_t pos)
{
	MyString temp (ptr);
	size_t lengthDest = length();
	if (pos - 1 <= lengthDest && ch != '\0')
	{
		delAndNewCount();
		ptr = new char[lengthDest + 2];
		for (size_t  i = 0; i < pos - 1; i++)
		{
			ptr[i] = temp.ptr[i];
		}
		ptr[pos - 1] = ch;
		for (size_t i = pos; i < lengthDest + 1; i++)
		{
			ptr[i] = temp.ptr[i - 1];
		}
		ptr[lengthDest+1]='\0';
	}
	return (ptr[pos - 1] == ch);
}

bool MyString::insert (const char *s, size_t pos)
{
	size_t lengthDest = length();
	size_t lengthSource = strlength (s);
	bool compare = false;
	if (pos - 1 <= lengthDest && lengthSource > 0 && pos >0)
	{
		MyString temp (ptr);
		delAndNewCount();
		ptr = new char[lengthSource + lengthDest + 1];
		for (size_t  i = 0; i < pos - 1; i++)
		{
			ptr[i] = temp.ptr[i];
		}
		for (size_t  i = 0; i < lengthSource; i++)
		{
			ptr[pos - 1 + i] = s[i];
		}
		for (size_t i = pos - 1; i < lengthDest; i++)
		{
			ptr[lengthSource + i] = temp.ptr[i];
		}
		ptr[lengthSource + lengthDest] = '\0';
		compare=true;
	}
	return compare;
}

bool MyString::insert (const MyString &s, size_t pos)
{
	size_t lengthDest = length();
	size_t lengthSource = s.length();
	bool compare = false;
	if (pos - 1 <= lengthDest && lengthSource > 0 && pos>0)
	{
		MyString temp (ptr);
		delAndNewCount();
		ptr = new char[lengthSource + lengthDest + 1];
		for (size_t  i = 0; i < pos - 1; i++)
		{
			ptr[i] = temp.ptr[i];
		}
		for (size_t  i = 0; i < lengthSource; i++)
		{
			ptr[pos - 1 + i] = s.ptr[i];
		}
		for (size_t i = pos - 1; i < lengthDest ; i++)
		{
			ptr[lengthSource + i] = temp.ptr[i];
		}
		ptr[lengthSource + lengthDest] = '\0';
		compare=true;
	}
	return compare;
}

bool MyString::erase (const size_t pos, const size_t amount)
{
	size_t lenstr = length();
	bool compare = false;
	if (pos + amount - 1 <= lenstr && amount > 0)
	{
		if (pos == 1 && amount == lenstr)
		{
			if (*count < 2)
			{
				delete []ptr;
				delete count;
				count = nullptr;
			}
			else
			{
				(*count)--;
				//				count=new size_t ;
				//				delete count;
				count = nullptr;
			}
			ptr = nullptr;
		}
		else
		{
			MyString temp (ptr);
			delAndNewCount();
			ptr = new char[lenstr - amount];
			for (size_t i = 0; i < pos - 1; i++)
			{
				ptr[i] = temp.ptr[i];
			}
			for (size_t i = pos - 1; i < lenstr - amount + 1; i++)
			{
				ptr[i] = temp.ptr[i + amount];
			}
			compare = (ptr[pos - 2] == temp.ptr[pos - 2] && ptr[pos - 1] == temp.ptr[pos - 1 + amount]);
		}
	}
	return compare;
}

MyString MyString::operator = (const MyString &s)
{
	if (count != nullptr)
	{
		if (*count == 1)
		{
			delete[] ptr;
			delete count;
		}
		else
		{
			(*count)--;
		}
	}
	ptr = s.ptr;
	//	count= new size_t ; //i don't know
	count = s.count;
	if (count != nullptr)
	{
		*count = *count + 1;
	}
	return (*this);
}

MyString MyString::operator = (const char *const s)
{
	size_t len = strlength (s);
	if (count != nullptr)
	{
		if (*count < 2)
		{
			delete []ptr;
		}
		else
		{
			(*count)--;
		}
	}
	ptr = nullptr;
	count = nullptr;
	if (len != 0)
	{
		ptr = new char[len];
		count = new size_t ;
		(*count) = 1;
	}
	for (size_t i = 0; i < len + 1; i++)
	{
		ptr[i] = s[i];
	}
	return (*this);
}

MyString MyString::operator+ (const MyString &s)
{
	size_t lenstr = length();
	size_t lengthSource = s.length();
	char *str = nullptr;
	if (lengthSource != 0 || lenstr != 0)
	{
		str = new char[lenstr + lengthSource + 1];
		for (size_t i = 0; i < lenstr; i++)
		{
			str[i] = ptr[i];
		}
		for (size_t i = 0; i < lengthSource; i++)
		{
			str[i + lenstr] = s.ptr[i];
		}
		if (lenstr + lengthSource != 0)
		{
			str[lenstr + lengthSource] = '\0';
		}
	}
	return 	MyString (str);
}

MyString MyString::operator+ (const char *const s)
{
	MyString temp (ptr);
	size_t lenstr = length();
	size_t lengthSource = strlength (s);
	char *str;
	if (lengthSource != 0 || lenstr != 0)
	{
		str = new char[lenstr + lengthSource + 1];
		for (size_t i = 0; i < lenstr; i++)
		{
			str[i] = temp.ptr[i];
		}
		for (size_t i = 0; i < lengthSource + 1; i++)
		{
			str[i + lenstr] = s[i];
		}
	}
	return MyString (str);
}

char MyString::operator[] (size_t pos)
{
	char ch = '\0';
	if (pos > 0 && pos <= length())
	{
		ch = ptr[pos - 1];
	}
	return ch;
}

bool MyString::operator == (const MyString &s)
{
	bool compare=true;
	size_t lenstr = length();
	if (lenstr == s.length())
	{
		if (s.ptr == ptr)
		{
			compare = true;
		}
		else
		{
			for (size_t i = 0; i < lenstr; i++)
			{
				compare = (ptr[i] == s.ptr[i]);
				if (!compare)
				{
					break;
				}
			}
		}
	}
	else
	{
		compare = false;
	}
	return compare;
}

bool MyString::operator == (const char *s)
{
	bool compare=true;
	size_t lenstr = length();
	if (lenstr == strlength (s))
	{
		if (s == ptr)
		{
			compare = true;
		}
		else
		{
			for (size_t i = 0; i < lenstr; i++)
			{
				compare = (ptr[i] == s[i]);
				if (!compare)
				{
					break;
				}
			}
		}
	}
	else
	{
		compare = false;
	}
	return compare;
}

bool MyString::operator != (const MyString &s)
{
	bool compare;
	size_t lenstr = length();
	if (lenstr == s.length())
	{
		if (s.ptr == ptr)
		{
			compare = false;
		}
		else
		{
			for (size_t i = 0; i < lenstr; i++)
			{
				compare = (ptr[i] != s.ptr[i]);
				if (compare)
				{
					break;
				}
			}
		}
	}
	else
	{
		compare = true;
	}
	return compare;
}

bool MyString::operator != (const char *s)
{
	bool compare;
	size_t lenstr = length();
	if (lenstr == strlength (s))
	{
		if (s == ptr)
		{
			compare = false;
		}
		else
		{
			for (size_t i = 0; i < lenstr; i++)
			{
				compare = (ptr[i] != s[i]);
				if (compare)
				{
					break;
				}
			}
		}
	}
	else
	{
		compare = true;
	}
	return compare;
}

std::ostream &operator<< (std::ostream &out, const MyString &s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		out << s.ptr[i];
	}
	return out;
}

std::istream &operator>> (std::istream &in, MyString &s)
{
	char tempstr[256];
	in.getline (tempstr, 256);
	size_t templen = strlength (tempstr);
	s.delAndNewCount();
	s.ptr = new char[templen + 1];
	for (int i = 0; i < templen + 1 ; i++)
	{
		s.ptr[i] = tempstr[i];
	}
	return in;
}

MyString::~MyString()
{
	if (count != nullptr)
	{
		if (*count == 1)
		{
			delete[] ptr;
			delete count;
		}
		else
		{
			(*count)--;
		}
	}
}
