/***************************************************************************
 *   Copyright (C) 2007 by Prabhat Kumar Gupta                             *
 *   mcs072895@yaman.cse.iitd.ernet.in                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "graph.h"

#define MAX_WEIGHT 1000

using namespace std;

void connected_graph(vertex *, long ,int);
int  genrandom_graph(vertex* ,long ,long ,int);
int  check_edge(vertex *,int ,int );

//This Generates a connected Graph
void connected_graph(vertex *v_array, long max_nodes,int max_weight)
{
       int s = rand() % max_nodes;// initial source node
	int d,d1;// destination nodes
	int n=0;
	
	//generate a spaning tree
	while(n<max_nodes-1){
		
		do{
		d= rand()%max_nodes;
		}while(s == d || v_array[d].edgelist != NULL);

		//source should be

		int weight=rand()%max_weight;

		createEdge1(v_array,s,d,weight);
		//add_edge(v_array,s,d,weight);
		
		do{
			d1= rand()%max_nodes;
		}while(v_array[d1].edgelist == NULL);	
		s = d1;
		n++;
	}

}


int  genrandom_graph(vertex* v_array,long max_nodes,long num_edges,int max_weight)
    {
       connected_graph(v_array,max_nodes,max_weight);
	int s=0,d=0,weight=0;
	int n=0;
       int adl_edges;
	adl_edges = num_edges-max_nodes-1;

	while(n<(adl_edges)){

	        while(s==d || check_edge(v_array,s,d)){
			s=rand()%max_nodes;	
			d=rand()%max_nodes;	
		}
		weight=rand()%max_weight +1;
		createEdge1(v_array,s,d,weight);
//		add_edge(v_array,s,d,weight);
		++n;
		}
		return 0;
    }



int check_edge(vertex *v_array,int s,int d)
{

	node *temp = v_array[s].edgelist;
		while(temp != NULL)
                {
			if(temp -> v2 == d)
			    return 1;
                        temp = temp->next;
		}
	return 0;
}

int main()
{

int itype;
int no_vertex;
int option ;	
int max_nodes;
//vertex *pgraph;

cout<<endl<<"How many nodes you want in your graph of nodes:";
cin>>max_nodes;

unsigned int t =(unsigned int) time(NULL);
srand(t);
long maxedges, minedges,num_edges;

maxedges= max_nodes * (int)(log(max_nodes)/log(2));
minedges= max_nodes -1;
num_edges=(rand()%(maxedges-minedges)) + (minedges);

vertex * v_array = createVertexList(max_nodes);

//vertex_v1 * v_array;

//v_array = make_list(max_nodes);	//initialize the graph
genrandom_graph(v_array,max_nodes,num_edges,MAX_WEIGHT); // generate random graph

ofstream foutt;
foutt.open("graph.txt");
foutt<<max_nodes<<" ";

for(int i = 0; i < max_nodes; i++)
{	
		node *e = (v_array + i ) -> edgelist;
		while(e != NULL)
		{	
			foutt<<i<<" "<<e->v2<<" "<<e->weight<<endl;			
			e = e -> next;
		}

}
cout<<"Random Graph Generated.";
return 0;
	
}
