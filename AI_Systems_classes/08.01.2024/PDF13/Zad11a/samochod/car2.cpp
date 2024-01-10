#include <stdio.h>

#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate)	{ return ( defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate ); }

double ruleActivationMethod_min(double degreeOfSupport, double membership)	{ return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2)	{ return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_car {

	public: 

	double distance;
	double speed;

	
	double change;

	private: 
	
	double distance_far;
	double distance_near;
	double distance_very_far;
	double distance_very_near;

	
	double speed_fast;
	double speed_slow;
	double speed_very_fast;
	double speed_very_slow;


	
	double defuzzify_change[1000];


	public:
	FunctionBlock_car();
	void calc();
	void print();

	private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_change_big_increase(double x);
	double membership_change_big_reduce(double x);
	double membership_change_increase(double x);
	double membership_change_keep(double x);
	double membership_change_reduce(double x);
	double membership_distance_far(double x);
	double membership_distance_near(double x);
	double membership_distance_very_far(double x);
	double membership_distance_very_near(double x);
	double membership_speed_fast(double x);
	double membership_speed_slow(double x);
	double membership_speed_very_fast(double x);
	double membership_speed_very_slow(double x);
	void calc_No1();

};


FunctionBlock_car::FunctionBlock_car() {
	change = 0.0;
}


void FunctionBlock_car::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}


void FunctionBlock_car::calc_No1() {
	
	double degreeOfSupport_1 = 1.0 * ( ruleConnectionMethod_and(distance_near , speed_slow) );
	if( degreeOfSupport_1 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -20.0 + i * 0.035;
			double membership = membership_change_keep(x);
			double y = ruleActivationMethod_min( degreeOfSupport_1 , membership );
			defuzzify_change[i] += ruleAccumulationMethod_max( defuzzify_change[i], y );
		}
	}

	
	double degreeOfSupport_2 = 1.0 * ( ruleConnectionMethod_and(distance_near , speed_fast) );
	if( degreeOfSupport_2 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -20.0 + i * 0.035;
			double membership = membership_change_big_reduce(x);
			double y = ruleActivationMethod_min( degreeOfSupport_2 , membership );
			defuzzify_change[i] += ruleAccumulationMethod_max( defuzzify_change[i], y );
		}
	}

	
	double degreeOfSupport_3 = 1.0 * ( ruleConnectionMethod_and(distance_far , speed_slow) );
	if( degreeOfSupport_3 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -20.0 + i * 0.035;
			double membership = membership_change_increase(x);
			double y = ruleActivationMethod_min( degreeOfSupport_3 , membership );
			defuzzify_change[i] += ruleAccumulationMethod_max( defuzzify_change[i], y );
		}
	}

	
	double degreeOfSupport_4 = 1.0 * ( ruleConnectionMethod_and(distance_far , speed_fast) );
	if( degreeOfSupport_4 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -20.0 + i * 0.035;
			double membership = membership_change_keep(x);
			double y = ruleActivationMethod_min( degreeOfSupport_4 , membership );
			defuzzify_change[i] += ruleAccumulationMethod_max( defuzzify_change[i], y );
		}
	}

	
	double degreeOfSupport_5 = 1.0 * ( ruleConnectionMethod_and(distance_very_near , speed_very_fast) );
	if( degreeOfSupport_5 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -20.0 + i * 0.035;
			double membership = membership_change_big_reduce(x);
			double y = ruleActivationMethod_min( degreeOfSupport_5 , membership );
			defuzzify_change[i] += ruleAccumulationMethod_max( defuzzify_change[i], y );
		}
	}

	
	double degreeOfSupport_6 = 1.0 * ( ruleConnectionMethod_and(distance_very_far , speed_very_slow) );
	if( degreeOfSupport_6 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -20.0 + i * 0.035;
			double membership = membership_change_big_increase(x);
			double y = ruleActivationMethod_min( degreeOfSupport_6 , membership );
			defuzzify_change[i] += ruleAccumulationMethod_max( defuzzify_change[i], y );
		}
	}

}


void FunctionBlock_car::defuzzify() {
	double sum_change = 0.0;
	double wsum_change = 0.0;
	for (int i = 0; i < 1000 ; i++ ) {
		double x = -20.0 + i * 0.035;
		sum_change += defuzzify_change[i];
		wsum_change += x * defuzzify_change[i];
	}
	change = wsum_change / sum_change;
}


void FunctionBlock_car::fuzzify() {
	distance_far = membership_distance_far(distance);
	distance_near = membership_distance_near(distance);
	distance_very_far = membership_distance_very_far(distance);
	distance_very_near = membership_distance_very_near(distance);
	speed_fast = membership_speed_fast(speed);
	speed_slow = membership_speed_slow(speed);
	speed_very_fast = membership_speed_very_fast(speed);
	speed_very_slow = membership_speed_very_slow(speed);
}

 
double FunctionBlock_car::membership_change_big_increase(double x) {
	if ( x <= 5.0 )	return 0.0;
	if ( x > 15.0 )	return 1.0;
	if ( x <= 10.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 5.0 ) / ( 10.0 - 5.0 ) );
	if ( x <= 15.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 10.0 ) / ( 15.0 - 10.0 ) );
}

double FunctionBlock_car::membership_change_big_reduce(double x) {
	if ( x <= -20.0 )	return 1.0;
	if ( x > -10.0 )	return 0.0;
	if ( x <= -15.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - -20.0 ) / ( -15.0 - -20.0 ) );
	if ( x <= -10.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - -15.0 ) / ( -10.0 - -15.0 ) );
}

double FunctionBlock_car::membership_change_increase(double x) {
	if ( x <= 0.0 )	return 0.0;
	if ( x > 7.0 )	return 0.0;
	if ( x <= 5.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 0.0 ) / ( 5.0 - 0.0 ) );
	if ( x <= 7.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 5.0 ) / ( 7.0 - 5.0 ) );
}

double FunctionBlock_car::membership_change_keep(double x) {
	if ( x <= -6.0 )	return 0.0;
	if ( x > 3.0 )	return 0.0;
	if ( x <= 0.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - -6.0 ) / ( 0.0 - -6.0 ) );
	if ( x <= 3.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 0.0 ) / ( 3.0 - 0.0 ) );
}

double FunctionBlock_car::membership_change_reduce(double x) {
	if ( x <= -15.0 )	return 0.0;
	if ( x > -5.0 )	return 0.0;
	if ( x <= -10.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - -15.0 ) / ( -10.0 - -15.0 ) );
	if ( x <= -5.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - -10.0 ) / ( -5.0 - -10.0 ) );
}

double FunctionBlock_car::membership_distance_far(double x) {
	if ( x <= 250.0 )	return 0.0;
	if ( x > 400.0 )	return 0.0;
	if ( x <= 325.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 250.0 ) / ( 325.0 - 250.0 ) );
	if ( x <= 400.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 325.0 ) / ( 400.0 - 325.0 ) );
}

double FunctionBlock_car::membership_distance_near(double x) {
	if ( x <= 100.0 )	return 0.0;
	if ( x > 300.0 )	return 0.0;
	if ( x <= 200.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 100.0 ) / ( 200.0 - 100.0 ) );
	if ( x <= 300.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 200.0 ) / ( 300.0 - 200.0 ) );
}

double FunctionBlock_car::membership_distance_very_far(double x) {
	if ( x <= 350.0 )	return 0.0;
	if ( x > 500.0 )	return 1.0;
	if ( x <= 420.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 350.0 ) / ( 420.0 - 350.0 ) );
	if ( x <= 500.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 420.0 ) / ( 500.0 - 420.0 ) );
}

double FunctionBlock_car::membership_distance_very_near(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 200.0 )	return 0.0;
	if ( x <= 75.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 75.0 - 0.0 ) );
	if ( x <= 200.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 75.0 ) / ( 200.0 - 75.0 ) );
}

double FunctionBlock_car::membership_speed_fast(double x) {
	if ( x <= 25.0 )	return 0.0;
	if ( x > 100.0 )	return 0.0;
	if ( x <= 70.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 25.0 ) / ( 70.0 - 25.0 ) );
	if ( x <= 100.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 70.0 ) / ( 100.0 - 70.0 ) );
}

double FunctionBlock_car::membership_speed_slow(double x) {
	if ( x <= 15.0 )	return 0.0;
	if ( x > 40.0 )	return 0.0;
	if ( x <= 20.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 15.0 ) / ( 20.0 - 15.0 ) );
	if ( x <= 40.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 20.0 ) / ( 40.0 - 20.0 ) );
}

double FunctionBlock_car::membership_speed_very_fast(double x) {
	if ( x <= 90.0 )	return 0.0;
	if ( x > 200.0 )	return 1.0;
	if ( x <= 150.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 90.0 ) / ( 150.0 - 90.0 ) );
	if ( x <= 200.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 150.0 ) / ( 200.0 - 150.0 ) );
}

double FunctionBlock_car::membership_speed_very_slow(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 20.0 )	return 0.0;
	if ( x <= 10.0 )	return 1.0 + ( 1.0 - 1.0 ) * ( ( x - 0.0 ) / ( 10.0 - 0.0 ) );
	if ( x <= 20.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 10.0 ) / ( 20.0 - 10.0 ) );
}



void FunctionBlock_car::print() {
	printf("Function block car:\n");
	printf("	Output %20s : %f\n", "change" , change);
	printf("	Input  %20s : %f\n", "distance" , distance);
	printf("	       %20s : %f\n", "distance_far" , distance_far);
	printf("	       %20s : %f\n", "distance_near" , distance_near);
	printf("	       %20s : %f\n", "distance_very_far" , distance_very_far);
	printf("	       %20s : %f\n", "distance_very_near" , distance_very_near);
	printf("	Input  %20s : %f\n", "speed" , speed);
	printf("	       %20s : %f\n", "speed_fast" , speed_fast);
	printf("	       %20s : %f\n", "speed_slow" , speed_slow);
	printf("	       %20s : %f\n", "speed_very_fast" , speed_very_fast);
	printf("	       %20s : %f\n", "speed_very_slow" , speed_very_slow);
}

t
void FunctionBlock_car::reset() {
	for( int i=0 ; i < 1000 ; i++ )	{ defuzzify_change[i] = 0.0; }
}

int main(int argc, char *argv[]) {

	FunctionBlock_car car;


	if( argc > 1 ) { car.distance = atof(argv[1]); }
	if( argc > 2 ) { car.speed = atof(argv[2]); }


	car.calc();

	
	car.print();
}
