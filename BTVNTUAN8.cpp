//I Trắc nghiệm 
//1C 2C 3A 4C 5A 6C 7C 8B 9C 10B
//II Lập trình
#include<bits/stdc++.h>
using namespace std;
void cau1(int a[], int n, int k) {
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i]+a[j]==k)
				cout<<a[i]<<" "<<a[j];
		}
		cout<<endl;
	}
}

void cau3(int a[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
bool cau4(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while(left <= right) {
		int mid = (left + right) / 2;
		if(a[mid] == x) {
			return true;
		}
		else if(a[mid] < x) {

			left = mid + 1;
		}
		else {

			right = mid - 1;
		}
	}
	return false;
}

//cau2
int main() {

	int M, N, K, Q;
	cin >> M >> N >> K >> Q;
	int grid[M][N];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] = 0;
		}
	}

	for (int i = 0; i < K; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		grid[x][y] = v;
	}

	for (int i = 0; i < Q; i++) {
		int xq, yq;
		cin >> xq >> yq;

		int sum = 0;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int nx = xq + dx;
				int ny = yq + dy;
				if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
					sum += grid[nx][ny];
				}
			}
		}

		cout << sum << endl;
	}

	return 0;
}
