#include <stdio.h>
#include <string.h>

char *stackcom[] = { "add", "list", "search", "delete", "quit"};

int i=0;
int counter =0;

struct handbook{
    int flag;
    char name[20];
    char number[7];
}phonebook[10];

void EnteredField(char *EnterName, char *EnterNumber){
    printf("Введите имя (не более 20 символов)\n");
    scanf("%s", EnterName);
    printf("Введите номер\n");
    scanf("%s", EnterNumber);
}

int comstr(char *str1, char *str2){
    int done = 0;
    if (strlen(str1)==strlen(str2)){
	for(counter=0; counter<strlen(str1); counter++){
	    if(str1[counter] == str2[counter]){
		done = 1;
	    } else {
		done = 0;
		break;
	    }
	}
    }
    return done;
}

int comcom(char *str1){
    int done =0;
    counter = 0;
    for(i=0; i<5; i++){
	if(comstr(str1, stackcom[i]) == 1) done = ++counter;
    }
    return done;
}

int main(){
    int help = 0;
    char command[20];
    char yes[] = "y";
    for(i=0; i<10; i++) phonebook[i].flag = 0;
    int escape=0;
    while(escape == 0){
	printf("Введите команду\n");
	scanf("%s", command);
	switch (comcom(command)){
	    case 1:
		for(help = 0, i=0; i<10; i++, help++){
		    if(phonebook[i].flag == 0){
			phonebook[i].flag = 1;
			EnteredField(phonebook[i].name, phonebook[i].number);
			break;
		    }
		}
		if (help==10){
		    printf("Свободных полей для записи нет. Желаете перзаписать? (y/n)\n");
		    scanf("%s", command);
		    if (comstr(command, yes) == 1){
		        printf("Какое поле хотите перезаписать? (введите имя)\n");
		        scanf("%s", command);
		        for(i=0; i<10; i++){
			    if(comstr(phonebook[i].name, command) == 1){
				EnteredField(phonebook[i].name, phonebook[i].number);
				break;
			    }
			}
		    } else break;
		}
		break;
	    case 2:
	        for(counter = 10, i=0; i<10; i++){
		    if(phonebook[i].flag==1){
			printf("Имя: %s, Номер: %s\n", phonebook[i].name, phonebook[i].number);
			counter--;
		    }
		}
		if(counter>0) printf("Осталось %d свободных полей\n", counter);
		if(counter <= 0) printf("Свободных полей не осталось\n");
		break; //}
	    case 3:
		/*printf("По какомуполю хотите осуществить поиск?");
		scanf("%s", command
		*/
		printf("Введите имя искомого контакта\n");
		scanf("%s", command);
		for(i=0, help=0; i<10; i++){
		    if(comstr(phonebook[i].name, command) == 1 && phonebook[i].flag == 1){
			printf("Номер телефона: %s\n", phonebook[i].number);
			help = 1;
		    }
		}
		if(help==0){
		    printf("Такого контакта нет\n");
		}
		break; //}
	    case 4:
		printf("Какой контакт хотите удалить? (Введите имя)\n");
		scanf("%s", command);
		for(i=0, help=0; i<10; i++){
		    if(comstr(command, phonebook[i].name) == 1){
			phonebook[i].flag = 0;
			help = 1;
		    }
		}
		if(help==0){
		    printf("Такого контакта нет\n");
		}
		break; //}
	    case 5:
		escape = 1;
		break;
	    case 0:
		printf("Такой команды нет!\n");
	}
    }
    return 0;
}