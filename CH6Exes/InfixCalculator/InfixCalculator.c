#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	char* expcpy = (char*)malloc(len + 1);
	strcpy_s(expcpy, len + 1, exp);

	ConvToRPNExp(expcpy);
	int result = EvalRPNExp(expcpy);

	free(expcpy);
	return result;
}