#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define CODENUM 19*8
typedef long long ll;
using namespace std;
int t;
//QR 위치감지 패턴, 타이밍 패턴(교차하는 흑백), 서식 정보, 데이터와 오류수정코드
//26개의 데이터 및 오류 수정 코드, 19개 데이터 코드 7개 오류수정 코드
//데이터 코드는 10비트당 3개의 숫자 11비트당 2개의 알파뉴메릭 문자, 8비트당 1개의 기타 8비트 문자

//알파뉴메릭 문자열은 다음 45개 문자들을 포함하고 있는 문자열이다.(<SP>는 스페이스바를 나타낸다)
//0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ<SP>$%* +-. / :
//각각의 알파벳은 0부터 44의 수로 대응되며, 알파뉴메릭 두 문자는 다음과 같이 인코딩된다.
//<first char code> * 45 + <second char code>
//만일 한 개의 문자가 남는다면, 이것은 6 비트로 인코딩된다.

//13비트당 1개의 한자를 저장. 데이터의 종류, 문자의 수, 문자 정보를 저장한다.
//Mode Name      	Mode Bits   	Count Bits
//Numeric			0001			10
//Alphanumeric		0010			9
//8 bit byte		0100			8
//Kanji				1000			8
//Termination		0000			0 데이터 코드 공간이 없다면 생략되거나 불완전한 형태일수도 있음.
//터미네이션 코드 이후 등장하는 불완전한 코드 조각은 0으로 채움. 
//나머지 빈공간은 11101100과 00010001을 교대로 채운다.
//수로 이루어진 문자열은 한 번에 3자리씩 저장된다. 
//마지막 남은 문자열이 2글자일 경우엔 7bit로, 1글자일 경우엔 4bit로 저장

//8비트 문자 / 숫자와 한자를 저장하는 다음의 과정은 비교적 간단하다. 
//8비트 문자는 어떤 8비트의 코드로, 한자는 어떤 13비트의 코드로 저장될 것이며 
//그 문자를 찾는 대신 그저 16진수로 코드를 표현해내기만 하면 된다.


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
