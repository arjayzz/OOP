#include "Movie.h"

void Movie::set_name(const char* text)
{
	strcpy(name, text);
}
const char* Movie::get_name() const
{
	return name;
}
void Movie::set_year(int val)
{
	year = val;
}
int Movie::get_year() const
{
	return year;
}
void Movie::set_score(double val)
{
	if (val >= 1 && val <= 10)
		score = val;
}
double Movie::get_score() const
{
	return score;
}
void Movie::set_length (int val)
{
	length = val;
}
int Movie::get_length() const
{
	return length;
}
int Movie::passed_years() const
{
	auto now = std::chrono::system_clock::now();
	std::chrono::year_month_day ymd = std::chrono::floor<std::chrono::days>(now);
	return (int)ymd.year() - year;
}