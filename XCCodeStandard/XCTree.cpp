#include "XCTree.h"

XCTreeNode* XCTree::IsFoundInTree_obj(string v_className) {
	if (headNodeVec.empty()) {
		return false;
	}
	for (auto _headnode : headNodeVec) {
		XCTreeNode* temp = _headnode->IsFoundStartFromMe_obj(v_className);
		if (temp!=nullptr) {
			return temp;
		}
	}
	return nullptr;
}

