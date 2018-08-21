#include "LinkedList.h"


LinkedList::LinkedList(): m_head(NULL), m_tail(NULL), m_current(NULL), m_number(0){
  //Hi
}

LinkedList::~LinkedList(){
  //free all data
}

Node* LinkedList::getHead() const{
    return m_head;
}
void LinkedList::setHead(Node* value){
    m_head = value;
}

Node* LinkedList::getTail() const{
    return m_tail;
}
void LinkedList::setTail(Node* value){
    m_tail = value;
}

int LinkedList::getNumber() const{
    return m_number;
}

void LinkedList::addToTail(Student& newStudent){

    if(m_head == NULL){
      m_head = new Node(newStudent, NULL, NULL);
      m_tail = m_head;
    }
    else{
      m_current = new Node(newStudent, m_tail);
      m_tail->setPtrAfter(m_current);
      m_tail = m_current;
    }

}

Node* LinkedList::getCurrent() const{
  return m_current;
}
void LinkedList::setCurrent(Node* value){
  m_current = value;
}


ostream& operator <<(ostream& out, LinkedList& theList){

  theList.setCurrent(theList.getHead());

  while (theList.getCurrent() != theList.getTail()) {
    out << theList.getCurrent() << " ";
    theList.setCurrent(theList.getCurrent()->getPtrAfter());
  }

  out<< theList.getCurrent() << "\n";

  return out;
}
