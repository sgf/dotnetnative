#pragma once
#include  <memory>

namespace System {

	class String;
	class int32 {


	private:
		class int32Impl;  // int32实现类的前置声明
		const  std::unique_ptr<int32Impl> pimpl;

		//class Impl;
		//std::unique_ptr<Impl> pImpl_;

	public:
		int32();
		String& ToString();
		~int32();

	};


}
