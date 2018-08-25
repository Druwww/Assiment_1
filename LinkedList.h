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

  //Constructor
  LinkedList ();

  //Destructor
  virtual ~LinkedList ();

  //Getter/setter
  Node* getHead() const;
  void setHead(Node* value);

  Node* getTail() const;
  void setTail(Node* value);

  Node* getCurrent() const;
  void setCurrent(Node* value);

  int getNumber() const;

  //Member that add a new student in the linked list at the end of the list : the tail
  void addToTail(Student& newStudent);
  // Pre conditions : Receives a reference of the suddent to add : copy all his data in a new nodeDel
  //Post conditions : None

  //Member that rewrite the operator += : add all the studdent for a liste to the list inside
  void operator += (LinkedList& rLinkedAdd);
  // Pre conditions : Receives the list to copy of the studdent in the list where we are
  // Post conditions :  None

  //Member that remove a node in the liste : take care of all changment for other nodes to link the list
  void remove(Node* nodeDel);
  // Pre conditions : Receives the pointeurs of the node to remove from the list
  // Post conditions : None

  //Member that remove all nodes with the name of the sudent pass
  void remove(const string name);
  // Pre conditions : Receives the name of the student to remove from the list
  // Post conditions : None

  //Member that update the number of node in the list
  void setnumber();
  // Pre conditions : None
  // Post conditions : None

  //Member taht give the average of the all score in the list
  int calcAverage();
  // Pre conditions : None
  // Post conditions : Return the average of all score in the list

  //Member that count all the student with the name given in the list
  int count(const string name);
  // Pre conditions : Receives af string of the name of the studdent to count
  // Post conditions : Return the number of studdent with this name in the list

  //Member who swap position of two nodes in a row
  void swapNodeNext(Node* n1, Node* n2);
  // Pre conditions : Receives the ptr of two nodes to swap BUT they ahev to be in a row and n1 before n2
  // Post conditions : None

  //Memeber who check if the list have all the student in a alphabetic order : if found a not good order : swap one and tell the list isn't done
  bool orderAlphabet();
  // Pre conditions : None
  // Post conditions : Return true if the list is in alphabetic order, false if not and a swap did

  //Member that do a alphabetic order in the list of student
  void order();
  // Pre conditions : None
  // Post conditions : None

  //Member that update the head of the list
  void updateHead();
  // Pre conditions : None
  // Post conditions : None

  //Member that update the tail of the list
  void updateTail();

};

//Rewrite the operator << for a list
ostream& operator <<(ostream&, LinkedList& theList);

#endif
