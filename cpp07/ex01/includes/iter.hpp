#ifndef __ITER_HPP__
# define __ITER_HPP__

template <typename TArray>
void	iter(TArray const * array, int length, void (*f)(TArray const &)) {
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename TArray>
void	iter(TArray * array, int length, void (*f)(TArray &)) {
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif
