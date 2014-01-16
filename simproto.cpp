#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "SDL_proto.h"

#ifdef WIN32                     
int WinMain(int argc, char** argv)
#else
int main(int argc, char** argv)
#endif
{
    if(argc!=2)
    {
	    std::cout << "Usage: ./simproto <speed>\nSpeed for passing the selector is 10" << std::endl;
	    return 0;
    }
   
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "Unable to init SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1920, 1080, 16, SDL_HWSURFACE);
    if ( !screen )
    {
        std::cout << "Unable to set 1024x768 video: " << SDL_GetError() << std::endl;
        return 1;
    }

	SDL_WM_SetCaption("Press Enter to start the simulation", "Press Enter to start the simulation");
	
    //crea escena
	SDL_Proto proto (20, 1080/2, 10., 1., atof(argv[1]), 50., -50.);
	
	//preparacio variables del bucle
	SDL_Event event;
	bool simula=0;
	Uint32 prevTicks, actTicks;
	
	actTicks = SDL_GetTicks();
	
    while(true)
	{
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				exit(0);
			if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
						break;
					case SDLK_RETURN:
						simula=1;
						break;
				}
			}
		}
		prevTicks = actTicks;
		actTicks = SDL_GetTicks();
		
		//simulacio
		if(simula)
		{
			proto.stepSim((actTicks-prevTicks) / 1000.);
		}
		
		//dibuixa
		SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
		filledCircleColor(screen, proto.getX(), proto.getY(), 7, 0xff0000ff);
		SDL_Flip(screen);
	}
    return 0;
}

