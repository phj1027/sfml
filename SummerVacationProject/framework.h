#pragma once
// ������� - ���̺귯���� ���� ��
// ���Զ��̺귯���� ���� ex) <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <typeinfo>
#include <random>

using namespace std;

// pch(Precompiled Header) : �̸� �����ϵ� ���, ���ֺ������ �ʴ� ��ҽ��� �̸� �������Ͽ� 
// �����ϰ���� ������ ���Ͽ� �����Ͽ�, �ٽ� �Ȱ��� ����� �����Ͻ� �ش������� ó������ �����������ʰ� 
// �̸������ϵ� ��� ������ ����� ������ �ӵ��� ������ ������ ��