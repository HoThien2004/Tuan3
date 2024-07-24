#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define MAX 100

void taoMaTran(int a[MAX][MAX], int n) {
	srand(time(NULL));  
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 100;
		}
	}
}
void xuatMaTran(int a[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
void xuatDuongCheoChinh(int a[MAX][MAX], int n) {
	printf("Phan tu tren duong cheo chinh:\n");
	for (int i = 0; i < n; i++) {
		printf("%4d", a[i][i]);
	}
	printf("\n");
}
void xuatDuongCheoSongSong(int a[MAX][MAX], int n) {
	printf("Phan tu tren duong cheo song song voi duong cheo chinh:\n");
	for (int k = 1; k < n; k++) {
		printf("Cheo song song thu %d:\n", k);
		for (int i = 0; i < n - k; i++) {
			printf("%4d", a[i][i + k]);
		}
		printf("\n");
	}
}
int timMaxTamGiacTren(int a[MAX][MAX], int n) {
	int max = a[0][1];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { 
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}
void sapXepZicZac(int a[MAX][MAX], int n) {
	int arr[MAX * MAX];
	int k = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[k++] = a[i][j];
		}
	}

	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	k = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = arr[k++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = arr[k++];
			}
		}
	}
}

int main() {
	int n = 5;  
	int a[MAX][MAX];

	taoMaTran(a, n);
	printf("Ma tran vuong ngau nhien:\n");
	xuatMaTran(a, n);

	xuatDuongCheoChinh(a, n);

	xuatDuongCheoSongSong(a, n);

	int max = timMaxTamGiacTren(a, n);
	printf("Gia tri lon nhat trong tam giac tren cua duong cheo chinh: %d\n", max);

	sapXepZicZac(a, n);
	printf("Ma tran sau khi sap xep zic-zac:\n");
	xuatMaTran(a, n);

	return 0;
	_getch();
}
