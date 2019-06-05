
#include <stdio.h>
#include <stdlib.h>	
#include <string.h> 

int main ()
{
	double calcGross(double payRate, double hours); 
	double calcFICA(double ficaLimit, double ficaRate, double ytd, double gross);
	void newPage(FILE* outFile, int *pageKt, int *lineKt, double gross, double ficaTax, double net);
	FILE *inFile; 
	FILE *outFile;
	FILE *inFicaInfo;
	
	
	char fileInName[31];
	char fileOutName[31];
	char ficaInfo[60] = "ficaInfo.txt";
	char response;
	double ficaLimit;
	double ficaRate;
	int empCount = 0;


	inFicaInfo = fopen(ficaInfo, "r");
	if (inFicaInfo == NULL)
	{
		fclose(inFicaInfo);
		printf("Missing FICA file. Program terminating.");
		exit(1);
	}

	while ((fscanf(inFicaInfo, "%lf%lf" , &ficaLimit, &ficaRate)) != EOF)
	{
		ficaLimit = ficaLimit;
		ficaRate = ficaRate;
	}
	
	
	printf("Enter the name and path of the input file [max 30 characters]: ");
	scanf("%s" , fileInName);
	inFile = fopen(fileInName, "r" ); 
	
	if (inFile == NULL)
	{
		printf("File could not be opened. Input file does not exist! Program terminating.\n"); 
		exit(1);	
	}

	printf("Enter the name & path of the file to hold the results [max 30 characters]:");
	scanf("%s", fileOutName);

	
	if ((outFile = fopen(fileOutName, "r")) != NULL)
{
		printf("\nA file by the name %s already exists. \n" , fileOutName);
		printf("Do you wish to overwrite (Y or N): "); 
		scanf("%*c%c" , &response); 
	if ((response == 'N' ) || (response == 'n'))
	{
		fclose(outFile);
		printf("\nProgram aborted to prevent overwrite\n"); 
		exit(1);
	}
}
	
	outFile = fopen(fileOutName, "w");
	
	if (outFile == NULL)
	{
		printf("Could not create the output file! Program terminating.\n");
		exit(1);
	}
	
	printf("\nThe file \"%s\" has been written to \"%s\", have a nice day!!\n\n" , fileInName, fileOutName);
	
	char givenName[10];
	char surname[10];
	char dept[7];
	double hours, payrate, ytd; 
	double gross, ficaTax, net, newYtd;
	int empNumber;
	int lineKt = 0;
	int pageKt = 0;
	double pgGross, pgFica, pgNet;
	double deptGross, deptFica, deptNet;
	double totalGross, totalFica, totalNet;
	char deptSave[7];
	
	fprintf(outFile, "\t\t\t\t\t\t\t\t\t\tACME Sports Inc.	\n \t\t\t\t\t\t\t\t\"We are the best, you use the best!\"\n");
	fprintf(outFile, "\n_______________________________________________________________________________________________\n\n\f");
	fprintf(outFile, "\t\t\t\t\t\t\t\t\t\tACME Tools\n\n");
	fprintf(outFile, "	Emp#	Name					Dept   	New YTD		Gross		FICA		 Net\n");
	while ((fscanf(inFile, "%i%s%s%s" , &empNumber, givenName, surname, dept)) != EOF)
	{
	
		fscanf(inFile, "%lf%lf%lf" , &ytd, &payrate, &hours);
		
		empCount = empCount + 1;
		
		gross = calcGross(payrate, hours);	
		ficaTax = calcFICA(ficaLimit, ficaRate, ytd, gross);
		net = gross - ficaTax;
		newYtd = ytd + gross;

		//if(strcmp(deptSave, dept)!= 0 && strlen(deptSave) > 1)
		if(strcmp(deptSave, dept)!= 0 && (strcmp(deptSave, ("")) > 0))
		{		
	
			fprintf(outFile, "\n\n\t\tDepartment totals: \t\t\t\t\t\t\t$%9.2lf\t$%7.2lf\t$%8.2lf\n\n"  , deptGross, deptFica, deptNet); 
			
			deptGross = 0; 
			deptFica = 0; 
			deptNet = 0;
			
		}
		
		 if (lineKt == 4)
		 {
		 
		 newPage(outFile, &pageKt, &lineKt, pgGross, pgFica, pgNet);
		 
		 pgGross = 0; 
		 pgFica = 0; 
		 pgNet = 0;
		 
		 }
		 
		fprintf(outFile, "\t%i\t\t%-10s\t%-10s%6s $%10.2lf\t$%9.2lf\t$%7.2lf\t$%8.2lf\n" , empNumber, givenName, surname, dept, newYtd, gross, ficaTax, net);
		
			deptGross += gross;
			deptFica += ficaTax;
			deptNet += net;
			
			pgGross += gross;
			pgFica += ficaTax;
			pgNet += net;
		
			strncpy(deptSave,dept,7);
			lineKt = lineKt + 1;
	
			totalGross += gross;
			totalFica += ficaTax;
			totalNet += net;
	
}	
		
	fprintf(outFile, "\n\n\t\tDepartment totals: \t\t\t\t\t\t\t$%9.2lf\t$%7.2lf\t$%8.2lf\n\n " , deptGross, deptFica, deptNet); 
	pageKt = pageKt + 1;
	fprintf(outFile, "\nPage %i Totals : \t\t\t\t\t\t\t\t\t\t$%9.2lf\t$%7.2lf\t$%8.2lf\n\n" , pageKt, pgGross, pgFica, pgNet);
	fprintf(outFile, "\nPage %i \n\n" , pageKt);
	fprintf(outFile, "\f=============================================================================================\n");
	fprintf(outFile, "\n\t\t\t\t\t\t\t\t\tACME Tools\t\t\t\n");
	fprintf(outFile, "\n\n\t\t\t\t\t\t\t\tReport Summary\n");
	fprintf(outFile, "\nNumber of Records Processed : %i" , empCount);
	fprintf(outFile, "\nTotal Gross: $%10.2lf \nTotal FICA:  $%10.2lf \nTotal Net:   $%10.2lf", totalGross, totalFica, totalNet);
	
		pageKt = pageKt + 1;
	
	fprintf(outFile, "\n\n\nPage %i " , pageKt);
	
		fclose(inFicaInfo);
		fclose(inFile);
		fclose(outFile);
	
		return 0; 
}
