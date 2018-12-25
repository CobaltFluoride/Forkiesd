#include "include/app.h"

Game::Game(int width, int height, irr::video::E_DRIVER_TYPE driverType, bool fullscreen)
{
	device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(width, height));

	driver = device->getVideoDriver();
	scenemgr = device->getSceneManager();

	device->setWindowCaption(L"Forkies'd");

	while(device->run() && driver)
	{
		driver->beginScene(true, true, irr::video::SColor(255, 255, 140, 140));
		scenemgr->drawAll();
		driver->endScene();
	}

	device->drop();
}
