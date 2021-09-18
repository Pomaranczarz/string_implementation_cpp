#pragma once

#include <utility>
#include <stdexcept>

class String {
public:
	static const size_t npos = -1;
public:
	String();
	String(size_t capacity);
	String(size_t count, char c);
	String(const char* str);
	String(const String& another);
	String operator=(const String& another);
	String(String&& another);
	String operator=(String&& another);

	String& assign(size_t count, char c);
	String& assign(const String& another);
	String& assign(const String& another, size_t pos, size_t count = String::npos);
	String& assign(String&& another);
	String& assign(const char* str);
	String& assign(const char* str, size_t count);
	String& assign(std::initializer_list<char> ilist);

public:
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	char& at(size_t index);
	const char& at(size_t index) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;
	const char* c_str() const;
	char* data();

public:
	void clear();
	void push_back(char c);
	void pop_back();
	bool starts_with(const char* str);
	bool ends_with(const char* str);
	bool contains(const char* str);

	String& append(char c);
	String& append(size_t count, char c);
	String& append(const String& another);
	String& append(const String& another, size_t pos, size_t count = String::npos);
	String& append(String&& another);
	String& append(const char* str);
	String& append(const char* str, size_t count);
	String& append(std::initializer_list<char> ilist);

	String& operator+=(const String& another);
	String& operator+=(const char* str);
	String& operator+=(char c);
	String& operator+=(std::initializer_list<char> ilist);

public:
	bool empty();
	const bool empty() const;
	size_t size();
	const size_t size() const;
	size_t length();
	const size_t length() const;
	size_t max_size();
	const size_t max_size() const;
	void reserve(size_t new_capacity);
	size_t capacity();
	const size_t capacity() const;
	void shrink_to_fit();

public:
	bool operator==(const String& another);
	bool operator==(const char* str);
	bool operator!=(const String& another);
	bool operator!=(const char* str);

public:
	class iterator : public std::iterator<std::random_access_iterator_tag, char> {
	public:
		explicit iterator(char* p);

		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		iterator operator+(int step);
		iterator operator-(int step);

		bool operator==(const iterator& another);
		bool operator!=(const iterator& another);
		char& operator*();
	private:
		char* data;
	};

	class const_iterator : public std::iterator<std::random_access_iterator_tag, char> {
	public:
		explicit const_iterator(char* p);

		const_iterator& operator++();
		const_iterator operator++(int);
		const_iterator& operator--();
		const_iterator operator--(int);
		const_iterator operator+(int step);
		const_iterator operator-(int step);

		bool operator==(const const_iterator& another);
		bool operator!=(const const_iterator& another);
		const char& operator*() const;
	private:
		char* data;
	};

	class rev_iterator : public std::iterator<std::random_access_iterator_tag, char> {
	public:
		explicit rev_iterator(char* p);
		
		rev_iterator& operator++();
		rev_iterator operator++(int);
		rev_iterator& operator--();
		rev_iterator operator--(int);
		rev_iterator operator+(int step);
		rev_iterator operator-(int step);

		bool operator==(const rev_iterator& another);
		bool operator!=(const rev_iterator& another);
		char& operator*();
	private:
		char* data;
	};

	iterator begin();
	iterator end();

	const_iterator cbegin();
	const_iterator cend();

	rev_iterator rbegin();
	rev_iterator rend();
private:
	size_t strlen(const char* str);
	size_t strlen(char* str);

private:
	char* m_data;
	size_t m_size{ 0 };
	size_t m_capacity{ 20 };
};

typedef String string;