#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <stdarg.h>
#include <ctime>
#include <initializer_list>


class Sort
{
    int a[100];
    int n;

public:
    Sort(int nrelem, int mini, int maxi);
    Sort(std::initializer_list<int> list);
    Sort(int arr[], int m);
    Sort(int count, ...);
    Sort(const char* s);
    void InsertSort(bool ascendent);
    void QuickSort(bool ascendent);
    void BubbleSort(bool ascendent);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
