#include <stdio.h>

typedef struct 
{
    int weight;
    int totalSum;
    int *neighborIdx;
    int neighborCap;
    int neighborCnt;
} vert;

void initVert(vert* verts, int size, int neighborCap) 
{
    for(int i = 0; i < size; i++) {
        verts[i].neighborIdx = malloc(sizeof(int)*neighborCap);
        verts[i].neighborCap = neighborCap;
        verts[i].neighborCnt = 0;
        verts[i].totalSum = 0;
    }
}

void enlargeNeighbor(vert *v)
{
    int *newArr = malloc(sizeof(int)*(vert.neighborCap*2));
    for(int i = 0; i < vert.neighborCap; i++)
        *newArr[i] = vert.neighborIdx[i];
    free(vert.neighborIdx);
    vert.neighborIdx = newArr;
}

void insertNeighbor(vert* verts, int a, int b)
{
    if(verts[a].neighborCnt == verts[a].neighborCap) {
        enlargeNeighbor(verts+a);
    }
    verts[a].neighborIdx[verts[a].neighborCnt++] = b;
    verts[a].totalSum += verts[b].weight;
    if(verts[b].neighborCnt == verts[b].neighborCap) {
        enlargeNeighbor(verts+b);
    }
    verts[b].neighborIdx[verts[b].neighborCnt++] = b;
    verts[b].totalSum += verts[a].weight; 
}

int hLeft(int i)
{
    return i*2+1;
}
int hRight(int i)
{
    return i*2+2;
}
int hParent(int i)
{
    return (i-1)/2;
}

int 


int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);
    vert *verts = malloc(sizeof(vert)*n);

    initVert(verts, n, 10);
    for(int i = 0; i < n; i++)
        scanf("%d", &verts[i].weight);
    
    for(int i = 0; i < m; i++) {
        int va, vb;
        scanf("%d%d", &va, &vb);
        insertNeighbor(verts, va-1, vb-1);
    }

    
}