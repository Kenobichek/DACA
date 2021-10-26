#include "polynomials.h"

std::vector<double> input(int n) {
	std::cout << "\nPolynomial " << n << "\n\n";

	std::cout << "Please enter the highest degree: ";
	int degree;
	std::cin >> degree;

	std::vector <double> vectorCoeff;
	
	while (degree >= 0) {
		std::cout << "x^" << degree << " coefficient = ";
		double coeff;
		std::cin >> coeff;
		vectorCoeff.push_back(coeff);
		degree--;
	}
	return vectorCoeff;
}

void myTask(std::vector <double> vectorCoeff) {
	int degree = vectorCoeff.size();
	std::cout << "(";
	for (int i = 0; i < vectorCoeff.size(); i++) {
		degree--;
		if (vectorCoeff[i]) {
			if (i != 0) std::cout << " + ";
			std::cout << vectorCoeff[i];
			if (degree > 1) std::cout << "x^" << degree;
			if (degree == 1) std::cout << "x";
		}
	}
	std::cout << ")";
}

std::vector <double> calculate(std::vector <double> pol1Coeff, std::vector<double> pol2Coeff) {
	int MAXdegree1 = pol1Coeff.size() - 1;
	int MAXdegree2 = pol2Coeff.size() - 1; 
	std::vector<double> result(MAXdegree1 + MAXdegree2 + 1);
	int degree1 = pol1Coeff.size() - 1;
	for (int i = 0; i < pol1Coeff.size(); i++) {
		int degree2 = pol2Coeff.size() - 1;
		for (int j = 0; j < pol2Coeff.size(); j++) {
			result[degree1 + degree2] += pol1Coeff[i] * pol2Coeff[j];
			degree2--;
		}
		degree1--;
	}
	return result;
}

void printResult(std::vector <double> r) {
	for (int i = r.size() - 1; i >= 0; i--) {
		if (r[i] != 0) {
			if(i != r.size() - 1) std::cout << " + ";
			std::cout << r[i];
			if (i > 1) std::cout << "x^" << i;
			if (i == 1) std::cout << "x";
		}
	}
	std::cout << std::endl;
}

void MultiplicationPolynomials() {
	std::cout << "TASK 1:\n";
	std::cout << "The calculator calculates the product of two polynomials\n";
	
	std::vector <double> pol1Coeff;
	std::vector <double> pol2Coeff;

	pol1Coeff = input(1);
	pol2Coeff = input(2);

	std::cout << "\nEntered task\n";
	myTask(pol1Coeff);
	myTask(pol2Coeff);

	std::cout << "\n\nResult\n";
	std::vector <double> result;
	result = calculate(pol1Coeff, pol2Coeff);
	printResult(result);
	std::cout << std::endl << std::endl;
}