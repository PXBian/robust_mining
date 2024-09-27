#include <math.h>
#include <fstream>
#include <iostream>
#include <algorithm> 
#include <sstream>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;
typedef int64_t INT;  


struct interval
{
	INT start;
	INT end;
	INT contain;
};

/** KMP pre-processing **/
void preKmp(unsigned char * x, INT m, INT * kmpNext) 
{
	INT i, j;

	i = 0;
	j = kmpNext[0] = -1;
	
	while (i < m)
	{
		while (j > -1 && x[i] != x[j])
			j = kmpNext[j];
		i++;
		j++;
		
		if (x[i] == x[j])
			kmpNext[i] = kmpNext[j];
		else
			kmpNext[i] = j;
			
	}
}

/** KMP computation **/
void KMP(unsigned char * x, unsigned char * y, vector<interval> &occ)
{
	INT m = strlen( (char*) x );
	INT n = strlen( (char*) y );
	
	
	INT * kmpNext = ( INT * ) malloc (  ( m+1 ) * sizeof ( INT ) );
	
	INT i, j;

	/* Preprocessing */
	preKmp(x, m, kmpNext);

	/* Searching */
	i = j = 0;
	while (j < n)
	{
		while (i > -1 && x[i] != y[j])
			i = kmpNext[i];
		i++;
		j++;
		
		if (i >= m)
		{
			occ.push_back({j - i, j-i+ m-1, 0});
  			i = kmpNext[i];
		}
	}
	
	free( kmpNext );
	
}

/** Binary search **/
void binarySearch(INT start, INT &end, INT n, bool result, INT * tested_index)
{

	if( result == 1 ) // result returned 'YES'
	{
		end = min( n-1, end + (end - start + 1) / 2 );
	}
        else if (result == 0) // result returned 'NO'
        {	
        	end = min( n-1, start + (end - start) / 2);
	}
	
}


INT DP( vector<interval> occ, INT k )
{
	INT M = 0;

	// Compute number of intervals that contain d for initialisation
	for (INT b = 0; b < occ.size(); b++) 
	{
		INT d_b = occ.at(b).end;
		INT count = 0;

		for (INT i = 0; i < occ.size(); i++)
		{

			if (occ.at(i).start <= d_b && occ.at(i).end >= d_b)
				count++;

		}

		occ.at(b).contain = count;
	}


	// Compute w_ab
	INT ** w_ab = new INT*[occ.size()];
	for(INT i = 0; i<occ.size(); i++)
		w_ab[i] = new INT[occ.size()];
		
	for(INT i = 0; i<occ.size(); i++)
		for(INT j = 0; j<occ.size(); j++)
			w_ab[i][j] = 0;
			
	for (INT a = 0; a < occ.size(); a++)
	{
		for (INT b = a+1; b <occ.size(); b++)
		{
			if( occ.at(b).start > occ.at(a).end )
			{
				w_ab[a][b] = 1;
			}
			
		}
	}
	
	// Initialize DP
	INT ** T = new INT*[occ.size()];
	for(INT i = 0; i<occ.size(); i++)
		T[i] = new INT[k];
		
	for (INT b = 0; b < occ.size(); b++)
		T[b][0] = occ.at(b).contain;

	for (INT h = 0; h < k; h++)
		T[0][h] = occ.at(0).contain;

	// Compute DP
	for (INT h = 1; h < k; h++) 
	{
		for (INT b = 1; b < occ.size(); b++)
		{
			INT max_val = 0;

			for (INT a = 0; a<b; a++)
			{
				INT val = T[a][h - 1] + w_ab[a][b-1];
				if (val > max_val)
					max_val = val;
			}

			T[b][h] = max_val;
		}

	}
	
	for(INT i = 0; i<occ.size(); i++)
		for(INT j = 0; j<k; j++ )
			if( T[i][j] > M )
				M = T[i][j];
				
	for(INT a = 0; a<occ.size(); a++)
	{
		delete[] T[a];
		delete[] w_ab[a];
	}
	
	delete[] T ;	
	delete[] w_ab ;
	
	return M;
}

int main(int argc, char **argv)
{
	if( argc < 5 )
 	{
        	cout<<"Wrong arguments!\n";
 		cout<<"./k_kill <text_file> <k> <t> <output_file>\n";
 		exit(-1);
 	}
 	ifstream is;
 	is.open(argv[1], ios::in | ios::binary);
 	
 	ifstream in_file(argv[1], ios::binary);
   	in_file.seekg(0, ios::end);
	INT text_file_size = in_file.tellg();
	
	std::string str_k(argv[2]);
	
  	INT k;
 	std::stringstream(str_k)>>k;
 	
 	std::string str_t(argv[3]);
	
  	INT t;
 	std::stringstream(str_t)>>t;
 	
 	std::string str_out(argv[4]);
   
   	unsigned char * text = ( unsigned char * ) malloc (  ( text_file_size + 1 ) * sizeof ( unsigned char ) );
   	
  	// Read in text
  	char c = 0;
  	INT n = 0;
	for (INT i = 0; i < text_file_size; i++)
	{	
		is.read(reinterpret_cast<char*>(&c), 1);
		if( (unsigned char) c == '\n')
			continue;
		else
		{
			text[n] = (unsigned char) c ;
			n++;
		}
	}
	in_file.close();
	text[n] = '\0';
	
	if( k < 1 )
	{
	
		fprintf( stderr, " Error: k must be larger than 0!\n");
		return ( 1 );
	}
	
	if( t < 2 )
	{
	
		fprintf( stderr, " Error: t must be larger than 1!\n");
		return ( 1 );
	}
	
	vector<interval> occ;
	
	unsigned char * pattern = ( unsigned char * ) malloc (  ( n + 1 ) * sizeof ( unsigned char ) );
	
	INT * output = ( INT * ) malloc (  ( n ) * sizeof ( INT ) );
	
	for(INT i = 0; i<n; i++)
		output[i] = 0;
		
	for(INT i = 0; i<n; i++)
	{
	
		INT * tested_index = ( INT * ) malloc (  ( n ) * sizeof ( INT ) );
		
		for(INT i = 0; i<n; i++)
			tested_index[i] = 0;
				
		INT end = i + ( n-i )/2 ;
		INT result = 1; // to check if the answer was 'YES' or 'NO'
		
		while(  tested_index[end] == 0 )
		{
			memcpy( &pattern[0], &text[i], end-i+1 );
			pattern[ end-i+1] = '\0';
			
			// Compute occurrences
			KMP( pattern, text, occ ); 
			
			if( occ.size() >= t )
			{ 
				// Compute killed intervals
				INT M = DP( occ, k );
				
				if( occ.size() - M >= t )
				{
					result = 1; 
					
					if( end > output[i] )
						output[i] = end;		
				}
				else result = 0;
					
			}
			else result = 0;
			
			occ.clear();
			tested_index[end] = 1;
			
			//binary search using i and end position
			binarySearch( i, end, n, result, tested_index ); 
				
		}
		
		free( tested_index );
	}
	
	
	ofstream output_f(str_out);
	
	// Output results
	for(INT i = 0; i<n; i++)
	{
		if( output[i] > 0 )
			output_f<<output[i]-i+1<<endl;
		else output_f<<output[i]<<endl;
	}
	
	free( output );
	free( pattern );
	free( text );
	
	return 0;
}
