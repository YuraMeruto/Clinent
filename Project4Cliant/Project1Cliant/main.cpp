#include <stdio.h>
#include <winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include<future>
#include<string>
//����񂯂�Q�[��

enum Zyanken { None, G, C, P, Finish };
WSADATA wsadata;
WORD mVersion = MAKEWORD(2, 0);
SOCKET sock, serversock;
struct sockaddr_in addr, server;
char sendbuf[100];
std::string SendMessage;

int
main()
{
	Ini();
	SendtoMessage();
	Finish();
}


void Ini()
{
	WSAStartup(mVersion, &wsadata);
	//UDP�ʐM�̐ݒ�
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	//�s�����ݒ�
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
}

void SendtoMessage()
{
	Zyanken zyanken = Zyanken::None;
	while (zyanken == Zyanken::Finish)
		//	���肽�����b�Z�[�W��ݒ�
		std::cin >> SendMessage;
	switch (zyanken)
	{
	case Zyanken::G:
		break;

	}
	sendto(sock, SendMessage.c_str(), SendMessage.size(), 0, (struct sockaddr *)&addr, sizeof(addr));
	closesocket(sock);
}


void Finish()
{
	WSACleanup();
}