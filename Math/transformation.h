#ifndef MATH_TRANSFORMATION
#define MATH_TRANSFORMATION

#include "math.h"
#include "matrix.h"
#include "vector.h"

#define PI 3.14

namespace MN{
	namespace Math{
		namespace Transformation3D{

			template<typename T>
			MN::Math::matrix<T,4> translation(const MN::Math::vector3<T>& tr){
				MN::Math::matrix<T,4> ret;
				ret.clear();

				for(int x = 0; x < 3; x++){
        			ret.data[x][3] = tr.at(x);
			    }

				return ret;
			}


			
			template<typename T>
			MN::Math::matrix<T,4> scale(const MN::Math::vector3<T>& tr){
				MN::Math::matrix<T,4> ret;
				ret.clear();

				 for(int x = 0; x < 3; x++){
        			ret.data[x][x] = tr.at(x);
			    }

				return ret;
			}

			
			
			template<typename T>
			MN::Math::matrix<T,4> rotateZ(T angle){
				MN::Math::matrix<T,4> ret;
				ret.clear();

                T cosO = cos( (angle * PI) / 180.0);
                T senO = sin((angle * PI) / 180.0);

				
		    	ret.data[0][0] = cosO;
			    ret.data[1][0] = senO;
			    ret.data[0][1] = -senO;
			    ret.data[1][1] = cosO;

				return ret;
			}

			template<typename T>
			MN::Math::matrix<T,4> rotateX(T angle){
				MN::Math::matrix<T,4> ret;
				ret.clear();

                T cosO = cos( (angle * PI) / 180.0);
                T senO = sin((angle * PI) / 180.0);

				
		    	ret.data[1][1] = cosO;
			    ret.data[2][1] = senO;
			    ret.data[1][2] = -senO;
			    ret.data[2][2] = cosO;


				return ret;
			}

			template<typename T>
			MN::Math::matrix<T,4> rotateY(T angle){
				MN::Math::matrix<T,4> ret;
				ret.clear();

                T cosO = cos( (angle * PI) / 180.0);
                T senO = sin((angle * PI) / 180.0);
		    
			    ret.data[0][0] = cosO;
			    ret.data[2][0] = -senO;
			    ret.data[0][2] = senO;
			    ret.data[2][2] = cosO;

				return ret;
			}

			template<typename T>
			MN::Math::matrix<T,4> rotate(const MN::Math::vector3<T>& rt){
				MN::Math::matrix<T,4> ret;

				ret = rotateZ(rt.at(2))*rotateY(rt.at(1))*rotateX(rt.at(0));

				return ret;
			}



		}//End of transformation3D

	}//End of namespace math
}


#endif
