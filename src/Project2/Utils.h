#include <omp.h>
#include <iostream>
#include <string>

#include "Body.h"

namespace Project2
{
	class Utils 
	{
	public:
		static float GetDistanceSquared(const Body& bi, const Body& bj);
		static float GetUnitVector(const Body& from, const Body& to, /*out*/ float& ux, /*out*/ float& uy, /*out*/ float& uz);
		static float GetRandom(float low, float high);
		static int   GetRandom(int ilow, int ihigh);
		static std::string GetProgramDirectory();
	};
}