#include<stdio.h>

/*	Author : Soner Türkoðlu
 *
 *
 *
 */

void function1 ();
void function2 ();

typedef enum{
	
	sunday=0,
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday
	
}days;


int main(){
	
	function1 ();
	function2 ();
	
	return 0;
}


void function1 (){
	
	FILE * fp;
	char start_date[20];
	char end_date[20];
	
	int s_day;
	int s_month;
	int s_year;

	int e_day;
	int e_month;
	int e_year;
	
	int day29=29;
	int day30=30;
	int day31=31;
	int day32=32;
	
	if( (fp=fopen("input_date.txt","w")) == NULL ){
		
		printf("writting or reading error \n");
	}
	
	
	printf("Enter the start date (format is dd/MM/yyyy) \n");
	scanf("%s",start_date);
	printf("Enter the end date (format is dd/MM/yyyy ) \n");
	scanf("%s",end_date);
	
	s_day= (start_date[0]-48) * 10 + (start_date[1]-48) + 1;			// getting the start day as an integer value//
	s_month= (start_date[3]-48) * 10 + (start_date[4]-48);				//  getting the start month as an integer value//
	s_year= (start_date[6]-48) * 1000 + (start_date[7]-48) * 100 + (start_date[8]-48) * 10 + (start_date[9]-48); 	//  getting the start year as an integer value //
	
	e_day= (end_date[0]-48) * 10 + (end_date[1]-48);					//  getting the end day as an integer value//
	e_month= (end_date[3]-48) * 10 + (end_date[4]-48);					//  getting the end  month as an integer value//
	e_year= (end_date[6]-48) * 1000 + (end_date[7]-48) * 100 + (end_date[8]-48) * 10 + (end_date[9]-48);	//  getting the end year as an integer value//
	
	
	while(s_day!=e_day-1 || s_month!=e_month || s_year!=e_year){
		
		if(s_month>12){
			s_month%=12;
			s_year++;
		}
		
		switch(s_month){
		
			case 4:	
			case 6:
			case 9:
			case 11:
				while (s_day<day31){
					fprintf(fp,"%c%c/",(s_day/10) + 48,(s_day % 10) + 48);
					fprintf(fp,"%c%c/",(s_month/10) + 48,(s_month % 10 ) + 48);
					fprintf(fp,"%c%c%c%c",(s_year/1000) + 48,( (s_year/100) % 10 ) + 48,( (s_year/10) % 10) + 48,(s_year % 10) + 48);
					fprintf(fp,"%c",'\n');
					s_day++;
				}
				break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				while (s_day<day32){
					fprintf(fp,"%c%c/",(s_day/10) + 48,(s_day % 10) + 48);
					fprintf(fp,"%c%c/",(s_month/10) + 48,(s_month % 10 ) + 48);
					fprintf(fp,"%c%c%c%c",(s_year/1000) + 48,( (s_year/100) % 10 ) + 48,( (s_year/10) % 10) + 48,(s_year % 10) + 48);
					fprintf(fp,"%c",'\n');
					s_day++;
				}
				break;
			case 2:
				if(s_year%4==0){
					while (s_day<day30){
						fprintf(fp,"%c%c/",(s_day/10) + 48,(s_day % 10) + 48);
						fprintf(fp,"%c%c/",(s_month/10) + 48,(s_month % 10 ) + 48);
						fprintf(fp,"%c%c%c%c",(s_year/1000) + 48,( (s_year/100) % 10 ) + 48,( (s_year/10) % 10) + 48,(s_year % 10) + 48);
						fprintf(fp,"%c",'\n');
						s_day++;
					}
				}
				else{
					while (s_day<day29){
						fprintf(fp,"%c%c/",(s_day/10) + 48,(s_day % 10) + 48);
						fprintf(fp,"%c%c/",(s_month/10) + 48,(s_month % 10 ) + 48);
						fprintf(fp,"%c%c%c%c",(s_year/1000) + 48,( (s_year/100) % 10 ) + 48,( (s_year/10) % 10) + 48,(s_year % 10) + 48);
						fprintf(fp,"%c",'\n');	
						s_day++;
					}
				}
							
				break;
			default :
				break;
		
		}
		
		if(s_month==e_month - 1 && s_year==e_year){
			day29=e_day;
			day30=e_day;
			day31=e_day;
			day32=e_day;
			s_day=1;
		}
		
		if(s_month==e_month  && s_year==e_year){
			break;
		}
		else {
			s_day=1;
			s_month++;
		}	
	}
	
	fclose(fp);
	
}

void function2 (){
	
	int i=0;
	char date[20];
	char x;
	
	int rest;
	days reference_day;
	int convert_day;
	
	int day;
	int month;
	int year;
	
	
	FILE *fp1;
	FILE *fp2;
	
	
	
	if( (fp1=fopen("input_date.txt","r")) == NULL){
		
		printf("Reading error\n");
	}
	
	if( (fp2=fopen("new_date.txt","w")) == NULL ){
		
		printf("Writing error\n");
	}
	
	while( ( x=fgetc(fp1) ) != EOF){
		
		i=0;
		while (x != '\n' && x != EOF){
			
			date[i]=x;
			i++;
			x=fgetc(fp1);
		}
		
		day= (date[0] - 48) * 10 + (date[1] - 48) ;
		month= (date[3] - 48) * 10 + (date[4] - 48) ;
		year= (date[6] - 48) * 1000 + (date[7] - 48) * 100 + (date[8] - 48) * 10 + (date[9] - 48) ;
	
		if( 0<= year%400 && year%400 < 100){ 				// getting the reference day //
			reference_day=tuesday;
		}
		
		if( 100<= year%400 && year%400 < 200){
			reference_day=sunday;
		}
		
		if( 200<= year%400 && year%400 < 300){
			reference_day=friday;
		}
		
		if( 300<= year%400 && year%400 < 400){
			reference_day=wednesday;
		}
		
		reference_day=( reference_day + ( (year % 100) + ( (year % 100) / 4) ) ) % 7 ;
		
		if( month == 4 || month == 6 || month == 8 || month == 10 || month == 12){  			// reference day with respect to month //
			
			convert_day=( reference_day + ( (day - month) % 7 ) ) % 7;
		}
			
		if( month == 9 ){
			convert_day= ( reference_day + ( (day - 5) % 7 ) ) % 7;
		}
		
		if( month == 5 ){
			convert_day= ( reference_day + ( (day - 9) % 7 ) ) % 7;
		}
		
		if( month == 7 ){
			convert_day= ( reference_day + ( (day - 11) % 7 ) ) % 7;
		}
		
		if( month == 11 ){
			convert_day= ( reference_day + ( (day - 7) % 7 ) ) % 7;
		}
		
		if( month == 2 ){
			
			if( year % 4 == 0 ){
				if( year % 400 == 100 || year % 400 == 200 || year % 400 == 300){
					convert_day= ( reference_day + ( (day - 28) % 7 ) ) % 7;	
				}
				convert_day= ( reference_day + ( (day - 29) % 7 ) ) % 7 ;
			}
			
			if( year % 4 != 0 ){
				convert_day= ( reference_day + ( (day - 28) % 7 ) ) % 7;
			}
		}
		
		if( month == 3 ){
			convert_day= ( reference_day + ( (day - 0) % 7 ) ) % 7;
		}
		
		if( month == 1 ){
			
			if( year % 4 == 0 ){
				if( year % 400 == 100 || year % 400 == 200 || year % 400 == 300){
					convert_day= ( reference_day + ( (day - 3) % 7 ) ) % 7;	
				}
				convert_day= ( reference_day + ( (day - 4) % 7 ) ) % 7;
			}
			
			if( year % 4 != 0 ){
				convert_day= ( reference_day + ( (day - 3) % 7 ) ) % 7;
			}
			
		}
		
		if(convert_day < 0){
			convert_day=7+convert_day;
		}
		
		switch (convert_day){									// writing the file //
			
			case 0:
				fprintf(fp2,"%s,","Sunday");
				break;
			case 1:
				fprintf(fp2,"%s,","Monday");
				break;
			case 2:
				fprintf(fp2,"%s,","Tuesday");
				break;
			case 3:
				fprintf(fp2,"%s,","Wednesday");
				break;
			case 4:
				fprintf(fp2,"%s,","Thursday");
				break;
			case 5:
				fprintf(fp2,"%s,","Friday");
				break;
			case 6:
				fprintf(fp2,"%s,","Saturday");
				break;
			default :
				break;
		}
		
		switch (month){
			
			case 1:
				fprintf(fp2,"%s %d,","January",day);
				break;
			case 2:
				fprintf(fp2,"%s %d,","February",day);
				break;
			case 3:
				fprintf(fp2,"%s %d,","March",day);
				break;
			case 4:
				fprintf(fp2,"%s %d,","April",day);
				break;
			case 5:
				fprintf(fp2,"%s %d,","May",day);
				break;
			case 6:
				fprintf(fp2,"%s %d,","June",day);
				break;
			case 7:
				fprintf(fp2,"%s %d,","Julay",day);
				break;
			case 8:
				fprintf(fp2,"%s %d,","August",day);
				break;
			case 9:
				fprintf(fp2,"%s %d,","Septenber",day);
				break;
			case 10:
				fprintf(fp2,"%s %d,","October",day);
				break;
			case 11:
				fprintf(fp2,"%s %d,","November",day);
				break;
			case 12:
				fprintf(fp2,"%s %d,","December",day);
				break;
			default :
				break;
		}
		fprintf(fp2,"%d",year);
		fprintf(fp2,"%c",'\n');
	}
	
	fclose(fp1);
	fclose(fp2);
}
