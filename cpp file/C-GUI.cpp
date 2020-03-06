#include <iostream>
#include "CGUI/cgui.h"

int main()
{

	cgui::cWindow WIN( cgmath::Vector2(800,600) );
	WIN.SetBgColor( cgui::cColor(236, 233,216) );

	cgui::cButton BTN;
	BTN.Position = cgmath::Vector2(800 / 2, 600 / 2);
	BTN.Size = cgmath::Vector2(100, 50);
	BTN.SetColor( cgui::cColor(255,255,255) );
	BTN.SetText(L"TEST");


	cgui::cLabel LAB1;
	LAB1.SetText(L"Label \nTest Label 12345 \n54321 \nSlash N test \nGood");
	LAB1.SetPos(cgmath::Vector2(20,20));
	LAB1.SetSize(cgmath::Vector2(150, 100));

	while (1) {

			WIN.Update();
			WIN.Clear();
			BTN.Update(WIN);
			BTN.Hover();

			LAB1.Update(WIN);

			if (BTN.Pressed()) {
				BTN.Position = cgmath::Vector2(100 + rand() % 800 / 2, 100 + rand() % 600 / 2);
			}

	}

}

