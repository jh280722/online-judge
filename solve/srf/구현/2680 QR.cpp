#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define CODENUM 19*8
typedef long long ll;
using namespace std;
int t;
//QR ��ġ���� ����, Ÿ�̹� ����(�����ϴ� ���), ���� ����, �����Ϳ� ���������ڵ�
//26���� ������ �� ���� ���� �ڵ�, 19�� ������ �ڵ� 7�� �������� �ڵ�
//������ �ڵ�� 10��Ʈ�� 3���� ���� 11��Ʈ�� 2���� ���Ĵ��޸� ����, 8��Ʈ�� 1���� ��Ÿ 8��Ʈ ����

//���Ĵ��޸� ���ڿ��� ���� 45�� ���ڵ��� �����ϰ� �ִ� ���ڿ��̴�.(<SP>�� �����̽��ٸ� ��Ÿ����)
//0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ<SP>$%* +-. / :
//������ ���ĺ��� 0���� 44�� ���� �����Ǹ�, ���Ĵ��޸� �� ���ڴ� ������ ���� ���ڵ��ȴ�.
//<first char code> * 45 + <second char code>
//���� �� ���� ���ڰ� ���´ٸ�, �̰��� 6 ��Ʈ�� ���ڵ��ȴ�.

//13��Ʈ�� 1���� ���ڸ� ����. �������� ����, ������ ��, ���� ������ �����Ѵ�.
//Mode Name      	Mode Bits   	Count Bits
//Numeric			0001			10
//Alphanumeric		0010			9
//8 bit byte		0100			8
//Kanji				1000			8
//Termination		0000			0 ������ �ڵ� ������ ���ٸ� �����ǰų� �ҿ����� �����ϼ��� ����.
//�͹̳��̼� �ڵ� ���� �����ϴ� �ҿ����� �ڵ� ������ 0���� ä��. 
//������ ������� 11101100�� 00010001�� ����� ä���.
//���� �̷���� ���ڿ��� �� ���� 3�ڸ��� ����ȴ�. 
//������ ���� ���ڿ��� 2������ ��쿣 7bit��, 1������ ��쿣 4bit�� ����

//8��Ʈ ���� / ���ڿ� ���ڸ� �����ϴ� ������ ������ ���� �����ϴ�. 
//8��Ʈ ���ڴ� � 8��Ʈ�� �ڵ��, ���ڴ� � 13��Ʈ�� �ڵ�� ����� ���̸� 
//�� ���ڸ� ã�� ��� ���� 16������ �ڵ带 ǥ���س��⸸ �ϸ� �ȴ�.


int bit_to_num(int incode[CODENUM], int &idx, int count_bits) {
	int num = 0;

	for (int i = 0; i < count_bits; i++) {
		num += incode[i + idx] << count_bits - i - 1;
	}
	idx += count_bits;
	return num;
}

string Alphanumeric = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:" };

string alp(int num) {
	string s = "";
	s += Alphanumeric[num/45];
	s += Alphanumeric[num%45];
	return s;
}

string ithex(int num) {
	string r = "", s = "";
	int cnt = 0;
	do {
		r += Alphanumeric[num % 16];
		num /= 16;
		cnt++;
	} while (num);

	if (cnt==1 || cnt == 3)
		s += '0';
	for (int i = r.size() - 1; i >= 0; i--)
		s += r[i];
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		int cnt = 0;
		char code[38];
		string str = "";
		for (int i = 0; i < 38; i++) {
			cin >> code[i];
			if (code[i] >= 'A' && code[i] <= 'F')
				code[i] -= 'A' - 10;
			else
				code[i] -= '0';
		}
		int incode[CODENUM];
		int eidx = 0;
		int sidx = 0;
		for (int i = 0; i < 38; i++) {
			for (int j = 0; j < 4; j++) {
				bool bit = (code[i] >> 3 - j) & 1;
				incode[eidx++] = bit;
			}
		}
		while (sidx < eidx) {
			int mode = 0;//0 termin 1 num 2 alp 4 8bit 8 kanji
			mode=bit_to_num(incode, sidx, 4);
			if (mode == 0)
				break;

			int strcnt = 0;
			switch (mode) {
			case 8://kanji
				strcnt = bit_to_num(incode, sidx, 8);
				cnt += strcnt;
				while (strcnt--) {
					int tmp = bit_to_num(incode, sidx, 13);
					if (tmp >= 0x20 && tmp <= 0x7e)
						str += tmp;
					else {
						str += '#';
						str += ithex(tmp);
					}
				}
				break;
			case 4://8 bit
				strcnt = bit_to_num(incode, sidx, 8);
				cnt += strcnt;
				while (strcnt--) {
					int tmp = bit_to_num(incode, sidx, 8);
					if (tmp >= 0x20 && tmp <= 0x7e)
						str += tmp;
					else {
						str += '\\';
						str += ithex(tmp);
					}
				}
				break;
			case 2://alp
				strcnt = bit_to_num(incode, sidx, 9);
				cnt += strcnt;
				while (strcnt/2) {
					int tmp = bit_to_num(incode, sidx, 11);
					str += alp(tmp);
					strcnt -= 2;
				}
				if (strcnt==1) {
					int tmp = bit_to_num(incode, sidx, 6);
					str += Alphanumeric[tmp];
					strcnt --;
				}
				break;
			case 1://num
				strcnt = bit_to_num(incode, sidx, 10);
				cnt += strcnt;
				while (strcnt>=3) {
					int tmp = bit_to_num(incode, sidx, 10);            
					if (0 <= tmp && tmp <= 9) 
						str += ("00" + to_string(tmp));
					else if (10 <= tmp && tmp <= 99) 
						str += ("0" + to_string(tmp));
					else
						str += to_string(tmp);
					strcnt -= 3;
				}
				if (strcnt==2) {
					int tmp = bit_to_num(incode, sidx, 7);
					if (0 <= tmp && tmp <= 9)
						str += ("0" + to_string(tmp));
					else
						str += to_string(tmp);
					strcnt -= 2;
				}
				else if (strcnt==1) {
					int tmp = bit_to_num(incode, sidx, 4);
					str += to_string(tmp);
					strcnt--;
				}
				break;
			default:
				sidx = eidx;
				break;
			}
		}
		cout << cnt << ' ' << str << '\n';
	}

	return 0;
}
