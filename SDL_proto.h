// SDL_proto.h

#ifndef _SDL_PROTO_H_
#define _SDL_PROTO_H_

#include <SDL/SDL.h>
#include "proto.h"


class SDL_Proto : public Proto
{
public:
	SDL_Proto(Sint16 _x, Sint16 _y, Ogre::Real _c_ele, Ogre::Real _c_mag, Ogre::Real _vx, Ogre::Real _pl_sup, Ogre::Real _pl_inf);
	~SDL_Proto(void);
	
	Sint16 getX(void);
	Sint16 getY(void);
	Sint16 getAccX(void);
	Sint16 getAccY(void);
	Sint16 getVelX(void);
	Sint16 getVelY(void);
	Sint16 getMagX(void);
	Sint16 getMagY(void);
	
protected:
	Sint16 offx;
	Sint16 offy;
	static constexpr Ogre::Real scaling = 10.;
};

SDL_Proto::SDL_Proto(Sint16 _x, Sint16 _y, Ogre::Real _c_ele, Ogre::Real _c_mag, Ogre::Real _vx, Ogre::Real _pl_sup, Ogre::Real _pl_inf) :
Proto(_c_ele, _c_mag, _vx, _pl_sup, _pl_inf), offx(_x), offy(_y)
{
}

SDL_Proto::~SDL_Proto(void)
{
}

inline Sint16 SDL_Proto::getX(void)
{
	return Sint16(round(offx + pos.x * scaling));
}

inline Sint16 SDL_Proto::getY(void)
{
	return Sint16(round(offy - pos.y*scaling));
}

inline Sint16 SDL_Proto::getAccX(void)
{
	return getX() + Sint16(acc.x*scaling);
}

inline Sint16 SDL_Proto::getAccY(void)
{
	return getY() - Sint16(acc.y*scaling);
}

inline Sint16 SDL_Proto::getVelX(void)
{
	return getX() + Sint16(vel.x*scaling);
}

inline Sint16 SDL_Proto::getVelY(void)
{
	return getY() - Sint16(vel.y*scaling);
}

inline Sint16 SDL_Proto::getMagX(void)
{
	return getX() + Sint16(vel.crossProduct(c_mag).x*scaling);
}

inline Sint16 SDL_Proto::getMagY(void)
{
	return getY() - Sint16(vel.crossProduct(c_mag).y*scaling);
}
#endif
