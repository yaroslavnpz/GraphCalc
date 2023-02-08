#include "kalk.h"




double kalk::my_pow(double x, double y) {
	return 0;
}









void kalk::clear(bool s) {
	if (s == 0) {
		mes.clear();
	}
	num.clear();
	zn.clear();
	v.clear();
	is_x = 0;
}

void kalk::f1(double& x, int i) {
	for (int q = i - 1; q >= 0; q--) {
		if (zn[q] != 0) {
			x = num[q];
			//cout << x << ' ' << q << ' ' << zn[q] << '\n';
			num[q] = 0;
			zn[q] = 0;
			v[q] = 0;
			break;
		}
	}
}

void kalk::f2(double& y, int i) {
	for (int q = i + 1; q < v.size(); q++) {
		if (zn[q] != 0) {
			y = num[q];
			num[q] = 0;
			zn[q] = 0;
			v[q] = 0;
			break;
		}
	}
}

double kalk::result() {
	int i = 0;
	bool t = 0;
	int tt = 1;
	int sk = 0;
	int sk_max = 0;
	for (int u = 0; u < mes.length(); u++) {
		while (int(num.size()) - 1 < i || int(zn.size()) - 1 < i || int(v.size()) - 1 < i) {
			num.push_back(0);
			zn.push_back(0);
			v.push_back(0);
		}
		if (mes[u] <= '9' && mes[u] >= '0') {
			num[i] = num[i] * 10 + mes[u] - '0';
			zn[i] = 1;
			if (t == 1) {
				tt *= 10;
			}
		} else if (mes[u] == '.') {
			t = 1;
		} else if (mes[u] == '(') {
			sk += 10;
		} else if (mes[u] == ')') {
			sk -= 10;
		} else if (mes[u] == 'x') {
			num[i] = is_x;
			zn[i] = 1;
		} else {
			if (t == 1) {
				t = 0;
				num[i] /= tt;
				tt = 1;
			}
			i++;
			while (int(num.size()) - 1 < i || int(zn.size()) - 1 < i || int(v.size()) - 1 < i) {
				num.push_back(0);
				zn.push_back(0);
				v.push_back(0);
			}
			zn[i] = mes[u];
			switch (mes[u]) {
			case '+':
				v[i] = 1 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case '-':
				v[i] = 1 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case '*':
				v[i] = 2 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case '/':
				v[i] = 2 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case '!':
				v[i] = 9 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case '^':
				v[i] = 9 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 'r'://корень
				v[i] = 9 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 's'://sin
				v[i] = 8 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 'c'://cos
				v[i] = 8 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 't'://tan
				v[i] = 8 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 'k'://kotan
				v[i] = 8 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 'l'://log
				u++;
				v[i] = 8 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				i++;
				while (int(num.size()) - 1 < i || int(zn.size()) - 1 < i || int(v.size()) - 1 < i) {
					num.push_back(0);
					zn.push_back(0);
					v.push_back(0);
				}
				zn[i] = mes[u];
				v[i] = 8 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			case 'a'://abs
				v[i] = 9 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				i++;
				u++;
				while (int(num.size()) - 1 < i || int(zn.size()) - 1 < i || int(v.size()) - 1 < i) {
					num.push_back(0);
					zn.push_back(0);
					v.push_back(0);
				}
				zn[i] = mes[u];
				v[i] = 9 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				///////////////////////////////////////////////////////
				i++;
				u++;
				while (int(num.size()) - 1 < i || int(zn.size()) - 1 < i || int(v.size()) - 1 < i) {
					num.push_back(0);
					zn.push_back(0);
					v.push_back(0);
				}
				zn[i] = mes[u];
				v[i] = 9 + sk;
				if (v[i] > sk_max) {
					sk_max = v[i];
				}
				break;
			}
			i++;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (t == 1) {
		t = 0;
		num[i] /= tt;
		tt = 0;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	double x, y;
	for (int u = sk_max; u > 0; u--) {
		for (int i = 0; i < zn.size(); i++) {
			x = y = 0;
			if (v[i] == u) {
				if (zn[i] != 0) {
					switch (zn[i]) {
					case '+':
						f1(x, i);

						f2(y, i);
						num[i] = x + y;
						break;
					case'-':
						f1(x, i);
						f2(y, i);
						num[i] = x - y;
						break;
					case'*':
						f1(x, i);
						f2(y, i);
						num[i] = x * y;
						break;
					case'/':
						f1(x, i);
						f2(y, i);
						num[i] = x / y;
						break;
					case'!':
						f1(x, i);
						num[i] = factorial(x);
						break;
					case'^':
						f1(x, i);
						f2(y, i);
						num[i] = pow(x, y);
						break;
					case'r':
						f1(x, i);
						f2(y, i);
						num[i] = pow(y, 1 / x);
						break;
					case 's'://sin
						f2(y, i);
						num[i] = sin(y);
						break;
					case 'c'://cos
						f2(y, i);
						num[i] = cos(y);
						break;
					case 't'://tan
						f2(y, i);
						num[i] = tan(y);

						break;
					case 'k'://kotan
						f2(y, i);
						num[i] = tan(y);
						num[i] = 1 / num[i];
						break;
					case 'l'://log
						i++;
						f2(y, i);
						if (zn[i] == 'n') {
							num[i - 1] = log(y);
							zn[i] = 0;
						} else {
							num[i - 1] = log10(y);
							zn[i] = 0;
						}


						break;
					case 'a'://log
						i++;
						//f2(y, i);
						if (zn[i] == 'b') {
							i++;
							if (zn[i] == 's') {
								f2(y, i);
								num[i - 2] = abs(y);
								zn[i] = 0;
								zn[i - 1] = 0;
							}
						}


						break;
					}

				}
			}
		}
	}
	for (int u = 0; u < num.size(); u++) {
		if (zn[u] != 0) {
			return num[u];
		}
	}
}

unsigned int kalk::gcd(unsigned int a, unsigned int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

unsigned int kalk::lcm(unsigned int a, unsigned int b) {
	return uint64_t(a) * uint64_t(b) / gcd(a, b);
}

int kalk::gcd_ext(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = gcd_ext(b, a % b, x, y);
	x -= (a / b) * y;
	swap(x, y);
	return d;
}