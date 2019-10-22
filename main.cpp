#include "func.h"
#include <iostream>
#include <conio.h>
int main()
{
	int n, k;
	std::cout << "Enter amount of cities:\n";
	std::cin >> n;
	int **m = new int*[n];
    for (int i = 0; i < n; i++)
        m[i] = new int[n];
	FormMatr(m, n);
	MatrOut(m,n);
	std::cout << "Enter begin city:\n";
	std::cin >> k;
	HeuristicAlg(m, n, k);
	system("pause");
	return 0;
}