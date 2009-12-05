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
#ifndef GRAPH_H
#define GRAPH_H


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include<stdio.h>
#include<malloc.h>

using namespace std;
struct node{
unsigned int v2;
int weight;
node *next;
};

struct vertex{
int index;
node *edgelist;
};

void Graph(void );
vertex *createVertexList(int);
void createEdge(vertex *,int, int, int);
void createEdge1(vertex *,int, int, int);
void printEdgeList(vertex *,int );
void printVertexList(vertex * ,int );
void printGraph(vertex *,int );
void printNode(node *);


#endif
