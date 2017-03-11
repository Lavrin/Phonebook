#include <stdio.h>
#include <string.h>

int i=0;

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
    printf("strlen1: %d - %s, strlen2: %d - %s\n", strlen(str1), str1,  strlen(str2), str2);
    if (strlen(str1)==strlen(str2)){
	for(i=0; i<strlen(str1); i++){
	    if(str1[i] == str2[i]){
		done = 1;
	    } else {
		done = 0;
		break;
	    }
	}
    }
    return done;
}

int main(){
    int help = 0, counter;
    char command[20];
    char add[] = "add";
    char list[] = "list";
    char search[] = "search";
    char delete[] = "delete";
    char quit[] = "quit";
    for(i=0; i<10; i++) phonebook[i].flag = 0;
    while(comstr(command, quit) != 1){
	printf("Введите команду\n");
	scanf("%s", command);
	if(comstr(command, add) == 1){
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
		if (command == "y"){
		    printf("Какое поле хотите перезаписать? (введите имя)\n");
		    scanf("%s", command);
		    for(i=0; i<10 && phonebook[i].name == command; i++){
			EnteredField(phonebook[i].name, phonebook[i].number);
			break;
		    }
		} else break;
	    }
	}
	if(comstr(command, list) == 1){
	    for(counter = 10, i=0; i<10 && phonebook[i].flag==1; i++, counter--){
		printf("Имя: %s, Номер: %s %d\n", phonebook[i].name, phonebook[i].number, i);
	    }
	    if(counter>0) printf("Осталось %d свободных полей\n", counter);
	    if(counter == 0) printf("свободных полей не осталось\n");
	}
	if(comstr(command, search) ==1){
	    printf("Введите имя искомого контакта\n");
	    scanf("%s", command);
	    for(i=0; i<10; i++){
		printf("name: %s, command: %s, comstr: %d\n", phonebook[i].name, command, comstr(command, phonebook[i].name));
		if(comstr(phonebook[i].name, command) == 1){
		    printf("Номер телефона: %s\n", phonebook[i].number);
		}
	    }
	}
	for(i=0; i<10; i++) printf("name: %s; number: %s\n", phonebook[i].name, phonebook[i].number);
    }
    return 0;
}
