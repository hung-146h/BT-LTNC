#include <iostream>
using namespace std;


int strlen(const char *a) {
	int len = 0;
	while (*(a + len) != '\0') len++;
	return len;
}


void reverse(char *a) {
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++) {
		swap(*(a + i), *(a + len - 1 - i));
	}
}

void delete_char(char *a, char c) {
	char *src = a, *dst = a;
	while (*src) {
		if (*src != c) {
			*dst++ = *src;
		}
		src++;
	}
	*dst = '\0';
}


void pad_right(char *a, int n) {
	int len = strlen(a);
	if (len >= n) return;
	for (int i = len; i < n; i++) {
		*(a + i) = ' ';
	}
	*(a + n) = '\0';
}


void pad_left(char *a, int n) {
	int len = strlen(a);
	if (len >= n) return;
	int shift = n - len;
	for (int i = len - 1; i >= 0; i--) {
		*(a + i + shift) = *(a + i);
	}
	for (int i = 0; i < shift; i++) {
		*(a + i) = ' ';
	}
	*(a + n) = '\0';
}


void truncate(char *a, int n) {
	if (strlen(a) > n) {
		*(a + n) = '\0';
	}
}


bool is_palindrome(const char *a) {
	int len = strlen(a);
	for (int i = 0; i < len / 2; i++) {
		if (*(a + i) != *(a + len - 1 - i)) return false;
	}
	return true;
}


void trim_left(char *a) {
	char *start = a;
	while (*start == ' ') start++;
	char *dst = a;
	while (*start) {
		*dst++ = *start++;
	}
	*dst = '\0';
}


void trim_right(char *a) {
	int len = strlen(a);
	while (len > 0 && *(a + len - 1) == ' ') {
		*(a + --len) = '\0';
	}
}

int main() {
	char str[100] = "  hello world  ";

	cout << str << "\n";

	reverse(str);
	cout <<str << "\n";
	reverse(str);

	delete_char(str, 'l');
	cout<< str << "\n";

	pad_right(str, 15);
	cout<< str << "\n";

	pad_left(str, 20);
	cout << str << "\n";

	truncate(str, 10);
	cout  << str << "\n";

	cout << (is_palindrome(str) ? "Yes" : "No") << "\n";

	trim_left(str);
	cout << str << "\n";

	trim_right(str);
	cout << str << "\n";

	return 0;
}
