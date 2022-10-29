//
// Created by Haibin Cao on 10/27/22.
//

#ifndef CROSSWORDPUZZLE_CLASS_H
#define CROSSWORDPUZZLE_CLASS_H
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>

void menu();
void generateBoard(char front[50][50], int& row, int& col);
void calcRowColSize(std::string word[], int wordCount, int& row, int& col);
void printBoard(char front[50][50], int row, int col);
void addWord(char front[50][50], std::string word[], int wordCount, int row, int col);
void verticalWord(char front[50][50], std::string word, int row, int col);
void horizontalWord(char front[50][50], std::string word, int row, int col);
void diagonalWord(char front[50][50], std::string word, int row, int col);
void fillPuzzle(char front[50][50], char back[50][50], int row, int col);
void createFile(std::ofstream &fout, std::string& fileName);
void saveFile(char front[50][50], char back[50][50], std::ofstream &fout, std::string fileName, int row, int col);
void readFile(std::string fileName, char front[50][50]);

#endif //CROSSWORDPUZZLE_CLASS_H
