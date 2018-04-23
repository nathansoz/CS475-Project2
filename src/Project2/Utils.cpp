#include "Utils.h"

#ifndef _WIN32
    #include <sys/types.h>
    #include <unistd.h>
    #include <algorithm>
#endif

using namespace Project2;

float Utils::GetDistanceSquared(const Body& bi, const Body& bj)
{
	float dx = bi.x - bj.x;
	float dy = bi.y - bj.y;
	float dz = bi.z - bj.z;
	return dx * dx + dy * dy + dz * dz;
}

float Utils::GetUnitVector(const Body& from, const Body& to, /*out*/ float& ux, /*out*/ float& uy, /*out*/ float& uz)
{
	float dx = to.x - from.x;
	float dy = to.y - from.y;
	float dz = to.z - from.z;

	float d = sqrt(dx*dx + dy * dy + dz * dz);
	if (d > 0.)
	{
		dx /= d;
		dy /= d;
		dz /= d;
	}

	ux = dx;
	uy = dy;
	uz = dz;

	return d;
}

float Utils::GetRandom(float low, float high)
{
	float r = (float)rand();         // 0 - RAND_MAX
	return(low + r * (high - low) / (float)RAND_MAX);
}

int Utils::GetRandom(int ilow, int ihigh)
{
	float low = (float)ilow;
	float high = (float)ihigh + 0.9999f;

	return (int)(Utils::GetRandom(low, high));
}

std::string Utils::GetProgramDirectory()
{
#ifdef _WIN32
	char* pgmptr;
	_get_pgmptr(&pgmptr);
	std::string path(pgmptr);
	return path.substr(0, path.find_last_of("/\\"));
#else
        int len = 1024;
        char pBuf[len];
	char szTmp[32];
	sprintf(szTmp, "/proc/%d/exe", getpid());
	int bytes = std::min((int)readlink(szTmp, pBuf, len), len - 1);
	if (bytes >= 0)
		pBuf[bytes] = '\0';
	std::string path(pBuf);
	return path.substr(0, path.find_last_of("/\\"));
#endif
}
