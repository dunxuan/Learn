#include <iostream>
#include <cstring>

using namespace std;

int numpassword(string password);

int main()
{
	string password;
	cout << "输入密码:";
	cin >> password;

	int num = numpassword(password);
	if(num == 1) {
		cout << "这是安全密码。";
	} else {
		cout << "这不是安全密码。";
	}

	return 0;
}
int numpassword(string password)
{
	int i, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num = 0;
	for(i = 0; i < password.length(); i++) {
		if(password[i] >= 'A' && password[i] <= 'Z')
			num1 = 1;
		else if(password[i] >= 'a' && password[i] <= 'z')
			num2 = 1;
		else if(password[i] >= '0' && password[i] <= '9')
			num3 = 1;
		else if(password[i] == '~' || password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^')
			num4 = 1;
	}
	num = num1 + num2 + num3 + num4;
	if(num >= 3 && password.length() >= 8 && password.length() <= 16) {
		return 1;
	} else {
		return 0;
	}
}