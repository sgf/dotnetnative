#pragma once
#include <vector>
#include <gsl/span>
using namespace gsl;

namespace System {


	template<class T>
	class  Array
	{
		//T const (&m);
		//span<T> spans;
		std::vector <T> m;

	public:
		template<size_t N>
		Array(T const (&& inner)[N]) :m(inner) {
		}
		Array(initializer_list<T> list) :m(list) {

		}

		~Array() {

		}

		T& operator[](const i32 idx)const noexcept { return  m[idx]; }


		//private:

	};


}
