#include "divideANDconquer.h"

void personally(std::vector<int>& A, int size) {
	for (int i = 0; i < size; i++) {
		int a;
		std::cin >> a;
		A.push_back(a);
	}
}

void randomly(std::vector<int>& A,int size){
	for (int i = 0; i < size; i++) {
		A.push_back(rand() % 100 - 50);
	}
}

void print(std::vector <int>& A) {
	std::cout << "Print array:\n";
	for (int i = 0; i < A.size(); i++) {
		std::cout << A[i] << " ";
	}
}

int Count(std::vector <int>& A, int l, int r) {	// Divide-and-conquer algorithm
	if (l > r) {
		return 0;
	}
	else if (l == r) {
		return A[l] > 0;
	}
	else {
		return Count(A, l, (l + r) / 2) + Count(A, (l + r) / 2 + 1, r);
	}
}

int Count2(std::vector <int>& A) {			    // Linear algorithm		
	int count = 0;
	for (int i = 0; i < A.size(); i++) {
		if(A[i] > 0){
			count++;
		}
	}
	return count;
}

void counter() {
	std::cout << "TASK 2:\n";
	std::cout << "Find the number of positive elements integer array A\n\n";
	
	std::cout << "Number of elements: ";
	int num;
	std::cin >> num;

	std::vector <int> A;

	std::cout << "Enter manually or randomly? (1 or 2): ";
	int opt;
	std::cin >> opt;
	opt == 1 ? personally(A, num) : randomly(A, num);
	
	//print(A);
	clock_t Start1 = clock();
	std::cout << "\nCount 1 = " << Count(A, 0, num - 1) << std::endl;
	clock_t End1 = clock();

	clock_t Start2 = clock();
	std::cout << "Count 2 = " << Count2(A) << std::endl << std::endl;
	clock_t End2 = clock();

	float Time1 = (float(End1 - Start1)) / CLOCKS_PER_SEC;
	float Time2 = (float(End2 - Start2)) / CLOCKS_PER_SEC;

	std::cout << "Time 1 (Divide-and-conquer algorithm): " << Time1 << std::endl;
	std::cout << "Time 2 (Linear algorithm): " << Time2 << std::endl;

}