#include "proto.h"

Proto::Proto(Ogre::Real _c_ele, Ogre::Real _c_mag, Ogre::Real _vx, Ogre::Real _pl_sup, Ogre::Real _pl_inf)
: pos(0, 0, 0), vel(_vx, 0, 0), acc(0, 0, 0),
c_ele(0, -_c_ele, 0), c_mag(0, 0, -_c_mag),
pl_sup(_pl_sup), pl_inf(_pl_inf)
{
}

Proto::~Proto(void)
{
}

void Proto::stepSim(Ogre::Real dt)
{
	//acc = c_ele*carrega/massa;
	//acc += carrega/massa * vel.crossProduct(c_mag);
	
	acc = c_ele;
	acc += vel.crossProduct(c_mag);
	vel += acc * dt;
	pos += vel * dt;
	
	if(pos.y >= pl_sup || pos.y <= pl_inf)
	vel.y = -vel.y*damping;
	
	/*std::cout << "acc: " << acc.x << ", " << acc.y << std::endl;	
	std::cout << "vel: " << vel.x << ", " << vel.y << std::endl;	
	std::cout << "pos: " << pos.x << ", " << pos.y << std::endl;*/
}
