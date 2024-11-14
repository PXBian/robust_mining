#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <climits>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>
#include <chrono>

using namespace std;

typedef int32_t INT;

#define FOR(I, A, B) for (INT I = (A); I <= (B); I++)
#define FORD(I, A, B) for (INT I = (A); I >= (B); I--)
#define REP(I, N) for (INT I = 0; I < (N); I++)
#define VAR(V, init) __typeof(init) V = (init)
#define FORE(I, C) for (VAR(I, (C).begin()); I != (C).end(); I++)


struct STedge;
struct STvertex
{
  	map<unsigned char,STedge, greater<unsigned char>> g; /* edges to children */ // Order the children in descending order to build the SA of this ST
  	STvertex *f; /* suffix link */
  	/* suffix number (0 is the whole word, -1 means the vertex is not a leaf) */
  	INT numer, str_depth_of_N = 0;
    bool flag; /*false: not frequent and survive; true: frequent and survive*/
    // vector<STvertex*> path; /*the path from root to this node*/
	STvertex *parent;
    pair<INT,INT> SA_interval;
};
struct STedge
{
  INT l,r; /* x[l]..x[r] is a piece of text representing an edge */
  STvertex *v;	// The node that this edge points to v (child)
};

STvertex *root;
unsigned char *txt;
INT liscie; /* number of leaves created */

inline void Canonize(STedge &kraw, unsigned char *x)
{
  if (kraw.l<=kraw.r)
  {
    STedge e=kraw.v->g[x[kraw.l]];
    while (e.r-e.l <= kraw.r-kraw.l)
    {
      kraw.l+=e.r-e.l+1;
      kraw.v=e.v;
      if (kraw.l<=kraw.r) e=kraw.v->g[x[kraw.l]];
    }
  }
}

inline bool Test_and_split(STvertex* &w,const STedge &kraw)
{
  w=kraw.v;
  if (kraw.l<=kraw.r)	// If kraw is not in the intial case. Special case: for the intial step, kraw.l=-1, kraw.r=0
  {
    char c=txt[kraw.l];	// get the current first char on the string of edge kraw
    STedge e=kraw.v->g[c];	// create a new edge as the child of kraw with label c
    if (txt[kraw.r+1] == txt[e.l+kraw.r-kraw.l+1]) return true;	// Finish go through the string on kraw and don't need to split
    w=new STvertex; w->numer=-1;	// START to split: create a new node w (-1 not the leaf)
    kraw.v->g[c].r = e.l+kraw.r-kraw.l;
    kraw.v->g[c].v = w;		// Add the new node w between kraw.v and its child
    e.l+=kraw.r-kraw.l+1;
    w->g[txt[e.l]]=e;
    return false;
  } 
  return kraw.v->g.find(txt[kraw.l]) != kraw.v->g.end();
}

void Update(STedge &kraw, INT n)	// kraw: the edge of the current process; n is the length of S
{
  STvertex *oldr=root,*w;
  while (!Test_and_split(w,kraw))	// Test_and_split is false: not split in this function
  {
    STedge e;
    e.v=new STvertex; e.l=kraw.r+1; e.r=n-1;
    e.v->numer=liscie++;
    w->g[txt[kraw.r+1]]=e;
    if (oldr!=root) oldr->f=w;
    oldr=w;
    kraw.v=kraw.v->f;
    Canonize(kraw,txt);
  }
  if (oldr!=root) oldr->f=kraw.v;
}

/* x should have some '$' at the end */
STvertex* Create_suffix_tree(unsigned char *x,INT n)
{
	STvertex *top; /* pinezka */
	STedge e;
	top=new STvertex; root=new STvertex; txt=x;
	top->numer = root->numer = -1;
	e.v=root; liscie=0;	
	// e.l is the index of start char on the edge e, e.r is of end char on e; 
	// top->g[x[i]]: Assign e as one to-child edge of node top 
	REP(i,n) { e.r=-i; e.l=-i; top->g[x[i]]=e; }		
	// Initialize root: Assign the suffix link (f) of root as node top, 
	root->f=top;
	e.l=0; e.v=root; // e.l=0: start position of building the tree
	REP(i,n)	// Go through the S to get each char
	{
	  e.r=i-1; Update(e,n);	// e.r: the current end position of the string on e; n: the length of the S + 1
	  e.r++; Canonize(e,x);
	}
	return root;
}

// void STDelete(STvertex *w)
// {
//   FORE(it,w->g) STDelete(it->second.v);
//   delete w;
// }



// struct Pair 
// {
//     STvertex * node;
//     map<unsigned char, STedge>::iterator it;
//     Pair(STvertex * _node, map<unsigned char, STedge>::iterator _it)
//     {
//         node = _node;
//         it = _it;
//     }
// };


// INT add_children( stack<STvertex *> * st, STvertex * current, vector<INT> * leaves )
// {
// 	map<unsigned char, STedge>::iterator indx; 

// 	for(indx = current->g.begin(); indx != current->g.end(); indx++ )	// Go through all the children of current
// 	{
	
// 		if( indx->second.v->numer != -1 )	// numer == -1: It is not a leaf (root or internal node); != -1: It is a leaf, add it to the leaves vector
// 		{
// 			leaves->push_back( indx->second.v->numer );
			
// 		}
// 		else st->push( indx->second.v );	// It is not a leaf: push it to the stack
// 	}
	
	
// 	return 0;
// }


// vector<INT> search( STvertex * r )
// {
// 	vector<INT> leaves;
// 	stack<STvertex *> st;

// 	st.push( r );
	
// 	while( st.size() > 0 )
// 	{
// 		st.pop();
		
// 		add_children( &st, r, &leaves );
		
// 		if( st.size() > 0 )
// 			r = st.top();
// 	}
		
// 	return leaves;
// }

// vector<INT> Find(unsigned char *s,STvertex *r, unsigned char *x)	// *s is the pattern needs to be found, intial *r is the root of ST, *x is the text
// {

// 	vector<INT> occ;
// 	INT n=strlen( (char*) s);
	
// 	INT i=0;
	
// 	while (i<n)
// 	{
	
// 		if (r->g.find(s[i]) == r->g.end())	// Finish searching at the end of children of r
// 			return occ;
		
// 		STedge e=r->g[s[i]];	// e is the edge toward to the current child s[i] of r
	
// 		FOR(j,e.l,e.r)
// 		{
// 			if( s[i++]!=x[j] )	// if the current char in the pattern s does not match the text x
// 	  			return occ;
	  			
// 			if (i == n)
// 			{
// 				r = e.v;	// set r to the child corresponding to e.v
				
// 				if( r->numer == -1 )	// r is not a leaf
// 				{
// 					vector<INT> children = search(r);
					
// 					for(INT a = 0; a<children.size(); a++) {
// 						occ.push_back( children.at(a) );
// 					}	
								
// 				}
// 				else occ.push_back( r->numer );
	
// 				return occ;
// 			}
// 		}

// 		r=e.v;
// 	}
 	
//  	occ.push_back( r->numer );

// 	return occ;
// }

// void print_edge(STedge edge, unsigned char *x) {
// 	// Print the current info on edge
// 	unsigned char substring[edge.r - edge.l + 2];
// 	memcpy(substring, x + edge.l, edge.r - edge.l + 1);
// 	substring[edge.r - edge.l + 1] = '\0'; // Add null terminator
// 	cout << "The string on current edge is " << substring << endl;
// }
