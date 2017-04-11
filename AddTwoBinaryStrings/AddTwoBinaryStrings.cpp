#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const string AddTwoBinaryStrings(string& str, string& str2)
{
	int carry = 0;
	string str3;
	const string::size_type N = str.size() > str2.size() ? str.size() : str2.size();
	reverse(str.begin(), str.end());
	reverse(begin(str2), end(str2));
	for (size_t i = 0; i != N; ++i)
	{
		int ia = i < str.size() ? str[i] - '0' : 0;
		int ib = i < str2.size() ? str2[i] - '0' : 0;
		int tmpval = (ia + ib + carry) % 2;
		carry = (ia + ib + carry) / 2;
		str3.insert(str3.begin(), tmpval + '0');
	}
	if (carry == 1) str3.insert(str3.begin(), '1');
	return str3;
}

int main(int argc, char** argv)
{
	string str, str2;
	cout << "Please input two binary strings: ";
	cin >> str >> str2;
	cout << "The result is: " << AddTwoBinaryStrings(str, str2) << endl;
	return EXIT_SUCCESS;
}