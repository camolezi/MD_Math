#ifndef MATH_MATRIX
#define MATH_MATRIX

#include <iostream>
#include <array>
#include <initializer_list>
#include <assert.h>
#include <algorithm>

#include "vector.h"

namespace MN{
	namespace Math{

		//Only square matrix for now
		template<typename T , std::size_t N>
        class matrix{
			public:
				T data[N][N];

				matrix(){
					zero();
				}

				T at(const std::size_t index1,const std::size_t index2) const{
					assert(index1 >= 0 && index1 < N);
					assert(index2 >= 0 && index2 < N);
					
					return data[index1][index2];
				}

				void zero(){
					for(std::size_t x =0; x < N; x++){
						for(std::size_t y = 0; y < N; y++){
							data[x][y] = static_cast<T>(0);
						}
					}
				}

				void clear(){
					for(std::size_t x =0; x < N; x++){
						for(std::size_t y = 0; y < N; y++){
							if(x == y)
								data[x][y] = static_cast<T>(1);
							else
								data[x][y] = static_cast<T>(0);
						}
					}
				}

				std::size_t size() const{
					return _size;
				}

			private:
				std::size_t _size = N;
		};

		//Operators

		//Add
		template<typename T , std::size_t N>
		matrix<T,N> operator+(const matrix<T,N>& mat1, const matrix<T,N>& mat2){
			matrix<T,N> ret;
			for(std::size_t x =0; x < N; x++){
				for(std::size_t y = 0; y < N; y++){
					ret.data[x][y] = mat1.at(x,y) + mat2.at(x,y);
				}
			}

			return ret;
		}

		//Sub
		template<typename T , std::size_t N>
		matrix<T,N> operator-(const matrix<T,N>& mat1, const matrix<T,N>& mat2){
			matrix<T,N> ret;
			for(std::size_t x =0; x < N; x++){
				for(std::size_t y = 0; y < N; y++){
					ret.data[x][y] = mat1.at(x,y) - mat2.at(x,y);
				}
			}

			return ret;
		}

			//Mult matrix * vector
		template<typename T , std::size_t N, typename V>
		vector<V,N> operator*(const matrix<T,N>& mat, const vector<V,N>& vec){
			
			vector<V,N> ret(0);

			for(std::size_t x =0; x < N; x++){
				for (std::size_t count = 0 ; count < N; count++){
					ret[x] += mat.at(x,count) * vec.at(count);
				}
			}			
			

			return ret;
		}


        //homogene coordenates multiplication
		template<typename T , std::size_t N, typename V>
		vector<V,N-1> operator*(const matrix<T,N>& mat, const vector<V,N-1>& vec){
			
			vector<V,N-1> ret(0);

			for(std::size_t x =0; x < N-1; x++){
				for (std::size_t count = 0 ; count < N; count++){
					if(count == N-1)
						ret[x] += mat.at(x,count) * 1;
					else
						ret[x] += mat.at(x,count) * vec.at(count);
                }
            }

			return ret;
		}



		//Ineversion
		template<typename T , std::size_t N>
		matrix<T,N> operator-(const matrix<T,N>& mat){
			matrix<T,N> ret;
			for(std::size_t x =0; x < N; x++){
				for(std::size_t y = 0; y < N; y++){
					ret.data[x][y] = -mat.at(x,y);
				}
			}

			return ret;
		}



		//Mult Matrix * matrix
		template<typename T , std::size_t N>
		matrix<T,N> operator*(const matrix<T,N>& mat1, const matrix<T,N>& mat2){
			matrix<T,N> ret;

			for(std::size_t x =0; x < N; x++){
				for(std::size_t y = 0; y < N; y++){
					for (std::size_t count = 0 ; count < N; count++){
						ret.data[x][y] += mat1.at(x,count) * mat2.at(count,y);
					}
				}
			}			
			

			return ret;
		}


	}//End namespace math
}



#endif
