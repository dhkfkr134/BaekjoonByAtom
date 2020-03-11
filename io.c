#include <stdio.h>

int main()
{
  int N=0;

  scanf("%d",&N);

  int arr[N][3];
  for(int i=0;i<N;i++)
  {
    scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
  }

  //x좌표순서로 오름차순만들기
  for(int j=0;j<N;j++)
  {
    for(int i=0;i<N-j-1;i++)
    {
      if(arr[i][0]>arr[i+1][0])
      {
        int tmp[3] = {arr[i][0],arr[i][1],arr[i][2]};
        arr[i][0] = arr[i+1][0];
        arr[i][1] = arr[i+1][1];
        arr[i][2] = arr[i+1][2];
        arr[i+1][0] = tmp[0];
        arr[i+1][1] = tmp[1];
        arr[i+1][2] = tmp[2];
      }
    }
  }
//
int maxx=0;
for(int i=0;i<N-1;i++)
{
  if(arr[i][2]>maxx) maxx=arr[i][2];
}
//x좌표1부터 각각 가장높은H값을 기억하기
  int trans=0;//x-n의 스카이라인(기억값)
  for(int i=1;i<maxx+1;i++)
  {
    int maxh=0;//x의 스카이라인
    int count=0;//건물이 떨어져있을때는 y값이0인걸하기위함(한x값에 해당하는배열이 1개라면)
    int arrnum=-100;//count된 배열번호기억
    int arrnum2=-100;
    for(int j=0;j<N;j++)
    {
      if(arr[j][0] <= i&&arr[j][2] >= i)
      {
        count++;
        if(arrnum==-100)
          arrnum = j;
        else
          arrnum2 = j;
        if(arr[j][1]>maxh)
        {
          maxh= arr[j][1];
        }
      }
    }

    if(trans!=maxh&&count!=2)// 이전높이랑 지금높이다를때
    {
      trans=maxh;
      printf("%d %d ",i,trans);
    }
    if(count==1) // 겹치는게없을때
     if(i==arr[arrnum][2]&&i!=arr[arrnum+1][0])
     {
       trans=0;
       printf("%d 0 ",i);
     }
     if(count==2) // 두건물만 곂치는데 높이다를때
      if(arr[arrnum][2]==arr[arrnum2][2])
      {
        trans=arr[arrnum2][1];
        printf("%d %d",i,trans);
      }
   }

  return 0;
}
