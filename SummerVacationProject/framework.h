#pragma once
// ������� - ���̺귯���� ���� ��
// ���Զ��̺귯���� ���� ex) <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <fstream>
#include <random>

using namespace std;

#define DELETE(x) if(x) delete (x); (x) = nullptr
constexpr float PI = 3.14159265f;

// pch(Precompiled Header) : �̸� �����ϵ� ���, ���ֺ������ �ʴ� ��ҽ��� �̸� �������Ͽ� 
// �����ϰ���� ������ ���Ͽ� �����Ͽ�, �ٽ� �Ȱ��� ����� �����Ͻ� �ش������� ó������ �����������ʰ� 
// �̸������ϵ� ��� ������ ����� ������ �ӵ��� ������ ������ ��