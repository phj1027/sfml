#pragma once

class Object : public Sprite  // Object는 Sprite에 상속됨
{
public:

	// 생성자,소멸자= default -> 기본 생성자 소멸자들
	Object() = default;
	virtual ~Object() = default; // 상속 받을 여지 있으므로 virtual씀

private:
	bool isActive = true;

private: // 나 자신만 사용가능

	virtual void Init() = 0;

//protected: // 상속받는 클래스끼리 쓸수있음
//
//	vector<Texture*> animation;

public:

	bool IsActive();
	void SetActive(bool isActive);

	// 상속받는 애들의 Init, Destroy, Update는 다를수 있으므로 virtual void 씀
	// 함수 = 0; -> 순수가상함수
	// ㄴ> 이 오브젝트로 상속받는 애들은 모두 이 Init,Destroy,Update 함수가 필수적으로 있어야하기때문에 순수가상함수를 씀
	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Update(const Vector2f& mousePosition);


};

