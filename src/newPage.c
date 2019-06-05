#include <stdio.h>
#include <stdlib.h>

void newPage(FILE* outFile, int *pageKt, int *lineKt, double pgGross, double pgFica, double pgNet)
{
	
	if (*pageKt != 0)
	{

	*pageKt = *pageKt + 1;
	
	fprintf(outFile, "\nPage %i Totals : \t\t\t\t\t\t\t\t\t\t$%9.2lf\t$%7.2lf\t$%8.2lf\n\n " , *pageKt, pgGross, pgFica, pgNet);
	fprintf(outFile, "\nPage %i \n\n\f" , *pageKt);
	fprintf(outFile, "=============================================================================================\n\n\n");
	fprintf(outFile, "\t\t\t\t\t\t\t\t\t\tACME Tools\n\n");
	fprintf(outFile, "	Emp#	Name					Dept   	New YTD		Gross		FICA		 Net\n");

	*lineKt = 0;
	}
	
	else 
	{
	*pageKt = *pageKt + 1;
	fprintf(outFile, "\nPage %i Totals : \t\t\t\t\t\t\t\t\t\t$%9.2lf\t$%7.2lf\t$%8.2lf\n\n " , *pageKt, pgGross, pgFica, pgNet);//try this
	fprintf(outFile, "\nPage %i \n\n\f" , *pageKt);
	fprintf(outFile, "===============================================================================================\n\n\n");
	fprintf(outFile, "\t\t\t\t\t\t\t\t\t\t\tACME Tools\n\n");
	fprintf(outFile, "	Emp#	Name					Dept   	New YTD		Gross		FICA		 Net\n");

	*lineKt = 0;	
	}
	
	return;


	
}
