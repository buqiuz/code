#include <stdio.h>
#include <stdlib.h>

void PrintA(int A[], int N)//输出下一步
{
    int i;
    for(i=0;i<N;i++) {
        if(i != N-1)
            printf("%d ", A[i]);
        else
            printf("%d", A[i]);
    }
}

int IsSameArr(int A[], int C[], int N)//比较结果是否相同
{
    int i;
    for(i=0;i<N;i++)
        if(A[i] != C[i]) return 0;
    return 1;
}

void CopyArr(int A[], int B[], int N)//因为要经历两次排序故用两个数组
{
    int i;
    for(i=0;i<N;i++)
        B[i] = A[i];
}

void Read(int A[], int B[], int N)//读入数据
{
    int i;
    for(i=0;i<N;i++) {
        scanf("%d", &A[i]);
    }
    for(i=0;i<N;i++) {
        scanf("%d", &B[i]);
	}
}

void InsertionSort(int A[], int B[], int N)//插入排序,边插入边比较
{
    int P, i;
    int Tmp;
    int flag = 0;

    for(P=1;P<N;P++){
        Tmp = A[P];
        for(i=P;i>0 && A[i-1]>Tmp;i--){
        	A[i] = A[i-1];
		}  
        A[i] = Tmp;
        if(IsSameArr(A, B, N)) { //后面的continue后进入下一个P循环后这个if就不成立了而flag仍是上一轮在if中赋的1，故可以执行下面用来输出的if 
            printf("Insertion Sort\n");
            flag = 1;
            continue;//得到下一步就结束的关键
        }
        if(flag== 1) {
            flag = 0;
            PrintA(A, N);
        }
    }
}

void Merge(int A[], int TmpA[], int L, int R, int RightEnd)
{
    int LeftEnd = R - 1;
    int Tmp = L;
    int NumElements = RightEnd - L + 1;
    int i;
    while(L <= LeftEnd && R <= RightEnd) {
        if(A[L] <= A[R]) TmpA[Tmp++] = A[L++];
        else             TmpA[Tmp++] = A[R++];
    }
    while(L <= LeftEnd)
        TmpA[Tmp++] = A[L++];
    while(R <= RightEnd)
        TmpA[Tmp++] = A[R++];
    for(i=0;i<NumElements;i++, RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
}

void Merge_Pass(int A[], int TmpA[], int N, int length)
{
    int i, j;
    for(i=0;i<N-2*length;i+=2*length)
        Merge(A, TmpA, i, i+length, i+2*length-1);
    if(i+length < N)
        Merge(A, TmpA, i, i+length, N-1);
    else
        for(j=i;j<N;j++)    TmpA[j] = A[j];

}

void Merge_Sort(int A[], int B[], int N)//归并排序，边归并边比较
{
    int *TmpA;
    int length = 1;
    int flag = 0;
    int flag2 = 0;
    TmpA = (int*)malloc(sizeof(int)*N);
    if(TmpA != NULL) {
        while(length < N) {
            Merge_Pass(A, TmpA, N, length);
            length *= 2;
            if(IsSameArr(A, B, N)) { //!!!之后的flag和flag2与A,TmpA交换对应，完美的解决了输出下一步的问题 
                printf("Merge Sort\n");
                flag = 1;
            }
            if(flag2 == 1) {
                flag2 = 0;
                PrintA(A, N);
            }
            Merge_Pass(TmpA, A, N, length);
            length *= 2;
            if(IsSameArr(A, B, N)) { 
                printf("Merge Sort\n");
                flag2 = 1;
            }
            if(flag == 1) {
                flag = 0;
                PrintA(A, N);
            }
        }
        free(TmpA);
    }
}

int main()
{
    int N;  
    scanf("%d\n", &N);
    int A[N], B[N], Tmp[N];
    Read(A, B, N);
    CopyArr(A, Tmp, N);
    InsertionSort(Tmp, B, N);
    CopyArr(A, Tmp, N);
    Merge_Sort(A, B, N);
    return 0;
}
