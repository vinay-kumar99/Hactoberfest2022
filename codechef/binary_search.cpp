#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch(vector<int> v, int To_Find)
{
	int lo = 0, hi = v.size() - 1;
	int mid;
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (v[mid] < To_Find) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	if (v[lo] == To_Find) {
		return lo;
	}
	else if (v[hi] == To_Find) {
		return hi;
	}
	else {
		return "Not Found";
	}
}

