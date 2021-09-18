#include "String.h"

String::String()
{
	m_data = new char[m_capacity];
}

String::String(size_t capacity)
{
	m_capacity = capacity;
	m_data = new char[m_capacity];
}

String::String(size_t count, char c)
{
	m_capacity = count * 2;
	m_data = new char[m_capacity];
	for (size_t i = 0; i < count; i++) {
		m_data[i] = c;
		m_size++;
	}
}

String::String(const char* str)
{
	m_capacity = strlen(str) * 2;
	m_data = new char[m_capacity];
	for (size_t i = 0; i < m_capacity / 2; i++) {
		m_data[i] = str[i];
		m_size++;
	}
}

String::String(const String& another)
{
	m_capacity = another.m_capacity;
	m_size = another.m_size;

	m_data = new char[m_capacity];

	for (size_t i = 0; i < m_size; i++)
		m_data[i] = another.m_data[i];
}

String String::operator=(const String& another)
{
	if (this == &another)
		return *this;

	return String(another);
}

String::String(String&& another)
{
	m_capacity = std::move(another.m_capacity); 
	m_size = std::move(another.m_size);

	m_data = new char[m_capacity];

	for (size_t i = 0; i < m_size; i++)
		m_data[i] = std::move(another.m_data[i]);
}

String String::operator=(String&& another)
{
	if (this == &another)
		return *this;

	return String(std::forward<String&&>(another));
}

String& String::assign(size_t count, char c)
{
	clear();

	for (size_t i = 0; i < count; i++)
		push_back(c);

	return *this;
}

String& String::assign(const String& another)
{
	clear();

	for (size_t i = 0; i < another.size(); i++)
		push_back(another[i]);

	return *this;
}

String& String::assign(const String& another, size_t pos, size_t count)
{
	clear();

	for (size_t i = 0; i < count; i++)
		push_back(another.at(pos + i));

	return *this;
}

String& String::assign(String&& another)
{
	clear();

	for (size_t i = 0; i < another.length(); i++)
		push_back(another[i]);

	return *this;
}

String& String::assign(const char* str)
{
	clear();

	for (size_t i = 0; i < strlen(str); i++)
		push_back(str[i]);

	return *this;
}

String& String::assign(const char* str, size_t count)
{
	clear();

	for (size_t i = 0; i < count && i < strlen(str); i++)
		push_back(str[i]);

	return *this;
}

String& String::assign(std::initializer_list<char> ilist)
{
	clear();

	for (char c : ilist)
		push_back(c);

	return *this;
}

String::iterator String::begin()
{
	return iterator(m_data);
}

String::iterator String::end()
{
	return iterator(m_data + m_size);
}

String::const_iterator String::cbegin()
{
	return const_iterator(m_data);
}

String::const_iterator String::cend()
{
	return const_iterator(m_data + m_size);
}

String::rev_iterator String::rbegin()
{
	return rev_iterator(m_data + m_size - 1);
}

String::rev_iterator String::rend()
{
	return rev_iterator(m_data - 1);
}

String::const_rev_iterator String::crbegin()
{
	return const_rev_iterator(m_data + m_size - 1);
}

String::const_rev_iterator String::crend()
{
	return const_rev_iterator(m_data - 1);
}

size_t String::strlen(const char* str)
{
	size_t count{ 0 };
	while (str[count] != '\0')
		count++;
	return count;
}

size_t String::strlen(char* str)
{
	size_t count{ 0 };
	while (str[count] != '\0')
		count++;
	return count;
}

void String::clear()
{
	m_size = 0;
}

void String::push_back(char c)
{
	if (m_size + 1 >= m_capacity)
		reserve(m_capacity * 2);

	m_data[m_size++] = c;
}

void String::pop_back()
{
	m_size--;
}

bool String::starts_with(const char* str)
{
	if (strlen(str) > m_size)
		return false;

	for (size_t i = 0; i < strlen(str); i++)
		if (m_data[i] != str[i])
			return false;

	return true;
}

bool String::ends_with(const char* str)
{
	if (strlen(str) > m_size)
		return false;
	for (size_t str_index = strlen(str) - 1, data_index = m_size - 1; str_index >= 0; str_index--, data_index--)
		if (m_data[data_index] != str[str_index])
			return false;
	
	return true;
}

bool String::contains(const char* str)
{
	size_t str_count{ 0 };
	for (size_t i = 0; i < length(); i++) {
		if (m_data[i] == str[str_count])
			str_count++;
		else
			str_count = 0;

		if (str_count == strlen(str))
			return true;
	}

	return false;
}

String& String::append(char c)
{
	push_back(c);

	return *this;
}

String& String::append(size_t count, char c)
{
	for (size_t i = 0; i < count; i++)
		push_back(c);

	return *this;
}

String& String::append(const String& another)
{
	for (size_t i = 0; i < another.length(); i++)
		push_back(another[i]);

	return *this;
}

String& String::append(const String& another, size_t pos, size_t count)
{
	for (size_t i = 0; i < another.length() && i < count; i++)
		push_back(another[pos + i]);

	return *this;
}

String& String::append(String&& another)
{
	for (size_t i = 0; i < another.length(); i++)
		push_back(another[i]);

	return *this;
}

String& String::append(const char* str)
{
	for (size_t i = 0; i < strlen(str); i++)
		push_back(str[i]);

	return *this;
}

String& String::append(const char* str, size_t count)
{
	for (size_t i = 0; i < strlen(str) && i < count; i++)
		push_back(str[i]);

	return *this;
}

String& String::append(std::initializer_list<char> ilist)
{
	for (char c : ilist)
		push_back(c);

	return *this;
}

String& String::operator+=(const String& another)
{
	return append(std::forward<decltype(another)>(another));
}

String& String::operator+=(const char* str)
{
	return append(str);
}

String& String::operator+=(char c)
{
	return append(c);
}

String& String::operator+=(std::initializer_list<char> ilist)
{
	return append(std::forward<decltype(ilist)>(ilist));
}

bool String::empty()
{
	return m_size == 0;
}

const bool String::empty() const
{
	return m_size == 0;
}

size_t String::size()
{
	return m_size;
}

const size_t String::size() const
{
	return m_size;
}

size_t String::length()
{
	return m_size;
}

const size_t String::length() const
{
	return m_size;
}

size_t String::max_size()
{
	return npos;
}

const size_t String::max_size() const
{
	return npos;
}

void String::reserve(size_t new_capacity)
{
	if (new_capacity <= m_capacity)
		return;
	char* temp_buf = new char[m_size];
	for (size_t i = 0; i < m_size; i++)
		temp_buf[i] = m_data[i];

	delete[] m_data;
	m_capacity = new_capacity;

	m_data = new char[m_capacity];
	for (size_t i = 0; i < m_size; i++)
		m_data[i] = temp_buf[i];

	delete[] temp_buf;
}

size_t String::capacity()
{
	return m_capacity;
}

const size_t String::capacity() const
{
	return m_capacity;
}

void String::shrink_to_fit()
{
	if (m_capacity <= m_size)
		return;
	char* temp_buf = new char[m_size];
	for (size_t i = 0; i < m_size; i++)
		temp_buf[i] = m_data[i];

	delete[] m_data;
	m_capacity = m_size;

	m_data = new char[m_capacity];
	for (size_t i = 0; i < m_size; i++)
		m_data[i] = temp_buf[i];

	delete[] temp_buf;
}

bool String::operator==(const String& another)
{
	if (size() != another.size())
		return false;

	for (size_t i = 0; i < size(); i++)
		if (m_data[i] != another[i])
			return false;

	return true;
}

bool String::operator==(const char* str)
{
	return (*this == String(str));
}

bool String::operator!=(const String& another)
{
	return !(*this == another);
}

bool String::operator!=(const char* str)
{
	return !(*this == str);
}

size_t String::find(char c)
{
	for (size_t i = 0; i < size(); i++)
		if (m_data[i] == c)
			return i;

	return npos;
}

size_t String::find(const char* str)
{
	size_t str_count{ 0 };
	for (size_t i = 0; i < length(); i++) {
		if (m_data[i] == str[str_count])
			str_count++;
		else
			str_count = 0;

		if (str_count == strlen(str))
			return i - str_count + 1;
	}

	return npos;
}

size_t String::find(const String& str)
{
	size_t str_count{ 0 };
	for (size_t i = 0; i < length(); i++) {
		if (m_data[i] == str[str_count])
			str_count++;
		else
			str_count = 0;

		if (str_count == str.size())
			return i - str_count + 1;
	}

	return npos;
}

char& String::operator[](size_t index)
{
	return m_data[index];
}

const char& String::operator[](size_t index) const
{
	return m_data[index];
}

char& String::at(size_t index)
{
	if (index >= m_size)
		throw std::out_of_range{ "index out of range" };

	return m_data[index];
}

const char& String::at(size_t index) const
{
	if (index >= m_size)
		throw std::out_of_range{ "index out of range" };

	return m_data[index];
}

char& String::front()
{
	return m_data[0];
}

const char& String::front() const
{
	return m_data[0];
}

char& String::back()
{
	return m_data[m_size - 1];
}

const char& String::back() const
{
	return m_data[m_size - 1];
}

const char* String::c_str() const
{
	return m_data;
}

char* String::data()
{
	return m_data;
}

String::iterator::iterator(char* p)
{
	data = p;
}

String::iterator& String::iterator::operator++()
{
	data++;
	return *this;
}

String::iterator String::iterator::operator++(int)
{
	iterator retval = *this;
	data++;
	return retval;
}

String::iterator& String::iterator::operator--()
{
	data--;
	return *this;
}

String::iterator String::iterator::operator--(int)
{
	iterator retval = *this;
	data--;
	return retval;
}

String::iterator String::iterator::operator+(int step)
{
	return iterator(this->data + step);
}

String::iterator String::iterator::operator-(int step)
{
	return iterator(this->data - step);
}

bool String::iterator::operator==(const iterator& another)
{
	return data == another.data;
}

bool String::iterator::operator!=(const iterator& another)
{
	return !(*this == another);
}

char& String::iterator::operator*()
{
	return *data;
}

String::const_iterator::const_iterator(char* p)
{
	data = p;
}

String::const_iterator& String::const_iterator::operator++()
{
	data++;
	return *this;
}

String::const_iterator String::const_iterator::operator++(int)
{
	const_iterator retval = *this;
	data++;

	return retval;
}

String::const_iterator& String::const_iterator::operator--()
{
	data++;
	return *this;
}

String::const_iterator String::const_iterator::operator--(int)
{
	const_iterator retval = *this;
	data++;

	return retval;
}

String::const_iterator String::const_iterator::operator+(int step)
{
	return const_iterator(this->data + step);
}

String::const_iterator String::const_iterator::operator-(int step)
{
	return const_iterator(this->data - step);
}

bool String::const_iterator::operator==(const const_iterator& another)
{
	return this->data == another.data;
}

bool String::const_iterator::operator!=(const const_iterator& another)
{
	return !(*this == another);
}

const char& String::const_iterator::operator*() const
{
	return *data;
}

String::rev_iterator::rev_iterator(char* p)
{
	data = p;
}

String::rev_iterator& String::rev_iterator::operator++()
{
	data--;
	return *this;
}

String::rev_iterator String::rev_iterator::operator++(int)
{
	rev_iterator retval = *this;
	data--;

	return retval;
}

String::rev_iterator& String::rev_iterator::operator--()
{
	data++;
	return *this;
}

String::rev_iterator String::rev_iterator::operator--(int)
{
	rev_iterator retval = *this;
	data++;

	return retval;
}

String::rev_iterator String::rev_iterator::operator+(int step)
{
	return rev_iterator(this->data - step);
}

String::rev_iterator String::rev_iterator::operator-(int step)
{
	return rev_iterator(this->data + step);
}

bool String::rev_iterator::operator==(const rev_iterator& another)
{
	return data == another.data;
}

bool String::rev_iterator::operator!=(const rev_iterator& another)
{
	return !(*this == another);
}

char& String::rev_iterator::operator*()
{
	return *data;
}

String::const_rev_iterator::const_rev_iterator(char* p)
{
	data = p;
}


String::const_rev_iterator& String::const_rev_iterator::operator++()
{
	data--;
	return *this;
}

String::const_rev_iterator String::const_rev_iterator::operator++(int)
{
	const_rev_iterator retval = *this;
	data--;

	return retval;
}

String::const_rev_iterator& String::const_rev_iterator::operator--()
{
	data++;
	return *this;
}

String::const_rev_iterator String::const_rev_iterator::operator--(int)
{
	const_rev_iterator retval = *this;
	data++;

	return retval;
}

String::const_rev_iterator String::const_rev_iterator::operator+(int step)
{
	return const_rev_iterator(this->data - step);
}

String::const_rev_iterator String::const_rev_iterator::operator-(int step)
{
	return const_rev_iterator(this->data + step);
}

bool String::const_rev_iterator::operator==(const const_rev_iterator& another)
{
	return data == another.data;
}

bool String::const_rev_iterator::operator!=(const const_rev_iterator& another)
{
	return !(*this == another);
}

const char& String::const_rev_iterator::operator*() const
{
	return *data;
}
