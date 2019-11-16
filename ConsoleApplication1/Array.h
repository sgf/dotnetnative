#pragma once
#include <vector>
#include <memory>
#include <gsl/span>

namespace System {
	using namespace gsl;
	using namespace std;


	//template<class T, size_t N>
//class  Array :public array<T, N>
//{
		//	//T const (&m);
	//	//span<T> spans;
	//	std::vector <T> m1;
	//	std::array<T, 30> m2;

	//	unique_ptr<T[]> m;
	//	//std::array<int, 2> a{ 1,2 };
	//public:
	//	template<size_t N>
	//	Array(T const (&& inner)[N]) :m(make_unique(inner)) {
	//	}

	//	template<typename ...T>
	//	Array(T&&...e) : m(make_unique({ { forward<T>(e)... } })) {
	//		/*T bb[] = { forward<T>(e)... };
	//		m = ;*/
	//	}

	//	//Array(const initializer_list<T> list) {
	//	//	constexpr int size = list.size;
	//	//	T tmp[22] = list;
	//	//	m = std::make_unique(tmp...);
	//	//	//m = ::make_unique<T[]>();
	//	//	//m = ::make_unique<T[]>(new T[list.size()]{ list... });
	//	//}

	//	~Array() {

	//	}

	//	T& operator[](const i32 idx)const noexcept { return  m[idx]; }


		//private:

//};


}
