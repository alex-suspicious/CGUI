#pragma once

namespace cgui {

	class cButton {
	private:
		HBRUSH BgBrush;
		HPEN BgPen;
		cColor Color;
		cColor HoverColor;
		cColor PressedColor;
		cColor TempColor;
		LPCTSTR Text;
	public:

		cgmath::Vector2 Position;
		cgmath::Vector2 Size;

		void SetPos(cgmath::Vector2 Pos) {
			Position = Pos;
		}

		void SetSize(cgmath::Vector2 SZ) {
			Size = SZ;
		}

		void SetText(LPCTSTR TEX) {
			Text = TEX;
		}

		void SetColor(cColor CLR) {
			Color = CLR;
			HoverColor = cColor(0, 0, 255);
			PressedColor = cColor(0, 255, 0);
			BgBrush = CreateSolidBrush(TempColor.GetREF());
			BgPen = CreatePen(0, 1, RGB(0,0,0));
		}

		bool Hover() {
			cgmath::Vector2 Mpos( cgui::MousePos.x - cgui::ConsoleRect.left - 6, cgui::MousePos.y - cgui::ConsoleRect.top - 30);

			if (Mpos.x > Position.x & Mpos.x < Position.x + Size.x & Mpos.y > Position.y & Mpos.y < Position.y + Size.y) {

				TempColor = HoverColor;
				return true;

			}
			else {
				TempColor = Color;
				return false;
			}
		}

		int Pressed() {
			cgmath::Vector2 Mpos(cgui::MousePos.x - cgui::ConsoleRect.left - 6, cgui::MousePos.y - cgui::ConsoleRect.top - 30);

			if (Mpos.x > Position.x& Mpos.x < Position.x + Size.x & Mpos.y > Position.y& Mpos.y < Position.y + Size.y) {
				if (GetAsyncKeyState(VK_LBUTTON)) {
					TempColor = PressedColor;
					return 1;
				}
				else if (GetAsyncKeyState(VK_RBUTTON)) {
					TempColor = PressedColor;
					return 2;
				}
				else 
				{
					return 0;
				}
			}
			else {
				return 0;
			}
		}

		void Update(cWindow WIN) {

			BgBrush = CreateSolidBrush(TempColor.GetREF());
			SelectObject(WIN.GetDC(), BgPen);
			SelectObject(WIN.GetDC(), BgBrush);
			Rectangle(WIN.GetDC(), Position.x, Position.y, Position.x+ Size.x, Position.y+ Size.y);
			RECT SHAPE;
			SHAPE.left = Position.x;
			SHAPE.top = Position.y;
			SHAPE.bottom = Position.y + Size.y;
			SHAPE.right = Position.x + Size.x;

			DrawText(WIN.GetDC(), Text, -1, &SHAPE, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

			DeleteObject(BgBrush);
		}

	};


	class cLabel {
	private:
		LPCTSTR Text;
	public:

		cgmath::Vector2 Position;
		cgmath::Vector2 Size;

		void SetPos(cgmath::Vector2 Pos) {
			Position = Pos;
		}

		void SetSize(cgmath::Vector2 SZ) {
			Size = SZ;
		}


		void SetText(LPCTSTR TEX) {
			Text = TEX;
		}

		void Update(cWindow WIN) {

			HBRUSH BgBrush = CreateSolidBrush(BGcolor.GetREF());
			HPEN BgPen = CreatePen(0,1, (BGcolor*0.8).GetREF());

			SelectObject(WIN.GetDC(), BgPen);
			SelectObject(WIN.GetDC(), BgBrush);

			Rectangle(WIN.GetDC(), Position.x, Position.y-15, Position.x + Size.x, Position.y + Size.y);


			DeleteObject(BgBrush);
			DeleteObject(BgPen);

			RECT SHAPE;
			SHAPE.left = Position.x;
			SHAPE.top = Position.y;
			SHAPE.bottom = Position.y + Size.y;
			SHAPE.right = Position.x + Size.x;

			DrawText(WIN.GetDC(), Text, -1, &SHAPE, DT_CENTER | DT_VCENTER );


		}

	};


}