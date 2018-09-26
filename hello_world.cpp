#include <iostream>
#include <omp.h>

int main(){

	int size,rank;
	size = omp_get_num_threads();
#pragma omp parallel
{

	rank = omp_get_thread_num();
	
	std::cout << "Hello world from "<< rank << "of" <<	size<< "processes " << std::endl;

}
	return 0;
}
