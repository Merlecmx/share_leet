bool isLongPressedName(char *name, char *typed) {
    int name_index = 0;
    int typed_index = 0;
    while (name[name_index] && typed[typed_index]) {
        if (name[name_index] == typed[typed_index]) {
            name_index++;
            typed_index++;
        } else {
            typed_index++;
        }
    }
    return name_index == strlen(name);
}
