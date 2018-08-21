#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node {
private:

  Student* m_data;

  Node* m_before;
  Node* m_after;

public:

  Node();
  Node(Student& data, Node* ptrNodeBefore = NULL, Node* ptrNodeAfter = NULL);

  Student* getData() const;
  void setData(Student* value);

  Node* getPtrBefore() const;
  void setPtrBefore(Node* value);

  Node* getPtrAfter() const;
  void setPtrAfter(Node* value);

  virtual ~Node ();
};

ostream& operator <<(ostream&, const Node*);

#endif
