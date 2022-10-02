//file gard, protecting the textOccurence.h to be included for more than 1 time 
#ifndef _TEXTREVERSE_H
#define _TEXTREVERSE_H 

#include<iostream>      // std:: cout, std::endl
#include<string>        // std::string
#include<fstream>       // std::fstream
#include<sstream>       // std::stringstream
#include<vector>        // std::vector
#include<algorithm>     // std::sort()


//textReverse  class SIGNATURE DEFINITION
class textReverse   
{
public:
// Class method

// preprocessing and reverse words  
void reverse();

//Constructor
textReverse()=delete; // default constructor is not allowed
textReverse(std::string&);

//setters
void setName(std::string&);

//getters
std::string getName ();

// Destructor 
~textReverse()=default;

private: 
std::string m_filename;
// std::vector<std::string> m_data;
// for improvement, I would read all the text data into a vector
};
#endif // _TEXTREVERSE_H