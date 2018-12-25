#include "include/app.h"

Game::Game(int width, int height, irr::video::E_DRIVER_TYPE driverType, bool fullscreen)
{
	device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(width, height));

	driver = device->getVideoDriver();
	scenemgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();

	device->setWindowCaption(L"Forkies'd - DEVELOPMENT PREVIEW");

	guienv->addStaticText(L"DEVELOPMENT PREVIEW!", irr::core::rect<irr::s32>(10,10,260,22), true, true, 0, -1, true);

	addForkie(0, 0, 0);

	scenemgr->addCameraSceneNode(0, irr::core::vector3df(0, 1, 4), irr::core::vector3df(0, 0, 0));
	scenemgr->addLightSceneNode(0, irr::core::vector3df(0, 3, 4), irr::video::SColorf(1.0f, 1.0f, 1.0f), 100.0f, -1);

	while(device->run() && driver)
	{
		driver->beginScene(true, true, irr::video::SColor(255, 255, 140, 140));
		scenemgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}

	device->drop();
}

int Game::addForkie(int x, int y, int z)
{
	irr::scene::IAnimatedMesh *forkieMesh = scenemgr->getMesh("res/forkie.obj");
	irr::scene::ISceneNode *node = 0;
	if(!forkieMesh)
	{
		device->drop();
		return -1;
	}
	node = scenemgr->addMeshSceneNode(forkieMesh->getMesh(0));
}
