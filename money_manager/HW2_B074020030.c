// 計概期末報告 - 以一個月為單位的記帳程式 
#include <stdio.h>

void input_amount (int select); // 宣告函數
void calculate_total (unsigned long int total,  int total_frequency); //宣告函數 

//全域變數 
int month; //設定月份; 
unsigned long int budget; //設定預算 
int count_1=0, count_2=0, count_3=0, count_4=0, count_5=0; //各品項的輸入次數 
int sum_1=0, sum_2=0, sum_3=0, sum_4=0, sum_5=0; //各品項之合計 

int main (void) 
{
	printf("請輸入月份 (1~12): ");
	scanf("%d", &month);
	printf("請設定預算: ");
	scanf("%lu", &budget);
	puts("");
	
	int select;
	unsigned long int total; 
	int total_frequency;
	
	input_amount(select); //選擇品項並計算各品項之合計 
	calculate_total(total, total_frequency); //列出表格及該月花費資料  	
}

void input_amount (int select) //選擇品項並計算各品項之合計 
{
	printf("請選擇品項:\n1飲食、2娛樂、3交通、4日常用品、5其他\n輸入-1來結算\n");
	scanf("%d", &select);
	while(select != -1){
		
		
		unsigned long int amount; //花費金額 
		
		switch(select){ //選擇該筆花費的要歸類到的品項，並輸入金額 
			case 1:
				printf("請輸入金額: ");
				scanf("%lu", &amount);
				count_1++;
				sum_1+=amount;
				break;
			
			case 2:
				printf("請輸入金額: ");
				scanf("%lu", &amount);
				count_2++;
				sum_2+=amount;
				break;
				
			case 3:
				printf("請輸入金額: ");
				scanf("%lu", &amount);
				count_3++;
				sum_3+=amount;
				break;
				
			case 4:
				printf("請輸入金額: ");
				scanf("%lu", &amount);
				count_4++;
				sum_4+=amount;
				break;
				
			case 5:
				printf("請輸入金額: ");
				scanf("%lu", &amount);
				count_5++;
				sum_5+=amount;
				break;
			
			default:
				printf("輸入錯誤，請輸入1~5");
				puts("");
				break;			
		}
		puts("");
		printf("請選擇品項:\n1飲食、2娛樂、3交通、4日常用品、5其他\n輸入-1來結算\n");
		scanf("%d", &select);
	}
}
 
void calculate_total (unsigned long int total, int total_frequency) //列出表格及該月花費資料
{  
	puts("");
	puts("");
	
	printf("%8s%16s%18s\n", "品項", "次數", "合計金額");
	printf("%8s%15d%18lu\n", "1 飲食", count_1, sum_1);
	printf("%8s%15d%18lu\n", "2 娛樂", count_2, sum_2);
	printf("%8s%15d%18lu\n", "3 交通", count_3, sum_3);
	printf("%12s%11d%18lu\n", "4 日常用品", count_4, sum_4);
	printf("%8s%15d%18lu\n", "5 其他", count_5, sum_5);
	puts("");
	
	total = sum_1+sum_2+sum_3+sum_4+sum_5; //計算該月花費總金額 
	total_frequency = count_1+count_2+count_3+count_4+count_5; //計算該月花錢總次數 
	
	printf("%d月付錢的總次數: %d次\n", month, total_frequency);
	printf("%d月總花費: %lu元\n", month, total);
	puts("");
	
	unsigned long int balance = total-budget; //預算及實際花費的差額 
	
	if(total>budget){		
		printf("你太揮霍了，這個月超支%lu元\n", balance);	
	} 
	else if(total<budget){
		printf("你太省了，其實你還有%lu元可以花\n", -balance);
	}
	else{
		printf("你真是精打細算，預算剛好用完\n");
	}		
}


