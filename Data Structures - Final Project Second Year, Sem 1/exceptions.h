#pragma once

// exceptions class
#include <iostream>
#include <string>

class exceptions 
{
public:
	exceptions(const char* _str) { m_str = _str; }
	const char* what() const {return m_str.c_str(); }

private:
	std::string m_str;
};
