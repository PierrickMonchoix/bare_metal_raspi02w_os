#include <stdint.h>


void returnString(char* init , char* result){
    int counter = 0;
    int numMaxChar = 0;
    while(init[counter] != '\0'){
        counter ++;
    }
    numMaxChar = counter - 1;
    for(counter = 0 ; counter <= numMaxChar ; counter ++){
        result[counter] = init[numMaxChar - counter];
    }
    result[counter] = '\0';
}


void intToString(char* string , uint64_t num64 ){
    int base  = 16;
    char digit = 0;
    int counter = 0;
    char stringReturned[65];

    while(num64 > 0){
        digit = num64 % base;
        switch( digit )
        {
            case 0:
                stringReturned[counter] = '0';
                break;
            case 1:
                stringReturned[counter] = '1';
                break;
            case 2:
                stringReturned[counter] = '2';
                break;
            case 3:
                stringReturned[counter] = '3';
                break;
            case 4:
                stringReturned[counter] = '4';
                break;
            case 5:
                stringReturned[counter] = '5';
                break;
            case 6:
                stringReturned[counter] = '6';
                break;
            case 7:
                stringReturned[counter] = '7';
                break;
            case 8:
                stringReturned[counter] = '8';
                break;
            case 9:
                stringReturned[counter] = '9';
                break;
            case 10:
                stringReturned[counter] = 'A';
                break;
            case 11:
                stringReturned[counter] = 'B';
                break;
            case 12:
                stringReturned[counter] = 'C';
                break;
            case 13:
                stringReturned[counter] = 'D';
                break;
            case 14:
                stringReturned[counter] = 'E';
                break;
            case 15:
                stringReturned[counter] = 'F';
                break;
            }   
        num64 = num64 / base;
        counter  ++;
    }
    stringReturned[counter] = '\0';
    returnString(stringReturned , string);
}

