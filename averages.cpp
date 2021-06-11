#include "averages.h"


// Get all the averages from the league and store in a struct
averages::averages(double goalsf_average, double goalsa_average, double speed_average, double technique_average, double strength_average)
	:goalsf_average{goalsf_average}, goalsa_average{ goalsa_average }, speed_average{ speed_average }, technique_average{ technique_average }, strength_average{ strength_average }
{

}

const double averages::get_goalsf()
{
	return goalsf_average;
}

const double averages::get_goalsa()
{
	return goalsa_average;
}

const double averages::get_speed()
{
	return speed_average;
}

const double averages::get_technique()
{
	return technique_average;
}

const double averages::get_strength()
{
	return strength_average;
}

