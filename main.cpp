#include"textOccurence.h"
#include"textReverse.h"
         
// The main function test both classes
// input: sample.txt
// output: sample.reverse.txt
//         sample.table.txt 
int main(int argc, char** argv)
{
    if(argc<2)
        return (EXIT_FAILURE);

    // Test textOccurence class
    std::string name1=argv[1];
    textOccurence testTextOccurence(name1);
    std::string Line=testTextOccurence.preProcessing();
    testTextOccurence.wordsOccurence(Line);

    // Test textReverse class
    std::string name2=argv[1];
    textReverse testTextReverse(name2);
    testTextReverse.reverse();

    return EXIT_SUCCESS;
}  