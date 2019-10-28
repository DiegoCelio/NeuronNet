#include "random.h"
#include <random>

RandomNumbers::RandomNumbers(unsigned long int s)
{
	if(s<=0) {
		std::random_device rd;
		seed = rd();
		}
	else seed = s;
		
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& vect, double lower, double upper)
{
	for (auto& element : vect) {
		element = uniform_double(lower, upper);
	}
}


double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> unif(lower, upper);
	return unif(rng);
}

void RandomNumbers::normal(std::vector<double>& vect, double mean, double sd)
{
	for (auto& element : vect) {
		element = normal(mean, sd);
	}
}

double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<> norm(mean, sd);
	return norm(rng);
}

void RandomNumbers::poisson(std::vector<int>& vect, double mean)
{
	for (auto& element : vect) {
		element = poisson(mean);
	}		
}

int RandomNumbers::poisson(double mean)
{
    std::poisson_distribution<int> pois(mean);
	return pois(rng);
}
