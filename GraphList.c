#include<stdio.h>	
#include<stdlib.h>
#define max 30

typedef struct graph {
	int vertex;
	struct graph* link;
}graph;
typedef struct graphType {                                   
	int n;
	graph* adjlist[max];
}graphType;
void create(graphType* g) {
	g->n = 0;
	for (int i = 0; i < max; i++) {
		g->adjlist[i] = NULL;
	}
}
void insert(graphType* g, int u) {
	if (((g->n) + 1) > max) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}
void insertE(graphType* g, int u, int n) {
	graph* node = (graph*)malloc(sizeof(graph));;
	if (u >= g->n || n >= g->n) {
		printf("\n 그래프에 없는 정점입니다.");
		return;
	}
	node->vertex = n;
	node->link = g->adjlist[u];
	g->adjlist[u] = node;
}
void print_adj(graphType* g) {
	graph* p;
	for (int i = 0; i < g->n; i++)
	{
		printf("\n\t\t정점 %c의 인접 리스트", i + 'A');
		p = g->adjlist[i];
		while (p) {
			printf(" -> %c", p->vertex + 'A');
			p = p->link;
		}
	}
}
int main() {
	graphType* g1 = (graphType*)malloc(sizeof(graphType));
	create(g1);
	for (int i = 0; i < 4; i++) insert(g1, i);
	insertE(g1, 0, 3);
	insertE(g1, 0, 1);
	insertE(g1, 1, 3);
	insertE(g1, 1, 2);
	insertE(g1, 1, 0);
	insertE(g1, 2, 3);
	insertE(g1, 2, 1);
	insertE(g1, 3, 2);
	insertE(g1, 3, 1);
	insertE(g1, 3, 0);
	printf("\n G1의 인접 리스트");
	print_adj(g1);

	return 0;


}
