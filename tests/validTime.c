int isValidTime(int hour, int minute){
  if(hour < 25 && minute < 60)
    return 1;
  else
    return 0;
}
