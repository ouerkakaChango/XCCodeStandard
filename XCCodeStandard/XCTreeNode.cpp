#include "XCTreeNode.h"

bool XCTreeNode::IsFoundInDownClasses(string v_className) {
	for (auto iter : downClassVec) {
		if (v_className == iter->className) {
			return true;
		}
	}
	return false;
}

XCTreeNode* XCTreeNode::IsFoundStartFromMe_obj(string v_className) {
	XCTreeNode* _temp;
	_temp = this;
	if (v_className == className) { return this; }
	for (auto& iter : downClassVec) {
		XCTreeNode* temp = iter->IsFoundStartFromMe_obj(v_className);
		if (temp!=nullptr) {
			return temp;
		}
	}
	return nullptr;
}