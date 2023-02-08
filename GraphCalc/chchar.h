#pragma once
#ifndef CHCHAR_H
#define CHCHAR_H

#include "start.h"




class Text {
public:
	Text() {
		uint8_t* data = stbi_load("font.png", &width, &height, &nrChannels, 0);
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D, 0, GL_RGBA,
			width, height,
			0,
			GL_RGBA, GL_UNSIGNED_BYTE, data
		);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		stbi_image_free(data);
	}
	//////////////////////////////////////////////////////////////////////////////////////
	void print(float x, float y, float z, float sizex, float sizey, string a) {
		float x1, y1, x2, yy;
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, z);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glColor4f(1, 1, 1, 1);
		for (int u = 0; u < a.length(); u++) {
			a[u] -= ' ';
			x1 = a[u] % 16;
			x1 = x1 * 0.0625;
			x2 = x1 + (sizex / sizey) * 0.0625;
			y1 = a[u] / 16;
			/*if (a[u] % 16 == 0) {
				y1--;
			}*/
			y1 = y1 * 0.0625;
			yy = y1 + 0.0625;

			glTexCoord2f(x1, yy); glVertex2f(x, y);	// Низ лево
			glTexCoord2f(x2, yy); glVertex2f(x + sizex, y);	// Низ право
			glTexCoord2f(x2, y1); glVertex2f(x + sizex, y + sizey);	// Верх право
			glTexCoord2f(x1, y1); glVertex2f(x, y + sizey);	// Верх лево
			x += sizex;
		}
		/*
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Низ лево
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Низ право
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Верх право
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Верх лево
		*/
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	void printV(float x, float y, float z, float sizex, float sizey, vector<uint8_t>a) {
		float x1, y1, x2, yy;
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, z);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin(GL_QUADS);
		glColor4f(1, 1, 1, 1);
		for (int u = 0; u < a.size(); u++) {
			a[u] -= ' ';
			x1 = a[u] % 16;
			x1 = x1 * 0.0625;
			x2 = x1 + (sizex / sizey) * 0.0625;
			y1 = a[u] / 16;
			/*if (a[u] % 16 != 0) {
				y1++;
			}*/
			y1 = y1 * 0.0625;
			yy = y1 + 0.0625;

			glTexCoord2f(x1, yy); glVertex2f(x, y);	// Низ лево
			glTexCoord2f(x2, yy); glVertex2f(x + sizex, y);	// Низ право
			glTexCoord2f(x2, y1); glVertex2f(x + sizex, y + sizey);	// Верх право
			glTexCoord2f(x1, y1); glVertex2f(x, y + sizey);	// Верх лево
			x += sizex;
		}
		/*
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);	// Низ лево
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);	// Низ право
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);	// Верх право
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);	// Верх лево
		*/
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	void printI(float x, float y, float z, float sizex, float sizey, int a) {
		ostringstream oss;
		oss << a;
		print(x, y, z, sizex, sizey, oss.str());
	}
	void printD(float x, float y, float z, float sizex, float sizey, double a) {
		print(x, y, z, sizex, sizey, to_string(a));
	}
private:
	int width, height, nrChannels;
	GLuint texture;
};



#endif // !CHCHAR_H
