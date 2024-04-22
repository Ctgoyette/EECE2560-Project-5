#include "../include/node.h"

node::node()
// Constructor, creates a new, uninitialized node. Id is initialized
// elsewhere (by the graph constructor).
{
   unMark();
   unVisit();
   setWeight(0);
}

node::node(const node &n)
// Copy constructor
{
   setNode(n.getId(), n.getWeight(), n.isMarked(), n.isVisited());
}

node &node::operator=(const node &n)
// Overloaded assignment operator.
{
   setNode(n.getId(), n.getWeight(), n.isMarked(), n.isVisited());
   return *this;
}

NodeWeight node::getWeight() const
// Return node's weight
{
   return weight;
}

void node::setWeight(NodeWeight w)
// Set node's weight to w.
{
   weight = w;
}
   
void node::setId(int i)
// Set node's id to i.  Throws an exception if i < 0.
{
   if (i < 0)
      throw rangeError("Bad value in node::setId");
   
   id = i;
}
   
int node::getId() const
// Return node's id
{
   return id;
}

void node::setNode(int id, NodeWeight w, bool m, bool v)
// Initialize a node;
{
   setId(id);
   setWeight(w);

   if (m)
      mark();
   else
      unMark();
   
   if (v)
      visit();
   else
      unVisit();
}

void node::mark()
   // Mark node.
{
   marked = true;
}

void node::unMark()
   // Un-mark node.
{
   marked = false;
}

bool node::isMarked() const
   // Return true if node is marked, and false otherwise.
{
   return marked;
}

void node::visit()
   // Set visited to true;
{
   visited = true;
}

void node::unVisit()
   // Set visited to false;
{
   visited = false;
}

bool node::isVisited() const
   // Return true if node is visited, and false otherwise.
{
   return visited;
}

ostream &operator<<(ostream &ostr, const node &n)
{
   ostr << "node: " << n.getId() << " weight: " << n.getWeight() 
        << " visited: " << n.isVisited() << " marked " << n.isMarked() << endl;

   return ostr;
}