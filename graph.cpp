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
#include "graph.h"

vertex *createVertexList(int n)
{
vertex *vertexlist,*temp;
vertexlist = (vertex*) malloc(n*sizeof(vertex));
temp=vertexlist;
for(int i=0; i<n; i++)
{
	temp->index=i;
	temp->edgelist=NULL;
	temp=temp + 1;
}
return vertexlist;
}

void createEdge(vertex *vertexlist,int v1, int v2, int w)
{
node *newnode1,*newnode2,*temp;
vertex *ver1, *ver2;
ver1 = vertexlist + v1;
ver2 = vertexlist + v2;
newnode1 = (node*) malloc(sizeof(node));
newnode2 = (node*) malloc(sizeof(node));

newnode1->v2 = v2;
newnode1->weight=w;
newnode1->next = ver1->edgelist;
/*ver1*/ (vertexlist + v1)->edgelist = newnode1;


newnode2->v2 = v1;
newnode2->weight=w;
newnode2->next = ver2->edgelist;
(vertexlist + v2)->edgelist=newnode2;
}

void createEdge1(vertex *vertexlist,int v1, int v2, int w)
{
node *newnode1,*newnode2,*temp;
vertex *ver1, *ver2;
ver1 = vertexlist + v1;
ver2 = vertexlist + v2;
newnode1 = (node*) malloc(sizeof(node));
newnode2 = (node*) malloc(sizeof(node));

newnode1->v2 = v2;
newnode1->weight=w;
newnode1->next = ver1->edgelist;
/*ver1*/ (vertexlist + v1)->edgelist = newnode1;

/*
newnode2->v2 = v1;
newnode2->weight=w;
newnode2->next = ver2->edgelist;
(vertexlist + v2)->edgelist=newnode2;*/
}
void printNode(node *N)
{
cout<<endl<<"Address of Node : "<<N<<"\t Key : "<<N->v2<< "\t Weight : "<<N->weight<<"\t Next : "<<N->next<<endl;
}

void printEdgeList(vertex *vertexlist,int v)
{
vertex *ver = vertexlist + v;
cout<<endl<<"  "<<ver->index;
node *temp;
temp = ver->edgelist;
while(temp != NULL)
{
	cout<<"\t=>\t"<<temp->v2<<"("<<temp->weight<<")";
	temp=temp->next;
}
}
void printVertexList(vertex *vl,int n)
{
vertex *temp = vl;
for(int i =0; i<n; i++)
{	if(temp->edgelist !=NULL)
	cout<<"vertex index "<<temp->index<<" edgelist "<<temp->edgelist->v2<<endl;
	temp = temp+1;
}
}
void printGraph(vertex *vl,int n)
{
	vertex *temp = vl;node *t;
	cout<<endl<<"*****************************************************************************";
	cout<<endl<<"VERTEX  =>  \tEDGELIST";
	cout<<endl<<"*****************************************************************************";
	for(int i =0; i<n; i++)
	{	if(temp->edgelist !=NULL)
		{
			printEdgeList(vl,i); 
		}
		else
		if(i!=0)
			cout<<endl<<"  "<<temp->index;
		temp = temp+1;
	}
	cout<<endl<<"*****************************************************************************";
}
