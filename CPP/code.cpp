#include <iostream>
#include <string>
using namespace std;

enum Sex {
	Female,
	Male
};
struct TripInfo {
	string time;
	string place;
	float temperature;
};
struct TripListNode {
	TripInfo data;
	TripListNode *next;
};
struct PersonInfo {
	string name;
	string id;
	Sex sex;
	int age;
	string address;
	TripListNode *trip;
};
struct PersonListNode {
	PersonInfo data;
	PersonListNode *next;
};

PersonListNode *inputPersonInfo(void);
void inputTripInfo(PersonListNode *head);
void searchPersonInfo(PersonListNode *head);
void searchAbnormalTemperature(PersonListNode *head);

int main(void)
{
	PersonListNode *head = nullptr;
	PersonListNode *p = nullptr;
	PersonListNode *q = nullptr;

	for(;;) {
		cout << "1.录入人员信息\n"
			<< "2.录入出行轨迹和体温\n"
			<< "3.查询人员信息\n"
			<< "4.查询体温异常信息\n"
			<< "输入要进行的操作:";
		char menuSelect = cin.get();
		switch(menuSelect) {
		case '1':
			q = inputPersonInfo();
			if(q != nullptr) {
				p = q;
				if(head == nullptr) {
					head = p;
				}
				p = p->next;
			}
			break;
		case '2':
			inputTripInfo(head);
			break;
		case '3':
			searchPersonInfo(head);
			break;
		case '4':
			searchAbnormalTemperature(head);
			break;
		}
		cout << '\n';
	}
}

PersonListNode *inputPersonInfo(void)
{
	PersonListNode *newNode = new PersonListNode;
	if(newNode == nullptr) {
		return nullptr;
	}
	cout << "输入姓名：";
	cin >> newNode->data.name;
	cout << "输入身份证号：";
	cin >> newNode->data.id;
	cout << "输入性别：";
	string sex_input;
	cin >> sex_input;
	if(sex_input == "男") {
		newNode->data.sex = Male;
	} else {
		newNode->data.sex = Female;
	}
	cout << "输入年龄：";
	cin >> newNode->data.age;
	cout << "输入家庭住址：";
	cin >> newNode->data.address;
	newNode->data.trip = nullptr;

	return newNode;
}

void inputTripInfo(PersonListNode *head)
{
	PersonListNode *p = head;
	string nameTemp;
	string idTemp;

	cout << "输入姓名：";
	cin >> nameTemp;
	cout << "输入身份证号：";
	cin >> idTemp;

	while(p != nullptr) {
		if(p->data.name == nameTemp && p->data.id == idTemp) {
			TripListNode *q = p->data.trip;
			while(q != nullptr) {
				q = q->next;
			}
			cout << "输入时间：";
			cin >> q->data.time;
			cout << "输入地点：";
			cin >> q->data.place;
			cout << "输入体温：";
			cin >> q->data.temperature;
			return;
		}
		p = p->next;
	}
	return;
}

void searchPersonInfo(PersonListNode *head)
{
	PersonListNode *p = head;
	string nameTemp;
	string idTemp;

	cout << "输入姓名：";
	cin >> nameTemp;
	cout << "输入身份证号：";
	cin >> idTemp;

	while(p != nullptr) {
		if(p->data.name == nameTemp && p->data.id == idTemp) {
			cout << "性别：" << p->data.sex << '\n';
			cout << "年龄：" << p->data.age << '\n';
			cout << "住址：" << p->data.address << '\n';
			TripListNode *q = p->data.trip;
			cout << "行程信息：" << '\n';
			while(q != nullptr) {
				cout << "时间：" << q->data.time << '\n';
				cout << "地点：" << q->data.place << '\n';
				cout << "体温：" << q->data.temperature << '\n';
				cout << '\n';
				q = q->next;
			}
			return;
		}
		p = p->next;
	}
}

void searchAbnormalTemperature(PersonListNode *head)
{
	PersonListNode *p = head;
	while(p != nullptr) {
		TripListNode *q = p->data.trip;
		while(q->data.temperature <= 37.3f) {
			q = q->next;
		}
		if(q->data.temperature > 37.3f) {
			cout << "姓名：" << p->data.name << '\n';
			cout << "身份证号：" << p->data.id << '\n';
			cout << "性别：" << p->data.sex << '\n';
			cout << "年龄：" << p->data.age << '\n';
			cout << "住址：" << p->data.address << '\n';
			cout << "行程信息：" << '\n';
			q = p->data.trip;
			while(q != nullptr) {
				cout << "时间：" << q->data.time << '\n';
				cout << "地点：" << q->data.place << '\n';
				cout << "体温：" << q->data.temperature << '\n';
				cout << '\n';
				q = q->next;
			}
			cout << '\n';
		}
		p = p->next;
	}
}