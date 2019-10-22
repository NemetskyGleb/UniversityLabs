#include "func.h"
#include <iostream>
#include <ctime>
void FormMatr(int **m, int n){
	srand(time(0));
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
			 m[i][j] = rand() % 10 + 1;
    	}
    }
	for (int i = 0; i < n; i++)
		m[i][i] = -1;
}
void MatrOut(int **m, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			std::cout << "   " << m[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	}
void MatrDelete(int **m, int n){
	for (int i = 0; i < n; i++)
        delete [] m[i];
    delete [] m;
}
void HeuristicAlg(int **m, int n, int k){
	int *from = new int[n];
	int *to = new int[n];
	int **mcopy = new int*[n];
    for (int i = 0; i < n; i++)
        mcopy[i] = new int[n];
	CopyMatr(mcopy, m, n);
	for(int i = 0; i < n; i++)
		m[i][k - 1] = -1;
	to[0] = FindMinCost(m, n, k - 1, from);
	from[0] = k - 1;
	int i = 1;
	DelRowCol(m, n, from[0], to[0]); // Delete first col
	m[to[0]][from[0]] = 0; // Del cicle
	MatrOut(m, n); // First Matrix out
	while(!NullMatr(m, n)){ // If Matrix is not equal 1 or 0
		from[i] = to[i-1]; // (k -1 ; mc)(mc, ... )...
		to[i] = FindMinCost(m, n, from[i], from); // find new mc
		DelRowCol(m, n, from[i], to[i]); // Del col
		m[to[i]][from[i]] = 0; // Del cycle
		i++;
		MatrOut(m, n);
		//ArrayOut(from, n); std::cout << std::endl;
		//ArrayOut(to, n); std::cout << std::endl;
	}
	from[i] = to[i - 1];
	to[i] = k - 1;
	ArrayOut(from, n); std::cout << std::endl;
	//ArrayOut(to, n);
	int cost = Cost(mcopy, n, from, to);
	std::cout << "Cost = " << cost << std::endl;
	delete[] from;
	delete[] to;
	delete[] mcopy;
}
bool NullMatr(int **m, int n){
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if (m[i][j] > 0)  return false;
		}
	}
	return true;
}
void DelRowCol(int **m, int n, int row, int col){
	for(int i = row, j = 0; j < n; ++j) {
		m[i][j]	= 0;	
	}
	for(int j = col, i = 0; i < n; ++i) {
		m[i][j]	= 0;	
}
}
int FindMinCost(int **m, int n, int k, int *from){
	int min; // not init!!
	int minj; // not init!
	int i = k;
	for (int j = 0; j < n; j++)
		if (m[i][j] > 0){
			min = m[i][j];
			minj = j;
			break;
		}
	for (int j = minj; j < n; j++)
		if(m[i][j] < min && m[i][j] > 0){
			min = m[i][j];
			minj = j;
		}
		/*if(CheckCycle(minj, from, n)) {
			std::cout << "cycle!" << std::endl;
			system("pause");
			exit(-1);
		}
		*/
	return minj;
}
void ArrayOut(int *m, int n){
	for (int i = 0; i < n; ++i)
	{
		std::cout << m[i] + 1 << " ";
	}
}
bool CheckCycle(int minj, int *from, int n){
	for (int i = 0; i < n; i++){
		if (minj == from[i])
			return true;
	}
	return false;
}
int Cost(int **m, int n, int *from, int *to){
	int cost = 0;
	for (int i = 0; i < n;i++){
		cost += m[from[i]][to[i]];
	}
	return cost;
}
void CopyMatr(int **mcopy, int **m, int n){
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
			 mcopy[i][j] = m[i][j];
    	}
    }
}
