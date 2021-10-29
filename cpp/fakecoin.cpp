#include <iostream>
#include <cstdlib>
using namespace std;

class Coin {
private:
	int middle;
	int coin[30];
public:
	Coin();
	int partition(int middle, int b, int e);
	int search_fake_coin(int b, int e);
};
Coin::Coin() {
	for (int i = 0; i < 30; i++) {
		coin[i] = 10;
	}
	cout << endl;
	srand((unsigned int)time(NULL));
	int fake_coin = rand() % 30;
	cout << "가짜 코인 위치 : " << fake_coin << endl;
	coin[fake_coin] = 9;
}
int Coin::partition(int middle, int b, int e) {
	cout << "b : " << b << "  " << "e : " << e << endl;
	cout << "가운데 값  : " << middle << endl;
	int left_sum =0, right_sum=0;
	if ((b + e + 1) % 2 == 0) {
		for (int i = 0; i < (middle-b); i++) {
			left_sum += coin[b + i];
			right_sum += coin[i + middle];
		}
	}//짝수개수의 동전을 비교할때 
	else {
		for (int i = 0; i < (middle-b); i++) {
			left_sum += coin[b + i];
			right_sum += coin[i + middle + 1];
		}
	}
	cout << left_sum << " " << right_sum << endl << endl;
	if (right_sum < left_sum) {
		return 1;
	}
	else if(right_sum > left_sum) {
		return -1;
	}
	else {
		cout << "가짜는 : " << middle;
		return 100;
	}
}
int Coin::search_fake_coin(int b=0, int e=29) {
	if (e - b < 3) {
		if (coin[b] < coin[e]) {
			cout << "가짜1는 : " << b;
			return 0;
		}
		else if (coin[b] > coin[e]) {
			cout << "가짜2는 : " << e;
			return 0;
		}
		else if (coin[b] == coin[e]) {
			cout << "가짜3는 : " << b+1;
			return 0;
		}
	}
	if ((b + e + 1) % 2 == 0) {
		int middle = (b + e + 1) / 2;
		if (b < e) {
			int q = partition(middle, b, e);
			if (q == 1) {
				search_fake_coin(middle, e);
			}
			else if (q == -1) {
				search_fake_coin(b, middle - 1);
			}
		} 
	}//짝수개일때
	else {
		int middle = (b + e) / 2;
		if (b < e) {
			int q = partition(middle, b, e);
			if (q == 1) {
				search_fake_coin(middle, e);
			}
			else if (q == -1) {
				search_fake_coin(b, middle - 1);
			}
			else if (q == 100) {
				return 0;
			}
		}
	}
	return 0;
}
int main() {
	Coin coin;
	coin.search_fake_coin();
}
