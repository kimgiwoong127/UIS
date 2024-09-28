#include<iostream>
using namespace std;

int main() {
	cout << "시작";
	int pl;
	cin >> pl;
	switch (pl)
	{
	case 1:
		cout << "강공격" << endl;
		break;
	case 2:
		cout << "약공격" << endl;
		break;
	case 3:
		cout << "방어" << endl;
		break;
	case 4:
		cout << "회피" << endl;
		break;
	case 5:
		cout << "회복" << endl;
		break;
	default:
		break;
	}

	return 0;
}