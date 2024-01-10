#include <stdio.h>
#include <iostream>
#include <stdlib.h>
double ruleAccumulationMethod_max(double defuzzifierValue, double valueToAggregate) { return (defuzzifierValue > valueToAggregate ? defuzzifierValue : valueToAggregate); }

double ruleActivationMethod_min(double degreeOfSupport, double membership) { return (degreeOfSupport < membership ? degreeOfSupport : membership); }

double ruleConnectionMethod_and(double antecedent1, double antecedent2) { return (antecedent1 < antecedent2 ? antecedent1 : antecedent2); }

class FunctionBlock_car1 {

public:

	double odleglosc;


	double predkosc;

private:

	double odleglosc_duza;
	double odleglosc_mala;
	double odleglosc_srednia;



	double defuzzify_predkosc[1000];


public:
	FunctionBlock_car1();
	void calc();
	void print();

private:
	void defuzzify();
	void fuzzify();
	void reset();
	double membership_odleglosc_duza(double x);
	double membership_odleglosc_mala(double x);
	double membership_odleglosc_srednia(double x);
	double membership_predkosc_duza(double x);
	double membership_predkosc_mala(double x);
	double membership_predkosc_srednia(double x);
	void calc_No1();

};


FunctionBlock_car1::FunctionBlock_car1() {
	predkosc = 0.0;
}


void FunctionBlock_car1::calc() {
	reset();
	fuzzify();
	calc_No1();
	defuzzify();
}


void FunctionBlock_car1::calc_No1() {

	double degreeOfSupport_1 = 1.0 * (odleglosc_mala);
	if (degreeOfSupport_1 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = 0.0 + i * 0.12;
			double membership = membership_predkosc_mala(x);
			double y = ruleActivationMethod_min(degreeOfSupport_1, membership);
			defuzzify_predkosc[i] += ruleAccumulationMethod_max(defuzzify_predkosc[i], y);
		}
	}

	
	double degreeOfSupport_2 = 1.0 * (odleglosc_srednia);
	if (degreeOfSupport_2 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = 0.0 + i * 0.12;
			double membership = membership_predkosc_srednia(x);
			double y = ruleActivationMethod_min(degreeOfSupport_2, membership);
			defuzzify_predkosc[i] += ruleAccumulationMethod_max(defuzzify_predkosc[i], y);
		}
	}

	
	double degreeOfSupport_3 = 1.0 * (odleglosc_duza);
	if (degreeOfSupport_3 > 0) {
		for (int i = 0; i < 1000; i++) {
			double x = 0.0 + i * 0.12;
			double membership = membership_predkosc_duza(x);
			double y = ruleActivationMethod_min(degreeOfSupport_3, membership);
			defuzzify_predkosc[i] += ruleAccumulationMethod_max(defuzzify_predkosc[i], y);
		}
	}

}


void FunctionBlock_car1::defuzzify() {
	double sum_predkosc = 0.0;
	double wsum_predkosc = 0.0;
	for (int i = 0; i < 1000; i++) {
		double x = 0.0 + i * 0.12;
		sum_predkosc += defuzzify_predkosc[i];
		wsum_predkosc += x * defuzzify_predkosc[i];
	}
	predkosc = wsum_predkosc / sum_predkosc;
}


void FunctionBlock_car1::fuzzify() {
	odleglosc_duza = membership_odleglosc_duza(odleglosc);
	odleglosc_mala = membership_odleglosc_mala(odleglosc);
	odleglosc_srednia = membership_odleglosc_srednia(odleglosc);
}


double FunctionBlock_car1::membership_odleglosc_duza(double x) {
	if (x <= 500.0)	return 0.0;
	if (x > 1000.0)	return 1.0;
	if (x <= 1000.0)	return 0.0 + (1.0 - 0.0) * ((x - 500.0) / (1000.0 - 500.0));
}

double FunctionBlock_car1::membership_odleglosc_mala(double x) {
	if (x <= 0.0)	return 1.0;
	if (x > 450.0)	return 0.0;
	if (x <= 450.0)	return 1.0 + (0.0 - 1.0) * ((x - 0.0) / (450.0 - 0.0));
}

double FunctionBlock_car1::membership_odleglosc_srednia(double x) {
	if (x <= 250.0)	return 0.0;
	if (x > 750.0)	return 0.0;
	if (x <= 500.0)	return 0.0 + (1.0 - 0.0) * ((x - 250.0) / (500.0 - 250.0));
	if (x <= 750.0)	return 1.0 + (0.0 - 1.0) * ((x - 500.0) / (750.0 - 500.0));
}

double FunctionBlock_car1::membership_predkosc_duza(double x) {
	if (x <= 60.0)	return 0.0;
	if (x > 120.0)	return 1.0;
	if (x <= 100.0)	return 0.0 + (1.0 - 0.0) * ((x - 60.0) / (100.0 - 60.0));
	if (x <= 120.0)	return 1.0 + (1.0 - 1.0) * ((x - 100.0) / (120.0 - 100.0));
}

double FunctionBlock_car1::membership_predkosc_mala(double x) {
	if (x <= 0.0)	return 1.0;
	if (x > 60.0)	return 0.0;
	if (x <= 20.0)	return 1.0 + (1.0 - 1.0) * ((x - 0.0) / (20.0 - 0.0));
	if (x <= 60.0)	return 1.0 + (0.0 - 1.0) * ((x - 20.0) / (60.0 - 20.0));
}

double FunctionBlock_car1::membership_predkosc_srednia(double x) {
	if (x <= 20.0)	return 0.0;
	if (x > 100.0)	return 0.0;
	if (x <= 60.0)	return 0.0 + (1.0 - 0.0) * ((x - 20.0) / (60.0 - 20.0));
	if (x <= 100.0)	return 1.0 + (0.0 - 1.0) * ((x - 60.0) / (100.0 - 60.0));
}



void FunctionBlock_car1::print() {
	printf("Function block car1:\n");
	printf("	Input  %20s : %f\n", "odleglosc", odleglosc);
	printf("	       %20s : %f\n", "odleglosc_duza", odleglosc_duza);
	printf("	       %20s : %f\n", "odleglosc_mala", odleglosc_mala);
	printf("	       %20s : %f\n", "odleglosc_srednia", odleglosc_srednia);
	printf("	Output %20s : %f\n", "predkosc", predkosc);
}


void FunctionBlock_car1::reset() {
	for (int i = 0; i < 1000; i++) { defuzzify_predkosc[i] = 0.0; }
}


double predkosc(double value) {
	return value * 10 / 36; }



int main(int argc, char* argv[]) {
	
	unsigned int time = 5;
	unsigned int distance = 0;
	std::cout.precision(3);

	FunctionBlock_car1 car1;


	std::cout << "Podaj poczatkowa odleglosc: ";
	std::cin >> car1.odleglosc;


	while (car1.odleglosc > 0.0)
	{
		car1.calc();
		std::cout << "Predkosc: " << car1.predkosc << " po  5 s ";
		car1.odleglosc -= predkosc(car1.predkosc);
		std::cout << "odleglosc: " << car1.odleglosc << std::endl;
	}
	
}
