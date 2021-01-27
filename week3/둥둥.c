#include <stdio.h>

int INSERT = 1;
int DELETE = 2;
int SHOW = 3;
int QUIT = 4;

int queueSize = 0;

void insertQueue(int* queue, int newValue) {
    queue[queueSize++] = newValue;
}

void deleteQueue(int* queue) {
    printf("큐에서 삭제됨 : %d\n", queue[--queueSize]);
}

void displayQueue(int* queue) {
    printf("큐 : ");
    
    for(int i = 0; i < queueSize; i++) {
        printf("%d ", queue[i]);    
    }
    
    printf("\n");
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
            if( queueSize == 0 ) {
                printf("큐가 비어있습니다.\n");
            } else {
                deleteQueue(queue);    
            }
            
            
        } else if (command == SHOW) {
            if( queueSize == 0 ) {
                printf("큐가 비어있습니다.\n");
            } else {
                displayQueue(queue);    
            }
        }
        else if (command == QUIT) {
            return 0;
        }
        
        printf("1. 삽입\n2. 삭제\n3. 조회\n4. 종료\n");
    }
    

    return 0;
}

