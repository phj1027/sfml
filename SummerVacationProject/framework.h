#pragma once
// 헤더파일 - 라이브러리가 들어가는 곳
// 정규라이브러리를 포함 ex) <stdio.h>

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

// pch(Precompiled Header) : 미리 컴파일된 헤더, 자주변경되지 않는 긴소스를 미리 컴파일하여 
// 컴파일결과를 별도의 파일에 저장하여, 다시 똑같은 헤더를 컴파일시 해당파일을 처음부터 컴파일하지않고 
// 미리컴파일된 헤더 파일을 사용해 컴파일 속도를 월등히 향상시켜 줌