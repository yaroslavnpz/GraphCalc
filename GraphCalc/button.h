#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include "start.h"

class Button {
private:
	int low_x, low_y, high_x, high_y;
public:
	Button(int x1, int y1, int x2, int y2) {
		low_x = x1;
		low_y = y1;
		high_x = x2;
		high_y = y2;
	}
	bool press(mouse m) {
		if ((low_x <= m.x && m.x <= high_x) && (low_y <= m.y && m.y <= high_y)) {
			return 1;
		}
		return 0;
	}
};

class ButtonGL {
private:
	float low_x, low_y, high_x, high_y, z;
	int w, h;
	float f = 0;
public:
	ButtonGL(float x1, float y1, float x2, float y2, float zz, int x, int y) {
		low_x = x1;
		low_y = y1;
		high_x = x2;
		high_y = y2;
		if (low_x > high_x) {
			swap(low_x, high_x);
		}
		if (low_y > high_y) {
			swap(low_y, high_y);
		}
		z = zz;
		w = x;
		h = y;
	}
	bool press(mouse m) {//tg(22,5)=0,4142135623730950488016887242097
		float i = 90;
		int lx = w / 2 + (low_x * i);
		int hx = w / 2 + (high_x * i);
		int ly = h / 2 - ((low_y * i));
		int hy = h / 2 - ((high_y * i));
		if (hy < ly) {
			swap(ly, hy);
		}

		//cout <<lx<<' '<<m.x<<' '<<hx<<"    "<< ly << ' ' << m.y << ' ' << hy << '\n';

		if ((lx <= m.x && m.x <= hx) && (ly <= m.y && m.y <= hy)) {
			f = 0.2;
			return 1;
		}
		f = 0;
		return 0;
	}
	void show(float r, float g, float b, float a) {
		glLoadIdentity();
		glTranslatef(0, 0, z - f + 0.1);
		//cout << f << '\n';
		if (f > 0.0) {
			f -= 0.0625;
		} else {
			f = 0;
		}
		glBegin(GL_QUADS);
		glColor4f(r, g, b, a);
		/*glVertex2f(low_x + 0.1, low_y + 0.1);
		glVertex2f(high_x - 0.1, low_y + 0.1);
		glVertex2f(high_x - 0.1, high_y - 0.1);
		glVertex2f(low_x + 0.1, high_y - 0.1);

		glColor4f(r - 0.1, g - 0.1, b - 0.1, a);
		glVertex3f(low_x, low_y, -0.1);
		glVertex3f(low_x + 0.1, low_y + 0.1, 0);
		glVertex3f(high_x - 0.1, low_y + 0.1, 0);
		glVertex3f(high_x, low_y, -0.1);

		glVertex3f(high_x, high_y, -0.1);
		glVertex3f(high_x - 0.1, high_y - 0.1, 0);
		glVertex3f(high_x - 0.1, low_y + 0.1, 0);
		glVertex3f(high_x, low_y, -0.1);

		glVertex3f(low_x, high_y, -0.1);
		glVertex3f(low_x + 0.1, high_y - 0.1, 0);
		glVertex3f(low_x + 0.1, low_y + 0.1, 0);
		glVertex3f(low_x, low_y, -0.1);

		glVertex3f(low_x, high_y, -0.1);
		glVertex3f(low_x + 0.1, high_y - 0.1, 0);
		glVertex3f(high_x - 0.1, high_y - 0.1, 0);
		glVertex3f(high_x, high_y, -0.1);*/

		glVertex2f(low_x, low_y);
		glVertex2f(high_x, low_y);
		glVertex2f(high_x, high_y);
		glVertex2f(low_x, high_y);

		glEnd();

		glColor4f(0, 0, 0, a);
		glLineWidth(5);
		glBegin(GL_LINE_STRIP);
		glVertex2f(low_x, low_y);
		glVertex2f(high_x, low_y);
		glVertex2f(high_x, high_y);
		glVertex2f(low_x, high_y);
		glVertex2f(low_x, low_y);
		glEnd();
	}
};
#endif