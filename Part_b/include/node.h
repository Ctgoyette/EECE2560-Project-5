#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef int WeightType;
typedef int NodeType;

int const MaxNumNodex = 9999;

typedef int NodeWeight;
typedef int EdgeWeight;

class node
{
   public:
      node();
      node(const node &);
      node &operator=(const node &);
   
      void setId(int i);
      int getId() const;

      void setWeight(NodeWeight);
      NodeWeight getWeight() const;
   
      void setNode(int id, NodeWeight w = 0, bool m = false, bool v = false);

      void mark();
      void unMark();
      bool isMarked() const;

      void visit();
      void unVisit();
      bool isVisited() const;

      friend ostream &operator<<(ostream &ostr, const node &n);

   private:
      int id;
      NodeWeight weight;
      bool marked;
      bool visited;
};

#endif
