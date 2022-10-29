//
// Created by Haibin Cao on 10/27/22.
//

#include "class.h"

void menu()
{
    int choice;
    std::cout << "Welcome to Crossworld Puzzle Land \n" << "Choose an option: \n"
    << "(1) New Puzzle\n" << "(2) Load Previous Puzzle\n" << "(3) Solution for puzzle\n";
    std::cin >> choice;
    switch(choice)
    {
        case 1: {
            std::ofstream fout;
            std::string fileName;
            char front[50][50];
            char back[50][50];
            int row = 0, col = 0, wordCount = 0;
            std::string word[50];
            std::cout << "Enter a new file's name" << std::endl;
            std::cin >> fileName;
            createFile(fout, fileName);
            std::cout << "How many words do you want: " << std::endl;
            std::cin >> wordCount;
            std::cout << "Input " << wordCount << " words: " << std::endl;
            for (int i = 0; i < wordCount; ++i) {
                std::cin >> word[i];
                calcRowColSize(word, wordCount, row, col);
            }
            generateBoard(front, row, col);
            generateBoard(back, row, col);
            addWord(front, word, wordCount, row, col);
            fillPuzzle(front, back, row, col);
            saveFile(front, back, fout, fileName, row, col);
            break;
        }
        case 2:
        {
            char front[50][50];
            std::ofstream fout;
            std::string fileName;
            std::cout << "What was the puzzle's name?" << std::endl;
            std::cin >> fileName;
            readFile(fileName, front);
            break;
        }
        case 3:
            break;
    }
}
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
        int randomChoice = rand() % 3;
        if(randomChoice == 0)
        {
            verticalWord(front, word[i], row, col);
        }
        else if(randomChoice == 1)
        {
            horizontalWord(front, word[i], row, col);
        }
        else if(randomChoice == 2)
        {
            diagonalWord(front, word[i], row, col);
        }
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

void diagonalWord(char front[50][50], std::string word, int row, int col)
{
    int randomRow = rand() % row;
    int randomCol = rand() % col;
    bool isGood = false;
    for (int i = 0; i < word.length(); ++i) {
        if (randomRow + word.length() <= row && randomCol + word.length() <= col) {
            if (front[randomRow + i][randomCol + i] == ' ')
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


        if (randomRow - word.length() >= 0 && randomCol - word.length() >= 0)
        {
            if (front[randomRow - i][randomCol - i] == ' ')
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
            if (randomRow + word.length() <= row && randomCol + word.length() <= col) {
                if (front[randomRow + i][randomCol + i] == ' ')
                {
                   front[randomRow + i][randomCol + i] = word[i];
                    continue;
                }
            }


            if (randomRow - word.length() >= 0 && randomCol - word.length() >= 0)
            {
                if (front[randomRow - i][randomCol - i] == ' ')
                {
                    front[randomRow - i][randomCol - i] = word[i];
                    continue;
                }
            }
        }
    }
    else
    {
        diagonalWord(front, word, row, col);
    }
}

void fillPuzzle(char front[50][50], char back[50][50], int row, int col)
{
    char a = 'a';

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if(front[i][j] == ' ')
            {
                char temp = a + rand()%26;
                back[i][j] = temp;
            }
            else
            {
                back[i][j] = front[i][j];
            }
        }
    }
}

void createFile(std::ofstream &fout, std::string& fileName)
{
    fout.open(fileName);

    if(fout.fail())
    {
        std::cout << "Could not open file";
        exit(1);
    }
    fout.close();
}

void saveFile(char front[50][50], char back[50][50], std::ofstream &fout, std::string fileName, int row, int col)
{
    fout.open(fileName);

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            fout.width(3);
            fout << front[i][j];
        }
        fout << std::endl;
    }

    fout << '.' << std::endl;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            fout.width(3);
            fout << back[i][j];
        }
        fout << std::endl;
    }
    fout.close();
}

void readFile(std::string fileName, char front[50][50])
{
    std::ifstream fin;
    char c;
    int row = 0, col = 0;
    fin.open(fileName);
    if(fin.fail())
    {
        std::cout << "No such file" << std::endl;
        exit(1);
    }

    while(fin >> c)
    {
        col++;
        if(fin.get() == '\n')
        {
            row++;
        }
        else if(fin.get()  == '.')
        {
            break;
        }
    }
    std::cout << col << std::endl << row << std::endl;
    col = col/row;
    while(fin >> c)
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                fin >> front[i][j];
            }
        }

//    printBoard(front, row, col);
}