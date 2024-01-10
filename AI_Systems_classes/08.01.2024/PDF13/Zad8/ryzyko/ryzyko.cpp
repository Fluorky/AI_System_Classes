

#include <stdio.h>

#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate)	{ return ( defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate ); }

double ruleActivationMethod_min(double degreeOfSupport, double membership)	{ return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2)	{ return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_ryzyko {

	public: 

	double moc;
	double wiek;


	double ryz;

	private: 

	double moc_duza;
	double moc_mala;
	double moc_srednia;

	
	double wiek_mlody;
	double wiek_sredni;
	double wiek_stary;


	
	double defuzzify_ryz[1000];


	public:
	FunctionBlock_ryzyko();
	void calc();
	void print();

	private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_moc_duza(double x);
	double membership_moc_mala(double x);
	double membership_moc_srednia(double x);
	double membership_ryz_niskie(double x);
	double membership_ryz_srednie(double x);
	double membership_ryz_srednion(double x);
	double membership_ryz_sredniow(double x);
	double membership_ryz_wysokie(double x);
	double membership_wiek_mlody(double x);
	double membership_wiek_sredni(double x);
	double membership_wiek_stary(double x);
	void calc_No1();

};


FunctionBlock_ryzyko::FunctionBlock_ryzyko() {
	ryz = 0.0;
}


void FunctionBlock_ryzyko::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}


void FunctionBlock_ryzyko::calc_No1() {
	
	double degreeOfSupport_1 = 1.0 * ( ruleConnectionMethod_and(wiek_mlody , moc_duza) );
	if( degreeOfSupport_1 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_wysokie(x);
			double y = ruleActivationMethod_min( degreeOfSupport_1 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_2 = 1.0 * ( ruleConnectionMethod_and(wiek_mlody , moc_srednia) );
	if( degreeOfSupport_2 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_sredniow(x);
			double y = ruleActivationMethod_min( degreeOfSupport_2 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_3 = 1.0 * ( ruleConnectionMethod_and(wiek_sredni , moc_duza) );
	if( degreeOfSupport_3 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_sredniow(x);
			double y = ruleActivationMethod_min( degreeOfSupport_3 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_4 = 1.0 * ( ruleConnectionMethod_and(wiek_sredni , moc_srednia) );
	if( degreeOfSupport_4 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_srednie(x);
			double y = ruleActivationMethod_min( degreeOfSupport_4 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_5 = 1.0 * ( ruleConnectionMethod_and(wiek_sredni , moc_mala) );
	if( degreeOfSupport_5 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_srednion(x);
			double y = ruleActivationMethod_min( degreeOfSupport_5 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_6 = 1.0 * ( ruleConnectionMethod_and(wiek_mlody , moc_mala) );
	if( degreeOfSupport_6 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_srednie(x);
			double y = ruleActivationMethod_min( degreeOfSupport_6 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_7 = 1.0 * ( ruleConnectionMethod_and(wiek_stary , moc_duza) );
	if( degreeOfSupport_7 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_srednie(x);
			double y = ruleActivationMethod_min( degreeOfSupport_7 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_8 = 1.0 * ( ruleConnectionMethod_and(wiek_stary , moc_srednia) );
	if( degreeOfSupport_8 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_srednion(x);
			double y = ruleActivationMethod_min( degreeOfSupport_8 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

	
	double degreeOfSupport_9 = 1.0 * ( ruleConnectionMethod_and(wiek_stary , moc_mala) );
	if( degreeOfSupport_9 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = 5.0 + i * 0.02;
			double membership = membership_ryz_niskie(x);
			double y = ruleActivationMethod_min( degreeOfSupport_9 , membership );
			defuzzify_ryz[i] += ruleAccumulationMethod_max( defuzzify_ryz[i], y );
		}
	}

}


void FunctionBlock_ryzyko::defuzzify() {
	double sum_ryz = 0.0;
	double wsum_ryz = 0.0;
	for (int i = 0; i < 1000 ; i++ ) {
		double x = 5.0 + i * 0.02;
		sum_ryz += defuzzify_ryz[i];
		wsum_ryz += x * defuzzify_ryz[i];
	}
	ryz = wsum_ryz / sum_ryz;
}


void FunctionBlock_ryzyko::fuzzify() {
	moc_duza = membership_moc_duza(moc);
	moc_mala = membership_moc_mala(moc);
	moc_srednia = membership_moc_srednia(moc);
	wiek_mlody = membership_wiek_mlody(wiek);
	wiek_sredni = membership_wiek_sredni(wiek);
	wiek_stary = membership_wiek_stary(wiek);
}


double FunctionBlock_ryzyko::membership_moc_duza(double x) {
	if ( x <= 120.0 )	return 0.0;
	if ( x > 170.0 )	return 1.0;
	if ( x <= 170.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 120.0 ) / ( 170.0 - 120.0 ) );
}

double FunctionBlock_ryzyko::membership_moc_mala(double x) {
	if ( x <= 20.0 )	return 1.0;
	if ( x > 70.0 )	return 0.0;
	if ( x <= 70.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 20.0 ) / ( 70.0 - 20.0 ) );
}

double FunctionBlock_ryzyko::membership_moc_srednia(double x) {
	if ( x <= 70.0 )	return 0.0;
	if ( x > 170.0 )	return 0.0;
	if ( x <= 120.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 70.0 ) / ( 120.0 - 70.0 ) );
	if ( x <= 170.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 120.0 ) / ( 170.0 - 120.0 ) );
}

double FunctionBlock_ryzyko::membership_ryz_niskie(double x) {
	if ( x <= 5.0 )	return 1.0;
	if ( x > 10.0 )	return 0.0;
	if ( x <= 10.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 5.0 ) / ( 10.0 - 5.0 ) );
}

double FunctionBlock_ryzyko::membership_ryz_srednie(double x) {
	if ( x <= 10.0 )	return 0.0;
	if ( x > 20.0 )	return 0.0;
	if ( x <= 15.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 10.0 ) / ( 15.0 - 10.0 ) );
	if ( x <= 20.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 15.0 ) / ( 20.0 - 15.0 ) );
}

double FunctionBlock_ryzyko::membership_ryz_srednion(double x) {
	if ( x <= 5.0 )	return 0.0;
	if ( x > 15.0 )	return 0.0;
	if ( x <= 10.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 5.0 ) / ( 10.0 - 5.0 ) );
	if ( x <= 15.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 10.0 ) / ( 15.0 - 10.0 ) );
}

double FunctionBlock_ryzyko::membership_ryz_sredniow(double x) {
	if ( x <= 15.0 )	return 0.0;
	if ( x > 25.0 )	return 0.0;
	if ( x <= 20.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 15.0 ) / ( 20.0 - 15.0 ) );
	if ( x <= 25.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 20.0 ) / ( 25.0 - 20.0 ) );
}

double FunctionBlock_ryzyko::membership_ryz_wysokie(double x) {
	if ( x <= 20.0 )	return 0.0;
	if ( x > 25.0 )	return 1.0;
	if ( x <= 25.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 20.0 ) / ( 25.0 - 20.0 ) );
}

double FunctionBlock_ryzyko::membership_wiek_mlody(double x) {
	if ( x <= 20.0 )	return 1.0;
	if ( x > 40.0 )	return 0.0;
	if ( x <= 40.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 20.0 ) / ( 40.0 - 20.0 ) );
}

double FunctionBlock_ryzyko::membership_wiek_sredni(double x) {
	if ( x <= 30.0 )	return 0.0;
	if ( x > 50.0 )	return 0.0;
	if ( x <= 40.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 30.0 ) / ( 40.0 - 30.0 ) );
	if ( x <= 50.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 40.0 ) / ( 50.0 - 40.0 ) );
}

double FunctionBlock_ryzyko::membership_wiek_stary(double x) {
	if ( x <= 40.0 )	return 0.0;
	if ( x > 60.0 )	return 1.0;
	if ( x <= 60.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 40.0 ) / ( 60.0 - 40.0 ) );
}



void FunctionBlock_ryzyko::print() {
	printf("Function block ryzyko:\n");
	printf("	Input  %20s : %f\n", "moc" , moc);
	printf("	       %20s : %f\n", "moc_duza" , moc_duza);
	printf("	       %20s : %f\n", "moc_mala" , moc_mala);
	printf("	       %20s : %f\n", "moc_srednia" , moc_srednia);
	printf("	Output %20s : %f\n", "ryz" , ryz);
	printf("	Input  %20s : %f\n", "wiek" , wiek);
	printf("	       %20s : %f\n", "wiek_mlody" , wiek_mlody);
	printf("	       %20s : %f\n", "wiek_sredni" , wiek_sredni);
	printf("	       %20s : %f\n", "wiek_stary" , wiek_stary);
}


void FunctionBlock_ryzyko::reset() {
	for( int i=0 ; i < 1000 ; i++ )	{ defuzzify_ryz[i] = 0.0; }
}

int main(int argc, char *argv[]) {
	
	FunctionBlock_ryzyko ryzyko;

	
	if( argc > 1 ) { ryzyko.moc = atof(argv[1]); }
	if( argc > 2 ) { ryzyko.wiek = atof(argv[2]); }

	
	ryzyko.calc();

	
	ryzyko.print();
}
