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


void LinkedList::remove(Node* nodeDel){

    if(nodeDel->getPtrBefore() == NULL){
      m_head = nodeDel->getPtrAfter();
    }
    else{
      nodeDel->getPtrBefore()->setPtrAfter(nodeDel->getPtrAfter());
    }

    if(nodeDel->getPtrAfter() == NULL){
      m_tail = nodeDel->getPtrBefore();
    }
    else{
      nodeDel->getPtrAfter()->setPtrBefore(nodeDel->getPtrBefore());

    }
    nodeDel->~Node();

}

void LinkedList::remove(const string name){

    m_current = m_head;

    Node* tempPtr;

    while (m_current != m_tail) {
      tempPtr = m_current;
      m_current = m_current->getPtrAfter();
      if(tempPtr->getData()->get_name() == name){
          remove(tempPtr);
      }
    }

    if(m_tail->getData()->get_name() == name){
      remove(m_tail);
    }

}

void LinkedList::setnumber(){
  int value = 0;

  m_current = m_head;

  while (m_current != m_tail) {
    value++;
    m_current = m_current->getPtrAfter();
  }

  value++;

  if(m_head == NULL){
    m_number =0;
  }
  else{
    m_number = value;
  }

}


int LinkedList::calcAverage(){
    setnumber();

    if(m_head == NULL){
      return 0;
    }

    int total = 0;

    m_current = m_head;

    while (m_current != m_tail) {
      total += m_current->getData()->get_score();
      m_current = m_current->getPtrAfter();
    }

    total += m_tail->getData()->get_score();

    return total / m_number;

}

int LinkedList::count(const string name){
  int value = 0;

  if(m_head == NULL){
    return 0;
  }

  m_current = m_head;

  while (m_current != m_tail) {
    if(m_current->getData()->get_name() == name){
      value ++;
    }
    m_current = m_current->getPtrAfter();
  }

  if(m_tail->getData()->get_name() == name){
    value ++;
  }

  return value;

}



void LinkedList::operator += (LinkedList& rLinkedAdd){
    rLinkedAdd.setCurrent(rLinkedAdd.getHead());

    while(rLinkedAdd.getCurrent() != rLinkedAdd.getTail()){
      addToTail(*(rLinkedAdd.getCurrent()->getData()));
      rLinkedAdd.setCurrent(rLinkedAdd.getCurrent()->getPtrAfter());
    }

      addToTail(*(rLinkedAdd.getTail()->getData()));
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
