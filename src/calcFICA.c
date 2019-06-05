#include <stdio.h>

double calcFICA(double ficaLimit, double ficaRate, double ytd, double gross)
{
	double ficaTax;
	
	if (ytd >= ficaLimit)
		ficaTax = 0;
	else
			if ((ytd + gross) <= ficaLimit)
				
				ficaTax = ficaRate * gross; 
			
			else
				
				ficaTax = (ficaRate * (ficaLimit - ytd)); 
								
	return ficaTax;

}
