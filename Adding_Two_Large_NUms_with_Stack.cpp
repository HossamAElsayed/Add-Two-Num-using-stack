#include <iostream>
#include <stack>
#include <string>

using namespace std;


template<class T>
void print(stack<T>& s)
{
	cout << endl;
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main()
{
	stack<int> f;
	stack<int> s;
	stack<int> result;
	string fn = "12";
	string sn = "198111";
	string tmp;
	if (fn.length() < sn.length()) {
		int Zeros = sn.length() - fn.length();
		for (int i = 0; i < Zeros; i++) {
			tmp.append("0");
		}
		fn = tmp + fn;
		cout << fn;
	}
	else if (sn.length() < fn.length()) {
		int Zeros = fn.length() - sn.length();
		for (int i = 0; i < Zeros; i++) {
			tmp.append("0");
		}
		sn = tmp+ sn;
		cout << sn;
	}
	else cout << "Equal in length";

	for (int i = 0; i < fn.length(); i++) {
		int x = int(fn[i]) - 48;
		f.push(x);
	}
	for (int i = 0; i < sn.length(); i++) {
		int x = int(sn[i]) - 48;
		s.push(x);
	}
	int carry = 0;
	int i = 0;
	while (!f.empty()||!s.empty()) {
		
		carry = f.top() + s.top() + i;
		if (carry <= 9) {
			result.push(carry);
		}
		else {
			carry = carry - 10;
			result.push(carry);
			i = 1;
		}

		f.pop();
		s.pop();

	}
	print(result);
}