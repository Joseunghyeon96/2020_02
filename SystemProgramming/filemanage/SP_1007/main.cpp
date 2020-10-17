#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

struct  user
{
	string id;
	string name;
	int playTime;
	int score;
};

void SaveUserInfo(user uList[4])
{
	char ch = NULL;

	ofstream fout;

	fout.open("userinform.dat");

	for (int i = 0; i < 4; i++)
	{
		fout << uList[i].id << " " << uList[i].name 
			<< " " << uList[i].playTime << " " << uList[i].score << endl;
	}

	fout.close();
}
void PrintFileInfo(const char* input)
{
	HANDLE hFile;
	FILETIME fTime[3];
	SYSTEMTIME UTC[3];
	SYSTEMTIME Local[3];
	hFile = CreateFile(input, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("파일 열기 실패! \n");
		return;
	}

	if (!GetFileTime(hFile, &fTime[0], &fTime[1], &fTime[2]))
	{
		printf("파일 정보 얻어오기 실패! \n");
		return;
	}

	FileTimeToSystemTime(&fTime[0], &UTC[0]);
	SystemTimeToTzSpecificLocalTime(NULL, &UTC[0], &Local[0]);

	FileTimeToSystemTime(&fTime[1], &UTC[1]);
	SystemTimeToTzSpecificLocalTime(NULL, &UTC[1], &Local[1]);

	FileTimeToSystemTime(&fTime[2], &UTC[2]);
	SystemTimeToTzSpecificLocalTime(NULL, &UTC[2], &Local[2]);

	printf("Create time : %02d /%02d/%d  %02d:%02d\n", Local[0].wMonth, Local[0].wDay, Local[0].wYear, Local[0].wHour, Local[0].wMinute);
	printf("Access time : %02d /%02d/%d  %02d:%02d\n", Local[1].wMonth, Local[1].wDay, Local[1].wYear, Local[1].wHour, Local[1].wMinute);
	printf("Write time : %02d /%02d/%d  %02d:%02d\n", Local[2].wMonth, Local[2].wDay, Local[2].wYear, Local[2].wHour, Local[2].wMinute);

	CloseHandle(hFile);
}
int main()
{
	user list[4];
	for (int i = 0; i < 4; i++)
	{
		cout << "id 를 입력하세요 : ";
		cin >> list[i].id;

		cout << "이름을 입력하세요 : ";
		cin >> list[i].name;

		cout << "플레이 시간을 입력하세요 : ";
		cin >> list[i].playTime;

		cout << "점수를 입력하세요 : ";
		cin >> list[i].score;
	}
	SaveUserInfo(list);
	PrintFileInfo("userinform.dat");

	return 0;
}

