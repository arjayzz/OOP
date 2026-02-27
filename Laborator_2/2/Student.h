#pragma once
#include<cstring>
#include<iostream>
using namespace std;
class Student
{
private:
	char name[100];
	float math, eng, history;

public:
	void SetName(const char* text);
	const char* GetName() const;
	
	void SetMathGrade(float val);
	float GetMathGrade() const;

	void SetEnglishGrade(float val);
	float GetEnglishGrade() const;

	void SetHistoryGrade(float val);
	float GetHistoryGrade() const;

	float GetAverageGrade() const;
};