#pragma once

namespace cgmath {

	class Vector2 {
	public:
		int x;
		int y;

		Vector2() {
			x = 0; y = 0;
		}

		Vector2(int xx, int yy) {
			x = xx; y = yy;
		}

		Vector2 operator+(Vector2 B) {
			return Vector2(x + B.x, y + B.y);
		}
		Vector2 operator-(Vector2 B) {
			return Vector2(x - B.x, y - B.y);
		}
		Vector2 operator/(Vector2 B) {
			return Vector2(x / B.x, y / B.y);
		}
		Vector2 operator*(Vector2 B) {
			return Vector2(x * B.x, y * B.y);
		}

		Vector2 operator+(float B) {
			return Vector2(x + B, y + B);
		}
		Vector2 operator-(float B) {
			return Vector2(x - B, y - B);
		}
		Vector2 operator/(float B) {
			return Vector2(x / B, y / B);
		}
		Vector2 operator*(float B) {
			return Vector2(x * B, y * B);
		}

	};

}