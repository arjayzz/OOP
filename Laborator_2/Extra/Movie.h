#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include <chrono>
class Movie
{
private:
	char name[257];
	int year;
	double score;
	int length;
public:
	void set_name(const char* text); const char* get_name() const;
	void set_year(int val); int get_year() const;
	void set_score(double val); double get_score() const;
	void set_length(int val); int get_length() const;
	int passed_years() const;
};