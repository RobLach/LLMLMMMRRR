#include "Monocle.h"
#include "LL.h"

using namespace Monocle;

int main(void)
{
	Game *game = new Game("LLMLMMMRRR",1280,720,32, false);
	//game->SetScene(new LL::mainScene());
	game->SetScene(new LL::menuScene());
	game->Main();
	delete game;
	return 0;
}
