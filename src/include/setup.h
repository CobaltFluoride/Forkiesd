class SetupUI : Fl_Window
{
private:
	// Window dimensions
	
	int	left   = 100,
		top    = 100,
		width  = 360,
		height = 480;
	
	std::string title{"Forkies'd Setup"};

	// Widgets
	
	Fl_Box headerBox;

public:
	SetupUI(int left, int top, int width, int height, const char *title);
};
