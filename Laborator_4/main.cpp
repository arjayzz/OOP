#include "Sort.h"
int main()
{
	printf("---------------RANDOM------------------\n");
	Sort s1(10, 20, 50);
	printf("Numere random dintr-un interval dat\n");
	s1.Print();
	s1.BubbleSort(false);
	printf("\nDupa Bubble Sort cu ascendent = false:\n");
	s1.Print();

	printf("\n---------------VECTOR------------------\n");
	int v[5] = { 6, 10, 7, 9, 3 };
	Sort s2(v, 5);
	printf("Vector de elemente\n");
	s2.Print();
	s2.InsertSort(true);
	printf("\nDupa Insert Sort cu ascendent = true:\n");
	s2.Print();

	printf("\n---------PARAMETRI VARIADICI-----------\n");
	Sort s3(8, 3, 9, 10, 14, 4, 20, 19, 1);
	printf("Initializare cu parametri variadici\n");
	s3.Print();
	s3.QuickSort(false);
	printf("\nDupa Quick Sort cu ascendent = false:\n");
	s3.Print();

	printf("\n-------------CHAR STRING---------------\n");
	const char* carr = "10,40,100,5,70";
	Sort s4(carr);
	printf("Initializare cu un sir de caractere\n");
	s4.Print();
	s4.BubbleSort(true);
	printf("\nDupa Bubble Sort cu ascendent = true:\n");
	s4.Print();

	printf("\n-------------INIT LIST-----------------\n");
	Sort s5 = { 8, 3, 10, 5, 1, 2, 9 };
	printf("Folosind o lista de initializare\n");
	s5.Print();
	s5.InsertSort(false);
	printf("\nDupa Insert Sort cu ascendent = false:\n");
	s5.Print();
	printf("\n");
}