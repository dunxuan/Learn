#include <iostream>
#include <vector>

#define LENGTH 8

using namespace std;

void merge(int A[], int p, int q, int r);
void mergeSoft(int A[], int p, int r);
int num[LENGTH];

int main(void)
{
    for (int i = 0; i < LENGTH; i++) {
        cin >> num[i];
    }

    mergeSoft(num, 0, LENGTH - 1);

    for (int i = 0; i < LENGTH; i++) {
        cout << num[i] << '\t';
    }
    return 0;
}

void mergeSoft(int A[], int p, int r)
{
    if (p < r)  {
        int q = (p + r) / 2;
        mergeSoft(A, p, q);
        mergeSoft(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1), R(n2);
    int i, j;
    for (i = 0; i < n1 - 1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2 - 1; j++)
        R[j] = A[q + j];
    //L[n1] = ...
    //R[n2] = ...
    i = j = 0;
    for (int k = p; k < r; k++) {
        if (L[i] <= R[j])   {
            A[k] = L[i];
            i++;
        } else  {
            A[k] = R[j];
            j++;
        }
    }
}