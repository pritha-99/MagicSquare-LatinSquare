#ifndef SQUARE_H
#define SQUARE_H
void displayMagicSquare(int **magicSquare, int n);
void createOddMagicsqr(int);
bool checkMagicsqr(int,int**);

void createDoublyEvenMsqr(int n);
void fillQuarter(int **magicSquare, int firstRow, int lastRow, int firstCol, int lastCol, int num, int lastNum);
void exchangeCell(int i, int j, int** magicSquare, int n);
void createSinglyEvenMsqr(int n);
void createLatinsqr(int);
#endif
