#include"textOccurence.h"

// textOccurence class DEFINITION AND IMPLEMENTATION

// Class METHODS

// Preprocessing: This method prepare a clean string that is fed to wordsOccurence 
// to calculate the words occurrence
// the preprocessing removes special characters(' and -) and replace them by a space
// when removing (- or ') character, one character words are erase otherswise 
// the words is split into two subwords.

std::string textOccurence::preProcessing()
{
    std::ifstream fileIn;
    std::string line, bigLine;
    std::string filename=getName();

    fileIn.open(filename, std::ios::in);

    if (fileIn.is_open() && fileIn.good())
    {
        std::string token;

        while (std::getline(fileIn, line))
        {
            std::stringstream ss(line);
                     
            while (ss.good())
            {                
                ss >> token;

                for (auto i = 0; i < token.length(); i++)
                {
                    //check for the apostrophe character
                    if (token[i] == '\'')
                    {
                        size_t pos = token.find_first_of('\'');
                        std::string subToken1 = token.substr(0, pos);
                        std::string subToken2 = token.substr(pos + 1);

                        // remove one character word
                        if (subToken1.length() == 1)
                        {
                            token.erase(0, subToken1.length() + 1);
                            bigLine += token + ' ';
                            token.clear();
                        }
                        // if not than split the word into two words by inserting a space
                        else
                        {
                            token[pos] = ' ';
                            bigLine += token + ' ';
                            token.clear();
                        }
                    }
                    //check for the dash character
                    else if (token[i] == '-')
                    {
                        size_t pos = token.find_first_of('-');
                        std::string subToken1 = token.substr(0, pos);
                        std::string subToken2 = token.substr(pos + 1);

                        bigLine += subToken1+ ' '+subToken2;
                        token.clear();                    
                    }
                }

                bigLine += token + ' ';
                token.clear();
            }
        }
    }
    else
    {
    std::cout << "Error opening file from textOccurence class!"<<std::endl;;
    }
    fileIn.close();
    
return bigLine=bigLine.substr(0, bigLine.size()-3);
}

// Calculate the words occurrence: This method write one column text file. 
// The text files contains the words occurence sorted from highest to lowest value
// the occurence is performed using map library, since it is not possible to sort the map by value,
// the vector copied the map content then use std:: sort from algorithm to sort the vector contents
// sort() took lamda fuction to sort the vector by value.

void textOccurence::wordsOccurence(std::string& bigLine)
{
    std::ofstream fileOut;
    std::string fileName= "sample.table.txt";
    fileOut.open(fileName, std::ios::out);
    
    std::map<std::string, int>golosser;   
    
    std::stringstream ss(bigLine);
    std::string token;      
    // calculatr the wors occurence 
    while (ss.good())
    {
        ss >> token;
        ++golosser[token];
    }

    // copy glosser to a vector 
    std::vector<std::pair<std::string, int>> sortedVector(golosser.begin(), golosser.end());
    
    // sort vector contents by value using sort function lambda fuction[](){}
    std::sort(sortedVector.begin(), sortedVector.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
    
    // write into .txt file the vector contents
    for (auto& kv : sortedVector)
    {
        fileOut << kv.first << ", " << kv.second << "\n";
    }
    
    fileOut.close();

    //free memory
    golosser.clear();
    sortedVector.clear();
}

// contructors
// check for longest word in the object  instantiation 
textOccurence::textOccurence(std::string &filename):m_filename(filename)
{
    auto MaxWordLength=64;
    std::ifstream fileIn;
    fileIn. open(filename, std::ios::in);
    
    if (fileIn.is_open() && fileIn.good())
    {
        std::string token;
        std::string line;    
        while (std::getline(fileIn, line))
        {                            
            std::stringstream ss(line);
            std::string newline;
                
            while (ss.good())
            {
                std::string token;
                ss >> token; 

                // if a word is longer than 64 characters, then esxit the program
                if(token.length() >= MaxWordLength)
                {
                    std::cout<< "The program has been interrupted, no word longer \n"
                                "than 64 characters is authorised by textOccurence class!"<<std::endl;
                    exit(EXIT_SUCCESS);
                }  
            }
        }
    }
};

//setters
void textOccurence::setName(std::string& filename)
{
    m_filename=filename;
}

//getters
std::string textOccurence::getName()
{
    return m_filename;
}