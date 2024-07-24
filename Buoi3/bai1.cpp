#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define RAND_LIMIT 100

void Tao_Xuat_mang(int **a, int m, int n) {
	srand(time(NULL)); 
	printf("Ma tran %d dong %d cot:\n", m, n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = rand() % (RAND_LIMIT + 1);
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}
void Xuat_GTri(int **a, int m, int n) {
	printf("\nTong gia tri tung dong:\n");
	for (int i = 0; i < m; ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += a[i][j];
		}
		printf("Dong %d: %d\n", i + 1, sum);
	}
}
void Xuat_Ptulon(int **a, int m, int n) {
	printf("\nPhan tu lon nhat tren tung cot:\n");
	for (int j = 0; j < n; ++j) {
		int max = a[0][j];
		for (int i = 1; i < m; ++i) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
		printf("Cot %d: %d\n", j + 1, max);
	}
}
void Xuat_PTU_TrenDuongBien(int **a, int m, int n) {
	printf("\nCac phan tu tren cac duong bien:\n");
	for (int j = 0; j < n; ++j) {
		printf("%d ", a[0][j]);
		printf("%d ", a[m - 1][j]);
	}
	for (int i = 1; i < m - 1; ++i) {
		printf("%d ", a[i][0]); 
		printf("%d ", a[i][n - 1]); 
	}
	printf("\n");
}
void Xuat_MAX(int **a, int m, int n) {
	printf("\nCac phan tu cuc dai:\n");
	for (int i = 1; i < m - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] &&
				a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}
void Xuat_PTU_HoangHau(int **a, int m, int n) {
	printf("\nCac phan tu hoang hau:\n");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int isSaddle = 1;
			for (int k = 0; k < n; ++k) {
				if (a[i][j] < a[i][k]) {
					isSaddle = 0;
					break;
				}
			}
			if (isSaddle) {
				for (int k = 0; k < m; ++k) {
					if (a[i][j] > a[k][j]) {
						isSaddle = 0;
						break;
					}
				}
			}
			if (isSaddle) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}
void Xuat_Diem_YenNgua(int **a, int m, int n) {
	printf("\nDong chi chua so chan:\n");
	for (int i = 0; i < m; ++i) {
		int isEvenRow = 1;
		for (int j = 0; j < n; ++j) {
			if (a[i][j] % 2 != 0) {
				isEvenRow = 0;
				break;
			}
		}
		if (isEvenRow) {
			for (int j = 0; j < n; ++j) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}
void SapXep(int **a, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			for (int k = 0; k < n - j - 1; ++k) {
				if (a[i][k] > a[i][k + 1]) {
					int temp = a[i][k];
					a[i][k] = a[i][k + 1];
					a[i][k + 1] = temp;
				}
			}
		}
	}
}


int main() {
	int m, n;
	printf("Nhap so dong m va so cot n cua ma tran: ");
	scanf_s("%d %d", &m, &n);

	int **a = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; ++i) {
		a[i] = (int *)malloc(n * sizeof(int));
	}

	Tao_Xuat_mang(a, m, n);

	Xuat_GTri(a, m, n);

	Xuat_Ptulon(a, m, n);

	Xuat_PTU_TrenDuongBien(a, m, n);

	Xuat_MAX(a, m, n);

	Xuat_PTU_HoangHau(a, m, n);

	Xuat_Diem_YenNgua(a, m, n);

	SapXep(a, m, n);

	printf("\nMa tran sau khi sap xep theo tung dong:\n");
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < m; ++i) {
		free(a[i]);
	}
	free(a);

	_getch();
		return 0;
	}


