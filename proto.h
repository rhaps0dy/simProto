// simproto.h

#ifndef _SIMPROTO_H_
#define _SIMPROTO_H_

#include <OGRE/OgreVector3.h>
#include <SDL/SDL.h>

class Proto
{
public:
	Proto(Ogre::Real _c_ele, Ogre::Real _c_mag, Ogre::Real _vx, Ogre::Real _pl_sup, Ogre::Real _pl_inf);
	~Proto(void);
	
	void stepSim(Ogre::Real dt);
	
protected:
	Ogre::Vector3 pos;
	Ogre::Vector3 vel;
	Ogre::Vector3 acc;
	
	Ogre::Vector3 c_ele;
	Ogre::Vector3 c_mag;
	
	Ogre::Real pl_sup;
	Ogre::Real pl_inf;
	
	static constexpr Ogre::Real q_m = 1.6e-19 / 1.67e-27;
	static constexpr Ogre::Real damping = 0.5;
	//la carrega i massa no calen pq es compensen
};

#endif
