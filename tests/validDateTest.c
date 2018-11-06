#include <stdio.h>
#include "validDate.h"

void testDay(){
  if(!isValidDate(2,2,2)){
    printf("success\n");
  }else{
    printf("fail\n");
  }

}

uint8_t main(uint8_t argc, char** argv){
  testDay();
  return 0;
}
