#include <iostream>
#include "Student.h"
#include "CompareStudent.h"
using namespace std;
int main()
{
	Student s1;
	char text[100] = "Ana Maria";
	s1.SetName(text);
	s1.SetMathGrade(8);
	s1.SetEnglishGrade(9);
	s1.SetHistoryGrade(6);

	Student s2;
	char text2[100] = "Pop Popescu";
	s2.SetName(text2);
	s2.SetMathGrade(5);
	s2.SetEnglishGrade(6);
	s2.SetHistoryGrade(10);

	printf("%s are numele ", s1.GetName());
	(NameCompare(s1, s2) == 0) ? printf("egal cu") : ((NameCompare(s1, s2) == 1) ? printf("mai mare decat") : printf("mai mic decat")); printf(" numele studentului %s\n", s2.GetName());

	printf("%s are nota, %.2f, la matematica ", s1.GetName(), s1.GetMathGrade());
	(MathGradesCompare(s1, s2) == 0) ? printf("egala cu") : ((MathGradesCompare(s1, s2) == 1) ? printf("mai mare decat") : printf("mai mica decat")); printf(" nota studentului %s, %.2f\n", s2.GetName(),s2.GetMathGrade());

	printf("%s are nota, %.2f, la engleza ", s1.GetName(), s1.GetEnglishGrade());
	(EnglishGradesCompare(s1, s2) == 0) ? printf("egala cu") : ((EnglishGradesCompare(s1, s2) == 1) ? printf("mai mare decat") : printf("mai mica decat")); printf(" nota studentului %s, %.2f\n", s2.GetName(), s2.GetEnglishGrade());

	printf("%s are nota, %.2f, la istorie ", s1.GetName(), s1.GetHistoryGrade());
	(HistoryGradesCompare(s1, s2) == 0) ? printf("egala cu") : ((HistoryGradesCompare(s1, s2) == 1) ? printf("mai mare decat") : printf("mai mica decat")); printf(" nota studentului %s, %.2f \n", s2.GetName(), s2.GetHistoryGrade());

	printf("%s are media, %.2f,  ", s1.GetName(), s1.GetAverageGrade());
	(AvgGradeCompare(s1, s2) == 0) ? printf("egala cu") : ((AvgGradeCompare(s1, s2) == 1) ? printf("mai mare decat") : printf("mai mica decat")); printf(" media studentului %s, %.2f \n", s2.GetName(),s2.GetAverageGrade());
	
}