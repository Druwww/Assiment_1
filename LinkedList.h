#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Student.h"

class LinkedList {
private:

  Node* m_head;
  Node* m_tail;

  Node* m_current;

  int m_number;

public:

  LinkedList ();

  virtual ~LinkedList ();

  Node* getHead() const;
  void setHead(Node* value);

  Node* getTail() const;
  void setTail(Node* value);

  Node* getCurrent() const;
  void setCurrent(Node* value);

  int getNumber() const;

  void addToTail(Student& newStudent);

  void operator += (LinkedList& rLinkedAdd);

  void remove(Node* nodeDel);
  void remove(const string name);

  void setnumber();

  int calcAverage();

  int count(const string name);

  void swap(Node* n1, Node* n2);

  bool orderAlphabet();

  void order();

};

ostream& operator <<(ostream&, LinkedList& theList);

#endif
