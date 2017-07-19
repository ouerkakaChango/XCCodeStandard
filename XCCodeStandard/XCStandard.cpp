#include "XCStandard.h"

XCStandard& XCStandard::GetInstance() {
	static XCStandard x;
	return x;
}

bool XCStandard::Init() {
	XCALERT("XC Init","")
	return true;
}

