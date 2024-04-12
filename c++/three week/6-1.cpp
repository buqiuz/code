#include <stdio.h>
#define MAXSIZE 20
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position last; /* 线性表的长度*/
};
List Delete( List &L, ElementType minD, ElementType maxD );
List ReadInput() 
{
   int num,i,temp;
   scanf(“%d”,&num);
   for(i=0;i<num;i++)
{
    scanf(“%d”,&(L->Data[num]));
}
L->last = num-1;
}
void PrintList( List L ); 
{
     for(int i=0;i<=L->last;i++)
     {
          printf(“%d ”,L->Data[i]);
}
}

int main()
{
    List L;
    ElementType minD, maxD;
    int i;
    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );
    return 0;
}

/* 你的代码将被嵌在这里 */
List Delete( List &L, ElementType minD, ElementType maxD ){
for(int i=0;i<L.last;i++){
    if(L.Data[i]<minD||L.Data[i]>maxD){
        for(int j=i;j<L.last;j++){
            L.Data[j]=L.Data[j+1];
            
        }
        L.last--;
        i--;
    }
}
    return L;
}