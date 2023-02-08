#pragma once
#ifndef KALK_H
#define KALK_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class kalk {
private:
	vector<double> num;
	vector<char> zn;
	vector <int> v;
	void f1(double& x, int i);
	void f2(double& x, int i);
	double my_pow(double x, double y);
public:
	/*переменная со значением х*/
	double is_x;
	/*выдает результат*/
	double result();
	/*очистка решения и условия*/
	void clear(bool s);
	/*условие примера*/
	string mes;
	/*НОД*/
	unsigned int gcd(unsigned int a, unsigned int b);
	/*НОК*/
	unsigned int lcm(unsigned int a, unsigned int b);

	/*Заметим, что алгоритм найдёт только одно решение уравнения — x0 и y0. Все остальные подходящие пары x и y связаны следующим свойством:
x=x0+b/dt
y=y0−a/dt,
где t — любое целое число.

Вернёмся к изначальному уравенению ax+by=c. Пусть x0 и y0 — решение уравнения ax0+by0=d, тогда
x=c/dx0+b/dt
y=c/dy0−a/dt,где t — любое целое число.*/
	int gcd_ext(int a, int b, int& x, int& y);

	/*факториал*/
	uint64_t factorial(int n) {
		uint64_t x = 1;
		for (uint64_t i = 1; i <= n; i++) {
			x = x * i;
		}
		return x;
	}


};



#endif // !KALK_H


