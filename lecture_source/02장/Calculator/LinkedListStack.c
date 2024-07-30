#include "LinkedListStack.h"

void  LLS_CreateStack( LinkedListStack** Stack )
{
    //  스택을 자유 저장소에 생성 
    (*Stack )       = ( LinkedListStack*)malloc(sizeof( LinkedListStack ) );
    (*Stack )->List = NULL;
    (*Stack )->Top  = NULL;
}

void LLS_DestroyStack( LinkedListStack* Stack )
{
    while ( !LLS_IsEmpty(Stack ) )
    {
        Node* Popped = LLS_Pop( Stack );
        LLS_DestroyNode(Popped);    
    }

    //  스택을 자유 저장소에서 해제 
    free(Stack );
}

Node* LLS_CreateNode( char* NewData )
{
    Node* NewNode = ( Node*)malloc(sizeof( Node ) );
    NewNode->Data = ( char*)malloc(strlen( NewData ) + 1);

    strcpy( NewNode->Data, NewData );  //  데이터를 저장한다. 

    NewNode->NextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화한다. 

    return NewNode;//  노드의 주소를 반환한다. 
}

void  LLS_DestroyNode( Node* _Node )
{
    free(_Node->Data );
    free(_Node );
}

void LLS_Push( LinkedListStack* Stack, Node* NewNode )
{
    if ( Stack->List == NULL ) 
    {        
        Stack->List = NewNode;
    } 
    else
    {
        //  스택의 Top에 신규 노드를 연결한다.
        Stack->Top->NextNode = NewNode;
    }
    
    //  스택의 Top 필드에 새 노드의 주소를 등록한다. 
    Stack->Top = NewNode;
}

Node* LLS_Pop( LinkedListStack* Stack )
{
    //  LLS_Pop() 함수가 반환할 최상위 노드 저장 
    Node* TopNode = Stack->Top;


    if ( Stack->List == Stack->Top )
    {
        Stack->List = NULL;
        Stack->Top  = NULL;
    }
    else
    {
        // Top 아래에 있던 노드를 새로운 CurrentTop에 저장 
        Node* CurrentTop = Stack->List;
        while ( CurrentTop != NULL && CurrentTop->NextNode != Stack->Top )
        {
            CurrentTop = CurrentTop->NextNode;
        }

        // CurrentTop을 Top에 저장
        Stack->Top = CurrentTop;
        Stack->Top->NextNode = NULL;
    }

    return TopNode;
}

Node* LLS_Top( LinkedListStack* Stack )
{
    return Stack->Top;
}

int LLS_GetSize( LinkedListStack* Stack )
{
    int    Count = 0;
    Node*  Current = Stack->List;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

int LLS_IsEmpty( LinkedListStack* Stack )
{
    return (Stack->List == NULL);
}
