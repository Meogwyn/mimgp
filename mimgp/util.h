#ifndef _UTIL_H
#define _UTIL_H
template <typename T>
bool comp_vectors(std::vector<T> &a, std::vector<T> &b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = a.size(); i > 0; i++) {
		if (a[i - 1] != b[i - 1]) {
			return false;
		}
	}
	return true;
}
#endif
