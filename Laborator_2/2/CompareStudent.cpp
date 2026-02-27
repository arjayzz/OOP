#include "CompareStudent.h"

int NameCompare(const Student& s1, const Student& s2)
{
	int a = strcmp(s1.GetName(), s2.GetName());
	return a;
}

int MathGradesCompare(const Student& s1, const Student& s2)
{
	float g1 = s1.GetMathGrade(), g2 = s2.GetMathGrade();
	if (g1 > g2)
		return 1;
	else if (g1 == g2)
		return 0;
	return -1;
}

int EnglishGradesCompare(const Student& s1, const Student& s2)
{
	float g1 = s1.GetEnglishGrade(), g2 = s2.GetEnglishGrade();
	if (g1 > g2)
		return 1;
	else if (g1 == g2)
		return 0;
	return -1;
}
int HistoryGradesCompare(const Student& s1, const Student& s2)
{
	float g1 = s1.GetHistoryGrade(), g2 = s2.GetHistoryGrade();
	if (g1 > g2)
		return 1;
	else if (g1 == g2)
		return 0;
	return -1;
}
int AvgGradeCompare(const Student& s1, const Student& s2)
{
	float g1 = s1.GetAverageGrade(), g2 = s2.GetAverageGrade();
	if (g1 > g2)
		return 1;
	else if (g1 == g2)
		return 0;
	return -1;
}
