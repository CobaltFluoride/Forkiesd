class Game
{
private:
	std::string title;
	
	irr::core::dimension2d<irr::u32> dimensions;

	irr::video::E_DRIVER_TYPE driverType;

	// irrlicht stuff
	
	irr::IrrlichtDevice *device;

	irr::video::IVideoDriver *driver;

	irr::scene::ISceneManager *scenemgr;

public:
	Game(int width, int height, irr::video::E_DRIVER_TYPE driverType, bool fullscreen);
	
};
