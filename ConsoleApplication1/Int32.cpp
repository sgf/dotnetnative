#include "Int32.private.h"
#include "Int32.h"

using namespace System;


int32::int32() :pimpl(std::unique_ptr<int32Impl>{}) {
}


int32::~int32() {

}

String& int32::ToString() {
	return pimpl->ToString();
}
