#include <stdio.h>


int main(void)
{  
    int num = 4; // 사람 수 
    int times[4] = {1, 2, 5, 10}; // 소요시간 (정렬이 되어있다고 가정)
    int cross[4]; // 건넌 사람
    int sum = 0; // 소요시간 합

    if (num%2 == 0) // 건너는 사람의 수가 짝수 일 때
    {
        for (int i =0; i<num; i=i+2)
        {
            printf("%i %i\n", times[i], times[i+1]); // 두 사람이 건넘
            cross[i] = times[i+1]; // 건넌 사람 중 느린 사람 도착지점 할당
    
            if (times[i]<cross[0]) // times[i]이 도착해있는 사람보다 빠르다면
            {
                printf("%i\n", times[i]); // 다시 원위치로 돌아옴
            }
            else if(cross[0]<times[i]) // 도착해 있는 사람이 times[i]보다 빠르다면
            {
                printf("%i\n", cross[0]); // 다시 원위치로 돌아옴
                if (cross[0]==times[i-1]) // 만약 원위치로 돌아온 사람이 2번째로 빠른 사람이라면
                {
                    printf("%i %i\n", times[i-2], times[i-1]); // 원위치에 있던 가장 빠른 사람과 같이 건너옴
                }
            }
        }
    }
}
