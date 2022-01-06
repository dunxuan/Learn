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
		cout << "1.¼����Ա��Ϣ\n"
			<< "2.¼����й켣������\n"
			<< "3.��ѯ��Ա��Ϣ\n"
			<< "4.��ѯ�����쳣��Ϣ\n"
			<< "����Ҫ���еĲ���:";
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
	cout << "����������";
	cin >> newNode->data.name;
	cout << "�������֤�ţ�";
	cin >> newNode->data.id;
	cout << "�����Ա�";
	string sex_input;
	cin >> sex_input;
	if(sex_input == "��") {
		newNode->data.sex = Male;
	} else {
		newNode->data.sex = Female;
	}
	cout << "�������䣺";
	cin >> newNode->data.age;
	cout << "�����ͥסַ��";
	cin >> newNode->data.address;
	newNode->data.trip = nullptr;

	return newNode;
}

void inputTripInfo(PersonListNode *head)
{
	PersonListNode *p = head;
	string nameTemp;
	string idTemp;

	cout << "����������";
	cin >> nameTemp;
	cout << "�������֤�ţ�";
	cin >> idTemp;

	while(p != nullptr) {
		if(p->data.name == nameTemp && p->data.id == idTemp) {
			TripListNode *q = p->data.trip;
			while(q != nullptr) {
				q = q->next;
			}
			cout << "����ʱ�䣺";
			cin >> q->data.time;
			cout << "����ص㣺";
			cin >> q->data.place;
			cout << "�������£�";
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

	cout << "����������";
	cin >> nameTemp;
	cout << "�������֤�ţ�";
	cin >> idTemp;

	while(p != nullptr) {
		if(p->data.name == nameTemp && p->data.id == idTemp) {
			cout << "�Ա�" << p->data.sex << '\n';
			cout << "���䣺" << p->data.age << '\n';
			cout << "סַ��" << p->data.address << '\n';
			TripListNode *q = p->data.trip;
			cout << "�г���Ϣ��" << '\n';
			while(q != nullptr) {
				cout << "ʱ�䣺" << q->data.time << '\n';
				cout << "�ص㣺" << q->data.place << '\n';
				cout << "���£�" << q->data.temperature << '\n';
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
			cout << "������" << p->data.name << '\n';
			cout << "���֤�ţ�" << p->data.id << '\n';
			cout << "�Ա�" << p->data.sex << '\n';
			cout << "���䣺" << p->data.age << '\n';
			cout << "סַ��" << p->data.address << '\n';
			cout << "�г���Ϣ��" << '\n';
			q = p->data.trip;
			while(q != nullptr) {
				cout << "ʱ�䣺" << q->data.time << '\n';
				cout << "�ص㣺" << q->data.place << '\n';
				cout << "���£�" << q->data.temperature << '\n';
				cout << '\n';
				q = q->next;
			}
			cout << '\n';
		}
		p = p->next;
	}
}