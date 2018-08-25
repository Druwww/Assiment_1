#include "LinkedList.h"


LinkedList::LinkedList(): m_head(NULL), m_tail(NULL), m_current(NULL), m_number(0){
  //Hi
}

LinkedList::~LinkedList(){
  //setnumber();

  m_current = m_head;

  for(int i = 0; i < m_number; i++){
    Node* next = m_current->getPtrAfter();
    delete m_current;
    m_current = next;
  }

  cout << "Bye Bye !\n";

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

Node* LinkedList::getCurrent() const{
  return m_current;
}
void LinkedList::setCurrent(Node* value){
  m_current = value;
}

void LinkedList::addToTail(Student& newStudent){

    //If nothing in the list
    if(m_head == NULL){
      m_head = new Node(newStudent, NULL, NULL);
      m_tail = m_head;
    }
    else{
      m_current = new Node(newStudent, m_tail, NULL);
      m_tail->setPtrAfter(m_current);
      m_tail = m_current;
    }

    m_number++;

}


void LinkedList::remove(Node* nodeDel){

    //If the node delete is the head
    if(nodeDel->getPtrBefore() == NULL){
      m_head = nodeDel->getPtrAfter();
      m_head->setPtrBefore(NULL);
    }
    else{
      nodeDel->getPtrBefore()->setPtrAfter(nodeDel->getPtrAfter());
    }

    //if the node delete is the tail
    if(nodeDel->getPtrAfter() == NULL){
      m_tail = nodeDel->getPtrBefore();
      m_tail->setPtrAfter(NULL);
    }
    else{
      nodeDel->getPtrAfter()->setPtrBefore(nodeDel->getPtrBefore());

    }
    delete nodeDel;

    m_number --;

    //Security check
    updateHead();
    updateTail();

}

void LinkedList::remove(const string name){

    m_current = m_head;

    Node* tempPtr;

    //loking fot the Node* to remove with the name
    while (m_current != NULL) {
      tempPtr = m_current;
      m_current = m_current->getPtrAfter();
      if(tempPtr->getData()->get_name() == name){
          remove(tempPtr);
      }
    }
}

void LinkedList::setnumber(){
  int value = 0;

  m_current = m_head;

  while (m_current != NULL) {
    value++;
    m_current = m_current->getPtrAfter();
  }

  m_number = value;

}


int LinkedList::calcAverage(){
    //setnumber();

    //if nothing in the list...
    if(m_head == NULL){
      return 0;
    }

    int total = 0;

    m_current = m_head;

    //Add all the scores together
    while (m_current != NULL) {
      total += m_current->getData()->get_score();
      m_current = m_current->getPtrAfter();
    }

    return total / m_number;
}

int LinkedList::count(const string name){
  int value = 0;

  //if nothing in the list...
  if(m_head == NULL){
    return 0;
  }

  m_current = m_head;

  while (m_current != NULL) {
    if(m_current->getData()->get_name() == name){
      value ++;
    }
    m_current = m_current->getPtrAfter();
  }

  return value;

}

void LinkedList::swapNodeNext(Node* n1, Node* n2){

  if(n1->getPtrBefore() == NULL && n2->getPtrAfter() == NULL){
    n2->setPtrBefore(NULL);
    n2->setPtrAfter(n1);
    n1->setPtrBefore(n2);
    n1->setPtrAfter(NULL);
  }

  else if(n1->getPtrBefore() == NULL && n2->getPtrAfter() != NULL){
    Node* n2After = n2->getPtrAfter();

    n2->setPtrAfter(n1);
    n2->setPtrBefore(NULL);

    n1->setPtrAfter(n2After);
    n2After->setPtrBefore(n1);
    n1->setPtrBefore(n2);
  }

  else if(n1->getPtrBefore() != NULL && n2->getPtrAfter() == NULL){
    Node* n1Before = n1->getPtrBefore();

    n1->setPtrBefore(n2);
    n1->setPtrAfter(NULL);

    n2->setPtrAfter(n1);
    n2->setPtrBefore(n1Before);
    n1Before->setPtrAfter(n2);
  }

  else{
    Node* n1Before = n1->getPtrBefore();

    Node* n2After = n2->getPtrAfter();

    n1->setPtrAfter(n2After);
    n2After->setPtrBefore(n1);
    n1->setPtrBefore(n2);

    n2->setPtrAfter(n1);
    n2->setPtrBefore(n1Before);
    n1Before->setPtrAfter(n2);
  }

  updateHead();
  updateTail();

}


bool LinkedList::orderAlphabet(){

  m_current = m_head;
  for(int j = 0; j < m_number - 1; j++) {
    Node* nextPtr = m_current->getPtrAfter();
    if(m_current->getData()->get_name() > nextPtr->getData()->get_name()){
      swapNodeNext(m_current, nextPtr);
      return false;
    }
    else{
      m_current = m_current->getPtrAfter();
    }
  }


  return true;
}

void LinkedList::order(){
  while(!orderAlphabet()){}
}

void LinkedList::updateHead(){

  while (m_head->getPtrBefore() != NULL) {
    m_head = m_head->getPtrBefore();
  }

}

void LinkedList::updateTail(){

  while (m_tail->getPtrAfter() != NULL) {
    m_tail = m_tail->getPtrAfter();
  }

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
