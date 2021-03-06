#include <stdio.h>
#include <time.h>




void solution(int num2);
void medicine(int num3);
void judge(int period, int lastingterm);
void sym(int num1);
int check(char a);
void survey();
long calendar(int year, int month, int day);
void CountCycle(int year, int month, int day, int n);
void CountPeriod(int year, int month, int day, long j);

int main(void)
{
   int year, month, day, year1, month1, day1;
   int n = 0;
   int a;
   int ans;
   int num1;
   int lastingTerm;

   printf("저번 달 생리 시작일(0000년 00월 00일) 입력하세요 : \n");
   scanf_s("%d %d %d", &year, &month, &day);

   printf("저번 달 생리 끝일(0000년 00월 00일) 입력하세요 : \n");
   scanf_s("%d %d %d", &year1, &month1, &day1);

   printf("주기를 알면 1 모르면 2 를 선택해 주세요 : \n");
   do {
      scanf_s("%d", &ans);

      if (ans == 1)
      {
         printf("생리 주기(00일)를 입력하세요 : \n");
         scanf_s("%d일 ", &n);
         CountCycle(year, month, day, n);
      }

      else if (ans == 2)
      {
         printf("정상주기인 28일로 계산합니다.\n");
         n = 28;
         CountCycle(year, month, day, n);
      }
      else {
         printf("다시 입력해주세요 \n");
      }
   } while (ans != 1 && ans != 2);

   lastingTerm = calendar(year1, month1, day1) - calendar(year, month, day);





   printf("배란일은 ");
   CountPeriod(year, month, day, a = 9);
   printf("부터");

   CountPeriod(year, month, day, a = 17);
   printf("입니다.\n");
   printf("\n");

   printf("*평균 생리주기: 21일 ~ 35일(정상범위)          *정상 생리기간: 2일~10일 \n");
   printf("*이상적인 주기: 28, 30, 32일\n");
   judge(n, lastingTerm);
   printf("\n");

   while (1)//나가기 입력하기 전까지 무한루프
   {
      printf("자세히 알고 싶은 정보에 해당하는 숫자를 눌러주세요.\n");
      printf("1. 생리통 증상별 대처방법  2. 생리통 증상별 추천약  3.속발성 생리통 진단하기   0. 나가기 \n ");
      scanf_s("%d", &num1);
      if (num1 == 0) break;// 0입력시 break로 반복문 탈출
      printf("\n");
      sym(num1);
      printf("\n");
   }

   return 0;

}



long calendar(int year, int month, int day)
{
   int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };// 배열 이용해서 달마다 다른 날짜 고려하기
   int k = 0;
   long sum = 0L;

   sum = ((year - 1) * 365L) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);
   if (!(year % 4) && (year % 100) || !(year % 400))
      months[k]++;//윤년에 해당될 시 배열 중 2월에 해당하는 일수에 +1일 하기
   for (k = 0; k < month - 1; k++)
      sum += months[k];// 총 날짜 구하기
   sum += day;//나머지 날짜 더해주기

   return sum;
}


void CountCycle(int year, int month, int day, int n)
{
   int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int nextYear = calendar(year, 12, 31) - calendar(year, month, day); //다음해가 되기까지의 일 수

   int finalDay;

   if (n > nextYear) //생리 주기(n일)를 더했을 때 다음해를 초과하면
   {
      n -= nextYear; // n= n - nextYear
      year++;
      finalDay = n;

      month = 1;
      day = finalDay;
   }
   else //생리 주기(n일)를 더했을 때 다음해를 초과하지 않으면
   {
      finalDay = n;
      if (!(year % 4) && year % 100 || !(year % 400))
         months[1]++;

      if (day + finalDay <= months[month - 1]) //일 수를 더해도 그 달이 그대로면
      {
         day += finalDay;
      }
      else
      {
         finalDay -= (months[month - 1] - day);// 경과하는 n일의 날짜 중 해당 달을 채우고 다음달로 넘어가는 일수 계산 식 (시작한 날 에 말일까지의 남은 날짜를 뺌)

         month++;

         day = finalDay;
      }
   }
   printf("다음 생리 예정일은  %d년 %d월 %d일입니다\n", year, month, day);



}

void CountPeriod(int year, int month, int day, long j)
{
   int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int nextYear = calendar(year, 12, 31) - calendar(year, month, day); //다음해가 되기까지의 일 수

   int finalDay;

   if (j > nextYear) //배란주기(j일) 경과 후가 다음 해를 넘기면
   {
      j -= nextYear;
      year++;
      finalDay = j;

      month = 1;
      day = finalDay;
   }
   else //j일이 다음해를 안 넘기면
   {
      finalDay = j;
      if (!(year % 4) && year % 100 || !(year % 400))
         months[1]++;

      if (day + finalDay < months[month - 1]) //일 수를 더해도 그 달을 못 넘으면
      {
         day += finalDay;
      }
      else
      {
         finalDay -= (months[month - 1] - day);

         month++;

         day = finalDay;
      }
   }

   printf(" %d년 %d월 %d일", year, month, day);


}





void sym(int num1)
{
   int num2, num3;


   switch (num1)
   {
   case 1:
      printf("내 주요 생리통 증상은... (1) 아랫배(하복부) 통증 (2) 요통(허리통증) (3) 두통과 미열  (4) 부종\n ");
      scanf_s("%d", &num2);
      solution(num2);//입력받은 값에 따라 갈리는 switch함수

      break;

   case 2:
      printf("내 주요 생리통 증상은... (1) 아랫배(하복부) 통증 (2) 요통(허리통증) (3) 두통과 미열 \n");
      printf("번외] (4) 효과가 빠른 진통제를 원한다면?  (5) 약에 민감한 체질이라면? \n ");
      scanf_s("%d", &num3);
      medicine(num3);
      break;



   case 3:
      survey();
      break;

   default:
      printf("잘못된 명령입니다. 다시 입력해 주세요.\n");
      break;

   }

}

void judge(int period, int lastingTerm)
{
   printf("내 생리주기: %d일\n", period);
   if (period > 35 || period < 21) // OR이용해서 일정 기간보다 적거나 길시 경고문 내보냄
      printf("    ...전문의와 상담을 권장합니다.\n");
   else
   {
      printf("    ...정상입니다\n");
   }

   printf("내 생리기간: %d일\n", lastingTerm);
   if (lastingTerm > 10 || lastingTerm < 2)// OR이용해서 일정 기간보다 적거나 길시 경고문 내보냄
      printf("    ...전문의와 상담을 권장합니다.\n");
   else
   {
      printf("    ...정상입니다\n");
   }
}



void solution(int num2)
{

   switch (num2) //switch문 이용하여 분기문 여러개 설정하기
   {
   case 1:
      printf("Ⅰ하복부 아래는 따뜻하고 *상체가 시원해야 함* (ex. 반신욕, 족탕, 좌훈 등..) \n");
      printf("Ⅱ차가운 음식을 주의하기.\n");
      printf("  (*차가운 음식 : 온도가 차가운 음식 / 밀가루, 보리, 현미 등 성질이 차가운 음식, 날음식)\n");
      printf("Ⅲ 좋은 음식 : 미역, 부추, 바나나, 생강");
      break;

   case 2:
      printf("Ⅰ엎드린 개 자세(Downward-facing dog) + 10번 정도 긴 호흡 반복 \n");
      printf("Ⅱ허리와 복부에 핫팩 부착하기\n");
      printf("Ⅲ작약, 대추차 등 근긴장 완화 작용있는 차 마시기\n");
      break;

   case 3:
      printf("Ⅰ최대한 담백한 식사 지향 (기름진 음식, 밀가루 지양) \n");
      printf("Ⅱ철분제 꾸준히 복용하기\n");
      break;

   case 4:
      printf("Ⅰ타이트한 옷, 속옷 지양 \n");
      printf("Ⅱ자극적, 기름진 음식 지양\n");
      printf("Ⅲ평소 혈액순환이 잘 되도록 오메가 3섭취 권장(아마씨유 식물성 오메가3/ 감마오리자놀(신경비타민))\n");
      break;
   default:
      printf("잘못된 명령입니다. 다시 입력해 주세요.\n");
      break;
   }
}

void medicine(int num3)
{

   switch (num3)// switch문 이용하여 분기문 여러개 설정하기
   {
   case 1:
      printf("\n");
      printf("(1) 아랫배(하복부) 통증 \n");
      printf("부스코판플러스정 (5000원)\n");
      break;

   case 2:
      printf("\n");
      printf("(2) 요통 (허리 통증)\n");
      printf("낙센정 (3000원)\n");
      break;

   case 3:
      printf("\n");
      printf("(3) 두통과 미열\n");
      printf("우먼스타이레놀 (2500 ~ 3000원)\n");
      break;

   case 4:
      printf("\n");
      printf("(4) 효과 빠른 진통제를 원한다면?\n");
      printf("이지엔6 프로연질캡슐 (2500 ~ 3000원)\n");
      break;

   case 5:
      printf("\n");
      printf("(5) 약에 민감한 체질이라면?\n");
      printf("이지엔6이브연질캡슐 (2500 ~ 3000원)\n");
      break;

   default:
      printf("잘못된 명령입니다. 다시 입력해 주세요.\n");
      break;



   }
}
void survey()
{

   char Ans1, Ans2, Ans3, Ans4, Ans5;
   int t = 0;

   printf("속발성 진통 판단하기\n");
   printf("문항마다 해당되면 y,  해당되지 않으면 n을 입력 해 주세요.\n");


   printf("1.생리 중 통증이 지속되는 시간이 생리 시작 3~7일 전부터 생리 후 7~10일까지 통증이 지속된다. :");
   scanf_s(" %c", &Ans1, sizeof(char));//문자scanf_s는 추가로 변수의 크기를 입력 해 주기, 입력버퍼에는 개행문자가 그대로 남아있어 오류가 발생하는 것을 막기 위해 %c 앞에 white space 추가해 구분자 넣기
   t += check(Ans1);//y가 입력될 때 마다 점수가 쌓여 일정 점수 이상이면 속발성 생리통임을 판단
   printf("\n");

   printf("2. 25세 전후로 없던 생리통이 생겼다. :");
   scanf_s(" %c", &Ans2, sizeof(char));
   t += check(Ans2);
   printf("\n");

   printf("3. 생리 기관을 제외하고도 하복부 통증, 불쾌감이 든다. :");
   scanf_s(" %c", &Ans3, sizeof(char));
   t += check(Ans3);
   printf("\n");

   printf("4.생리가 시작 될수록 통증이 더 증가한다. :");
   scanf_s(" %c", &Ans4, sizeof(char));
   t += check(Ans4);
   printf("\n");

   printf("5.호르몬제나 진통제를 복용해도 통증이 호전되지 않는다. :");
   scanf_s(" %c", &Ans5, sizeof(char));
   t += check(Ans5);
   printf("\n");

   if (t >= 2)
   {
      printf("속발성 생리통일 가능성이 큽니다. 전문의와 상담이 필요합니다.\n");
   }
   else {
      printf("정상입니다. \n");
   }

}

int check(char a)
{
   int num;
   if (a == 'y')
   {
      num = 1;
      return num;// y를 입력할때마다 +1점
   }
   else if (a == 'n')
   {
      num = 0;
      return num;//n입력시 +0점
   }
   else
   {
      char aws;
      printf("다시 입력해주세요 >>");
      scanf_s("%c", &aws, sizeof(char));
      rewind(stdin);
      check(aws); // 재귀함수 이용해서 올바른 값 입력할 때까지 반복
   }
}