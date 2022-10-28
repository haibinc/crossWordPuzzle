#include <iostream>
#include "class.h"

int main() {
    srand(time(0));
    char front[50][50];
    char back[50][50];
    int row = 0, col = 0, wordCount = 0;
    std::string word[50];
    std::cout << "How many words do you want: " << std::endl;
    std::cin >> wordCount;
    std::cout << "Input " << wordCount << " words: " << std::endl;
    for (int i = 0; i < wordCount; ++i)
    {
        std::cin >> word[i];
        calcRowColSize(word, wordCount, row, col);
    }
    generateBoard(front, row, col);
    addWord(front, word, wordCount, row, col);
    printBoard(front, row, col);
    return 0;
}
