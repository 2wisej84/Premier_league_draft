#pragma once

struct averages {

	double goalsf_average;
	double goalsa_average;
	double speed_average;
	double technique_average;
	double strength_average;

	averages(double goalsf_average, double goalsa_average, double speed_average, double technique_average, double strength_average);
	const double get_goalsf();
	const double get_goalsa();
	const double get_speed();
	const double get_technique();
	const double get_strength();
};
