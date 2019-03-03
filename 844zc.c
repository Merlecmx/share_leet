int  stack(char *arry,char* arry2) {
	int count = 0;
	while (*arry != '\0') {
        if (*arry != '#') {
            arry2[count] = *arry;
			count++;
		} else if (count > 0) {
            count--;
        } else {
            count = 0;
        }
		arry++;
	}
	return count;
}
bool backspaceCompare(char* S, char* T) {
    char *arry_s = (char *)malloc(201*sizeof(char));
    char *arry_t = (char *)malloc(201*sizeof(char));
	int count_s = stack(S,arry_s);
    int count_t = stack(T,arry_t);
	if (count_s != count_t) {
        free(arry_s);
        free(arry_t);
		return false;
    } else {
        return (strncmp(arry_s, arry_t, count_s) == 0);
        free(arry_s);
        free(arry_t);
	}
}
