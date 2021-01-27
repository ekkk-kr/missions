#include <stdio.h>

int INSERT = 1;
int DELETE = 2;
int SHOW = 3;
int QUIT = 4;
int MAX_SIZE = 10;

int queueSize = 0;

void insertQueue(int* queue, int newValue) {
    if (queueSize != MAX_SIZE) {
        queue[queueSize++] = newValue;
    } else {
        printf("큐가 꽉 찼습니다.\n");
    }
}

void deleteQueue(int* queue) {
    if (queueSize == 0) {
        printf("큐가 비어있습니다.\n");
    } else {
        printf("큐에서 삭제됨 : %d\n", queue[--queueSize]);
    }
}

void displayQueue(int* queue) {
    if( queueSize == 0 ) {
        printf("큐가 비어있습니다.\n");
    } else {
        printf("큐 : ");
    
        for(int i = 0; i < queueSize; i++) {
           printf("%d ", queue[i]);    
        }
    
        printf("\n"); 
    }
}

int main()
{
    int queue[10] = {};
    
    while (1) {
        int command = 0;
        int insertValue = 0;
        
        printf("입력 : ");
        scanf("%d", &command);
        
        if (command == INSERT) {
            printf("삽입할 값 : "); scanf("%d", &insertValue);
            
            insertQueue(queue, insertValue);
        }
        else if (command == DELETE) {
            deleteQueue(queue);
        } else if (command == SHOW) {
            displayQueue(queue);
        }
        else if (command == QUIT) {
            return 0;
        }
        
        printf("1. 삽입\n2. 삭제\n3. 조회\n4. 종료\n");
    }
    

    return 0;
}

/*
1. insert(삽입) 시엔 배열 다음 요소에 값을 대입하고 큐 사이즈를 1 늘림
2. delete(삭제) 시엔 배열 마지막 요소의 값을 출력하고 큐 사이즈를 1 줄임
3. dispaly(조회) 시엔 요소들 출력
4. 계속 반복 시키기 위해서 종료(4)가 입력되지 않는 이상 계속 반복함
5. quit(종료) 시엔 메인 함수 자체를 반환
*/
