// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	printf("Hello World!");
	char string1[] = "applesedndudbananases";
	char string2[] = "bananas";
	//char string2[] = "wapplesedsthdubananasesaasd";
	char *longer = string2, *shorter = string1;
	int maxchunksize, i, j, k, l, ctr;
	int notfound = 1;
	int longestsofar = 0, indexoflongestsofar = -1;
	if (strlen(string1) > strlen(string2))
	{
		longer = string1;
		shorter = string2;
	}
	maxchunksize = strlen(shorter); //maxchunksize will be the longest possible substring
	system("cls");
	for (i = 0; i < strlen(longer) - 3 && longestsofar < maxchunksize; i++)
	{
		for (j = 0; shorter[j] != '\0' && shorter[j] != longer[i]; j++); //skip the first characters
		for (; j < strlen(shorter) - 3; j++) //stop at first character match
		{
			for (k = 0, ctr=1; shorter[k] != '\0' && shorter[j + k] == longer[i + k]; k++, ctr++); // keep on counting while equal
			if (ctr > longestsofar)
			{
				longestsofar = ctr - 1; // take back one kadam to honor the for-loop gods
				indexoflongestsofar = i;
			}
		}
	}
	printf("\n%d chars starting @%d of the longer string > ", longestsofar, indexoflongestsofar );
	for (i = indexoflongestsofar; longer[i] != '\0' && i < indexoflongestsofar + longestsofar; i++)
		printf("%c", longer[i]);
}

