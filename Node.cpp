#include "Node.h"


Node::Node(): m_data(NULL), m_before(NULL), m_after(NULL){
    //Hi teacher
}

Node::Node(Student* ptrData, Node* ptrNodeBefore = NULL, Node* ptrNodeAfter = NULL): m_data(ptrData), m_before(ptrNodeBefore), m_after(ptrNodeAfter){
  //nothing to put here ... sorry
}

Node::~Node(){
  //to add student destruction
}
