#include <stdio.h>
float operator""_Fahrenheit(unsigned long long int x)
{
	return (((float)x) - 32.0) / 1.8;
}

float operator""_Kelvin(unsigned long long int x)
{
	return ((float)x) - 273.15;
}
int main()
{
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	printf("300 Kelvin to Celsius: %.2f and 120 Fahrenheit to Celsius: %.2f ", a, b);
	return 0;
}