#pragma once
#include "ev.h"

namespace win2 {
kalk k[2];

string m1[2] = { "0","0" };


ButtonGL kl0(-5, 1.5, -4.1, 0.6, -6.5, 1000, 500);
ButtonGL kl1(-4, 1.5, -3.1, 0.6, -6.5, 1000, 500);
ButtonGL kl2(-3, 1.5, -2.1, 0.6, -6.5, 1000, 500);
ButtonGL kl3(-2, 1.5, -1.1, 0.6, -6.5, 1000, 500);
ButtonGL kl4(-1, 1.5, -0.1, 0.6, -6.5, 1000, 500);
ButtonGL kl5(0, 1.5, 0.9, 0.6, -6.5, 1000, 500);
ButtonGL kl6(1, 1.5, 1.9, 0.6, -6.5, 1000, 500);
ButtonGL kl7(2, 1.5, 2.9, 0.6, -6.5, 1000, 500);
ButtonGL kl8(3, 1.5, 3.9, 0.6, -6.5, 1000, 500);
ButtonGL kl9(4, 1.5, 4.9, 0.6, -6.5, 1000, 500);

ButtonGL kl_pl(-5, 0.5, -4.1, -0.4, -6.5, 1000, 500);
ButtonGL kl_m(-4, 0.5, -3.1, -0.4, -6.5, 1000, 500);
ButtonGL kl_um(-3, 0.5, -2.1, -0.4, -6.5, 1000, 500);
ButtonGL kl_del(-2, 0.5, -1.1, -0.4, -6.5, 1000, 500);
ButtonGL kl_t(-1, 0.5, -0.1, -0.4, -6.5, 1000, 500);
ButtonGL kl_sk1(0, 0.5, 0.9, -0.4, -6.5, 1000, 500);
ButtonGL kl_sk2(1, 0.5, 1.9, -0.4, -6.5, 1000, 500);
ButtonGL kl_step(2, 0.5, 2.9, -0.4, -6.5, 1000, 500);
ButtonGL kl_sin(3, 0.5, 3.9, -0.4, -6.5, 1000, 500);
ButtonGL kl_cos(4, 0.5, 4.9, -0.4, -6.5, 1000, 500);

ButtonGL kl_tan(-5, -0.5, -4.1, -1.4, -6.5, 1000, 500);
ButtonGL kl_ktan(-4, -0.5, -3.1, -1.4, -6.5, 1000, 500);
ButtonGL kl_log(-3, -0.5, -2.1, -1.4, -6.5, 1000, 500);
ButtonGL kl_11(-2, -0.5, -1.1, -1.4, -6.5, 1000, 500);
ButtonGL kl_12(-1, -0.5, -0.1, -1.4, -6.5, 1000, 500);
ButtonGL kl_13(0, -0.5, 0.9, -1.4, -6.5, 1000, 500);
ButtonGL kl_14(1, -0.5, 1.9, -1.4, -6.5, 1000, 500);
ButtonGL kl_15(2, -0.5, 2.9, -1.4, -6.5, 1000, 500);
ButtonGL kl_16(3, -0.5, 3.9, -1.4, -6.5, 1000, 500);
ButtonGL kl_rav(4, -0.5, 4.9, -1.4, -6.5, 1000, 500);

ButtonGL per(4, 1.6, 4.9, 2.5, -6.5, 1000, 500);
int bakspaceStop = 0;
int run = 1;
int pos = 0;

void ev() {
	SDL_StartTextInput();
	if (SDL_PollEvent(&w.e) != 0) {
		SDL_GetMouseState(&w.m.x, &w.m.y);
		switch (w.e.type) {
		case SDL_MOUSEBUTTONDOWN:
			if (kl0.press(w.m) == 1) {
				m1[pos] += '0';
			}
			if (kl1.press(w.m) == 1) {
				m1[pos] += '1';
			}
			if (kl2.press(w.m) == 1) {
				m1[pos] += '2';
			}
			if (kl3.press(w.m) == 1) {
				m1[pos] += '3';
			}
			if (kl4.press(w.m) == 1) {
				m1[pos] += '4';
			}
			if (kl5.press(w.m) == 1) {
				m1[pos] += '5';
			}
			if (kl6.press(w.m) == 1) {
				m1[pos] += '6';
			}
			if (kl7.press(w.m) == 1) {
				m1[pos] += '7';
			}
			if (kl8.press(w.m) == 1) {
				m1[pos] += '8';
			}
			if (kl9.press(w.m) == 1) {
				m1[pos] += '9';
			}
			if (kl_pl.press(w.m) == 1) {
				m1[pos] += '+';
			}
			if (kl_m.press(w.m) == 1) {
				m1[pos] += '-';
			}
			if (kl_um.press(w.m) == 1) {
				m1[pos] += '*';
			}
			if (kl_del.press(w.m) == 1) {
				m1[pos] += '/';
			}
			if (kl_sk1.press(w.m) == 1) {
				m1[pos] += '(';
			}
			if (kl_sk2.press(w.m) == 1) {
				m1[pos] += ')';
			}
			if (kl_t.press(w.m) == 1) {
				m1[pos] += '.';
			}
			if (kl_step.press(w.m) == 1) {
				m1[pos] += '^';
			}
			if (kl_sin.press(w.m) == 1) {
				m1[pos] += 's';
			}
			if (kl_cos.press(w.m) == 1) {
				m1[pos] += 'c';
			}
			if (kl_tan.press(w.m) == 1) {
				m1[pos] += 't';
			}
			if (kl_ktan.press(w.m) == 1) {
				m1[pos] += 'k';
			}
			if (kl_rav.press(w.m) == 1) {
				k[0].mes = m1[0];
				k[1].mes = m1[0];
			}
			if (per.press(w.m) == 1) {
				re_menu = 0;
				run = 0;
			}
			break;
		case SDL_TEXTINPUT:
			m1[pos] += w.e.text.text;
			break;
		case SDL_QUIT:
			exit(1);
		}

		switch (w.e.key.keysym.sym) {
		case SDLK_BACKSPACE:
			if (bakspaceStop <= 0) {
				if (m1[pos].size() > 0) {
					m1[pos].pop_back();
				}
				bakspaceStop = 2;
			}
			bakspaceStop--;
			break;
		case SDLK_RETURN:
			k[0].mes = m1[0];
			k[1].mes = m1[1];
			break;
		}
	}
}

void grmain() {
	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
	while (run) {
		int start = clock();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ev();
		/////////////////////////////////////////////////////////////////
		kl0.show(0.7, 0.7, 0.7, 1.0);
		kl1.show(0.7, 0.7, 0.7, 1.0);
		kl2.show(0.7, 0.7, 0.7, 1.0);
		kl3.show(0.7, 0.7, 0.7, 1.0);
		kl4.show(0.7, 0.7, 0.7, 1.0);
		kl5.show(0.7, 0.7, 0.7, 1.0);
		kl6.show(0.7, 0.7, 0.7, 1.0);
		kl7.show(0.7, 0.7, 0.7, 1.0);
		kl8.show(0.7, 0.7, 0.7, 1.0);
		kl9.show(0.7, 0.7, 0.7, 1.0);

		kl_pl.show(0.7, 0.7, 0.7, 1.0);
		kl_m.show(0.7, 0.7, 0.7, 1.0);
		kl_um.show(0.7, 0.7, 0.7, 1.0);
		kl_del.show(0.7, 0.7, 0.7, 1.0);
		kl_t.show(0.7, 0.7, 0.7, 1.0);
		kl_step.show(0.7, 0.7, 0.7, 1.0);
		kl_sk1.show(0.7, 0.7, 0.7, 1.0);
		kl_sk2.show(0.7, 0.7, 0.7, 1.0);
		kl_sin.show(0.7, 0.7, 0.7, 1.0);
		kl_cos.show(0.7, 0.7, 0.7, 1.0);

		kl_tan.show(0.7, 0.7, 0.7, 1.0);
		kl_ktan.show(0.7, 0.7, 0.7, 1.0);
		kl_rav.show(0.7, 0.7, 0.7, 1.0);

		per.show(1, 1, 1, 1);

		/////////////////////////////////////////////////
		Sprint(-4.5, 1.2, -6.4, 2, "0");
		Sprint(-3.5, 1.2, -6.4, 2, "1");
		Sprint(-2.5, 1.2, -6.4, 2, "2");
		Sprint(-1.5, 1.2, -6.4, 2, "3");
		Sprint(-0.5, 1.2, -6.4, 2, "4");
		Sprint(0.4, 1.2, -6.4, 2, "5");
		Sprint(1.4, 1.2, -6.4, 2, "6");
		Sprint(2.4, 1.2, -6.4, 2, "7");
		Sprint(3.4, 1.2, -6.4, 2, "8");
		Sprint(4.3, 1.2, -6.4, 2, "9");

		Sprint(-4.5, 0.2, -6.4, 2, "+");
		Sprint(-3.5, 0.2, -6.4, 2, "-");
		Sprint(-2.5, 0.2, -6.4, 2, "*");
		Sprint(-1.5, 0.2, -6.4, 2, "/");
		Sprint(-0.5, 0.2, -6.4, 2, ".");
		Sprint(0.4, 0.2, -6.4, 2, "(");
		Sprint(1.4, 0.2, -6.4, 2, ")");
		Sprint(2.4, 0.2, -6.4, 2, "^");
		Sprint(3.4, 0.2, -6.4, 2, "s");
		Sprint(4.3, 0.2, -6.4, 2, "c");

		Sprint(-4.8, -0.7, -6.4, 2, "tg");
		Sprint(-3.8, -0.7, -6.4, 2, "ktg");
		Sprint(4.3, -0.7, -6.4, 2, "=");
		/////////////////////////////////////////////////////////////////
		Sprint(-4.7, 2.4, -6, 2, m1[0]);
		k[0].clear(1);
		printdoubleM(-4.7, 2, -6, 2, k[0].result());


		glFlush();
		SDL_GL_SwapWindow(w.w);
		int end = clock();
		if (end - start < 40) {
			SDL_Delay(40 - (end - start));
		}
	}
}
}