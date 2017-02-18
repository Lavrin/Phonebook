#include <stdio.h>
#include <locale.h>

struct handbook{
	int flag;
	char name[20];
	char number[7];
}phonebook [10];

int main(){
	setlocale(LC_ALL, "RUS");
	int i;
	char command[7];
	for(i = 0; i<10; i++){
		phonebook[i].flag = 0;
	}
	while(*command != '5'){
		printf("Доступные комманды:\n1)Добавление элемента\n2)Поиск\n3)Вывод списка\n4)Удаление элемента\n5)Выход\n");
		printf("Введите комманду\n");
		//fgets(command, 7, stdin);
		//gets(command);
		scanf("%s", &command);
		if(*command == '3'){
			int help=10;
			for(i=0; i<10&&phonebook[i].flag==1; i++){
				help--;
				printf("Имя: %s, Номер: %s\n", phonebook[i].name, phonebook[i].number);
			}
			if(help > 0)printf("Осталось %d пустых полей\n", help); else if(help == 0) printf("Пустых полей не осталось");
		} else if(*command == '1'){
			for(i=0; i<10&&phonebook[i].flag==0; i++){
				printf("Введите имя\n");
				scanf("%s", &phonebook[i].name);
				printf("Введите номер\n");
				scanf("%s", &phonebook[i].number);
				phonebook[i].flag=1;
				break;
			}
		}else if(*command == '4'){
			printf("Какой элемент удалить?\n");
			scanf("%d", &i);
			phonebook[i].flag=0;
		} else printf("Такой комманды нет! ");
	}
	
	return 0;
}
