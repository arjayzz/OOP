#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
int slength(char* txt)
{
	int i = 0;
	while (txt[i] != '\0')
		i = i + 1;
	return i;
}

void scopy(char* s1, char* s2) //s1 < s2
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i]; i++;
	}
	s1[i] = '\0';
}

int scomp(char* s1, char* s2)
{
	int i = 0;
	while (s1[i]!='\0' || s2[i] != '\0')
	{
		if ((s1[i] < s2[i]) || (s1[i] == '\0' && s2[i] != '\0'))
		{
			return -1; 
		}
	
			if (s1[i] > s2[i] || (s2[i] == '\0' && s1[i] != '\0'))
			{
				return 1; 
			}
			i++;
	}
	return 0;
}

int main()
{
	char s[256], tempcuv[256];
	char txt[30][256],aux[256];

	scanf("%[^\n]",s);

	int i = 0, cont = 0, k = 0;

	while (s[i] != '\0')
	{	if (s[i] != ' ')
		{
			tempcuv[k] = s[i];
			k++;
		}
		tempcuv[k] = '\0';
		if ((s[i] == ' ') || (s[i+1] == '\0'))
		{
			scopy(txt[cont], tempcuv);
			cont++;
			k = 0;
			tempcuv[0] = '\0';
		}
		i++;
	}
	
	for (int j = 0; j < cont-1; j++)
		for (int a = j+1; a < cont; a++)
		{
			if (slength(txt[j]) < slength(txt[a]))
			{
				scopy(aux, txt[a]);
				scopy(txt[a], txt[j]);
				scopy(txt[j], aux);
			}
			if (slength(txt[j]) == slength(txt[a]))
			{
				if (scomp(txt[j], txt[a]) > 0)
				{
					scopy(aux, txt[j]);
					scopy(txt[j], txt[a]);
					scopy(txt[a], aux);
				}
			}
		}

	for (int j = 0; j < cont; j++)
		printf("%s\n", txt[j]);
	
}