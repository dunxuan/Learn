# include <iostream>
# include <iomanip>

# define N 5

using namespace std;

struct employee {
	int num;
	char name[8];
	float base_salary, post_salary, fund, tax, fact_salary;
};
void input(employee s[], int n)
{
	int i;
	cout << "Input employee data:" << endl;
	for(i = 0; i < n; i++)
		cin >> s[i].num >> s[i].name >> s[i].base_salary >> s[i].post_salary
		>> s[i].fund >> s[i].tax;
}
void calcu(employee s[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		s[i].fact_salary = s[i].base_salary + s[i].post_salary - s[i].fund - s[i].tax;
}
void sort(employee s[], int n)
{
	int i, j, k;
	employee temp;
	for(i = 0; i < n - 1; i++) {
		k = i;
		for(j = i + 1; j < n; j++)
			if(s[k].fact_salar < s[j].fact_salar) k = j;
		if(k != i) {
			temp = s[i]; s[i] = s[k]; s[k] = temp;
		}
	}
}
void output(employee s[], int n)
{
	int i;
	cout << setw(6) << "Num" << setw(8) << "Name" << setw(12) << "Base_salary"
		<< setw(12) << "Post_salary" << setw(8) << "Fund" << setw(8) << "Tax" << setw(12)
		<< "Fact_salary" << '\n';
	for(i = 0; i < n; i++)
		cout << setw(6) << s[i].num << setw(8) << s[i].name << setw(12) << s[i].base_salary
		<< setw(12) << s[i].post_salary << setw(8) << s[i].fund
		<< setw(8) << s[i].tax << setw(12) << s[i].fact_salary << '\n';
}
int main(void)
{
	employee w[N];
	input(w, N);
	calcu(w, N);
	sort(w, N);
	output(w, N);

	return 0;
}