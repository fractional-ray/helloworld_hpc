#include <iostream>
#include <mpi.h>
#include <tuple>
#include <omp.h>
int main(int argc, char* argv[]){
	
	MPI_Init(&argc, &argv);
	std::tuple <int , int> size;
	std::tuple <int, int> rank_tuple;
	int rank_mpi,size_mpi;
	MPI_Comm_rank ( MPI_COMM_WORLD, &rank_mpi);
	MPI_Comm_size ( MPI_COMM_WORLD, &size_mpi);
	#pragma omp parallel 
{	
        int rank_omp = omp_get_thread_num();
	int size_omp = omp_get_num_threads();
	size = std::make_tuple(size_omp, size_mpi);
	rank_tuple = std::make_tuple(rank_omp, rank_mpi);
	std::cout << "Size omp " << std::get<0>(size) << " Size mpi " << std::get<1>(size) << std::endl;
	std::cout << "Rank omp " << std::get<0>(rank_tuple) << " Rank mpi " << std::get<1>(rank_tuple) << std::endl;
}
	MPI_Finalize();
	return 0;

}
