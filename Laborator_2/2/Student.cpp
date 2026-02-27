#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"


void Student::SetName(const char* text)
{
	strcpy(name, text);
}

const char* Student::GetName() const
{
	return name;
}

void Student::SetMathGrade(float val)
{
	math = val;
}
float Student::GetMathGrade() const
{
	return math;
}
void Student::SetEnglishGrade(float val)
{
	eng = val;
}
float Student::GetEnglishGrade() const
{
	return eng;
}
void Student::SetHistoryGrade(float val)
{
	history = val;
}
float Student::GetHistoryGrade() const
{
	return history;
}
float Student::GetAverageGrade() const
{
	float a = GetMathGrade(), b = GetEnglishGrade(), c = GetHistoryGrade();
	return (a + b + c) / 3;
}


