#include <stdio.h>


double calcGross(double payrate, double hours)

{
	double gross;
	double over40;
	
	if(hours > 40.0)
	{
		over40 = hours - 40.0;
		gross = ((40.0 * payrate) + (over40 * 1.50 * payrate));
	}
	else
	{
		gross = payrate * hours;

	}
	
	return gross;
	
}

