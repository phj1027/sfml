#pragma once
// ������� - ���̺귯���� ���� ��
// ���Զ��̺귯���� ���� ex) <stdio.h>

#include <SFML/Graphics.hpp>

using namespace sf;

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// pch(Precompiled Header) : �̸� �����ϵ� ���, ���ֺ������ �ʴ� ��ҽ��� �̸� �������Ͽ� 
// �����ϰ���� ������ ���Ͽ� �����Ͽ�, �ٽ� �Ȱ��� ����� �����Ͻ� �ش������� ó������ �����������ʰ� 
// �̸������ϵ� ��� ������ ����� ������ �ӵ��� ������ ������ ��