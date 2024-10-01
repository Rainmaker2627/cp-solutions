#include "grader.h"
#include "cluedo.h"

void Solve() {
	int m=1, l=1, w=1;
	while (true) {
		switch (Theory(m, l, w)) {
			case 0: return;
			case 1: m++; break;
			case 2: l++; break;
			case 3: w++; break;
		}
	}
}