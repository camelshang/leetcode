int myAtoi(string str) {
  int sign = 1, base = 0, i = 0;
  while (str[i] == ' ') { // remove space
    i++;
  }
  if (str[i] == '-' || str[i] == '+') { // set sign
    sign = 1 - 2 * (str[i] == '-');
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
      if (sign == 1) {
        return INT_MAX;
      } else if (sign == -1) {
        return INT_MIN;
      }
    }
    base = 10 * base + str[i] - '0';
    i++;
  }
  return base * sign;
}