#include"integrate.h"
#include"constants.h"

void Integrate(double* y, double x)
{
	*y = *y + x * TIMESTEP;
}

void Integrate(double* y, double x, double h)
{
	*y = *y + x * h;
}