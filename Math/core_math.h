#ifndef CORE_MATH
#define CORE_MATH
	
	#include "vector.h"
	#include "matrix.h"
	#include "transformation.h"

		
	using vec2 = MN::Math::vector2<float>;
	using vec3 = MN::Math::vector3<float>;
	using vec4 = MN::Math::vector<float,4>;

	using mat4 = MN::Math::matrix<float,4>;
	using mat3 = MN::Math::matrix<float,3>;


	namespace transform = MN::Math::Transformation3D;

#endif