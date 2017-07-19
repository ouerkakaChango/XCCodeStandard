#ifndef XCSTANDARD_H
#define XCSTANDARD_H
#include <iostream>
#include <map>
#include <stdio.h>
#include "XCTree.h"
#include "XCStandardHead.h"
class XCStandard{
private:
	XCStandard() {}
public:
	XCTree xctree;
	std::map<string, XCTreeNode*> pendNodeMap;
	std::map<string, int> objCountMap;

	XCStandard(const XCStandard& x) = delete;
	XCStandard(XCStandard&&) = delete;
	XCStandard& operator=(const XCStandard& x) = delete;
	XCStandard& operator=(XCStandard&& x) = delete;
	static XCStandard& GetInstance();
	//std::pair<string,void*> FindSubFunctorBelongobjByName(string v_startClassName);
	bool Init();
};
#define XC XCStandard::GetInstance()
#define STR(v) #v

#define XCALERT(_str,_where) \
if(_where==""){\
	std::cout << "\nXCWARNING:" << _str <<"\n";\
}\
else {\
	std::cout << "\nXCWARNING:" << _str << " in " << _where << "\n";\
}


#define XCCLASS(_class) \
class _class { \
public: \
	string className = STR(_class); \
	_class(){\
	XC.objCountMap[STR(_class)]+=1;\
	if(XC.objCountMap[STR(_class)]<=1){\
		XC.pendNodeMap[STR(_class)]=new XCTreeNode(STR(_class));\
		}\
	}\


#define XCCLASSEND };

#define XCCONNECTION1(_upClass,_downClass) \
/*Try to Find _upClass in trees of forest,if not insert a new tree in forest*/\
XCTreeNode* tempUp = XC.xctree.IsFoundInTree_obj(STR(_upClass)); \
XCTreeNode* tempDown = XC.xctree.IsFoundInTree_obj(STR(_downClass)); \
if (tempUp != nullptr) {\
} \
else{\
		tempUp=XC.pendNodeMap[STR(_upClass)];\
		XC.pendNodeMap.erase(STR(_upClass));\
		XC.xctree.headNodeVec.push_back(tempUp); \
}\
if(tempDown!=nullptr){ \
}\
else { \
		tempDown=XC.pendNodeMap[STR(_downClass)];\
		XC.pendNodeMap.erase(STR(_downClass));\
}\
tempUp->downClassVec.push_back(tempDown); \
tempDown->upClassVec.push_back(tempUp);\

//???
#define GO(_startObj,_function,...) \
void* temp=FindSubFuncBelongobjByName(STR(_startObj));\
if(_startObj->className=="Car"){static_cast<Car>(_temp)->_function(__VA_ARGS__);}\
//...
#endif

