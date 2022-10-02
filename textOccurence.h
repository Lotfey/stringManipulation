//file gard, protecting the textOccurence.h to be included for more than 1 time 
#ifndef _TEXTOCCURENCE_H
#define _TEXTOCCURENCE_H 

#include<iostream>      // std:: cout, std::endl
#include<string>        // std::string
#include<fstream>       // std::fstream
#include<sstream>       // std::stringstream
#include<vector>        // std::vector
#include<algorithm>     // std::sort()
#include<map>           // std::map
//#include<iomanip>     // std::setw()


//textOccurence  class SIGNATURE DEFINITION
class textOccurence
{
public:
// Class methods 

// preprocessing 
std::string preProcessing();

// compute words occurence
void wordsOccurence(std::string&);

//Constructor
textOccurence()=delete; // default constructor is not allowed
textOccurence(std::string&);

//setters
void setName(std::string&);

//getter
std::string getName();

//Destructor
~textOccurence()=default;

private: 
std::string m_filename;
//std::vector<std::string> m_data;
// for improvement, I would read all the text data into a vector 
};
#endif // _TEXTOCCURENCE_H