#pragma once

namespace cgui {

	class cColor {
	private:
		COLORREF Color;
	public:
		int r;
		int g;
		int b;

		cColor(int Rr, int Gg, int Bb) {
			r = Rr; g = Gg; b = Bb;
			Color = RGB(r, g, b);
		}

		cColor() {
			r = 255; g = 255; b = 255;
			Color = RGB(r, g, b);
		}

		cColor operator+(float B) {
			return cColor(r + B, g + B, b + B);
		}
		cColor operator-(float B) {
			return cColor(r - B, g - B, b - B);
		}
		cColor operator/(float B) {
			return cColor(r / B, g / B, b / B);
		}
		cColor operator*(float B) {
			return cColor(r * B, g * B, b * B);
		}

		COLORREF GetREF() {
			return Color;
		}

	};

	HWND console = GetConsoleWindow();
	HDC consoleDC = GetDC(console);
	RECT ConsoleRect;
	cColor BGcolor;
	POINT MousePos;
	HDC Screen = GetDC(NULL);

	class cWindow {
	private:
		HBRUSH BgBrush;
		HPEN BgPen;
		RECT TEMPRECT;
		HDC BUFFER = CreateCompatibleDC(Screen);
		HBITMAP Hbit;
	public:
		cgmath::Vector2 Size;
		
		cWindow(cgmath::Vector2 CSize) {
			Size = CSize;
			GetWindowRect(console, &ConsoleRect);
			MoveWindow(console, ConsoleRect.left, ConsoleRect.top, Size.x, Size.y, TRUE);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
			TEMPRECT = ConsoleRect;

			Hbit = CreateCompatibleBitmap(Screen, Size.x, Size.y);
			SelectObject(BUFFER, Hbit);

			COORD c = { ( Size.x- 40) /8, ( Size.y/2.1 ) /8 };

			SetConsoleScreenBufferSize(hStdout, c);

		}

		void SetBgColor(cColor RGB) {
			BGcolor = RGB;
			BgBrush = CreateSolidBrush(RGB.GetREF());
			BgPen = CreatePen(0,1,RGB.GetREF());


			SelectObject(BUFFER, BgPen);
			SelectObject(BUFFER, BgBrush);
			Rectangle(BUFFER, 0, 0, Size.x, Size.y);
		}

		HWND GetHWND() {
			return console;
		}

		HDC GetDC() {
			return BUFFER;
		}
		

		void Clear() {
			SelectObject(BUFFER, BgPen);
			SelectObject(BUFFER, BgBrush);
			Rectangle(BUFFER, 0, 0, Size.x, Size.y);
		}

		void Update() {

			GetWindowRect(console, &ConsoleRect);
			GetCursorPos(&MousePos);
			

			MoveWindow(console, ConsoleRect.left, ConsoleRect.top, Size.x, Size.y, TRUE);
			HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

			COORD c = { (Size.x - 40) / 8, (Size.y / 2.1) / 8 };
			SetConsoleScreenBufferSize(hStdout, c);

			StretchBlt(consoleDC,0,0, Size.x, Size.y,BUFFER,0,0, Size.x, Size.y,SRCCOPY);
		}

		cgmath::Vector2 GetMousePos() {
			return cgmath::Vector2(MousePos.x, MousePos.y);
		}

	};

}