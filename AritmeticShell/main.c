#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include "Solver/FunctionSolver.h"

int main(int argc, char ** argv)
{

		char *str = 0;
		if (argc > 1) // if there is custom file name parameter
		{
			FILE *fi = fopen(argv[1], "r");
			if (fi)
			{
				str = (char*)malloc(sizeof(char) * 1024);
				*str = 0;
				while (!feof(fi))
				{
					char lineBuffer[256];
					fgets(lineBuffer, 255, fi);
					strcat(str, lineBuffer);

				}
			}
			else
			{
				printf("Cannot open file !");
			}
		}
		else // default file name 'input.txt'
		{
			FILE *fi = fopen("input.txt", "r");
			if (fi)
			{
				str = (char*)malloc(sizeof(char) * 1024);
				*str = 0;
				while (!feof(fi))
				{
					char lineBuffer[256];
					fgets(lineBuffer, 255, fi);
					strcat(str, lineBuffer);

				}
			}
			else
			{
				printf("-> You have to pass file name as an argument to process file...\n");
			}

		}

		//start routine
		SolverRoutine(str);

		system("pause");
	
}

