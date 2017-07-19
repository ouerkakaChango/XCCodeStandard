#ifndef XCTREENODE_H
#define XCTREENODE_H
#include "XCStandardHead.h"
class XCTreeNode{
public:
	string className;
	std::vector<XCTreeNode*> upClassVec,downClassVec;

	XCTreeNode(string v_className) :className(v_className) {}

	bool IsFoundInDownClasses(string v_className);
	XCTreeNode* IsFoundStartFromMe_obj(string v_className);
};
#endif

