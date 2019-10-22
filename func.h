#pragma once
#include <ctime>
void FormMatr(int **m, int n); // form cost matr
void MatrOut(int **m, int n); 
void ArrayOut(int *m, int n);
void MatrDelete(int **m, int n);
void HeuristicAlg(int **m, int n, int k); // third heuristic algotithm
int FindMinCost(int **m, int n, int k, int *from);
void DelRowCol(int **m, int n, int row, int col);
bool CheckCycle(int minj, int *from, int n);
int Cost(int **m, int n, int *from, int *to);
bool NullMatr(int **m, int n);
void CopyMatr(int **mcopy, int **m, int n);