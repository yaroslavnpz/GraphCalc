#pragma once

#include "ev.h"

namespace win1 {


double skr_w1, skr_h1;
struct xyz {
	float x, y, z;
};
xyz k;

struct mes {
	string m[3];
	int kof = 0;
};
mes ms;
mes mesg;

Button pole(0, 0, 500, 500);
//Button pole;
ButtonGL pole1(0, 1.9, 5.6, 2.8, -6.7, 1000, 500);
ButtonGL pole2(0, 0.9, 5.6, 1.9, -6.7, 1000, 500);
ButtonGL pole3(0, -0.1, 5.6, 0.9, -6.7, 1000, 500);

ButtonGL nar(0, -0.1, 2.8, -1, -6.7, 1000, 500);
ButtonGL if_kl(2.8, -0.1, 5.6, -1, -6.7, 1000, 500);

ButtonGL full(4.53, -1, 5.6, -3, -6.7, 1000, 500);

ButtonGL kl1(-4, 2, -3.1, 1.1, -6.7, 1000, 500);
ButtonGL kl2(-3, 2, -2.1, 1.1, -6.7, 1000, 500);
ButtonGL kl3(-2, 2, -1.1, 1.1, -6.7, 1000, 500);

ButtonGL kl4(-4, 1, -3.1, 0.1, -6.7, 1000, 500);
ButtonGL kl5(-3, 1, -2.1, 0.1, -6.7, 1000, 500);
ButtonGL kl6(-2, 1, -1.1, 0.1, -6.7, 1000, 500);

ButtonGL kl7(-4, 0, -3.1, -0.9, -6.7, 1000, 500);
ButtonGL kl8(-3, 0, -2.1, -0.9, -6.7, 1000, 500);
ButtonGL kl9(-2, 0, -1.1, -0.9, -6.7, 1000, 500);

ButtonGL ppp(0, -1, -6, -3, -6.7, 1000, 500);

//ButtonGL per(3.6, -1, 4.6, -3, -6.7, 1000, 500);
int bakspaceStop = 0;
bool fullScr = 0;
bool if_klav = 0;
int run = 1;
kalk a, b, c;


void ev() {
	SDL_StartTextInput();
	while (SDL_PollEvent(&w.e) != 0) {
		SDL_GetMouseState(&w.m.x, &w.m.y);
		int mx, my;
		mx = w.m.x;
		my = w.m.y;
		w.m.x = map(w.m.x, skr_w1, 1000);
		w.m.y = map(w.m.y, skr_h1, 500);

		switch (w.e.type) {
		case SDL_WINDOWEVENT:
			if (w.e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
				skr_w1 = w.e.window.data1;
				skr_h1 = w.e.window.data2;
				glViewport(0, 0, skr_w1, skr_h1);

			}
			break;
		case SDL_MOUSEBUTTONDOWN:

			if (fullScr == 0) {
				if (pole1.press(w.m)) {
					ms.kof = 0;
				}
				if (pole2.press(w.m)) {
					ms.kof = 1;
				}
				if (pole3.press(w.m)) {
					ms.kof = 2;
				}
				if (nar.press(w.m)) {
					mesg.m[0] = ms.m[0];
					mesg.m[1] = ms.m[1];
					mesg.m[2] = ms.m[2];
				}
				if (if_kl.press(w.m) == 1) {
					if_klav = !if_klav;
				}
				if (if_klav == 1) {
					if (kl1.press(w.m)) {
						ms.m[ms.kof] += 's';
					}
					if (kl2.press(w.m)) {
						ms.m[ms.kof] += 'c';
					}
					if (kl3.press(w.m)) {
						ms.m[ms.kof] += '^';
					}
					if (kl4.press(w.m)) {
						ms.m[ms.kof] += 't';
					}
					if (kl5.press(w.m)) {
						ms.m[ms.kof] += 'k';
					}
					if (kl6.press(w.m)) {
						ms.m[ms.kof] += 'x';
					}
					if (kl7.press(w.m)) {
						ms.m[ms.kof] += "ln";
					}
					if (kl8.press(w.m)) {
						ms.m[ms.kof] += "lg";
					}
					if (kl9.press(w.m)) {
						ms.m[ms.kof] += "abs";
					}

				} else if (pole.press(w.m) == 1) {
					pole_x = double(w.m.x - 241) / 86 / k.z - k.x / k.z;
					pole_y = ((double(250 - w.m.y) / 86) / k.z - k.y / k.z) * (skr_h1 / skr_w1 * 2);
					//pole_y = (double(250 - w.m.y) / 86) / k.z * (skr_h1 / skr_w1 * 2) - k.y / k.z;
				}
			} else {
				if (ppp.press(w.m) == 0) {
					pole_x = double(w.m.x - 241) / 86 / k.z - k.x / k.z;
					pole_y = ((double(250 - w.m.y) / 86) / k.z - k.y / k.z) * (skr_h1 / skr_w1 * 2);
					//pole_x = double(w.m.x - 241) / 86 / k.z - k.x / k.z;
					//pole_y = (double(250 - w.m.y) / 86) / k.z - k.y / k.z;
				}
			}
			if (full.press(w.m) == 1) {
				fullScr = !fullScr;
			}

			/*if (per.press(w.m)==1) {
				re_menu = 1;
				run = 0;
			}*/
			break;
		case SDL_MOUSEWHEEL:
			if (w.e.wheel.y > 0.0) {
				k.z += 0.1;
			} else if (w.e.wheel.y < 0.0) {
				k.z -= 0.1;
				if (k.z <= 0.05) {
					k.z += 0.1;
				}
			}
			break;
		case SDL_TEXTINPUT:
			ms.m[ms.kof] += w.e.text.text;
			break;
		case SDL_QUIT:
			exit(0);
		}
		if (w.e.key.keysym.sym == SDLK_UP) {
			k.y -= 0.25;
		} else if (w.e.key.keysym.sym == SDLK_DOWN) {
			k.y += 0.25;
		} else if (w.e.key.keysym.sym == SDLK_RIGHT) {
			k.x -= 0.25;
		} else if (w.e.key.keysym.sym == SDLK_LEFT) {
			k.x += 0.25;
		} else if (w.e.key.keysym.sym == SDLK_BACKSPACE) {
			if (bakspaceStop <= 0) {
				if (ms.m[ms.kof].size() > 0) {
					ms.m[ms.kof].pop_back();
				}
				bakspaceStop = 2;
			}
			bakspaceStop--;
		} else if (w.e.key.keysym.sym == SDLK_RETURN) {
			mesg.m[ms.kof] = ms.m[ms.kof];
		} else if (w.e.key.keysym.sym == SDLK_ESCAPE) {
			SDL_SetWindowFullscreen(w.w, 0);
		}
	}
}


void graf() {
	double kkk = skr_w1 / skr_h1 / 2;

	glLoadIdentity();
	glLineWidth(1.3);
	glTranslatef(k.x, k.y, -7);
	glRotatef(0, 1.0f, 0.0f, 0.0f);
	glRotatef(0, 0.0f, 1.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, 1.0f);
	glBegin(GL_LINE_STRIP);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);/////////////////////////////////////////////////////////
	double y;
	a.mes = mesg.m[0];
	b.mes = mesg.m[1];
	c.mes = mesg.m[2];
	for (double x = -300; x <= 300; x += 0.125) {
		a.is_x = x;
		y = a.result();
		glVertex2f(k.z * x - 3, k.z * y * kkk);////////
		a.clear(1);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);/////////////////////////////////////////////////////////////
	for (double x = -300; x <= 300; x += 0.125) {
		b.is_x = x;
		y = b.result();
		glVertex2f(k.z * x - 3, k.z * y * kkk + 0.01);////////////
		b.clear(1);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//////////////////////////////////////////////////////////////
	for (double x = -300; x <= 300; x += 0.125) {
		c.is_x = x;
		y = c.result();
		glVertex2f(k.z * x - 3, k.z * y * kkk - 0.01);/////////////
		//cout << c.result()*k.z << '\n';
		c.clear(1);
	}
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glVertex2f(-3, -300);
	glVertex2f(-3, 300);
	glVertex2f(-300, 0);
	glVertex2f(300, 0);
	glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
	for (int q = -300; q <= 300; q++) {
		glVertex2f(q * k.z - 3, -300 * k.z * kkk);
		glVertex2f(q * k.z - 3, 300 * k.z * kkk);
		glVertex2f(300 * k.z - 3, q * k.z * kkk);
		glVertex2f(-300 * k.z - 3, q * k.z * kkk);
	}
	glEnd();
}


void grafiki() {
	skr_w1 = 1000;
	skr_h1 = 500;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	k.z = 1;
	a.mes = ms.m[0] = mesg.m[0] = "x";
	b.mes = ms.m[1] = mesg.m[1] = "x^2";
	c.mes = ms.m[2] = mesg.m[2] = "x^3";
	while (run) {
		int start = clock();
		ev();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		/////////////////////////////////////////////////////////////////
		glLoadIdentity();
		glTranslatef(0, 0, -6.7);
		glBegin(GL_QUADS);
		glColor4f(1, 0, 0.5, 1);
		glVertex2f(0, -1);
		glVertex2f(4.6, -1);
		glVertex2f(4.6, -3);
		glVertex2f(0, -3);
		glEnd();
		text.printD(0.1, -1.5, -6, 0.3, 0.5, pole_x);
		text.printD(0.1, -2.5, -6, 0.3, 0.5, pole_y);
		/////////////////////////////////////////////////////////////////


		graf();
		if (fullScr == 0) {
			pole1.show(0.8, 0, 0, 1);
			pole2.show(0, 0.8, 0, 1);
			pole3.show(0, 0, 0.8, 1);
			nar.show(0, 0.7, 0.7, 1);
			text.printV(0.1, -0.6, -6.5, 0.26, 0.5, { 205, 224,247, 229, 240, 242, 232,242,252, });//32, 227,240,224,244,232,234
			text.printV(0.1, -0.9, -6.5, 0.32, 0.5, { 32, 227,240,224,244,232,234 });
			if_kl.show(0.7, 0, 0.7, 1);
			text.printV(2.9, -0.6, -6.0, 0.2, 0.4, { 202,235,224,226,232,224,242,243,240,224 });
			text.print(0.1, 1.9, -6, 0.3, 0.6, ms.m[0]);
			text.print(0.1, 0.9, -6, 0.3, 0.6, ms.m[1]);
			text.print(0.1, 0.1, -6, 0.3, 0.6, ms.m[2]);
			///////////////////////////////////////
			if (if_klav == 1) {
				kl1.show(0.6, 0.6, 0.6, 1);
				kl2.show(0.6, 0.6, 0.6, 1);
				kl3.show(0.6, 0.6, 0.6, 1);
				kl4.show(0.6, 0.6, 0.6, 1);
				kl5.show(0.6, 0.6, 0.6, 1);
				kl6.show(0.6, 0.6, 0.6, 1);
				kl7.show(0.6, 0.6, 0.6, 1);
				kl8.show(0.6, 0.6, 0.6, 1);
				kl9.show(0.6, 0.6, 0.6, 1);
				text.print(-3.8, 1.3, -6.5, 0.145, 0.39, "sin");
				text.print(-2.8, 1.3, -6.5, 0.145, 0.39, "cos");
				text.print(-1.8, 1.3, -6.5, 0.145, 0.39, " ^");

				text.print(-3.8, 0.3, -6.5, 0.145, 0.39, "tg");
				text.print(-2.8, 0.3, -6.5, 0.145, 0.39, "ktg");
				text.print(-1.8, 0.3, -6.5, 0.145, 0.39, " x");

				text.print(-3.8, -0.7, -6.5, 0.145, 0.39, "ln");
				text.print(-2.8, -0.7, -6.5, 0.145, 0.39, "lg");
				text.print(-1.8, -0.7, -6.5, 0.145, 0.39, "abs");
			}
		}
		full.show(0.5, 0.5, 0, 1);
		//per.show(1, 0, 0.5, 1);///////////////////////////////////////////////////////////////////////////
		text.printV(4.7, -1.5, -6.5, 0.118, 0.235, { 207, 238, 235, 237, 251, 233 });
		text.printV(4.7, -1.8, -6.5, 0.12, 0.235, { 221, 234, 240, 224, 237 });
		glFlush();
		SDL_GL_SwapWindow(w.w);
		int end = clock();
		if (end - start < 40) {
			SDL_Delay(40 - (end - start));
		}
		//SDL_Delay(100);
	}
}

}