#pragma once
#include <cstring>

class String {
public:
	char* str;
	int len;

	// Default constructor
	String()
		: len(0), str(nullptr)   
	{ }

	// Construct and assign literal value
	String(const char* s) 
		: len(std::strlen(s) + 1), str(new char[len])
	{
		std::strncpy(str, s, len);
	}

	// Copy construct and assign
	String(const String& s) 
		: len(s.len), str(new char[s.len]) 
	{ 
		std::strncpy(str, s.str, len);
	}

	// Destructor
	~String() { delete[] str; }

	// Assignment from literal value
	String& operator=(const char* s) {
		if (this->str)
			delete[] this->str;

		len = std::strlen(s) + 1;
		str = new char[len]; 
		std::strncpy(str, s, len);
		return *this;
	}

	// Assignment from string
	String& operator=(const String& s) {
		if (this->str)
			delete[] this->str;
		
		len = s.len;
		str = new char[len];
		std::strncpy(str, s.str, len);
		return *this;
	}
};	

// Ostream
inline std::ostream& operator<<(std::ostream& stream, const String& s) {
	return stream << s.str;
}

// Comparison
inline bool operator==(const String& a, const String& b) {
	return !(strcmp(a.str, b.str));
}

// Comparison
inline bool operator!=(const String& a, const String& b) {
	return !(a == b);
}

// Less than
inline bool operator<(const String& a, const String& b) {
	return a.len < b.len;	
}

// Less than or equal to
inline bool operator<=(const String& a, const String& b) {
	return (a < b) || (a == b);
}

// Greater than
inline bool operator>(const String& a, const String& b) {
	return a.len > b.len;	
}

// Greater than or equal to
inline bool operator>=(const String& a, const String& b) {
	return (a > b) || (a == b);
}
