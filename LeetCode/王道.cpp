// 01
bool DeL_Min(SqList &L, int &value){
    if(L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for(int i = 1; i<L.length; ++i){
        if(L.data[i] < value){
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    --L.length;
    return true;
}



// 02
void Reverse (SqList &L){
    int temp;
    for(int i = 0; i<L.length/2; ++i){
        temp = L.data[i];
        L.data[i] = L.data[L.length - i -1];
        L.data[L.length - i - 1] = temp;
    }
}


// 03
void del_x_l (SqList &L, int x)
{
    int k = 0, i;
    for(int i = 0; i<L.length; ++i){
        if(L.data[i] != x){
            L.data[k] = L.data[i];
            ++k;
        }
    }
    L.length = k;
}



// 04



// 05
bool Delete_Same(SqList &L){
    if(L.length == 0)
        return false;
    int i,j;
    for(i = 0, j = 1; j<L.length; ++j){
        if(L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
    }
    L.length = i + 1;
    return true;
}



// 06
bool Merge(SeqList A, SeqList B, SeqList &C){
    if(A.length + B.length > C.maxSize)
        return false;
    int i = 0, j = 0, k = 0;
    while(i < A.length && j < B.length){
        if(A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = A.data[j++];
    }
    while(i < A.length)
        C.data[k++] = A.data[i++];
    while(i < B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;
}



// 07
typedef int DataType;
void Reverse (DataType A[], int left, int right, int arraySize){
    if(left >= right || right >= arraySize)
        return;
    
    int mid = (left + right)/2;
    for(int i = 0; i<=mid - left; ++i){
        DataType temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}

void Exchange (DataType A[], int m, int n, int arraySize){
    Reverse(A,0,m+n-1,arraySize);
    Reverse(A,0,n-n,arraySize);
    Reverse(A,n,m+n-1,arraySize);
}




// 09
void sameKey(int A[], int B[], int C[], int n){
    int i = 0, j = 0, k = 0;
    while(i < n && j < n && k < n){
        if(A[i] == B[j] && B[j] == C[k]){
            std::cout<<A[i];
            ++i,++j,++k;
        }
        else{
            int maxNum = max(A[i], max(B[j],C[k]));
            if(A[i] < maxNum) ++i;
            if(B[j] < maxNum) ++j;
            if(C[k] < maxNum) ++k;
        }
    }
}



// 010

void Reverse (int R[], int from, int to){
    int i, temp;
    for(i = 0; i < (to-from+1)/2;++i){
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = temp;
    }
}

void Converse(int R[], int n, int p){
    Reverse(R,0,p-1);
    Reverse(R,p,n-1);
    Reverse(R,0,n-1);
}


// 011





// 链表
// 10

bool Pattern(LinkList A, LinkList B){
    LinkList *p = A;
    LinkList *pre = p;
    LinkList *q = B;
    while(p && q){
        if(p -> data == q -> data){
            p = p -> next;
            q = q -> next;
        }
        else{
            pre = pre -> next;
            p = pre;
            q = B;
        }
    }
    if(q == nullptr)
        return true;
    else
        return false;
}



// 11
bool Symmetry(DLinkList L){
    DNode *p = L -> next,*q = L -> prior;
    while(p != q && p -> next != q){
        if(p->data=q->data){
            p = p-> next;
            q = q-> next;
        }
        else{
            return false;
        }
    }
    return true;
}






void get_next(string s, int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < s.size()){
        if(j == 0 || s.ch[i] == s.ch[j]){
            ++i,++j;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }
}
