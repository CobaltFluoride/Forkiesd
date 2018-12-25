#include "include/app.h"
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_Widget.H>

void startGame_cb(Fl_Widget* widget, void *data)
{
	// Hide the window while the game is running.
	widget->parent()->hide();

	// Flush the events queue so that the window hides before game execution
	// starts. This prevents the window from freezing before it can hide.
	Fl::flush();

	// Mess to cast *data back to a vector containing spinners.
	auto spinners = static_cast<std::vector<Fl_Widget*>*>(data);

	auto widthSpinner = static_cast<Fl_Spinner*>(spinners->at(0));
	auto heightSpinner = static_cast<Fl_Spinner*>(spinners->at(1));
	auto driverChoice = static_cast<Fl_Choice*>(spinners->at(2));

	int width = static_cast<int>(widthSpinner->value());
	int height = static_cast<int>(heightSpinner->value());

	irr::video::E_DRIVER_TYPE driverType;

	// Check preferred driver type and set it.

	switch(driverChoice->value())
	{
		case 0:
			driverType = irr::video::EDT_OPENGL;
			break;
		case 1:
			driverType = irr::video::EDT_BURNINGSVIDEO;
			break;
	}

	//  Start the game
	Game game(width, height, driverType, false);
	// ^ Blocking constructor. Will block until game quits.

	// Show the window
	widget->parent()->show();
}

SetupUI::SetupUI(int left, int top, int width, int height, const char *title)
	: 	Fl_Window(left, top, width, height, title),
		headerBox(0,0,width,100)
{
	// Logo shown at top
	
	Fl_PNG_Image logoImg{"res/logo.png"};
	headerBox.image(logoImg);

	// Group to set properties of the game.

	Fl_Group itemsGroup{10, 110, width - 20, height - 156};
	itemsGroup.box(FL_UP_BOX);

	// Itemsgroup group

	
		Fl_Choice driverChoice{120, 120, width - 140, 32, "Driver Type"};
		driverChoice.add("OpenGL");
		driverChoice.add("Software");
		driverChoice.value(0);

		Fl_Choice screenMode{120, 162, width - 140, 32, "Screen Mode"};
		screenMode.add("Fullscreen");
		screenMode.add("Windowed");
		screenMode.value(1);

		Fl_Spinner widthSpinner{120, 204, 64, 32, "Width"};
		Fl_Spinner heightSpinner{198, 204, 64, 32, "Height"};
		
		widthSpinner.maximum(10000);
		heightSpinner.maximum(10000);
		widthSpinner.minimum(100);
		heightSpinner.minimum(100);
		
		heightSpinner.align(FL_ALIGN_BOTTOM);
		widthSpinner.align(FL_ALIGN_BOTTOM);

		widthSpinner.value(640);
		heightSpinner.value(480);

		Fl_Box hintBox{15, 110 + height - 193, width - 30, 32, "Set Driver Type to software to run on VMs"};
		hintBox.color(0xa0a0ff00);
		hintBox.box(FL_UP_BOX);

	itemsGroup.end();

	Fl_Button startButton{width - 120, height - 40, 116, 36, "Start"};

	// Store pointers to the widgets containing properties. They will be queried
	// when the start button is pressed.

	std::vector<Fl_Widget*> properties;
	properties.push_back(static_cast<Fl_Widget*>(&widthSpinner));
	properties.push_back(static_cast<Fl_Widget*>(&heightSpinner));
	properties.push_back(static_cast<Fl_Widget*>(&driverChoice));

	startButton.callback(startGame_cb, static_cast<void*>(&properties));

	end();
	show();
	Fl::run();
}

