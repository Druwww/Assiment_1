#include "Node.h"


Node::Node(): m_data(NULL), m_before(NULL), m_after(NULL){
    //Hi teacher
}

Node::Node(Student& data, Node* ptrNodeBefore, Node* ptrNodeAfter): m_before(ptrNodeBefore), m_after(ptrNodeAfter){
  m_data = new Student(data.get_name(), data.get_score());
}

Node::~Node(){
  m_data->~Student();
}


Student* Node::getData() const{
  return m_data;
}
void Node::setData(Student* value){
  m_data = value;
}

Node* Node::getPtrBefore() const{
  return m_before;
}
void Node::setPtrBefore(Node* value){
  m_before = value;
}

Node* Node::getPtrAfter() const{
  return m_after;
}
void Node::setPtrAfter(Node* value){
  m_after = value;
}

ostream& operator <<(ostream& out, const Node* value)
{
    out << *(value->getData());
    return out;
}
