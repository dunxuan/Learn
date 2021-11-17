#include <iostream>

using namespace std;

struct PersonListNode * ListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address);

struct PersonListNode * InputPersonInfo(void);

//性别
enum Sex {
	Female,
	Male
};
//轨迹信息：时间、地点
struct TrailInfo {
	string Time;
	string Place;
};
//健康信息：时间、体温
struct HealthInfo {
	string Time;
	float Temperature;
};
//人员信息
struct PersonInfo {
	string Name;//姓名
	string ID;//ID
	Sex P_Sex;//性别
	int Age;//年龄
	string Address;//家庭住址
	TrailInfo P_TrailInfo;//轨迹信息：时间、地点
	HealthInfo P_HealthInfo;//健康信息：时间、体温
};
//链表
struct PersonListNode {
	PersonInfo P_PersonInfo;
	PersonListNode * next;
};

int main(void)
{
	PersonListNode * head = NULL;
	bool DoesPersonInfoSave = false;
	char change = 0;
	PersonListNode * p;
	PersonListNode * q;
	for (;;) {
		cout << "输入要进行的操作：录入人员信息(i)、记录某人出行轨迹和体温(r)、查询某人出行轨迹和体温情况(s)、查询体温异常人员(e):";
		cin >> change;
		switch (change) {
		case 'i'://录入人员信息
			p = InputPersonInfo();
			if (p) {
				cout << "录入成功。" << endl;
				if (DoesPersonInfoSave == false) {
					DoesPersonInfoSave = true;
					q = head = p;
				} else {
					q->next = p;
				}
			} else {
				cout << "录入失败，请重新输入。" << endl;
			}
			break;
		case 'r'://记录某人出行轨迹和体温

			break;
		case 's'://查询某人出行轨迹和体温情况

			break;
		case 'e'://查询体温异常人员

			break;
		default:
			continue;
		}
	}
	return 0;
}

struct PersonListNode * ListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address)
{
	PersonListNode * NewListNode = new PersonListNode;
	if (NewListNode == (PersonListNode *)NULL) {
		return (PersonListNode *)NULL;
	}

	NewListNode->P_PersonInfo.Name = Name;
	NewListNode->P_PersonInfo.ID = ID;
	NewListNode->P_PersonInfo.P_Sex = P_Sex;
	NewListNode->P_PersonInfo.Age = Age;
	NewListNode->P_PersonInfo.Address = Address;
	NewListNode->next = NULL;

	return NewListNode;
}

//功能：录入人员信息
//返回：(PersonListNode *)地址 -> 录入信息成功，NULL -> 录入信息失败
struct PersonListNode * InputPersonInfo(void)
{
	string Name;//姓名
	string ID;//ID
	string P_SexInput;//性别，暂存输入内容
	Sex P_Sex = Female;//性别，处理后内容
	int Age = 0;//年龄
	string Address;//家庭住址

	cout << "输入姓名：";
	cin >> Name;
	cout << "输入ID：";
	cin >> ID;
	cout << "输入性别：";
	cin >> P_SexInput;
	cout << "输入年龄：";
	cin >> Age;
	cout << "输入家庭住址：";
	cin >> Address;
	//性别，处理输入内容
	if (P_SexInput == "男") {
		P_Sex = Male;
	} else {
		P_Sex = Female;
	}
	//将输入数据并入链表中
	PersonListNode * p = ListCreate(Name, ID, P_Sex, Age, Address);
	if (p) {
		return p;
	} else {
		return (PersonListNode *)NULL;
	}
}

//功能：记录某人出行轨迹和体温
//