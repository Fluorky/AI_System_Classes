#include <stdio.h>

#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate)	{ return ( defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate ); }

double ruleActivationMethod_min(double degreeOfSupport, double membership)	{ return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2)	{ return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_car1 {

	public: 

	double dystans;
	double predkosc;


	double zmiana_predkosci;

	private: 

	double dystans_bdlugi;
	double dystans_bkrotki;
	double dystans_dlugi;
	double dystans_krotki;
	double dystans_sredni;


	double predkosc_bduza;
	double predkosc_bmala;
	double predkosc_duza;
	double predkosc_mala;
	double predkosc_srednia;


	
	double defuzzify_zmiana_predkosci[1000];


	public:
	FunctionBlock_car1();
	void calc();
	void print();

	private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_dystans_bdlugi(double x);
	double membership_dystans_bkrotki(double x);
	double membership_dystans_dlugi(double x);
	double membership_dystans_krotki(double x);
	double membership_dystans_sredni(double x);
	double membership_predkosc_bduza(double x);
	double membership_predkosc_bmala(double x);
	double membership_predkosc_duza(double x);
	double membership_predkosc_mala(double x);
	double membership_predkosc_srednia(double x);
	double membership_zmiana_predkosci_bbredukuj(double x);
	double membership_zmiana_predkosci_bredukuj(double x);
	double membership_zmiana_predkosci_bzwiekszaj(double x);
	double membership_zmiana_predkosci_redukuj(double x);
	double membership_zmiana_predkosci_utrzymaj(double x);
	double membership_zmiana_predkosci_zwiekszaj(double x);
	void calc_No1();

};


FunctionBlock_car1::FunctionBlock_car1() {
	zmiana_predkosci = 0.0;
}


void FunctionBlock_car1::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}


void FunctionBlock_car1::calc_No1() {
	
	double degreeOfSupport_1 = 1.0 * ( ruleConnectionMethod_and(dystans_krotki , predkosc_bmala) );
	if( degreeOfSupport_1 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_zwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_1 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_2 = 1.0 * ( ruleConnectionMethod_and(dystans_krotki , predkosc_mala) );
	if( degreeOfSupport_2 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_utrzymaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_2 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_3 = 1.0 * ( ruleConnectionMethod_and(dystans_krotki , predkosc_srednia) );
	if( degreeOfSupport_3 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_redukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_3 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_4 = 1.0 * ( ruleConnectionMethod_and(dystans_krotki , predkosc_duza) );
	if( degreeOfSupport_4 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bredukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_4 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_5 = 1.0 * ( ruleConnectionMethod_and(dystans_krotki , predkosc_bduza) );
	if( degreeOfSupport_5 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bbredukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_5 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_6 = 1.0 * ( ruleConnectionMethod_and(dystans_bkrotki , predkosc_bmala) );
	if( degreeOfSupport_6 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_utrzymaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_6 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_7 = 1.0 * ( ruleConnectionMethod_and(dystans_bkrotki , predkosc_mala) );
	if( degreeOfSupport_7 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_redukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_7 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_8 = 1.0 * ( ruleConnectionMethod_and(dystans_bkrotki , predkosc_srednia) );
	if( degreeOfSupport_8 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bredukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_8 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_9 = 1.0 * ( ruleConnectionMethod_and(dystans_bkrotki , predkosc_duza) );
	if( degreeOfSupport_9 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bbredukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_9 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_10 = 1.0 * ( ruleConnectionMethod_and(dystans_bkrotki , predkosc_bduza) );
	if( degreeOfSupport_10 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bbredukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_10 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_11 = 1.0 * ( ruleConnectionMethod_and(dystans_sredni , predkosc_bmala) );
	if( degreeOfSupport_11 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_11 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_12 = 1.0 * ( ruleConnectionMethod_and(dystans_sredni , predkosc_mala) );
	if( degreeOfSupport_12 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_zwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_12 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_13 = 1.0 * ( ruleConnectionMethod_and(dystans_sredni , predkosc_srednia) );
	if( degreeOfSupport_13 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_utrzymaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_13 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_14 = 1.0 * ( ruleConnectionMethod_and(dystans_sredni , predkosc_duza) );
	if( degreeOfSupport_14 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_redukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_14 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_15 = 1.0 * ( ruleConnectionMethod_and(dystans_sredni , predkosc_bduza) );
	if( degreeOfSupport_15 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bredukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_15 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_16 = 1.0 * ( ruleConnectionMethod_and(dystans_dlugi , predkosc_bmala) );
	if( degreeOfSupport_16 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_16 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_17 = 1.0 * ( ruleConnectionMethod_and(dystans_dlugi , predkosc_mala) );
	if( degreeOfSupport_17 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_17 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}


	double degreeOfSupport_18 = 1.0 * ( ruleConnectionMethod_and(dystans_dlugi , predkosc_srednia) );
	if( degreeOfSupport_18 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_zwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_18 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_19 = 1.0 * ( ruleConnectionMethod_and(dystans_dlugi , predkosc_duza) );
	if( degreeOfSupport_19 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_utrzymaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_19 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_20 = 1.0 * ( ruleConnectionMethod_and(dystans_dlugi , predkosc_bduza) );
	if( degreeOfSupport_20 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_redukuj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_20 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_21 = 1.0 * ( ruleConnectionMethod_and(dystans_bdlugi , predkosc_bmala) );
	if( degreeOfSupport_21 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_21 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_22 = 1.0 * ( ruleConnectionMethod_and(dystans_bdlugi , predkosc_mala) );
	if( degreeOfSupport_22 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_22 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_23 = 1.0 * ( ruleConnectionMethod_and(dystans_bdlugi , predkosc_srednia) );
	if( degreeOfSupport_23 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_23 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_24 = 1.0 * ( ruleConnectionMethod_and(dystans_bdlugi , predkosc_duza) );
	if( degreeOfSupport_24 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_bzwiekszaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_24 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

	
	double degreeOfSupport_25 = 1.0 * ( ruleConnectionMethod_and(dystans_bdlugi , predkosc_bduza) );
	if( degreeOfSupport_25 > 0 ) {
		for (int i = 0 ; i < 1000 ; i++ ) {
			double x = -120.0 + i * 0.24;
			double membership = membership_zmiana_predkosci_utrzymaj(x);
			double y = ruleActivationMethod_min( degreeOfSupport_25 , membership );
			defuzzify_zmiana_predkosci[i] += ruleAccumulationMethod_max( defuzzify_zmiana_predkosci[i], y );
		}
	}

}


void FunctionBlock_car1::defuzzify() {
	double sum_zmiana_predkosci = 0.0;
	double wsum_zmiana_predkosci = 0.0;
	for (int i = 0; i < 1000 ; i++ ) {
		double x = -120.0 + i * 0.24;
		sum_zmiana_predkosci += defuzzify_zmiana_predkosci[i];
		wsum_zmiana_predkosci += x * defuzzify_zmiana_predkosci[i];
	}
	zmiana_predkosci = wsum_zmiana_predkosci / sum_zmiana_predkosci;
}


void FunctionBlock_car1::fuzzify() {
	dystans_bdlugi = membership_dystans_bdlugi(dystans);
	dystans_bkrotki = membership_dystans_bkrotki(dystans);
	dystans_dlugi = membership_dystans_dlugi(dystans);
	dystans_krotki = membership_dystans_krotki(dystans);
	dystans_sredni = membership_dystans_sredni(dystans);
	predkosc_bduza = membership_predkosc_bduza(predkosc);
	predkosc_bmala = membership_predkosc_bmala(predkosc);
	predkosc_duza = membership_predkosc_duza(predkosc);
	predkosc_mala = membership_predkosc_mala(predkosc);
	predkosc_srednia = membership_predkosc_srednia(predkosc);
}

 
double FunctionBlock_car1::membership_dystans_bdlugi(double x) {
	if ( x <= 750.0 )	return 0.0;
	if ( x > 1000.0 )	return 1.0;
	if ( x <= 1000.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 750.0 ) / ( 1000.0 - 750.0 ) );
}

double FunctionBlock_car1::membership_dystans_bkrotki(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 60.0 )	return 0.0;
	if ( x <= 60.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 0.0 ) / ( 60.0 - 0.0 ) );
}

double FunctionBlock_car1::membership_dystans_dlugi(double x) {
	if ( x <= 500.0 )	return 0.0;
	if ( x > 800.0 )	return 0.0;
	if ( x <= 650.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 500.0 ) / ( 650.0 - 500.0 ) );
	if ( x <= 800.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 650.0 ) / ( 800.0 - 650.0 ) );
}

double FunctionBlock_car1::membership_dystans_krotki(double x) {
	if ( x <= 50.0 )	return 0.0;
	if ( x > 450.0 )	return 0.0;
	if ( x <= 250.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 50.0 ) / ( 250.0 - 50.0 ) );
	if ( x <= 450.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 250.0 ) / ( 450.0 - 250.0 ) );
}

double FunctionBlock_car1::membership_dystans_sredni(double x) {
	if ( x <= 250.0 )	return 0.0;
	if ( x > 750.0 )	return 0.0;
	if ( x <= 500.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 250.0 ) / ( 500.0 - 250.0 ) );
	if ( x <= 750.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 500.0 ) / ( 750.0 - 500.0 ) );
}

double FunctionBlock_car1::membership_predkosc_bduza(double x) {
	if ( x <= 100.0 )	return 0.0;
	if ( x > 120.0 )	return 1.0;
	if ( x <= 120.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 100.0 ) / ( 120.0 - 100.0 ) );
}

double FunctionBlock_car1::membership_predkosc_bmala(double x) {
	if ( x <= 0.0 )	return 1.0;
	if ( x > 20.0 )	return 0.0;
	if ( x <= 20.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 0.0 ) / ( 20.0 - 0.0 ) );
}

double FunctionBlock_car1::membership_predkosc_duza(double x) {
	if ( x <= 75.0 )	return 0.0;
	if ( x > 105.0 )	return 0.0;
	if ( x <= 90.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 75.0 ) / ( 90.0 - 75.0 ) );
	if ( x <= 105.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 90.0 ) / ( 105.0 - 90.0 ) );
}

double FunctionBlock_car1::membership_predkosc_mala(double x) {
	if ( x <= 15.0 )	return 0.0;
	if ( x > 45.0 )	return 0.0;
	if ( x <= 30.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 15.0 ) / ( 30.0 - 15.0 ) );
	if ( x <= 45.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 30.0 ) / ( 45.0 - 30.0 ) );
}

double FunctionBlock_car1::membership_predkosc_srednia(double x) {
	if ( x <= 40.0 )	return 0.0;
	if ( x > 80.0 )	return 0.0;
	if ( x <= 60.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 40.0 ) / ( 60.0 - 40.0 ) );
	if ( x <= 80.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 60.0 ) / ( 80.0 - 60.0 ) );
}

double FunctionBlock_car1::membership_zmiana_predkosci_bbredukuj(double x) {
	if ( x <= -120.0 )	return 1.0;
	if ( x > -115.0 )	return 0.0;
	if ( x <= -115.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - -120.0 ) / ( -115.0 - -120.0 ) );
}

double FunctionBlock_car1::membership_zmiana_predkosci_bredukuj(double x) {
	if ( x <= -120.0 )	return 0.0;
	if ( x > -60.0 )	return 0.0;
	if ( x <= -100.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - -120.0 ) / ( -100.0 - -120.0 ) );
	if ( x <= -60.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - -100.0 ) / ( -60.0 - -100.0 ) );
}

double FunctionBlock_car1::membership_zmiana_predkosci_bzwiekszaj(double x) {
	if ( x <= 75.0 )	return 0.0;
	if ( x > 120.0 )	return 1.0;
	if ( x <= 120.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 75.0 ) / ( 120.0 - 75.0 ) );
}

double FunctionBlock_car1::membership_zmiana_predkosci_redukuj(double x) {
	if ( x <= -70.0 )	return 0.0;
	if ( x > -30.0 )	return 0.0;
	if ( x <= -50.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - -70.0 ) / ( -50.0 - -70.0 ) );
	if ( x <= -30.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - -50.0 ) / ( -30.0 - -50.0 ) );
}

double FunctionBlock_car1::membership_zmiana_predkosci_utrzymaj(double x) {
	if ( x <= -60.0 )	return 0.0;
	if ( x > 60.0 )	return 0.0;
	if ( x <= 0.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - -60.0 ) / ( 0.0 - -60.0 ) );
	if ( x <= 60.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 0.0 ) / ( 60.0 - 0.0 ) );
}

double FunctionBlock_car1::membership_zmiana_predkosci_zwiekszaj(double x) {
	if ( x <= 30.0 )	return 0.0;
	if ( x > 100.0 )	return 0.0;
	if ( x <= 75.0 )	return 0.0 + ( 1.0 - 0.0 ) * ( ( x - 30.0 ) / ( 75.0 - 30.0 ) );
	if ( x <= 100.0 )	return 1.0 + ( 0.0 - 1.0 ) * ( ( x - 75.0 ) / ( 100.0 - 75.0 ) );
}



void FunctionBlock_car1::print() {
	printf("Function block car1:\n");
	printf("	Input  %20s : %f\n", "dystans" , dystans);
	printf("	       %20s : %f\n", "dystans_bdlugi" , dystans_bdlugi);
	printf("	       %20s : %f\n", "dystans_bkrotki" , dystans_bkrotki);
	printf("	       %20s : %f\n", "dystans_dlugi" , dystans_dlugi);
	printf("	       %20s : %f\n", "dystans_krotki" , dystans_krotki);
	printf("	       %20s : %f\n", "dystans_sredni" , dystans_sredni);
	printf("	Input  %20s : %f\n", "predkosc" , predkosc);
	printf("	       %20s : %f\n", "predkosc_bduza" , predkosc_bduza);
	printf("	       %20s : %f\n", "predkosc_bmala" , predkosc_bmala);
	printf("	       %20s : %f\n", "predkosc_duza" , predkosc_duza);
	printf("	       %20s : %f\n", "predkosc_mala" , predkosc_mala);
	printf("	       %20s : %f\n", "predkosc_srednia" , predkosc_srednia);
	printf("	Output %20s : %f\n", "zmiana_predkosci" , zmiana_predkosci);
}


void FunctionBlock_car1::reset() {
	for( int i=0 ; i < 1000 ; i++ )	{ defuzzify_zmiana_predkosci[i] = 0.0; }
}

int main(int argc, char *argv[]) {

	FunctionBlock_car1 car1;


	if( argc > 1 ) { car1.dystans = atof(argv[1]); }
	if( argc > 2 ) { car1.predkosc = atof(argv[2]); }

	
	car1.calc();

	
	car1.print();
}
