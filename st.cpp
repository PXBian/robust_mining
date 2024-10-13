/* Construction of a suffix tree using the Ukkonen algorithm
 * (with an example of searching for words in it)
 * Complexity: O(n).
 */
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>

#define FOR(I, A, B) for (INT I = (A); I <= (B); I++)
#define FORD(I, A, B) for (INT I = (A); I >= (B); I--)
#define REP(I, N) for (INT I = 0; I < (N); I++)
#define VAR(V, init) __typeof(init) V = (init)
#define FORE(I, C) for (VAR(I, (C).begin()); I != (C).end(); I++)

typedef int64_t INT;

using namespace std;

INT read_patterns( string pattern_filename, unsigned char ** &patterns, INT &num_patterns)
{	

	ifstream is_patterns;
 	is_patterns.open (pattern_filename, ios::in | ios::binary);
 	
	INT max_len_pattern = 0;
	INT ALLOC_SIZE = 180224;
	INT seq_len = 0;
	INT max_alloc_seq_len = 0;
	INT max_alloc_seqs = 0;
	unsigned char chr = 0;
	
	while ( is_patterns.read(reinterpret_cast<char*>(&chr), 1) )
	{
		if( num_patterns >= max_alloc_seqs )
		{
			patterns = ( unsigned char ** ) realloc ( patterns,   ( max_alloc_seqs + ALLOC_SIZE ) * sizeof ( unsigned char* ) );
			patterns[ num_patterns ] = NULL;
			
			max_alloc_seqs += ALLOC_SIZE;
		}
		
		if( seq_len != 0 && chr == '\n' )
		{
			patterns[ num_patterns ][ seq_len ] = '\0';
			
			num_patterns++;

			if( seq_len > max_len_pattern)
				max_len_pattern = seq_len;
			
			seq_len = 0;
			max_alloc_seq_len = 0;
			
			patterns[ num_patterns ] = NULL;
		}
		else 
		{
			if ( seq_len >= max_alloc_seq_len )
			{
				patterns[ num_patterns ] = ( unsigned char * ) realloc ( patterns[ num_patterns ],   ( max_alloc_seq_len + ALLOC_SIZE ) * sizeof ( unsigned char ) );
				max_alloc_seq_len += ALLOC_SIZE;
			}
			
			patterns[ num_patterns ][ seq_len ] = ( unsigned char) chr;	
			seq_len++;	
		}
	} 
	is_patterns.close();
	
return 0;
}

struct STedge;
struct STvertex
{
  map<unsigned char,STedge> g; /* edges to children */
  STvertex *f; /* suffix link */
  /* suffix number (0 is the whole word, -1 means the vertex is not a leaf) */
  INT numer;
};
struct STedge
{
  INT l,r; /* x[l]..x[r] is a piece of text representing an edge */
  STvertex *v;
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
  if (kraw.l<=kraw.r)
  {
    char c=txt[kraw.l];
    STedge e=kraw.v->g[c];
    if (txt[kraw.r+1] == txt[e.l+kraw.r-kraw.l+1]) return true;
    w=new STvertex; w->numer=-1;
    kraw.v->g[c].r = e.l+kraw.r-kraw.l;
    kraw.v->g[c].v = w;
    e.l+=kraw.r-kraw.l+1;
    w->g[txt[e.l]]=e;
    return false;
  } 
  return kraw.v->g.find(txt[kraw.l]) != kraw.v->g.end();
}

void Update(STedge &kraw, INT n)
{
  STvertex *oldr=root,*w;
  while (!Test_and_split(w,kraw))
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
  REP(i,n) { e.r=-i; e.l=-i; top->g[x[i]]=e; }
  root->f=top;
  e.l=0; e.v=root;
  REP(i,n)
  {
    e.r=i-1; Update(e,n); 
    e.r++; Canonize(e,x);
  }
  return root;
}

void STDelete(STvertex *w)
{
  FORE(it,w->g) STDelete(it->second.v);
  delete w;
}



struct Pair 
{
    STvertex * node;
    map<unsigned char, STedge>::iterator it;
    Pair(STvertex * _node, map<unsigned char, STedge>::iterator _it)
    {
        node = _node;
        it = _it;
    }
};


INT add_children( stack<STvertex *> * st, STvertex * current, vector<INT> * leaves )
{
	map<unsigned char, STedge>::iterator indx; 

	for(indx = current->g.begin(); indx != current->g.end(); indx++ )
	{
	
		if( indx->second.v->numer != -1 )
		{
			leaves->push_back( indx->second.v->numer );
			
		}
		else st->push( indx->second.v );
	}
	
	
	
	
return 0;
}


vector<INT> search( STvertex * r )
{
	vector<INT> leaves;
	stack<STvertex *> st;

	st.push( r );
	
	while( st.size() > 0 )
	{
		st.pop();
		
		add_children( &st, r, &leaves );
		
		if( st.size() > 0 )
			r = st.top();
	}
		
				
	return leaves;
}

vector<INT> Find(unsigned char *s,STvertex *r, unsigned char *x)
{

	vector<INT> occ;
	INT n=strlen( (char*) s);
	
	INT i=0;
	
	while (i<n)
	{
	
		if (r->g.find(s[i]) == r->g.end())
			return occ;
		
		STedge e=r->g[s[i]];
	
		FOR(j,e.l,e.r)
		{
			if( s[i++]!=x[j] )
	  			return occ;
	  			
			if (i == n)
			{
				r = e.v;
				
				if( r->numer == -1 )
				{
					vector<INT> children = search(r);
					
					for(INT a = 0; a<children.size(); a++)	
						occ.push_back( children.at(a) );		
				}
				else occ.push_back( r->numer );
	
				return occ;
			}

	  		
	  
		}

		r=e.v;
	}
 	
 	occ.push_back( r->numer );

	return occ;
}

int main(int argc, char **argv)
{
	if( argc < 3 )
 	{
        	cout<<"Wrong arguments!\n";
 		cout<<"./st <text_file> <pattern_file> <output_filename>\n";
 		exit(-1);
 	}
 	
	// Input text file
 	ifstream is_text;
 	is_text.open (argv[1], ios::in | ios::binary);
 	
 	ifstream in_file(argv[1], ios::binary);
   	in_file.seekg(0, ios::end);
   	INT text_file_size = in_file.tellg();

 	// Input patterns
 	string pattern_filename = argv[2];
 	
 	// Input output file
 	string output_filename = argv[3]; 
 	
 	
	unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+2 ) * sizeof ( unsigned char ) );
   	char chr = 0;
  	INT text_size = 0;
  	
	for (INT i = 0; i < text_file_size - 1; i++)
	{	
		is_text.read(reinterpret_cast<char*>(&chr), 1);

		text_string[i] = chr;
		text_size++;
	}
	is_text.close();	
	text_string[ text_size ] = '~';
 	text_string[ text_size+1] = '\0';
	
	INT num_patterns = 0;
	
	unsigned char ** patterns = NULL;
	read_patterns( pattern_filename, patterns, num_patterns );
	
	ofstream pattern_output;
	pattern_output.open(output_filename);
	
	STvertex *r = Create_suffix_tree( text_string , text_size+1 );
	
 	vector<INT> occ;
 	INT hits = 0;
 
 	for(INT a = 0; a<num_patterns;a ++)
 	{
 		occ = Find( patterns[a], r, text_string );
 		
 		for(INT b = 0; b<occ.size(); b++ )
 		{
 			pattern_output<<patterns[a]<<" occurs at position "<<occ.at(b)<<endl;
 		}	
  		hits = hits + occ.size();
  	}
  	
  	cout<<"hits: "<<hits<<endl;
		
	STDelete(r);
	return 0;
}

