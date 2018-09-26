#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define elements 1000000

int main(){
	int size, rank;
	int i,sum;
	int array[elements];
	
	const clock_t start_time = clock();
	#pragma omp parallel 
	{
		unsigned int seed = omp_get_thread_num();
		size = omp_get_num_threads();
		rank = omp_get_thread_num();
		int work_portion = elements/size;
		int position = rank*work_portion;
		for(i = 0; i < work_portion; i++){
			array[position + i] = rand_r(&seed);
			
		}
	}


	std::cout << float(clock() - start_time)/CLOCKS_PER_SEC << std::endl;
	return 0;


}
