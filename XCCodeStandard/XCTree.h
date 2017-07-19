#ifndef XCTREE_H
#define XCTREE_H
#include "XCStandardHead.h"
#include "XCTreeNode.h"
class XCTree{
public:
	std::vector<XCTreeNode*> headNodeVec;
	XCTreeNode* IsFoundInTree_obj(string v_className);
};
#endif

