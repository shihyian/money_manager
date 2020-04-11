// �p���������i - �H�@�Ӥ묰��쪺�O�b�{�� 
#include <stdio.h>

void input_amount (int select); // �ŧi���
void calculate_total (unsigned long int total,  int total_frequency); //�ŧi��� 

//�����ܼ� 
int month; //�]�w���; 
unsigned long int budget; //�]�w�w�� 
int count_1=0, count_2=0, count_3=0, count_4=0, count_5=0; //�U�~������J���� 
int sum_1=0, sum_2=0, sum_3=0, sum_4=0, sum_5=0; //�U�~�����X�p 

int main (void) 
{
	printf("�п�J��� (1~12): ");
	scanf("%d", &month);
	printf("�г]�w�w��: ");
	scanf("%lu", &budget);
	puts("");
	
	int select;
	unsigned long int total; 
	int total_frequency;
	
	input_amount(select); //��ܫ~���íp��U�~�����X�p 
	calculate_total(total, total_frequency); //�C�X���θӤ��O���  	
}

void input_amount (int select) //��ܫ~���íp��U�~�����X�p 
{
	printf("�п�ܫ~��:\n1�����B2�T�֡B3��q�B4��`�Ϋ~�B5��L\n��J-1�ӵ���\n");
	scanf("%d", &select);
	while(select != -1){
		
		
		unsigned long int amount; //��O���B 
		
		switch(select){ //��ܸӵ���O���n�k���쪺�~���A�ÿ�J���B 
			case 1:
				printf("�п�J���B: ");
				scanf("%lu", &amount);
				count_1++;
				sum_1+=amount;
				break;
			
			case 2:
				printf("�п�J���B: ");
				scanf("%lu", &amount);
				count_2++;
				sum_2+=amount;
				break;
				
			case 3:
				printf("�п�J���B: ");
				scanf("%lu", &amount);
				count_3++;
				sum_3+=amount;
				break;
				
			case 4:
				printf("�п�J���B: ");
				scanf("%lu", &amount);
				count_4++;
				sum_4+=amount;
				break;
				
			case 5:
				printf("�п�J���B: ");
				scanf("%lu", &amount);
				count_5++;
				sum_5+=amount;
				break;
			
			default:
				printf("��J���~�A�п�J1~5");
				puts("");
				break;			
		}
		puts("");
		printf("�п�ܫ~��:\n1�����B2�T�֡B3��q�B4��`�Ϋ~�B5��L\n��J-1�ӵ���\n");
		scanf("%d", &select);
	}
}
 
void calculate_total (unsigned long int total, int total_frequency) //�C�X���θӤ��O���
{  
	puts("");
	puts("");
	
	printf("%8s%16s%18s\n", "�~��", "����", "�X�p���B");
	printf("%8s%15d%18lu\n", "1 ����", count_1, sum_1);
	printf("%8s%15d%18lu\n", "2 �T��", count_2, sum_2);
	printf("%8s%15d%18lu\n", "3 ��q", count_3, sum_3);
	printf("%12s%11d%18lu\n", "4 ��`�Ϋ~", count_4, sum_4);
	printf("%8s%15d%18lu\n", "5 ��L", count_5, sum_5);
	puts("");
	
	total = sum_1+sum_2+sum_3+sum_4+sum_5; //�p��Ӥ��O�`���B 
	total_frequency = count_1+count_2+count_3+count_4+count_5; //�p��Ӥ����`���� 
	
	printf("%d��I�����`����: %d��\n", month, total_frequency);
	printf("%d���`��O: %lu��\n", month, total);
	puts("");
	
	unsigned long int balance = total-budget; //�w��ι�ڪ�O���t�B 
	
	if(total>budget){		
		printf("�A�Ӵ��N�F�A�o�Ӥ�W��%lu��\n", balance);	
	} 
	else if(total<budget){
		printf("�A�Ӭ٤F�A���A�٦�%lu���i�H��\n", -balance);
	}
	else{
		printf("�A�u�O�르�Ӻ�A�w���n�Χ�\n");
	}		
}


