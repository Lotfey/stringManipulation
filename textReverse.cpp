#include"textReverse.h"

// textReverse class DEFINITION AND IMPLEMENTATION

// Class METHODS
// reverse: This methor write a test file that contains reverse words
// the testformating is similar to the input text formating 
// if the is (character'word), this mathod return (character'drow)
// if the is (word1-word2), this mathod return (2drow-1drow)

void textReverse::reverse()
{    
    std::string filename=getName();
    std::ifstream fileIn;
    std::ofstream fileOut;

    fileIn. open(filename, std::ios::in);    
    fileOut.open("sample.reverse.txt", std::ios::out);
 
    std::string line;

    if (fileIn.is_open() && fileIn.good())
    {
        std::string token;
            
        while (std::getline(fileIn, line))
        {                            
            std::stringstream ss(line);
            std::string newline;
                
            while (ss.good())
            {
                std::string token;
                ss >> token;

                for (auto i = 0; i < token.length(); i++)
                {   
                    // if there is - character in a word
                    // then replace it with a space character
                    // split the word into two subwords
                    // reverse each subword separately
                    // join reversed subwords by - character
                    if (token[i] == '-')
                    {
                        //token[i] = ' ';
                        size_t pos = token.find_first_of('-');
                        std::string subToken1 = token.substr(0, pos);
                        std::string subToken2 = token.substr(pos + 1);
                    

                        std::reverse(subToken1.begin(), subToken1.end());
                        std::reverse(subToken2.begin(), subToken2.end());
                        newline += subToken1 + "-" + subToken2;
                        token.clear();
                    }

                    // if there is ' character in a word
                    // then replace it with a space character
                    // split the word into two subwords
                    // reverse each subword separately
                    // join reversed subwords by - character
                    else if (token[i] == '\'')
                    {
                        size_t pos = token.find_first_of('\'');
                        std::string subToken1 = token.substr(0, pos);                        
                        std::string subToken2 = token.substr(pos + 1);

                        std::reverse(subToken1.begin(), subToken1.end());
                        std::reverse(subToken2.begin(), subToken2.end());
                        newline += subToken1 + "\'" + subToken2;
                        token.clear();
                    }
                }
                
                std::reverse(token.begin(), token.end());
                newline += token + ' ';
            }
            newline = newline.substr(0, newline.size() -1);

            //write into text file line of reverse words
            fileOut << newline;                  
            fileOut << '\n';
        }
        

        fileOut.close();
        fileIn.close();
    }    
    else
    {
    std::cout << "Error opening file from textReverse class!"<<std::endl;
    }
}

//constructor
// check for longest word in the object  instantiation 
textReverse::textReverse (std::string &filename):m_filename(filename)
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
                                "than 64 characters is authorised by textReverse class!"<<std::endl;
                    exit(EXIT_SUCCESS);
                }  
            }
        }
    }
    fileIn.close();
};

//setters
std::string textReverse::getName(){return m_filename;}

//getters
void textReverse::setName(std::string& filename)
{
    m_filename =filename;
}