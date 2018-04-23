#pragma once

namespace Project2
{
	struct Body
	{
		float mass;
		float x, y, z;            // position
		float vx, vy, vz;         // velocity
		float fx, fy, fz;         // forces
		float xnew, ynew, znew;
		float vxnew, vynew, vznew;
	};
}