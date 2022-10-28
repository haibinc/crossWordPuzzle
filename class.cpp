//
// Created by Haibin Cao on 10/27/22.
//

#include "class.h"

void generateBoard(char front[50][50], int& row, int& col)
{

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            front[i][j] = ' ';
        }
    }
}

void calcRowColSize(std::string word[], int wordCount, int& row, int& col)
{
    for (int i = 0; i < wordCount; ++i)
    {
        if (word[i].length() >= row || word[i].length() >= col)
        {
            row = word[i].length()*2;
            col = word[i].length()*2;
        }
    }

}
void printBoard(char front[50][50], int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << front[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addWord(char front[50][50], std::string word[], int wordCount, int row, int col)
{
    for (int i = 0; i < wordCount; ++i) {
        int randomChoice = rand() % 2;
        if(randomChoice == 0)
        {
            verticalWord(front, word[i], row, col);
        }
        else if(randomChoice == 1)
        {
            horizontalWord(front, word[i], row, col);
        }
//        else if(randomChoice == 2)
//        {
//            diagonalWord(front, word[i], row, col);
//        }
    }
}

void horizontalWord(char front[50][50], std::string word, int row, int col)
{
    int randomRow = rand() % row;
    int randomCol = rand() % col;
    bool isGood = false;
    for (int i = 0; i < word.length(); ++i)
    {
        if(randomCol + word.length() <= col)
        {
            if(front[randomRow][randomCol + i] == ' ')
            {
                isGood = true;
                continue;
            }
            else
            {
                isGood = false;
                break;
            }
        }

        if(randomCol - word.length() >= 0)
        {
            if(front[randomRow][randomCol - i] == ' ')
            {
                isGood = true;
                continue;
            }
            else
            {
                isGood = false;
                break;
            }
        }
    }

    if(isGood == true)
    {
        for (int i = 0; i < word.length(); ++i)
        {
            if(randomCol + word.length() <= col)
            {
                if(front[randomRow][randomCol + i] == ' ')
                {
                    front[randomRow][randomCol + i] = word[i];
                    continue;
                }
            }

            if(randomCol - word.length() >= 0)
            {
                if(front[randomRow][randomCol - i] == ' ')
                {
                    front[randomRow][randomCol - i] = word[i];
                    continue;
                }
            }
        }
    }
    else
    {
        horizontalWord(front, word, row, col);
    }
}

void verticalWord(char front[50][50], std::string word, int row, int col)
{
    int randomRow = rand() % row;
    int randomCol = rand() % col;
    bool isGood = false;
    for (int i = 0; i < word.length(); ++i)
    {
        if(randomRow + word.length() <= row)
        {
            if(front[randomRow + i][randomCol] == ' ')
            {
                isGood = true;
                continue;
            }
            else
            {
                isGood = false;
                break;
            }
        }

        if(randomRow - word.length() >= 0)
        {
            if (front[randomRow + i][randomCol] == ' ') {
                isGood = true;
                continue;
            } else {
                isGood = false;
                break;
            }
        }
    }

    if(isGood == true)
    {
        for (int i = 0; i < word.length(); ++i)
        {
            if(randomRow + word.length() <= row)
            {
                if(front[randomRow + i][randomCol] == ' ')
                {
                    front[randomRow + i][randomCol] = word[i];
                    continue;
                }
            }

            if(randomRow - word.length() >= 0)
            {
                if(front[randomRow - i][randomCol] == ' ')
                {
                    front[randomRow - i][randomCol] = word[i];
                    continue;
                }
            }
        }
    }
    else
    {
        verticalWord(front, word, row, col);
    }
}

//void diagonalWord(char front[50][50], std::string word, int row, int col)
//{
//    int randomRow = rand() % row;
//    int randomCol = rand() % col;
//    bool isGood = false;
//    for (int i = 0; i < word.length(); ++i)
//    {
//        if(randomRow + word.length() <= row && front[randomRow + i][randomCol] == ' ')
//        {
//            isGood = true;
//        }
//        else if(randomRow - word.length() >= 0 && front[randomRow - i][randomCol] == ' ')
//        {
//            isGood = true;
//        }
//        else
//        {
//            isGood = false;
//            break;
//        }
//    }
//
//    if(isGood == true)
//    {
//        for (int i = 0; i < word.length(); ++i)
//        {
//            if(randomRow + word.length() < row && front[randomRow + i][randomCol] == ' ')
//            {
//                front[randomRow + i][randomCol] = word[i];
//            }
//            else if(randomRow - word.length() > 0 && front[randomRow - i][randomCol] == ' ')
//            {
//                front[randomRow - i][randomCol] = word[i];
//            }
//        }
//    }
//    else
//    {
//        diagonalWord(front, word, row, col);
//    }
//}
