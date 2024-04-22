#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"

class graph
{
  public:
   graph();
   graph(int n);
   graph(ifstream &fin);
   graph(const graph &);
   graph &operator=(const graph &);   

   void addEdge(int i, int j, NodeWeight w = 0);
   void removeEdge(int i, int j);

   int addNode(NodeWeight w = 0);
   int addNode(node n);

   void setEdgeWeight(int i, int j, EdgeWeight w = 0);
   EdgeWeight getEdgeWeight(int i, int j) const;

   NodeWeight getTotalNodeWeight();
   EdgeWeight getTotalEdgeWeight();

   void setNodeWeight(int i, NodeWeight w = 0);
   NodeWeight getNodeWeight(int i) const;

   bool isEdge(NodeType i, NodeType j) const;
   int numNodes() const;
   int numEdges() const;
   
   node &getNode(int);
   const node &getNode(int) const;
   edge &getEdge(int i,int j);
   const edge &getEdge(int i, int j) const;

   void printNodes() const;
   void printEdges() const;

   void mark(int i);
   void mark(int i, int j);
   void unMark(int i);
   void unMark(int i, int j);
   bool isMarked(int i) const;
   bool isMarked(int i, int j) const;
   void clearMark();
   bool allNodesMarked();

   void visit(int i);
   void visit(int i, int j);
   void unVisit(int i);
   void unVisit(int i, int j);
   bool isVisited(int i, int j) const;
   bool isVisited(int i) const;
   void clearVisit();
   bool allNodesVisited();

   friend ostream &operator<<(ostream &ostr, const graph &g);

  private:
   matrix<edge> edges;
   vector<node> nodes;
   int NumEdges;

};

#endif