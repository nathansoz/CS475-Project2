#include "Body.h"
#include "Utils.h"

const double G = 6.67300e-11;   // m^3 / ( kg s^2 )
const double EARTH_MASS = 5.9742e24;     // kg
const double EARTH_DIAMETER = 12756000.32;   // meters
const float TIMESTEP = 1.0; // secs

#define NUMBODIES         100
#define NUMSTEPS          200
#define NUMTHREADS        1

Project2::Body Bodies[NUMBODIES];

using namespace Project2;

int main()
{
#ifndef _OPENMP
	std::cerr << "OpenMP is not supported here -- sorry." << std::endl;
	return 1;
#endif

	omp_set_num_threads(NUMTHREADS);
	int numProcessors = omp_get_num_procs();
	fprintf(stderr, "Have %d processors.\n", numProcessors);

	for (int i = 0; i < NUMBODIES; i++)
	{
		Bodies[i].mass = (float)EARTH_MASS * Utils::GetRandom(0.5f, 10.f);
		Bodies[i].x = (float)EARTH_DIAMETER * Utils::GetRandom(-100.f, 100.f);
		Bodies[i].y = (float)EARTH_DIAMETER * Utils::GetRandom(-100.f, 100.f);
		Bodies[i].z = (float)EARTH_DIAMETER * Utils::GetRandom(-100.f, 100.f);
		Bodies[i].vx = Utils::GetRandom(-100.f, 100.f);;
		Bodies[i].vy = Utils::GetRandom(-100.f, 100.f);;
		Bodies[i].vz = Utils::GetRandom(-100.f, 100.f);;
	};

	double time0 = omp_get_wtime();

	for (int t = 0; t < NUMSTEPS; t++)
	{
		for (int i = 0; i < NUMBODIES; i++)
		{
			float fx = 0.;
			float fy = 0.;
			float fz = 0.;
			Body *bi = &Bodies[i];
			for (int j = 0; j < NUMBODIES; j++)
			{
				if (j == i)     continue;

				Body *bj = &Bodies[j];

				float rsqd = Utils::GetDistanceSquared(*bi, *bj);
				if (rsqd > 0.)
				{
					float f = (float)(G * bi->mass * bj->mass / rsqd);
					float ux, uy, uz;
					Utils::GetUnitVector(*bi, *bj, ux, uy, uz);
					fx += f * ux;
					fy += f * uy;
					fz += f * uz;
				}
			}

			float ax = fx / Bodies[i].mass;
			float ay = fy / Bodies[i].mass;
			float az = fz / Bodies[i].mass;

			Bodies[i].xnew = Bodies[i].x + Bodies[i].vx*TIMESTEP + 0.5f*ax*TIMESTEP*TIMESTEP;
			Bodies[i].ynew = Bodies[i].y + Bodies[i].vy*TIMESTEP + 0.5f*ay*TIMESTEP*TIMESTEP;
			Bodies[i].znew = Bodies[i].z + Bodies[i].vz*TIMESTEP + 0.5f*az*TIMESTEP*TIMESTEP;

			Bodies[i].vxnew = Bodies[i].vx + ax * TIMESTEP;
			Bodies[i].vynew = Bodies[i].vy + ay * TIMESTEP;
			Bodies[i].vznew = Bodies[i].vz + az * TIMESTEP;
		}

		// setup the state for the next animation step:

		for (int i = 0; i < NUMBODIES; i++)
		{
			Bodies[i].x = Bodies[i].xnew;
			Bodies[i].y = Bodies[i].ynew;
			Bodies[i].z = Bodies[i].znew;
			Bodies[i].vx = Bodies[i].vxnew;
			Bodies[i].vy = Bodies[i].vynew;
			Bodies[i].vz = Bodies[i].vznew;
		}


	}  // t

	double time1 = omp_get_wtime();

	// print performance here:::

	return 0;
}