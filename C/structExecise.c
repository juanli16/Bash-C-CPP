#include<stdio.h>

struct PERSON{
	char type;
	char name[100];
	int age;

	union specific{
		struct professor{
			int salary;
			char university[100];
			char department[100];
			int tenured;
		}prof;

		struct student{
			int stdID;
			char university[100];
			char department[100];
			int honor;
			char program[100];
		}stud;
	}spec;
}person;

int main(void){
	//for the person:
	puts("Please put the information of the person.\n");
	puts("Enter your full name:");
	scanf("%[^\n]s",person.name);	
	puts("Enter your type, 'p' for professor, 's' for student:");
	scanf("%c",&person.type);
	puts("Enter your age:");
	scanf("%d",&person.age);
	if (person.type=='p'){
		puts("Please enter which university are you working in:");
		scanf("%[^\n]s",person.spec.prof.university);
		puts("Enter at which department:");
		scanf("%[^\n]s",person.spec.prof.department);
		puts("Are you tenured? '1' for True, '0' for false:");
		scanf("%d", &person.spec.prof.tenured);
		puts("Please enter your salary, if you do not want to, simply enter -1:");
	}else{
		puts("Please enter which university are you attending:");
		scanf("%[^\n]s",person.spec.stud.university);
		puts("Enter at which department:");
		scanf("%[^\n]s",person.spec.stud.department);
		puts("Which program are you? Undergraduate or Master or PHD");
		scanf("%[^\n]s",person.spec.stud.program);
		puts("Are you an honor student? '1' for True, '0' for false:");
		scanf("%d", &person.spec.stud.honor);
		puts("Enter your student ID:");
		scanf("%d",&person.spec.stud.stdID);
	}
	
	if(person.type == 'p'){
		if(person.spec.prof.tenured==1){
			if(person.spec.prof.salary!=(-1)){
				printf("%s is %d years old. %s works in %s and in the %s department, where %s is tenured and has an annual salary of %d",person.name,person.age,person.name,person.spec.prof.university, person.spec.prof.department,person.name,person.spec.prof.salary);
			}else{
				printf("%s is %d years old. %s works in %s and in the %s department, where %s is tenured.",person.name,person.age,person.name,person.spec.prof.university, person.spec.prof.department,person.name);
			}
		}else{
			if(person.spec.prof.salary!=(-1)){
				printf("%s is %d years old. %s works in %s and in the %s department, where %s has an annual salary of %d",person.name,person.age,person.name,person.spec.prof.university, person.spec.prof.department,person.name,person.spec.prof.salary);
			}else{
				printf("%s is %d years old. %s works in %s and in the %s department.",person.name,person.age,person.name,person.spec.prof.university,person.spec.prof.department);
			}
		}
	}

	return 0;
}


